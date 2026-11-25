#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_props_c.c"
/* Property registration helpers with default vectors and extra entries. */
typedef struct S20Vec3 { float x; float y; float z; } S20Vec3;
extern Ptr32<char> fn_801f0504(Ptr32<char>, Ptr32<char>);
extern Ptr32<char> fn_801f0210(Ptr32<char>, Ptr32<char>);
extern Ptr32<void> fn_801ec52c(Ptr32<char>, Ptr32<char>);
extern void fn_801e8d9c(Ptr32<char>);
extern char lbl_803ac12c[];
extern char lbl_803ac150[];
extern char lbl_803ac18c[];
extern char lbl_803ac1c8[];
extern char lbl_803ac208[];
extern float lbl_803ac230[];

int w3d_s20_register_vector_entries_801bfcf4(Ptr32<char> self) {
    Ptr32<char> property;
    S20Vec3 value;
    Ptr32<volatile float> words;
    property = fn_801f0504(self, lbl_803ac12c);
    words = (Ptr32<volatile float>)&value;
    words[0] = lbl_803ac230[0];
    words[2] = lbl_803ac230[0];
    words[1] = lbl_803ac230[0];
    *(Ptr32<S20Vec3>)(property + 8) = value;
    fn_801ec52c(self, lbl_803ac150);
    fn_801ec52c(self, lbl_803ac18c);
    fn_801ec52c(self, lbl_803ac1c8);
    fn_801ec52c(self, lbl_803ac208);
    fn_801e8d9c(self);
    return 0;
}

}
