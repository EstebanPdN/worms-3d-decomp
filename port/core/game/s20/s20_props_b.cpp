#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_props_b.c"
/* Property registration helpers with default vectors, finishing through a shared routine. */
typedef struct S20Vec2 { float x; float y; } S20Vec2;
typedef struct S20Vec4 { float x; float y; float z; float w; } S20Vec4;
extern Ptr32<char> fn_801f00f0(Ptr32<char>, Ptr32<char>);
extern Ptr32<char> fn_801f0b70(Ptr32<char>, Ptr32<char>);
extern Ptr32<void> fn_801ec52c(Ptr32<char>, Ptr32<char>);
extern Ptr32<void> fn_801ece2c(Ptr32<char>, Ptr32<char>);
extern void fn_801e8d9c(Ptr32<char>);
extern char lbl_803abec0[];
extern char lbl_803abef4[];
extern char lbl_803abf24[];
extern char lbl_803abf58[];
extern float lbl_803abf7c[];
extern char lbl_803aecf8[];
extern char lbl_803aed28[];
extern char lbl_803aed58[];
extern float lbl_803aed80[];
extern float lbl_803aed84[];
extern char lbl_803aedf4[];
extern char lbl_803aee28[];
extern float lbl_803aee4c[];
extern float lbl_803aee50[];

int w3d_s20_register_float_pairs_801ce708(Ptr32<char> self) {
    Ptr32<char> property;
    volatile S20Vec2 first;
    volatile S20Vec2 second;
    property = fn_801f00f0(self, lbl_803aecf8);
    first.y = lbl_803aed80[0];
    first.x = lbl_803aed80[0];
    *(Ptr32<S20Vec2>)(property + 8) = *(Ptr32<S20Vec2>)&first;
    property = fn_801f00f0(self, lbl_803aed28);
    second.y = lbl_803aed84[0];
    second.x = lbl_803aed84[0];
    *(Ptr32<S20Vec2>)(property + 8) = *(Ptr32<S20Vec2>)&second;
    fn_801ec52c(self, lbl_803aed58);
    fn_801e8d9c(self);
    return 0;
}

int w3d_s20_register_float_pair_801bf55c(Ptr32<char> self) {
    Ptr32<char> property;
    volatile S20Vec2 value;
    fn_801ec52c(self, lbl_803abec0);
    fn_801ec52c(self, lbl_803abef4);
    fn_801ec52c(self, lbl_803abf24);
    property = fn_801f00f0(self, lbl_803abf58);
    value.y = lbl_803abf7c[0];
    value.x = lbl_803abf7c[0];
    *(Ptr32<S20Vec2>)(property + 8) = *(Ptr32<S20Vec2>)&value;
    fn_801e8d9c(self);
    return 0;
}

int w3d_s20_register_vec4_property_801cee80(Ptr32<char> self) {
    Ptr32<char> property;
    S20Vec4 value;
    Ptr32<volatile float> w;
    fn_801ece2c(self, lbl_803aedf4);
    property = fn_801f0b70(self, lbl_803aee28);
    w = (Ptr32<volatile float>)&value;
    w[0] = lbl_803aee4c[0];
    w[2] = lbl_803aee4c[0];
    w[3] = lbl_803aee50[0];
    w[1] = lbl_803aee4c[0];
    *(Ptr32<S20Vec4>)(property + 8) = value;
    fn_801e8d9c(self);
    return 0;
}

}
