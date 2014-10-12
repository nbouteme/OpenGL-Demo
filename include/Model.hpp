/**
 * \author N.Boutemeur
 */

#pragma once

#include <DrawableComponent.hpp>
#include <Actor.hpp>

#include <memory>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


/**
 * \class Model Cette classe n'est pas instanciable par elle mémé, elle doit être dérivée pour pouvoir l'utiliser
 */
class Model : public DrawableComponent, public Actor 
{
	/**
	 * \brief Met à jour la matrice de transformation
	 */
	void rebuildModelMat();

public:
	virtual ~Model();

	virtual void draw  (const Camera &) = 0;
	virtual void update() = 0;

	// Utiliser seulement pour positionner sur la scène au début

	/**
	 * \brief Elargi le modèle
	 */
	void setScale(const glm::vec3&);
	/**
	 * \brief Déplace le modèle
	 */
	void setPosition(const glm::vec3&);
	/**
	 * \brief Tourne le modèle sur l'axe X
	 */
	void setRotation   (const glm::vec3&);

protected:
	glm::vec3 m_scale = glm::vec3(1.0f), m_rotation, m_position;
	/**
	 * \var m_vao
	 * \p Identifiant du Vertex Array Object
	 */
	/**
	 * \var m_vbo
	 * \p Identifiant du Vertex Buffer Object
	 */
	/**
	 * \var m_ebo
	 * \p Identifiant du Element Buffer Object
	 */
	unsigned m_vao = 0, m_vbo = 0, m_ebo = -1;
	/**
	 * \var m_modelMatrix
	 * \p Matrice de model
	 */
	glm::mat4 m_modelMatrix;
	/**
	 * \var vertNum
	 * \p Nombre de sommets
	 */
	/**
	 * \var faceNum
	 * \p Nombre de faces
	 */
	int vertNum, faceNum;
	/**
	 * \brief Instancie un model d'apres le code source OBJ
	 */
	Model(const std::string &);
	/**
	 * \brief Instancie un modèle d'après un tableau de sommet
	 *        et un tableau d'éléments
	 */
	Model(const float *, unsigned, const unsigned * = nullptr, unsigned = 0);
	/**
	 * \brief Instancie un modèle d'après le tableau
	 */
	Model(const std::vector<float> &);
	/**
	 * \brief Instancie un modèle d'après le tableau et les éléments
	 */
	Model(const std::vector<float> &, const std::vector<unsigned> &);
};
