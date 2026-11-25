#include "w3d_ptr.h"
#line 1 "s8hand_800a3c24.cpp"
struct s8_VisibilityGroup {
    char pad0[28];
    int visible;
    Ptr32<void> object32; Ptr32<void> object36; Ptr32<void> object40; Ptr32<void> object44; Ptr32<void> object48; Ptr32<void> object52;
    Ptr32<void> unused56; Ptr32<void> object60; Ptr32<void> unused64; Ptr32<void> object68;
};
extern "C" Ptr32<void> fn_80164fc8(Ptr32<void>);
extern "C" void fn_8002900c(Ptr32<void>,int);
extern "C" void fn_800f0c20(Ptr32<void>,int);
extern "C" void fn_801315a0(Ptr32<void>,int);
extern "C" void fn_800ff634(Ptr32<void>,int);
extern "C" void fn_800a3010(Ptr32<void>,int);
extern "C" void fn_80065c94(Ptr32<void>,int);
extern "C" void fn_800a14c4(Ptr32<void>,int);
extern "C" void fn_800243a8(Ptr32<void>,int);
extern "C" void s8_visibility_800a3c24(Ptr32<s8_VisibilityGroup> group) {
    Ptr32<void> p32 = fn_80164fc8(group->object32);
    if (p32) fn_8002900c(p32,group->visible);
    Ptr32<void> p36 = fn_80164fc8(group->object36);
    if (p36) fn_800f0c20(p36,group->visible);
    Ptr32<void> p40 = fn_80164fc8(group->object40);
    if (p40) fn_801315a0(p40,group->visible);
    Ptr32<void> p44 = fn_80164fc8(group->object44);
    if (p44) fn_800ff634(p44,group->visible);
    Ptr32<void> p48 = fn_80164fc8(group->object48);
    if (p48) fn_800a3010(p48,group->visible);
    Ptr32<void> p52 = fn_80164fc8(group->object52);
    if (p52) fn_80065c94(p52,group->visible);
    Ptr32<void> p60 = fn_80164fc8(group->object60);
    if (p60) fn_800a14c4(p60,group->visible);
    Ptr32<void> p68 = fn_80164fc8(group->object68);
    if (p68) fn_800243a8(p68,group->visible);
}


