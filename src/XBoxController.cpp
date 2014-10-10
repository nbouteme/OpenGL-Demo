#include <XBoxController.hpp>

using namespace std;

/**
 * \brief instancie la manette selon le nomero de manette
 */
XBoxController::XBoxController(int joyNum) : m_joyNum(joyNum)
{
}

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
 */

/**
 * \return les bouttons pressés
 */
glm::vec2 XBoxController::getMainStickPosition()
{
	int n;
	const float *data = glfwGetJoystickAxes(m_joyNum, &n);
	glm::vec2 ret(data[0], data[1]);

	if(glm::length(ret) > 1.0f)
		ret = glm::normalize(ret);

	return ret;
}

/**
 * \return la position des gachette, les 2 axes dans l'interval [-1; 1]
 */
glm::vec2 XBoxController::getSecondaryStickPosition()
{
	int n;
	const float *data = glfwGetJoystickAxes(m_joyNum, &n);
	glm::vec2 ret(data[3], data[4]);

	if(glm::length(ret) > 1.0f)
		ret = glm::normalize(ret);

	return ret;
}

/**
 * \return les bouttons pressés
 */
glm::vec2 XBoxController::getTriggers()
{
	const float *data = glfwGetJoystickAxes(m_joyNum, nullptr);
	glm::vec2 ret(data[2], data[4]);
	// on normalize pas, les gachette ne sont pas censer representer une direction
	return ret;
}

/*
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

/**
 * \return les bouttons pressés
 */
vector<bool> XBoxController::getButtons()
{
	int size;
	const unsigned char *data = glfwGetJoystickButtons(m_joyNum, &size);
	return vector<bool>(data, data + size);
}
