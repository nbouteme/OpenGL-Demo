#pragma once

#include <vector>
#include <string>
#include <tuple>

struct Vertex
{
	float x, y, z;
};

struct Normal
{
	float x, y, z;
};

struct TextureCoordinate
{
	float u, v;
};

// seulement les indices
// sommet/textureCoord/normal
typedef	std::array<int, 3> VGroup;

class OBJData
{
	std::vector<std::string>       m_tokens;

	std::vector<Vertex>            m_vertices;
	std::vector<Normal>            m_normals;
	std::vector<TextureCoordinate> m_text;

	// triangles
	std::vector<std::array<VGroup, 3>> m_faces;
public:
	OBJData(const std::string &);
	std::vector<float> getData();
};
