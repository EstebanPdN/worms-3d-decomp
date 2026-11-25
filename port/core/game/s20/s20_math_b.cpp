#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_math_b.c"
/* Normalizes a vector after a virtual call. */
extern int fn_80341584(int);
extern Ptr32<char> fn_801797b4(Ptr32<void>);
extern float fn_802e82c0(float);
extern float lbl_8038b600[];
extern float lbl_8038b604[];

void w3d_s20_normalize_after_call_800ed38c(Ptr32<char> self, int arg, Ptr32<float> vector) {
    float length_squared;
    fn_801797b4(w3d::G(fn_80341584(*(Ptr32<int>)(self + 192))));
    ((Ptr32<void (Ptr32<char>, int, Ptr32<float>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)self)[12])(self, arg, vector);
    length_squared = vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2];
    if (length_squared > lbl_8038b600[0]) {
        float scale = lbl_8038b604[0] / fn_802e82c0(length_squared);
        vector[0] = vector[0] * scale;
        vector[1] = vector[1] * scale;
        vector[2] = vector[2] * scale;
    }
}

}
