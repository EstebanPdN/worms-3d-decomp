#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_z.c"
/* Slot-table lookups, a reference replacement and a counted destructor. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern int fn_80177eb0(Ptr32<char>, Ptr32<void>, Ptr32<unsigned short>);
extern Ptr32<int> fn_80179170(Ptr32<void>);
extern int fn_80343744(int);
extern Ptr32<int> fn_80178f54(Ptr32<void>);
extern int fn_80343df4(int);

int w3d_s20_query_int_80176b2c(Ptr32<char> self, int key, Ptr32<int> out) {
    unsigned short index;
    int result;
    if (fn_80177eb0(self, w3d::G(key), &index) >= 0) {
        Ptr32<int> value = fn_80179170(w3d::G(fn_80343744(((Ptr32<int>)*(Ptr32<Ptr32<void>>)(self + 24))[index])));
        *out = *value;
        result = 0;
    } else {
        result = 0x80004005;
    }
    return result;
}

int w3d_s20_query_int_80176c68(Ptr32<char> self, int key, Ptr32<int> out) {
    unsigned short index;
    int result;
    if (fn_80177eb0(self, w3d::G(key), &index) >= 0) {
        Ptr32<int> value = fn_80178f54(w3d::G(fn_80343df4(((Ptr32<int>)*(Ptr32<Ptr32<void>>)(self + 24))[index])));
        *out = *value;
        result = 0;
    } else {
        result = 0x80004005;
    }
    return result;
}

void w3d_s20_replace_owned_801784e4(Ptr32<char> self, Ptr32<S20Object> value) {
    Ptr32<S20Object> current = *(Ptr32<Ptr32<S20Object>>)self;
    if (current != value) {
        if (current != 0) {
            ((Ptr32<void (Ptr32<S20Object>)>)current->vtable[16])(current);
            if (*(Ptr32<int>)self != 0) {
                *(Ptr32<int>)self = 0;
                *(Ptr32<int>)(self + 4) = 0;
            }
        }
        *(Ptr32<Ptr32<S20Object>>)self = value;
    }
}

extern int fn_801799d4(Ptr32<char>, int);
extern char lbl_80412e20[];
extern int lbl_804ab69c;

int w3d_s20_destruct_counted_80188ab8(Ptr32<char> self, int flags) {
    int count = lbl_804ab69c;
    Ptr32<S20Object> held = *(Ptr32<Ptr32<S20Object>>)(self + 168);
    *(Ptr32<Ptr32<char>>)self = lbl_80412e20;
    lbl_804ab69c = count - 1;
    if (held != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)held->vtable[4])(held);
    return fn_801799d4(self, flags);
}

}
