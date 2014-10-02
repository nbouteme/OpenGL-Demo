#include <ResourceManager.hpp>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 2)
		return 1;
	auto rm = ResourceManager::fromFile(argv[1]);

	std::cout << rm->getString("ABC") << std::endl;
    return 0;
}
