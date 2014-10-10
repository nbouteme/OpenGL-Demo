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
	 *\brief Construit un gestionnaire de ressource a partir d'un fichier
	 *
	 *\param File Fichier a lire
	 */
	ResourceManager(const std::string &);
	/**
	 *\brief Construit un gestionnaire de ressource a partir de donnees
	 *
	 *\param  data Donnees a lire
	 */
	ResourceManager(const std::vector<unsigned char> &);

	std::map<std::string, Resource> m_resources; //!< Listes des ressources de l'archive

public:
	/**
	 *\brief Ajoute un fichier a l'archive. Si le fichier est une archive, 
	 * alors son contenu est ajouté
	 *\param  File fichier a ajouter
	 */
	void addFile(const std::string &); // Le nom sert d'identifieur, si le fichier est une autre archive, alors sont contenu est ajouter, a la place
	/*!
	  \brief Ajoute des donnes a l'archive

	  \param  Handle Le nom a donner a la ressource
	  \param  data Les donnees a ajouter
	  */
	void addData(const std::string &, const std::vector<unsigned char> &);

	/*!
	  \brief Sauvegarde l'archive dans un fichier

	  \param  File Nom du fichier dans lequel sauvegarder
	  */
	void saveResource(const std::string &);
	/*!
	  \brief Ecrit l'archive dans un descripteur de fichier

	  \param fd Descripteur de fichier dans lequel ecrire l'archive
	  */
	void saveResource(int);

	/*!
	  \brief Recupere les donnees d'une ressource de l'archive

	  \param  Handle Le nom de la ressource a recuperer
	  \return Les donnees de la ressource
	  */
	std::vector<unsigned char> getData(const std::string &);
	/*!
	  \brief Recupere les donnees d'une ressource sous la forme d'une chaine

	  \param  Handle Nom de la ressource
	  \return Les donnees sous forme de chaine
	  */
	std::string getString(const std::string &);
	/*!
	  \brief Renvois toute les ressources de l'archive

	  \return Renvois toute les ressources de l'archive
	  */
	std::map<std::string, Resource> getRessources();

	/*!
	  \brief Instancie un gestionnaire a partir de donnees

	  \param  data Les donnees a lire
	  \return Un pointeur vers le gestionnaire de resources
	  */
	static std::shared_ptr<ResourceManager> fromData(const std::vector<unsigned char> &);
	/*!
	  \brief Instancie un gestionnaire a partir d'un fichier

	  \param  File Le fichier a lire
	  \return Un pointeur vers le gestionnaire de resources
	  */
	static std::shared_ptr<ResourceManager> fromFile(const std::string &);
};
