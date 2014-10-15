#pragma once

#include <string>

/**
 * \class Logger Cette classe gere les information a afficher, selon le niveau parametré
 */
struct Logger
{
	int filter, fd;
	Logger(int Filter = 0, int Fd = 2) : filter(Filter), fd(Fd) {}

	enum
	{
		Debug,
		Normal,
		Info,
		Warning,
		Error,
		Critical,
	};
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
