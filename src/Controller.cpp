#include <Controller.hpp>

#include <GLFW/glfw3.h>
#include <Controller.hpp>

#include <XBoxController.hpp>
#include <DummyController.hpp>

using namespace std;

/*
 * \return la premiere mannete trouvee et supportee, sinon une fausse manette.
 */
shared_ptr<Controller> Controller::getController()
{
	for(int i = 0; i < 16; ++i)
		if(glfwJoystickPresent(i))
			if(string("Generic X-Box pad") == glfwGetJoystickName(i))
				return make_shared<XBoxController>(i);
	return make_shared<DummyController>();
}
