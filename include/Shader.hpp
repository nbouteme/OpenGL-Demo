/**
 * \author N.Boutemeur
 */

#pragma once

#include <memory>

/**
 * \class Shader
 *  La classe Shader compile, link et gere les shaders
 */
class Shader
{
	/**
	 * \var m_shaderId
	 * \brief Identifiant du programme shader
	 */
	/**
	 * \var m_vertexId
	 * \brief Identifiant du vertex shader
	 */
	/**
	 * \var m_pixelId
	 * \brief Identifiant du fragment shader
	 */
	/**
	 * \var m_geometryId
	 * \brief Identifiant du geometry shader
	 */
	int m_shaderId,
		m_vertexId,
		m_pixelId ,
		m_geometryId = -1;
	/**
	 * \brief Affiche les erreur de compilation d'un shader et termine le programme
	 */
	static void dumpShaderErrorLog(int);

public:
	/**
	 * \brief Initialise un shader
	 * \param vs Code du vertex shader
	 * \param ps Code du fragment shader
	 * \param gs Code du geometry shader
	 */
	Shader(const char *, const char *, const char * = nullptr);
	~Shader();
	/**
	 * \brief Renvois un identifiant du shader
	 * \return un identifiant du programme
	 */
	int getProgramid() { return m_shaderId; }
	/**
	 * \brief Renvois un shader basique
	 * \return un shader basique
	 */
	static std::shared_ptr<Shader> BasicShader();
};
