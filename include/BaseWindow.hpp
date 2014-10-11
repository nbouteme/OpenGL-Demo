/**
 * \author N.Boutemeur
 */

#pragma once

/**
 *\class BaseWindow Définie l'interface d'une fenêtre.
 */
class BaseWindow
{
public:
	/**
	 * \return L'état d'exécution
	 */
	virtual int run(int = 0, char ** = 0) = 0;
	virtual ~BaseWindow(){}
};
