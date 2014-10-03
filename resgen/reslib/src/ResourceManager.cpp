#include <ResourceManager.hpp>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

using namespace std;

unsigned toLBE(unsigned);

vector<unsigned char> readToEnd(const string &File)
{
	struct stat buf;
	
	int fd = open(File.c_str(), O_RDONLY);
	fstat(fd, &buf);
	int size = buf.st_size;
	vector<unsigned char> ret(size);
	read(fd, ret.data(), size);
	close(fd);
	return ret;
}

ResourceManager::ResourceManager(const string &File) : ResourceManager(readToEnd(File))
{
}

ResourceManager::ResourceManager(const std::vector<unsigned char> &data)
{
	if(data.size() < 8) return;

	unsigned processedRes = 0;
	unsigned numRes = toLBE(*(unsigned*)(data.data() + 4));
	unsigned i = 8;

	while(processedRes++ < numRes)
	{
		Resource res;
		unsigned sizename  = toLBE(*(unsigned*)(data.data() + i));
		string   name      = string((char *)(data.data() + (i += 4)), sizename);
		unsigned resSize   = toLBE(*(unsigned*)(data.data() + (i += sizename)));
		unsigned resOffset = toLBE(*(unsigned*)(data.data() + (i += 8, i - 4)));
		res.assign(begin(data) + resOffset, begin(data) + resOffset + resSize);
		m_resources[name] = res;
	}
}

/*
 * Converti un entier code en LE vers BE ou inverse
 */
unsigned toLBE(unsigned in)
{
	return
		(in & 0xFF000000) >> 24 |
		(in & 0x00FF0000) >> 8  |
		(in & 0x0000FF00) << 8  |
		(in & 0x000000FF) << 24 ;
}

/* Format de fichier RES
 * 
 * 52 45 53 01  [xx xx xx xx] [aa aa aa aa] [bb bb ... {aa fois} .. bb] 
 * [cc cc cc cc][dd dd dd dd]
 *
 * 52 45 53 01 : RES\x01 (identifiant, \x01 = version 0.1)
 * xx xx xx xx : nombre de resources en Little Endian
 * aa aa aa aa : taille du nom de resource Little Endian
 * bb ... bb   : nom de resource
 * cc cc cc cc : taille resource Little Endian
 * dd dd dd dd : decalage des donnees de la resource par rapport au debut de l'archive
 */

void ResourceManager::addFile(const std::string &File)
{
	auto data = readToEnd(File);
	if(data.size() > 8)
	{
		if(toLBE(*(unsigned *)data.data()) == 0x52455301) // RES\x01
		{
			auto rm = fromData(data);
			for(auto res : rm->m_resources) // Un des problemes de "l'encapsulation" du C++.
				addData(res.first, res.second);
			return;
		}
	}
	addData(File, data);
}

void ResourceManager::addData(const std::string &Handle, const Resource &data)
{
	m_resources[Handle] = data;
}

shared_ptr<ResourceManager> ResourceManager::fromFile(const string &File)
{
	auto data = readToEnd(File);
	return fromData(data);
}

shared_ptr<ResourceManager> ResourceManager::fromData(const vector<unsigned char> &data)
{
	return shared_ptr<ResourceManager>(new ResourceManager(data));
}

void ResourceManager::saveResource(const string &File)
{
	int fd = open(File.c_str(), O_CREAT | O_RDWR | O_TRUNC, 0644);
	saveResource(fd);
	close(fd);
}

#include <cassert>

void ResourceManager::saveResource(int fd)
{
    /*
	 * les decalages des decalages par rapport au debut :^), 
	 * pour les modifier quand on a la taille complete du header
	 */
	vector<int> offsetsoffset;
	vector<unsigned char> header = { 'R', 'E', 'S', 1 };
	int hoffset = 8, offset = 0;

	header.insert(header.end(), {0, 0, 0, 0}); // on met le nombre de resources ici plus tard.

	for(auto res : m_resources)
	{
		unsigned size = res.first.size();

		header.push_back((size & 0xFF000000) >> 24);
		header.push_back((size & 0x00FF0000) >> 16);
		header.push_back((size & 0x0000FF00) >> 8);
		header.push_back( size & 0x000000FF);

		for(auto c : res.first)
			header.push_back(c);

		size = res.second.size();

		header.push_back((size & 0xFF000000) >> 24);
		header.push_back((size & 0x00FF0000) >> 16);
		header.push_back((size & 0x0000FF00) >> 8);
		header.push_back( size & 0x000000FF);

		offsetsoffset.push_back(hoffset += 8 + res.first.size());
		hoffset += 4;

		size = offset;
		offset += res.second.size();// on y ajoutera la taille du header plus tard

		header.push_back((size & 0xFF000000) >> 24);
		header.push_back((size & 0x00FF0000) >> 16);
		header.push_back((size & 0x0000FF00) >> 8);
		header.push_back( size & 0x000000FF);
	}

	while(header.size() % 16) header.push_back(0); // padding

	*(unsigned *)(header.data() + 4) = toLBE(m_resources.size());
	assert(*(unsigned *)(header.data() + 4) == toLBE(m_resources.size()));

	for(auto i : offsetsoffset) // On a autant de resources que d'entree dans le header
		*(unsigned *)(header.data() + i) = toLBE(toLBE(*(unsigned *)(header.data() + i)) + header.size());

	for(auto res : m_resources)
		header.insert(header.end(), res.second.begin(), res.second.end());

	write(fd, header.data(), header.size());
}

string ResourceManager::getString(const string &Handle)
{
	return string((char *)m_resources[Handle].data(), m_resources[Handle].size());
}

vector<unsigned char> ResourceManager::getData(const string &Handle)
{
	return m_resources[Handle];
}
