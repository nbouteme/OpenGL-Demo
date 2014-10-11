/**
 * \author N.Boutemeur
 */

#pragma once

#include <set>
#include <memory>

class Model;
class Camera;

/**
 * \class Scene
 * Une scène est un ensemble d'objets destinés à être rendu, cette classe n'est pas instanciable par elle même, et doit être dérivée
 */
class Scene
{
	/**
	 * \var m_models
	 * \p Modèles contenus dans la scène
	 */
	std::set<std::shared_ptr<Model>> m_models;

protected:
	/**
	 * \var m_cam
	 * \p Caméra utilisée lors du rendu
	 */
	Camera &m_cam;

	/**
	 * \brief Ajoute un modèle pour le dessin
	 */
	void addModel(const std::shared_ptr<Model> &model)
		{ m_models.insert(model); }

	/**
	 * \brief Ajoute un modèle derivé pour le dessin
	 */
	template <typename T>
	void addModel(const T& derived)
	{
		//Type safe car derived doit bien dériver de Model, pour compiler
		addModel(std::shared_ptr<Model>(derived));
	}

	/**
	 * \brief Construit une scène à partir d'une caméra à utiliser pour le rendu
	 */
	Scene(Camera &);
public:
	/**
	 * \brief Dessine la scène sur la cible active
	 */
	virtual void render();
	/**
	 * \return Les modèles de la scène
	 */
	std::set<std::shared_ptr<Model>> getModels() { return m_models; }
	virtual ~Scene(){};
};
