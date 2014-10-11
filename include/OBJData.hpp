/**
 * \author N.Boutemeur
 */

#pragma once

#include <vector>
#include <array>
#include <string>

/**
 * \struct Vertex
 * Représente une coordonnée dans l'espace
 */
struct Vertex
{
	/**
	 * \var x
	 * \brief Coordonnée X du point
	 */
	/**
	 * \var y
	 * \brief Coordonnée Y du point
	 */
	/**
	 * \var z
	 * \brief Coordonnée Z du point
	 */
	float x, y, z;
};

typedef Vertex Normal;

/**
 * \struct TextureCoordinate
 * Représente une coordonnée de texture
 */
struct TextureCoordinate
{
	/**
	 * \var u
	 * \brief Coordonnée U du point
	 */
	/**
	 * \var v
	 * \brief Coordonnée V du point
	 */
	float u, v;
};

/*
 * Un groupe de sommet contient des références à un ensemble de
 * Sommet/TextureUV/Normales par leur indices de déclaration + 1
 */
typedef	std::array<int,    3> VGroup;
typedef	std::array<VGroup, 3> Face;

/**
 *\class OBJData Cette classe représente les données présente dans un fichier OBJ
 *
 */
class OBJData
{
	/**
	 * \var m_tokens
	 * \brief Listes de jetons correspondant au code passé en paramètre
	 */
	std::vector<std::string>       m_tokens;
	/**
	 * \var m_vertices
	 * \brief Listes des sommets, dans l'ordre de déclaration dans le fichier passé en paramètre
	 */
	std::vector<Vertex>            m_vertices;
	/**
	 * \var m_vertices
	 * \brief Listes de normale, dans l'ordre de déclaration dans le fichier passé en paramètre
	 */
	std::vector<Normal>            m_normals;
	/**
	 * \var m_text
	 * \brief Listes de coordonnées de textures, dans l'ordre de déclaration dans le fichier passé en paramètre
	 */
	std::vector<TextureCoordinate> m_text;
	/**
	 * \var m_face
	 * \brief Listes de faces, dans l'ordre de déclaration dans le fichier passé en paramètre
	 */
	std::vector<Face> m_faces;
public:
	/**
	 * \brief Parcours une string et en créer une représentation interne
	 * \param objFile Code source du fichier OBJ
	 */
	OBJData(const std::string &objFile);
	/**
	 * \brief Construit un tableau prêt à l'emploi
	 * \return Un tableau de float constitué de n points de 8 floats chacun sous la forme [xyz uv abc]
	 */
	std::vector<float> getData();
};
