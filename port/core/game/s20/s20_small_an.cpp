#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_an.c"
/* Sink field description and float epsilon search. */
typedef struct S20Sink { Ptr32<Ptr32<void>> vtable; } S20Sink;
typedef Ptr32<int (Ptr32<S20Sink>, Ptr32<char>, Ptr32<char>, int)> S20SinkA;
typedef Ptr32<int (Ptr32<S20Sink>, int, Ptr32<char>, int)> S20SinkB;
extern char lbl_803a8200[];
extern char lbl_803a820c[];
int w3d_s20_describe_two_fields_801904c0(Ptr32<char> self, Ptr32<S20Sink> sink) {
    ((S20SinkA)sink->vtable[32])(sink, self + 20, lbl_803a8200, 0);
    ((S20SinkB)sink->vtable[13])(sink, *(Ptr32<unsigned char>)(self + 27), lbl_803a820c, 0);
    return 0;
}

extern float lbl_803a84bc[];
extern float lbl_803a84c0[];
extern float lbl_804ab6e4;
void w3d_s20_find_float_epsilon_80196668(void) {
    float one = lbl_803a84bc[0];
    float factor = lbl_803a84c0[0];
    lbl_804ab6e4 = one;
    do {
        lbl_804ab6e4 = lbl_804ab6e4 * factor;
    } while (lbl_804ab6e4 + one > one);
    lbl_804ab6e4 = 2.0f * lbl_804ab6e4;
}

}
