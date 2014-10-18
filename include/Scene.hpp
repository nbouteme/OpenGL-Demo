/**
 * \author N.Boutemeur
 */

#pragma once

#include <set>
#include <memory>
#include <vector>

class Model;
class Camera;
class CubeMap;
class Effect;

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
	/**
	 * \var m_effects
	 * \p Effets contenus dans la scène
	 */
	std::vector<std::shared_ptr<Effect>> m_effects;
protected:
	/**
	 * \var m_cam
	 * \p Caméra utilisée lors du rendu
	 */
	std::shared_ptr<Camera> m_cam;
	/**
	 * \brief Ajoute un modèle pour le dessin
	 */
	void addModel(const std::shared_ptr<Model> &model)
		{ m_models.insert(model); }
	/**
	 * \brief Ajoute un modèle pour le dessin
	 */
	void addEffect(const std::shared_ptr<Effect> &effect)
		{ m_effects.push_back(effect); }
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
	Scene();
	/**
	 * \var m_cubemap
	 * \p la skybox de la scene
	 */
	std::shared_ptr<CubeMap> m_cubemap;
	void setEnvironment(std::shared_ptr<CubeMap> env) { m_cubemap = env; }
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
