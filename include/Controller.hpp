/**
 * \author N.Boutemeur
 */

#pragma once

#include <vector>
#include <memory>

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class GLWindow;

/**
 * \class Controller La classe Controller définie les caractéristiques d'une manette
 */
class Controller
{
	friend GLWindow;
	/**
	 * \return La première manette trouvée et supportée, sinon une fausse manette.
	 */
	static std::shared_ptr<Controller> getController();
public:
	/**
	 * \return La position du stick principal, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getMainStickPosition()      = 0;
	/**
	 * \return La position du stick secondaire, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getSecondaryStickPosition() = 0;
	/**
	 * \return La position des gâchettes, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getTriggers()               = 0;
	/**
	 * \return Les boutons pressés
	 */
	virtual std::vector<bool> getButtons()        = 0;
	virtual ~Controller(){};
};
