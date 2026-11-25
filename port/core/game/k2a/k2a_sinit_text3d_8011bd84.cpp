#include "w3d_ptr.h"
#line 1 "k2a_sinit_text3d_8011bd84.cpp"
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct W3dType_80160038 { W3dType_80160038(Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int); int words[4]; };
extern W3dType_80160038 w3d_type_80361320;
extern "C" char w3d_str_803e8530[];
extern "C" char w3d_str_803617d0[];
extern "C" Ptr32<void> FUN_8011a844(void);
extern "C" int w3d_message_804af3a8[2];
extern "C" char w3d_str_8039af80[];
extern "C" Ptr32<void> w3d_cached_message_name_init(Ptr32<void>, Ptr32<const char>);
extern "C" char w3d_byte_804af3b0;
extern "C" char w3d_byte_804af3b1;
extern "C" char w3d_byte_804af3b2;
extern "C" char w3d_byte_804af3b3;
extern "C" char w3d_byte_804af3b4;
extern "C" char w3d_byte_804af3b5;
extern "C" char w3d_byte_804af3b6;
extern "C" char w3d_byte_804af3b7;

extern "C" void k2a_sinit_text3d_8011bd84(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&w3d_type_80361320) W3dType_80160038(w3d_str_803e8530, w3d_str_803617d0, (Ptr32<void>)FUN_8011a844, 9, 0);
        w3d_cached_message_name_init(w3d_message_804af3a8, w3d_str_8039af80);
        w3d_byte_804af3b0 = -1;
        w3d_byte_804af3b1 = -1;
        w3d_byte_804af3b2 = -1;
        w3d_byte_804af3b3 = -1;
        w3d_byte_804af3b4 = 0;
        w3d_byte_804af3b5 = 0;
        w3d_byte_804af3b6 = 0;
        w3d_byte_804af3b7 = -1;
    }
}


