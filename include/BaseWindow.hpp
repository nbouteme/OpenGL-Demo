/**
 * \author N.Boutemeur
 */

#pragma once

class BaseWindow
{
public:
	/**
	 * \return L'etat d'execution
	 */
	virtual int run(int = 0, char ** = 0) = 0;
	/**
	 * \brief Libere les ressources
	 */
	virtual ~BaseWindow(){}
};
