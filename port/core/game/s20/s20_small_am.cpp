#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_am.c"
/* Held-object handling, offset accumulation and id acceptance. */
typedef struct S20Obj { Ptr32<Ptr32<void>> vtable; } S20Obj;
typedef struct S20F3 { float x, y, z; } S20F3;
typedef Ptr32<void (Ptr32<S20Obj>, int, Ptr32<S20F3>)> S20CallV;
extern Ptr32<S20Obj> fn_80164fc8(int);
extern float lbl_8038b27c[];

typedef Ptr32<void (Ptr32<S20Obj>)> S20Call0;
extern void fn_800f6afc(Ptr32<char>);
extern void fn_8015af24(unsigned char);
extern void fn_8015aee8(unsigned char);

void w3d_s20_swap_handles_800f3028(Ptr32<char> self) {
    Ptr32<S20Obj> held;
    Ptr32<Ptr32<S20Obj>> slot;
    unsigned int i;
    Ptr32<S20Obj> empty;
    fn_800f6afc(self);
    if (*(Ptr32<int>)(self + 3196) != *(Ptr32<int>)(self + 3192)) {
        held = *(Ptr32<Ptr32<S20Obj>>)(self + 28);
        if (held != 0)
            ((S20Call0)held->vtable[4])(held);
        *(Ptr32<int>)(self + 28) = 0;
        for (i = 0, empty = 0, slot = (Ptr32<Ptr32<S20Obj>>)(self + 88); i < 200; i++) {
            if (*slot != 0)
                ((S20Call0)(*slot)->vtable[4])(*slot);
            *slot = empty;
            slot++;
        }
        if (*(Ptr32<int>)(self + 3192) >= 0) {
            fn_8015af24(*(Ptr32<unsigned char>)(self + 3192));
            *(Ptr32<int>)(self + 3192) = -1;
        }
        fn_8015aee8(*(Ptr32<unsigned char>)(self + 3196));
        *(Ptr32<int>)(self + 3192) = *(Ptr32<int>)(self + 3196);
    }
}

extern int fn_8026cc60(Ptr32<void>);
extern int fn_8026c96c(Ptr32<char>, int);

void w3d_s20_replace_held_800f3524(Ptr32<char> self, Ptr32<Ptr32<S20Obj>> holder, int arg) {
    Ptr32<S20Obj> held;
    Ptr32<S20Obj> old;
    held = *holder;
    if (held != 0)
        ((S20Call0)held->vtable[3])(held);
    old = *(Ptr32<Ptr32<S20Obj>>)(self + 32);
    if (old != 0)
        ((S20Call0)old->vtable[4])(old);
    *(Ptr32<Ptr32<S20Obj>>)(self + 32) = *holder;
    fn_8026c96c(self + 3072, fn_8026cc60(w3d::G(arg)));
    fn_800f6afc(self);
    if (*(Ptr32<int>)(self + 3168) == 0)
        *(Ptr32<int>)(self + 3168) = 1;
}

extern Ptr32<char> fn_8003888c(void);
extern int fn_8021eb00(int);
extern Ptr32<char> lbl_804aaabc;
extern Ptr32<char> lbl_804abac0;

int w3d_s20_can_accept_id_800f899c(Ptr32<char> self, Ptr32<unsigned short> id) {
    unsigned int i;
    Ptr32<unsigned short> list;
    if (*(Ptr32<int>)(fn_8003888c() + 36) != 0 || (*(Ptr32<unsigned int>)(lbl_804aaabc + 240) & 0x800000) != 0)
        return 0;
    for (i = 0; i < *(Ptr32<unsigned int>)(self + 440); i++) {
        if (*id == ((Ptr32<unsigned short>)*(Ptr32<Ptr32<char>>)(self + 436))[i]) return 0;
    }
    if (fn_8021eb00(*(Ptr32<int>)(*(Ptr32<Ptr32<char>>)(lbl_804abac0 + 36) + 24)) == 0)
        return 0;
    return 1;
}

void w3d_s20_accumulate_offset_800e9528(Ptr32<char> self, int arg) {
    S20F3 offset;
    Ptr32<S20F3> p = &offset;
    Ptr32<S20F3> position = (Ptr32<S20F3>)(self + 60);
    Ptr32<S20Obj> obj = fn_80164fc8(*(Ptr32<int>)(self + 192));
    ((S20CallV)obj->vtable[11])(obj, arg, position);
    offset.x = lbl_8038b27c[0];
    p->y = lbl_8038b27c[0];
    p->z = lbl_8038b27c[0];
    ((S20CallV)obj->vtable[15])(obj, arg, p);
    *(Ptr32<float>)(self + 60) += offset.x;
    position->y += p->y;
    position->z += p->z;
}

}
