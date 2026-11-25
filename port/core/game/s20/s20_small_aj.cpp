#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_aj.c"
/* Small helpers: held-object release, cleared constructor, vector reset and normalize. */
typedef struct S20V3 { int x; int y; int z; } S20V3;
typedef Ptr32<void (Ptr32<char>, int, Ptr32<S20V3>, Ptr32<S20V3>, int)> S20Call4;
extern void fn_800ddd14();
extern void fn_800dc6a8();
extern float lbl_8038af94[];

typedef struct S20I3 { int x; int y; int z; } S20I3;
typedef struct S20Obj { Ptr32<Ptr32<void>> vtable; } S20Obj;
typedef Ptr32<void (Ptr32<S20Obj>)> S20Call0;
extern void fn_8015af24(unsigned char);
extern int fn_8015fef0();
extern float fn_802e82c0(float);
extern char lbl_804102e8[];
extern float lbl_8038b5cc[];

void w3d_s20_release_held_pair_800f339c(Ptr32<char> self) {
    Ptr32<S20Obj> first = *(Ptr32<Ptr32<S20Obj>>)(self + 28);
    Ptr32<S20Obj> second;
    *(Ptr32<int>)(self + 3168) = 0;
    if (first != 0)
        ((S20Call0)first->vtable[4])(first);
    second = *(Ptr32<Ptr32<S20Obj>>)(self + 36);
    *(Ptr32<Ptr32<S20Obj>>)(self + 28) = 0;
    if (second != 0)
        ((S20Call0)second->vtable[4])(second);
    *(Ptr32<Ptr32<S20Obj>>)(self + 36) = 0;
    *(Ptr32<int>)(self + 80) = 0;
    if (*(Ptr32<int>)(self + 3192) >= 0) {
        fn_8015af24(*(Ptr32<unsigned char>)(self + 3192));
        *(Ptr32<int>)(self + 3192) = -1;
    }
}

Ptr32<char> w3d_s20_construct_cleared_800efe34(Ptr32<char> self) {
    fn_8015fef0();
    *(Ptr32<Ptr32<char>>)self = lbl_804102e8;
    *(Ptr32<int>)(self + 28) = 0;
    *(Ptr32<int>)(self + 44) = 0;
    *(Ptr32<int>)(self + 48) = 0;
    *(Ptr32<int>)(self + 52) = 0;
    *(Ptr32<int>)(self + 56) = 0;
    *(Ptr32<int>)(self + 60) = 0;
    *(Ptr32<int>)(self + 88) = 0;
    *(Ptr32<int>)(self + 92) = 0;
    *(Ptr32<int>)(self + 96) = 0;
    *(Ptr32<int>)(self + 100) = 0;
    *(Ptr32<int>)(self + 104) = 0;
    *(Ptr32<int>)(self + 108) = 0;
    *(Ptr32<int>)(self + 112) = 0;
    *(Ptr32<int>)(self + 116) = 0;
    *(Ptr32<int>)(self + 72) = 0;
    *(Ptr32<int>)(self + 68) = 0;
    *(Ptr32<int>)(self + 80) = 0;
    *(Ptr32<int>)(self + 76) = 0;
    *(Ptr32<unsigned char>)(self + 84) = 0;
    return self;
}

void w3d_s20_set_normalized_direction_800ecfe0(Ptr32<char> self, Ptr32<float> vector) {
    Ptr32<float> dir = (Ptr32<float>)(self + 72);
    float scale;
    *(Ptr32<S20I3>)dir = *(Ptr32<S20I3>)vector;
    scale = lbl_8038b5cc[0] / fn_802e82c0(dir[0] * dir[0] + dir[1] * dir[1] + dir[2] * dir[2]);
    dir[0] = dir[0] * scale;
    dir[1] = dir[1] * scale;
    dir[2] = dir[2] * scale;
}

void w3d_s20_forward_position_800e705c(Ptr32<char> self, int index, Ptr32<S20V3> out, int flag) {
    S20V3 position;
    fn_800ddd14();
    if (*(Ptr32<int>)(self + 164) != 0) {
        ((S20Call4)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 112))[17])(self, index, &position, out, flag);
        *out = position;
    }
}

void w3d_s20_reset_vectors_800e67d0(Ptr32<char> self) {
    Ptr32<float> first;
    Ptr32<float> second;
    float zero;
    fn_800dc6a8();
    zero = lbl_8038af94[0];
    *(Ptr32<int>)(self + 168) = *(Ptr32<int>)(self + 100);
    first = (Ptr32<float>)(self + 140);
    *(Ptr32<int>)(self + 164) = 0;
    second = (Ptr32<float>)(self + 152);
    first[0] = zero;
    first[1] = zero;
    first[2] = zero;
    second[0] = zero;
    second[1] = zero;
    second[2] = zero;
}

}
