#pragma once

#include <vector>
#include <string>
#include <tuple>

struct Vertex
{
	float x, y, z;
};

typedef Vertex Normal;

struct TextureCoordinate
{
	float u, v;
};

/*
 * Un groupe de sommet contient des references a un ensemble de
 * Sommet/TextureUV/Normales par leur indices de declaration + 1
 */
typedef	std::array<int, 3> VGroup;

class OBJData
{
	std::vector<std::string>       m_tokens;

	std::vector<Vertex>            m_vertices;
	std::vector<Normal>            m_normals;
	std::vector<TextureCoordinate> m_text;

	std::vector<std::array<VGroup, 3>> m_faces;
public:
	OBJData(const std::string &);
	std::vector<float> getData();
};
