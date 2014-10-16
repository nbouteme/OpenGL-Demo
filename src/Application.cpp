#include <Application.hpp>

#include <unistd.h>

#include <GLWindow.hpp>
#include <Controller.hpp>

using namespace std;

shared_ptr<Application> (*Application::_getSingleton)() = &Application::createSingleton;
shared_ptr<Application> Application::m_app = Application::getSingleton();
Logger Application::Log = Logger();

void help(char *name, int option = -1)
{
	string uOpt = "Unexpected argument of parameter '%c'\n";
	string helpStr = 
		"Usage: %2$s [options [argument]]\n"
		"\t-l {n}\tLog Level\n"
		"\t-f\tFullscreen\n";
	dprintf(2, option == -1 ? helpStr.c_str() : uOpt.c_str(), option, name);
	exit(1);
}

Application::Application()
{
}

int Application::run(int argc, char **argv)
{
	int opt;
	float sensitivity = 1.0f;
	opterr = 0;
	while((opt = getopt(argc, argv, "l:s:")) != -1)
	{
		switch(opt)
		{
		case 'l':
			if(stoi(optarg) > 5) help(argv[0], 'l');
			Log = Logger(stoi(optarg));
			Application::Log(string("Log level set to ") + optarg, Logger::Debug);
			break;
		case 's':
			if(stoi(optarg) > 100) help(argv[0], 's');
			sensitivity = float(stoi(optarg)) / 100;
			Application::Log(string("Sensitivity level set to ") + optarg, Logger::Debug);
			break;
		}
	}
	m_glWindow   = make_shared<GLWindow>(); // Instancie la fenetre.
	m_controller = Controller::getController(sensitivity);

	return m_glWindow->run(argc, argv); // Renvois l'état de retour
}

shared_ptr<Application> Application::createSingleton()
{
	Application::_getSingleton = &Application::returnSingleton;
	m_app = shared_ptr<Application>(new Application());
	return m_app; // renvoie une nouvelle instance du singleton
}

shared_ptr<Application> Application::returnSingleton()
{
	return m_app->shared_from_this(); // Renvoit un pointeur sur l'instance. // A revoir
}
