#include "w3d_ptr.h"
#line 1 "k2a_sinit_skybox_801069e4.cpp"
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct W3dType_80160038 { W3dType_80160038(Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int); int words[4]; };
struct K2aFloat3 { float a, b, c; };
struct K2aInt3 { int a, b, c; };
extern W3dType_80160038 w3d_type_803610e0;
extern "C" char w3d_str_803e83e0[];
extern "C" char w3d_str_803617d0[];
extern "C" Ptr32<void> FUN_80104694(void);
extern "C" const float w3d_f32_803999a4[];
extern "C" K2aFloat3 w3d_sky_8044b67c;
extern "C" K2aInt3 w3d_sky_8044b694;
extern "C" int w3d_sky_804af1e8[1];

extern "C" void k2a_sinit_skybox_801069e4(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&w3d_type_803610e0) W3dType_80160038(w3d_str_803e83e0, w3d_str_803617d0, (Ptr32<void>)FUN_80104694, 9, 0);
        w3d_sky_8044b67c.a = w3d_f32_803999a4[0];
        w3d_sky_8044b67c.b = w3d_f32_803999a4[0];
        w3d_sky_8044b67c.c = w3d_f32_803999a4[0];
        w3d_sky_8044b694.c = 0;
        w3d_sky_8044b694.b = 0;
        w3d_sky_8044b694.a = 0;
        w3d_sky_804af1e8[0] = 0;
    }
}


