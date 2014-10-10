/**
 * \author N.Boutemeur
 */

#pragma once

#include <vector>
#include <string>
#include <tuple>

/**
 * \struct Vertex
 * Represente une coordonnees dans l'espace
 */
struct Vertex
{
	/**
	 * \var x
	 * \brief Coordonnee X du point
	 */
	/**
	 * \var y
	 * \brief Coordonnee Y du point
	 */
	/**
	 * \var z
	 * \brief Coordonnee Z du point
	 */
	float x, y, z;
};

typedef Vertex Normal;

/**
 * \struct TextureCoordinate
 * Represente une coordonnees de texture
 */
struct TextureCoordinate
{
	/**
	 * \var u
	 * \brief Coordonnee U du point
	 */
	/**
	 * \var v
	 * \brief Coordonnee V du point
	 */
	float u, v;
};

/*
 * Un groupe de sommet contient des references a un ensemble de
 * Sommet/TextureUV/Normales par leur indices de declaration + 1
 */
typedef	std::array<int,    3> VGroup;
typedef	std::array<VGroup, 3> Face;

/**
 *\class OBJData Cette classe represente les donnees presente dans un fichier OBJ
 *
 */
class OBJData
{
	std::vector<std::string>       m_tokens;

	std::vector<Vertex>            m_vertices;
	std::vector<Normal>            m_normals;
	std::vector<TextureCoordinate> m_text;

	std::vector<Face> m_faces;
public:
	/**
	 * \brief Parcours une string et en creer une representation interne
	 * \param objFile Code source du fichier OBJ
	 */
	OBJData(const std::string &);
	/**
	 * \brief Construit un tableau pret a l'emploi
	 * \return Un tableau de float constitué de n points de 8 floats chacun sous la forme [xyz uv abc]
	 */
	std::vector<float> getData();
};
