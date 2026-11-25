#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_af.c"
typedef struct S20Sink { Ptr32<Ptr32<void>> vtable; } S20Sink;
typedef Ptr32<int (Ptr32<S20Sink>, Ptr32<char>, Ptr32<char>)> S20Sink3;
extern char lbl_803a8200[];
extern char lbl_803a820c[];
int w3d_s20_describe_fields_80190538(Ptr32<char> self, Ptr32<S20Sink> sink) {
    ((S20Sink3)sink->vtable[37])(sink, self + 20, lbl_803a8200);
    ((S20Sink3)sink->vtable[28])(sink, self + 27, lbl_803a820c);
    return 0;
}

}
