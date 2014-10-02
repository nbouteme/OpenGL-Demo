#pragma once

#include <string>
#include <memory>
#include <map>
#include <vector>

typedef std::vector<unsigned char> Resource;

class ResourceManager : public std::enable_shared_from_this<ResourceManager>
{
	ResourceManager(const std::string &);
	ResourceManager(const std::vector<unsigned char> &);

	std::map<std::string, Resource> m_resources;
public:
	void addFile(const std::string &); // Le nom sert d'identifieur
	void addData(const std::string &, const std::vector<unsigned char> &);
	void saveResource(const std::string &);

	std::vector<unsigned char> getData(const std::string &);
	std::string getString(const std::string &);

	static std::shared_ptr<ResourceManager> fromData(const std::vector<unsigned char> &);
	static std::shared_ptr<ResourceManager> fromFile(const std::string &);
};
