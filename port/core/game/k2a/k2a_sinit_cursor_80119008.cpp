#include "w3d_ptr.h"
#line 1 "k2a_sinit_cursor_80119008.cpp"
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct W3dType_80160038 { W3dType_80160038(Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int); int words[4]; };
struct K2aColor { unsigned char r, g, b; char a; };
extern W3dType_80160038 w3d_type_80361260;
extern "C" char w3d_str_803e84c0[];
extern "C" char w3d_str_803617d0[];
extern "C" Ptr32<void> FUN_80118bf0(void);
extern "C" K2aColor w3d_color_804af314;

extern "C" void k2a_sinit_cursor_80119008(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&w3d_type_80361260) W3dType_80160038(w3d_str_803e84c0, w3d_str_803617d0, (Ptr32<void>)FUN_80118bf0, 9, 0);
        w3d_color_804af314.r = 0;
        w3d_color_804af314.g = 5;
        w3d_color_804af314.b = 55;
        w3d_color_804af314.a = 255;
    }
}


