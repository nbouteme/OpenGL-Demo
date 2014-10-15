#pragma once

#include <string>

/**
 * \class Logger
 * Gère les informations à afficher, selon le niveau parametré
 */
struct Logger
{
	/**
	 *\var filter
	 * Niveau de sortie autorisé, les demandes de log avec un niveau inférieur
	 * à cette variable ne seront pas reportés
	 */
	/**
	 *\var fd
	 * Descripteur du fichier dans lequel écrire les logs.
	 */
	int filter, fd;
	/**
	 *\param Filter Niveau de filtre
	 *\param Fd Descripteur du fichier dans lequel écrire les logs.
	 */
	Logger(int Filter = 0, int Fd = 2) : filter(Filter), fd(Fd) {}

	/// Cette énumeration contient les différents niveau d'urgence existant
	enum
	{
		Debug,
		Normal,
		Info,
		Warning,
		Error,
		Critical,
	};

	/**
	 *\param rhs Chaine à écrire
	 *\param lvl Niveau d'urgence
	 */
	void operator()(const std::string& rhs = std::string(), int lvl = 1) const
	{
		if(lvl < filter) return;
		char      buf[80];
		time_t    now = time(0);
		struct tm tstruct;
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%X", &tstruct);
		std::string cols[] = { "4", "0", "34", "33", "35", "7"};
		dprintf(1, "\033[1;%sm[%s]: %s\033[1;0m\n", 
				cols[lvl].c_str(), 
				buf, 
				rhs.c_str());
	}
};
