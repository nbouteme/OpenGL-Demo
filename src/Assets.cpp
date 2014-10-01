#include <Assets.hpp>

// Maintenir ces fichiers est d'une souffrance.

unsigned char *bot_png   (_binary_bot_png_start);
unsigned char *top_png   (_binary_top_png_start);
unsigned char *back_png  (_binary_back_png_start);
unsigned char *left_png  (_binary_left_png_start);
unsigned char *right_png (_binary_right_png_start);
unsigned char *middle_png(_binary_middle_png_start);

char *cube_obj       (_binary_cube_obj_start       );
char *emerald_obj    (_binary_emerald_obj_start    );
char *baseFS_glsl    (_binary_baseFS_glsl_start    );
char *baseVS_glsl    (_binary_baseVS_glsl_start    );
char *emeraldFS_glsl (_binary_emeraldFS_glsl_start );
char *cubemapFS_glsl (_binary_cubemapFS_glsl_start );
char *cubemapVS_glsl (_binary_cubemapVS_glsl_start );
char *polyedreFS_glsl(_binary_polyedreFS_glsl_start);

unsigned long top_png_len        (_binary_top_png_end        -        _binary_top_png_start);
unsigned long bot_png_len        (_binary_bot_png_end        -        _binary_bot_png_start);
unsigned long back_png_len       (_binary_back_png_end       -       _binary_back_png_start);
unsigned long left_png_len       (_binary_left_png_end       -       _binary_left_png_start);
unsigned long cube_obj_len       (_binary_cube_obj_end       -       _binary_cube_obj_start);
unsigned long right_png_len      (_binary_right_png_end      -      _binary_right_png_start);
unsigned long middle_png_len     (_binary_middle_png_end     -     _binary_middle_png_start);
unsigned long baseFS_glsl_len    (_binary_baseFS_glsl_end    -    _binary_baseFS_glsl_start);
unsigned long baseVS_glsl_len    (_binary_baseVS_glsl_end    -    _binary_baseVS_glsl_start);
unsigned long emerald_obj_len    (_binary_emerald_obj_end    -    _binary_emerald_obj_start);
unsigned long emeraldFS_glsl_len (_binary_emeraldFS_glsl_end - _binary_emeraldFS_glsl_start);
unsigned long cubemapFS_glsl_len (_binary_cubemapFS_glsl_end - _binary_cubemapFS_glsl_start);
unsigned long cubemapVS_glsl_len (_binary_cubemapVS_glsl_end - _binary_cubemapVS_glsl_start);
unsigned long polyedreFS_glsl_len(_binary_cubemapVS_glsl_end - _binary_cubemapVS_glsl_start);
