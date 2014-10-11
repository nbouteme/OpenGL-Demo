#pragma once

#include <string>
#include <memory>
#include <map>
#include <vector>

typedef std::vector<unsigned char> Resource;

/**
 * \class ResourceManager
 */
class ResourceManager : public std::enable_shared_from_this<ResourceManager>
{
	/**
	 *\brief Construit un gestionnaire de ressource à partir d'un fichier
	 *
	 *\param File Fichier a lire
	 */
	ResourceManager(const std::string &);
	/**
	 *\brief Construit un gestionnaire de ressource à partir de données
	 *
	 *\param  data Données a lire
	 */
	ResourceManager(const std::vector<unsigned char> &);
	std::map<std::string, Resource> m_resources; //!< Listes des ressources de l'archive
public:
	/**
	 *\brief Ajoute un fichier à l'archive. Si le fichier est une archive, 
	 * alors son contenu est ajouté
	 *\param  File fichier à ajouter
	 */
	void addFile(const std::string &); // Le nom sert d'identifiant, si le fichier est une autre archive, alors sont contenu est ajouté, à la place
	/**
	 *\brief Ajoute des données à l'archive
	 *\param  Handle Le nom à donner à la ressource
	 *\param  data Les données à ajouter
	 */
	void addData(const std::string &, const std::vector<unsigned char> &);
	/**
	 *\brief Sauvegarde l'archive dans un fichier
	 *\param  File Nom du fichier dans lequel sauvegarder
	 */
	void saveResource(const std::string &File);
	/**
	 *\brief Écrit l'archive dans un descripteur de fichier
	 *\param fd Descripteur de fichier dans lequel écrire l'archive
	 */
	void saveResource(int);
	/**
	 *\brief Récupère les données d'une ressource de l'archive
	 *\param  Handle Le nom de la ressource à récupérer
	 *\return Les données de la ressource
	 */
	std::vector<unsigned char> getData(const std::string &Handle);
	/**
	 *\brief Récupère les données d'une ressource sous la forme d'une chaîne
	 *\param  Handle Nom de la ressource
	 *\return Les données sous forme de chaîne
	 */
	std::string getString(const std::string &Handle);
	/**
	 *\brief Renvois toute les ressources de l'archive
	 *\return Renvois toute les ressources de l'archive
	 */
	std::map<std::string, Resource> getRessources();
	/**
	 *\brief Instancie un gestionnaire à partir de données
	 *\param data Les données à lire
	 *\return Un pointeur vers le gestionnaire de resources
	 */
	static std::shared_ptr<ResourceManager> fromData(const std::vector<unsigned char> &data);
	/**
	 *\brief Instancie un gestionnaire à partir d'un fichier
	 *\param File Le fichier à lire
	 *\return Un pointeur vers le gestionnaire de resources
	 */
	static std::shared_ptr<ResourceManager> fromFile(const std::string &File);
};
