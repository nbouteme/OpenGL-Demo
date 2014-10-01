#include <OBJData.hpp>

#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

array<VGroup, 3>  parseFace  (vector<string>::iterator &it);
VGroup            parseVGroup(vector<string>::iterator &it);
Normal            parseNormal(vector<string>::iterator &it);
Vertex            parseVert  (vector<string>::iterator &it);
TextureCoordinate parseTexUV (vector<string>::iterator &it);

TextureCoordinate parseTexUV(vector<string>::iterator &it)
{
	++it;
	TextureCoordinate ret = { stof(*it++), stof(*it++) };
	return ret;
}

Vertex parseVert(vector<string>::iterator &it)
{
	++it;
	Vertex ret = { stof(*it++), stof(*it++), stof(*it++) };
	return ret;
}


Normal parseNormal(vector<string>::iterator &it)
{
	Vertex v = parseVert(it);
	Normal ret = { v.x, v.y, v.z };
	return ret;
}

VGroup parseVGroup(vector<string>::iterator &it)
{
	int vertIdx = -1, texIdx = -1, normIdx = -1;
	vertIdx = stoi(*it++);

	if(*it == "/") // on a des uv ou des normals
	{
		++it;
		if(*it == "/") // pas de textUV, seulement des normals
			normIdx = stoi(*++it);
		else
		{
			texIdx = stoi(*it++);
			if(*it == "/")
				normIdx = stoi(*++it);
		}
		++it;
	}

	return { vertIdx, texIdx, normIdx };
}

array<VGroup, 3> parseFace(vector<string>::iterator &it)
{
	++it;
	VGroup first = parseVGroup(it);
	VGroup sec   = parseVGroup(it);
	VGroup third = parseVGroup(it);

	return { first, sec, third };
}

OBJData::OBJData(const string &objFile)
{
	auto it = objFile.begin();
	string kTokens = "\n#ovnt/f";

	while(it != objFile.end())
	{
		string token;

		while(*it != ' ' && kTokens.find(*it) == string::npos)
		{
			token += *it;
			++it;
		}
		if(!token.empty())
			m_tokens.push_back(token);
		if(kTokens.find(*it) != string::npos)
			m_tokens.push_back(string(1, *it));

		++it;
	}

	for(auto it = m_tokens.begin(); it < m_tokens.end();)
	{
		switch(it[0][0])
		{
		case 'f':
			m_faces.push_back(parseFace(it));
			break;
		case 'v':
			switch(it[1][0])
			{
			case 'n':
				m_normals.push_back(parseNormal(++it));
				break;
			case 't':
				m_text.push_back(parseTexUV(it));
				break;
			default:
				m_vertices.push_back(parseVert(it));
			}
		case 'o': // nom: ignorer
		case '#': // commentaire
		case 's': // groupe de smooth vertices, aka. on s'en fout
			break;
		}
		while(it < m_tokens.end() && *it != "\n") ++it;
		while(it < m_tokens.end() && *it == "\n") ++it;
	}
}

vector<float> OBJData::getData()
{
	vector<float> data;

	for(auto face : m_faces) // on va preferer dupliquer les sommets/normales
		for(auto vgroup : face)
		{
			data.push_back(m_vertices[vgroup[0] - 1].x);
			data.push_back(m_vertices[vgroup[0] - 1].y);
			data.push_back(m_vertices[vgroup[0] - 1].z);

			data.push_back(!m_text   .empty() && vgroup[1] != -1 ? m_text   [vgroup[1] - 1].u : 0.0f);
			data.push_back(!m_text   .empty() && vgroup[1] != -1 ? m_text   [vgroup[1] - 1].v : 0.0f);
			data.push_back(!m_normals.empty() && vgroup[2] != -1 ? m_normals[vgroup[2] - 1].x : 0.0f);
			data.push_back(!m_normals.empty() && vgroup[2] != -1 ? m_normals[vgroup[2] - 1].y : 0.0f);
			data.push_back(!m_normals.empty() && vgroup[2] != -1 ? m_normals[vgroup[2] - 1].z : 0.0f);
		}

	return data;
}
