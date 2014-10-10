/**
 * \author N.Boutemeur
 */

#pragma once

#include <set>
#include <memory>

#include <Camera.hpp>
#include <Model.hpp>

/**
 * \class Scene
 * Une scene est un ensemble d'objet detines a etre rendu
 */
class Scene
{
	/**
	 * \var m_models
	 * \p Modeles contenus dans la scene
	 */
	std::set<std::shared_ptr<Model>> m_models;

protected:
	/**
	 * \var m_cam
	 * \p Camera utilisee lors du rendu
	 */
	Camera &m_cam;

	/**
	 * \brief Ajoute un model pour le dessin
	 */
	void addModel(const std::shared_ptr<Model> &model)
		{ m_models.insert(model); }

	/**
	 * \brief Ajoute un model derivé pour le dessin
	 */
	template <typename T>
	void addModel(const T& derived)
	{
		//Type safe car derived doit bien deriver de Model, pour compiler
		addModel(std::shared_ptr<Model>(derived));
	}

	/**
	 * \brief Construit une scene a partir d'une camera a utiliser pour le rendu
	 */
	Scene(Camera &);
public:
	/**
	 * \brief Dessine la scene sur la cible active
	 */
	virtual void render();
	/**
	 * \return Les modeles de la scene
	 */
	std::set<std::shared_ptr<Model>> getModels() { return m_models; }
	virtual ~Scene(){};
};
