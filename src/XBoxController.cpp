/*
 * La manette de Xbox a 8 axes.
 * 0: Axe horizontal, du stick gauche
 * 1: Axe vertical, du stick gauche
 * 2: Trigger gauche
 * 3: Axe horizontal, du stick droit
 * 4: Axe vertical du stick droit
 * 5: Trigger droit
 * 6: Pad directionel, horizontal
 * 7: Pad directionel, vertical
 *
 * Une manette de Xbox a 11 bouttons
 *  0: A
 *  1: B
 *  2: X
 *  3: Y
 *  4: LB
 *  5: RB
 *  6: Back
 *  7: Start
 *  8: Home
 *  9: LSB
 * 10: RSB
 */

#include <XBoxController.hpp>

using namespace std;
using namespace glm;

XBoxController::XBoxController(int joyNum, float sensitivity) : m_joyNum(joyNum), m_sensitivity(sensitivity)
{
}

vec2 XBoxController::getMainStickPosition()
{
	int n;
	if(!glfwJoystickPresent(m_joyNum)) return vec2();
	const float *data = glfwGetJoystickAxes(m_joyNum, &n);
	vec2 ret(data[0], data[1]);

	if(length(ret) > 1.0f)
		ret = normalize(ret);
	ret *= m_sensitivity;
	return ret;
}

vec2 XBoxController::getSecondaryStickPosition()
{
	int n;
	if(!glfwJoystickPresent(m_joyNum)) return vec2();
	const float *data = glfwGetJoystickAxes(m_joyNum, &n); // cette fonction ne verifie pas le pointeur nul...
	vec2 ret(data[3], data[4]);

	if(length(ret) > 1.0f)
		ret = normalize(ret);

	ret *= m_sensitivity;
	return ret;
}

vec2 XBoxController::getTriggers()
{
	if(!glfwJoystickPresent(m_joyNum)) return vec2();
	const float *data = glfwGetJoystickAxes(m_joyNum, nullptr); // alors que celle si, oui...
	vec2 ret(data[2], data[4]);
	// on normalize pas, les gachette ne sont pas censer representer une direction
	return ret;
}

vector<bool> XBoxController::getButtons()
{
	int size;
	if(!glfwJoystickPresent(m_joyNum)) return vector<bool>(20);
	const unsigned char *data = glfwGetJoystickButtons(m_joyNum, &size);
	return vector<bool>(data, data + size);
}
