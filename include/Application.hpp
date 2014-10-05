#pragma once
#include <memory>

#include <GLWindow.hpp>

class Controller;

class Application : public std::enable_shared_from_this<Application>
{
private:
	static std::shared_ptr<Application> m_app;

	std::shared_ptr<BaseWindow> m_glWindow;
	static std::shared_ptr<Controller> m_controller;

	static std::shared_ptr<Application> returnSingleton();
	static std::shared_ptr<Application> createSingleton();

	// _getSingleton est prive pour 'l'empecher' de se faire modifier 
	static std::shared_ptr<Application> (*_getSingleton)();
	// Pour empecher une instanciation.
	Application() {};
public:
	static std::shared_ptr<Application> getSingleton() { return _getSingleton(); }
	std::shared_ptr<BaseWindow>  getWindow()           { return m_glWindow;      }
	std::shared_ptr<Controller>  getController()       { return m_controller;    }
	int run(int = 0, char ** = 0);
};
