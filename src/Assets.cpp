#include <Assets.hpp>

using namespace std;

extern unsigned char _binary_models_res_end    [];
extern unsigned char _binary_shaders_res_end   [];
extern unsigned char _binary_textures_res_end  [];
extern unsigned char _binary_models_res_start  [];
extern unsigned char _binary_shaders_res_start [];
extern unsigned char _binary_textures_res_start[];

<<<<<<< HEAD
char *cube_obj       (_binary_cube_obj_start       );
char *emerald_obj    (_binary_emerald_obj_start    );
char *torus_obj      (_binary_torus_obj_start      );
char *polyedre_obj   (_binary_polyedre_obj_start   );
char *baseFS_glsl    (_binary_baseFS_glsl_start    );
char *baseVS_glsl    (_binary_baseVS_glsl_start    );
char *emeraldFS_glsl (_binary_emeraldFS_glsl_start );
char *torusFS_glsl   (_binary_torusFS_glsl_start   );
char *cubemapFS_glsl (_binary_cubemapFS_glsl_start );
char *cubemapVS_glsl (_binary_cubemapVS_glsl_start );
char *polyedreFS_glsl(_binary_polyedreFS_glsl_start);

unsigned long top_png_len        (_binary_top_png_end         -         _binary_top_png_start);
unsigned long bot_png_len        (_binary_bot_png_end         -         _binary_bot_png_start);
unsigned long back_png_len       (_binary_back_png_end        -        _binary_back_png_start);
unsigned long left_png_len       (_binary_left_png_end        -        _binary_left_png_start);
unsigned long cube_obj_len       (_binary_cube_obj_end        -        _binary_cube_obj_start);
unsigned long right_png_len      (_binary_right_png_end       -       _binary_right_png_start);
unsigned long middle_png_len     (_binary_middle_png_end      -      _binary_middle_png_start);
unsigned long baseFS_glsl_len    (_binary_baseFS_glsl_end     -     _binary_baseFS_glsl_start);
unsigned long baseVS_glsl_len    (_binary_baseVS_glsl_end     -     _binary_baseVS_glsl_start);
unsigned long emerald_obj_len    (_binary_emerald_obj_end     -     _binary_emerald_obj_start);
unsigned long torus_obj_len      (_binary_torus_obj_end       -       _binary_torus_obj_start);
unsigned long polyedre_obj_len   (_binary_polyedre_obj_end    -    _binary_polyedre_obj_start);
unsigned long emeraldFS_glsl_len (_binary_emeraldFS_glsl_end  -  _binary_emeraldFS_glsl_start);
unsigned long torusFS_glsl_len   (_binary_torusFS_glsl_end    -    _binary_torusFS_glsl_start);
unsigned long cubemapFS_glsl_len (_binary_cubemapFS_glsl_end  -  _binary_cubemapFS_glsl_start);
unsigned long cubemapVS_glsl_len (_binary_cubemapVS_glsl_end  -  _binary_cubemapVS_glsl_start);
unsigned long polyedreFS_glsl_len(_binary_polyedreFS_glsl_end - _binary_polyedreFS_glsl_start);
=======
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
>>>>>>> upstream/master
