#include <Assets.hpp>

using namespace std;

extern unsigned char _binary_models_res_end    [];
extern unsigned char _binary_shaders_res_end   [];
extern unsigned char _binary_textures_res_end  [];
extern unsigned char _binary_models_res_start  [];
extern unsigned char _binary_shaders_res_start [];
extern unsigned char _binary_textures_res_start[];


shared_ptr<ResourceManager> OBJRes =
	ResourceManager::fromData(vector<unsigned char>(
								  _binary_models_res_start,
								  _binary_models_res_end));

shared_ptr<ResourceManager> ShaderRes =
	ResourceManager::fromData(vector<unsigned char>(
								  _binary_shaders_res_start,
								  _binary_shaders_res_end));

shared_ptr<ResourceManager> TexRes =
	ResourceManager::fromData(vector<unsigned char>(
								  _binary_textures_res_start,
								  _binary_textures_res_end));