#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20param_801b9400.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S20Vec4 { float x; float y; float z; float w; } S20Vec4;
extern Ptr32<char> fn_801f0624(Ptr32<char>, Ptr32<char>);
extern void fn_801e8d9c(Ptr32<char>);
extern char lbl_803ab490[];
extern float lbl_803ab4b4[];
extern Ptr32<char> fn_801f0b70(Ptr32<char>, Ptr32<char>);
extern char lbl_803ab5e4[];
extern float lbl_803ab608[];

int w3d_s20reg4_801b9400(Ptr32<char> self) {
    Ptr32<char> property = fn_801f0624(self, lbl_803ab490);
    S20Vec4 value;
    Ptr32<volatile float> words = (Ptr32<volatile float>)&value;
    words[0] = lbl_803ab4b4[0];
    words[3] = lbl_803ab4b4[0];
    words[1] = lbl_803ab4b4[0];
    words[2] = lbl_803ab4b4[0];
    *(Ptr32<S20Vec4>)(property + 8) = value;
    fn_801e8d9c(self);
    return 0;
}

int w3d_s20reg4_801bac10(Ptr32<char> self) {
    Ptr32<char> property = fn_801f0b70(self, lbl_803ab5e4);
    S20Vec4 value;
    Ptr32<volatile float> words = (Ptr32<volatile float>)&value;
    words[0] = lbl_803ab608[0];
    words[3] = lbl_803ab608[0];
    words[1] = lbl_803ab608[0];
    words[2] = lbl_803ab608[0];
    *(Ptr32<S20Vec4>)(property + 8) = value;
    fn_801e8d9c(self);
    return 0;
}

}
