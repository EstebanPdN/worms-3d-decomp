#include "w3d_ptr.h"
#line 1 "k2a_sinit_arrow_8003d108.cpp"
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct W3dType_80160038 { W3dType_80160038(Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int); int words[4]; };
struct K2aFloat3 { float a, b, c; };
extern W3dType_80160038 w3d_type_8035ffa0;
extern "C" char w3d_str_803e79d0[];
extern "C" char w3d_str_803617d0[];
extern "C" Ptr32<void> FUN_8003b92c(void);
extern "C" const float w3d_f32_80374580[];
extern "C" const float w3d_f32_80374584[];
extern "C" K2aFloat3 w3d_arrow_804273c8;
extern "C" Ptr32<void> w3d_cached_message_name_init(Ptr32<void>, Ptr32<const char>);
extern "C" int w3d_message_804ad138[2];
extern "C" char w3d_str_80374488[];
extern "C" int w3d_message_804ad140[2];
extern "C" char w3d_str_8037449c[];
extern "C" int w3d_message_804ad148[2];
extern "C" char w3d_str_803744b4[];
extern "C" int w3d_message_804ad150[2];
extern "C" char w3d_str_803744cc[];
extern "C" int w3d_message_804ad158[2];
extern "C" char w3d_str_803744e4[];
extern "C" int w3d_message_804ad160[2];
extern "C" char w3d_str_803744f8[];
extern "C" int w3d_message_804ad168[2];
extern "C" char w3d_str_80374514[];
extern "C" int w3d_message_804ad170[2];
extern "C" char w3d_str_8037452c[];
extern "C" int w3d_message_804ad178[2];
extern "C" char w3d_str_80374548[];
extern "C" int w3d_message_804ad180[2];
extern "C" char w3d_str_80374564[];

extern "C" void k2a_sinit_arrow_8003d108(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        new (&w3d_type_8035ffa0) W3dType_80160038(w3d_str_803e79d0, w3d_str_803617d0, (Ptr32<void>)FUN_8003b92c, 9, 0);
        w3d_arrow_804273c8.a = w3d_f32_80374580[0];
        w3d_arrow_804273c8.b = w3d_f32_80374584[0];
        w3d_arrow_804273c8.c = w3d_f32_80374584[0];
        w3d_cached_message_name_init(w3d_message_804ad138, w3d_str_80374488);
        w3d_cached_message_name_init(w3d_message_804ad140, w3d_str_8037449c);
        w3d_cached_message_name_init(w3d_message_804ad148, w3d_str_803744b4);
        w3d_cached_message_name_init(w3d_message_804ad150, w3d_str_803744cc);
        w3d_cached_message_name_init(w3d_message_804ad158, w3d_str_803744e4);
        w3d_cached_message_name_init(w3d_message_804ad160, w3d_str_803744f8);
        w3d_cached_message_name_init(w3d_message_804ad168, w3d_str_80374514);
        w3d_cached_message_name_init(w3d_message_804ad170, w3d_str_8037452c);
        w3d_cached_message_name_init(w3d_message_804ad178, w3d_str_80374548);
        w3d_cached_message_name_init(w3d_message_804ad180, w3d_str_80374564);
    }
}


