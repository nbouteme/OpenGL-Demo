/**
 * \author N.Boutemeur
 */

#pragma once

#include <ResourceManager.hpp>

class ResourceManager;

// Seulement les gestionnaires de ressources sont visible.

/**
 * \var OBJRes
 * \p Gère les modèles OBJ
 */
extern std::shared_ptr<ResourceManager> OBJRes;

/**
 * \var ShaderRes
 * \p Gère les fichiers shaders
 */
extern std::shared_ptr<ResourceManager> ShaderRes;

/**
 * \var TexRes
 * \p Gère les textures
 */
extern std::shared_ptr<ResourceManager> TexRes;

