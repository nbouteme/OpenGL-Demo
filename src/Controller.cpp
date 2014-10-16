#include <Controller.hpp>

#include <GLFW/glfw3.h>

#include <Application.hpp>
#include <XBoxController.hpp>
#include <DummyController.hpp>

using namespace std;
#include <iostream>
/*
 * \return la premiere mannete trouvee et supportee, sinon une fausse manette.
 */
shared_ptr<Controller> Controller::getController(float sensitivity)
{
	for(int i = 0; i < 16; ++i)
		if(glfwJoystickPresent(i))
		{
			if(string("Generic X-Box pad") == glfwGetJoystickName(i) ||
			   string("Microsoft X-Box 360 pad") == glfwGetJoystickName(i))
			{
				Application::Log("Found an XBox Controller", Logger::Info);
				return make_shared<XBoxController>(i, sensitivity);
			}
			else
				Application::Log(string("Found a joypad : ") + glfwGetJoystickName(i));
		}
	Application::Log("Couldn't find a suitable controller", Logger::Debug);
	return make_shared<DummyController>();
}
