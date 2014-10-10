/**
 * \author N.Boutemeur
 */

#pragma once

#include <vector>

#include <glm/glm.hpp>

#include <GLWindow.hpp>

class GLWindow;

/**
 * \class Controller La classe Controller definie les caracteristiques d'une manette
 */
class Controller
{
	friend GLWindow;
	/**
	 * \return la premiere mannete trouvee et supportee, sinon une fausse manette.
	 */
	static std::shared_ptr<Controller> getController();
public:
	/**
	 * \return la position du stick principale, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getMainStickPosition()      = 0;
	/**
	 * \return la position du stick secondaire, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getSecondaryStickPosition() = 0;
	/**
	 * \return la position des gachette, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getTriggers()               = 0;
	/**
	 * \return les bouttons pressés
	 */
	virtual std::vector<bool> getButtons()        = 0;
	/**
	 * \brief
	 */
	virtual ~Controller(){};
};
