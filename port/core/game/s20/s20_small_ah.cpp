#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_ah.c"
typedef struct S20V3 { int x; int y; int z; } S20V3;
typedef struct S20Obj {
    short id;
    short pad;
    Ptr32<char> vtable;
    int a;
    int b;
    S20V3 v1;
    S20V3 v2;
    S20V3 v3;
} S20Obj;
extern char lbl_8040db38[];
Ptr32<char> w3d_s20_construct_three_vectors_800e7c78(Ptr32<char> self, short id, int a, int b, Ptr32<S20V3> v1, Ptr32<S20V3> v2, Ptr32<S20V3> v3) {
    *(Ptr32<short>)self = id;
    *(Ptr32<int>)(self + 8) = a;
    *(Ptr32<Ptr32<char>>)(self + 4) = lbl_8040db38;
    *(Ptr32<int>)(self + 12) = b;
    *(Ptr32<S20V3>)(self + 16) = *v1;
    *(Ptr32<S20V3>)(self + 28) = *v2;
    *(Ptr32<S20V3>)(self + 40) = *v3;
    return self;
}
typedef struct S20Obj2 { Ptr32<Ptr32<void>> vtable; } S20Obj2;
void w3d_s20_release_held_800f34a0(Ptr32<char> self) {
    Ptr32<S20Obj2> held = *(Ptr32<Ptr32<S20Obj2>>)(self + 888);
    *(Ptr32<int>)(self + 3168) = 0;
    if (held != 0)
        ((Ptr32<void (Ptr32<S20Obj2>)>)held->vtable[4])(held);
    *(Ptr32<int>)(self + 888) = 0;
}

}
