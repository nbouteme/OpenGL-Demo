#include <ResourceManager.hpp>
#include <cstdio>
#include <unistd.h>

using namespace std;

// TODO: Ajouter des options

void help(char *prg)
{
	if(string(prg).find("resread") != -1U)
		printf("Usage: %s archive resourcename\n", prg);
	else
		printf("Usage: %s [files] > output.res\n", prg);
	exit(1);
}

int main(int argc, char *argv[])
{
	if(argc < 2) help(argv[0]);

	if(argc == 3 && string(argv[0]).find("resread") != -1U)
	{
		auto rm = ResourceManager::fromFile(argv[1]);
		auto data = rm->getData(argv[2]);
		write(1, data.data(), data.size());
		return 0;
	}

	auto rm = ResourceManager::fromData(vector<unsigned char>());

	for(int i = 1; i < argc; ++i)
		rm->addFile(argv[i]);

	rm->saveResource(1);
    return 0;
}
