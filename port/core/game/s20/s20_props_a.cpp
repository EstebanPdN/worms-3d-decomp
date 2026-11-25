#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_props_a.c"
/* Property registration helpers that set a default value and finish through a shared routine. */
typedef struct S20Color { unsigned char r; unsigned char g; unsigned char b; unsigned char a; } S20Color;
typedef struct S20Vec { float x; float y; float z; } S20Vec;
extern Ptr32<char> fn_801f15e0(Ptr32<char>, Ptr32<char>);
extern Ptr32<char> fn_801f0210(Ptr32<char>, Ptr32<char>);
extern void fn_801e8d9c(Ptr32<char>);
extern char lbl_803a80c4[];
extern char lbl_803a8078[];
extern float lbl_803a809c[];

int w3d_s20_register_color_property_8018efe0(Ptr32<char> self) {
    Ptr32<char> property = fn_801f15e0(self, lbl_803a80c4);
    S20Color color;
    Ptr32<volatile unsigned char> bytes = (Ptr32<volatile unsigned char>)&color;
    bytes[0] = 0;
    bytes[3] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    *(Ptr32<int>)(property + 8) = *(Ptr32<int>)&color;
    fn_801e8d9c(self);
    return 0;
}

int w3d_s20_register_vector_property_8018ec60(Ptr32<char> self) {
    Ptr32<char> property = fn_801f0210(self, lbl_803a8078);
    S20Vec value;
    Ptr32<volatile float> words = (Ptr32<volatile float>)&value;
    words[0] = lbl_803a809c[0];
    words[2] = lbl_803a809c[0];
    words[1] = lbl_803a809c[0];
    *(Ptr32<S20Vec>)(property + 8) = value;
    fn_801e8d9c(self);
    return 0;
}

}
