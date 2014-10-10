/**
 * \author N.Boutemeur
 */

#pragma once

#include <ResourceManager.hpp>

// Seulement les gestionnaires de ressources sont visible.

/**
 * \var OBJRes
 * \p Gere les fichiers obj
 */
extern std::shared_ptr<ResourceManager> OBJRes;

/**
 * \var ShaderRes
 * \p Gere les fichiers shaders
 */
extern std::shared_ptr<ResourceManager> ShaderRes;

/**
 * \var TexRes
 * \p Gere les textures
 */
extern std::shared_ptr<ResourceManager> TexRes;

