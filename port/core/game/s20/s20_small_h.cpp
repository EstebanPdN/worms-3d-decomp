#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
extern "C" {
#line 1 "s20_small_h.c"
/* Handle checks, bit masks, counted construction and lookups. */
typedef struct S20HandleHolder { char pad[140]; int handle; } S20HandleHolder;
extern Ptr32<void> fn_80164fc8(int);
extern void fn_800cd178(Ptr32<void>);

void w3d_s20_refresh_handle_8013f2f8(Ptr32<S20HandleHolder> self) {
    if (self->handle != -1) {
        Ptr32<void> object = fn_80164fc8(self->handle);
        if (object == 0)
            self->handle = -1;
        else
            fn_800cd178(object);
    }
}

extern void fn_803096b0(Ptr32<char>, int);

void w3d_s20_enable_slot_8016857c(Ptr32<char> self, int slot) {
    int offset = slot * 64 + 264;
    int bit = 1 << slot;
    fn_803096b0(self + offset, bit);
    *(Ptr32<unsigned int>)(self + 776) |= bit;
}

extern Ptr32<void> fn_801857f4(Ptr32<char>);
extern char lbl_80412068[];
extern int lbl_804ab580;

Ptr32<char> w3d_s20_construct_counted_80172b14(Ptr32<char> self) {
    int count;
    fn_801857f4(self);
    count = lbl_804ab580;
    *(Ptr32<Ptr32<char>>)self = lbl_80412068;
    *(Ptr32<int>)(self + 128) = 0;
    lbl_804ab580 = count + 1;
    return self;
}

extern int fn_8017e22c(Ptr32<char>, Ptr32<void>, Ptr32<unsigned short>);

int w3d_s20_lookup_slot_8017ded8(Ptr32<char> self, int key) {
    unsigned short index;
    if (fn_8017e22c(self, w3d::G(key), &index) < 0)
        return 0;
    return (int)w3d::H(w3d_restab_slots()[index]);   // port (v29): tabla nativa; era *(self + index * 4 + 24)
}

extern int fn_801d60cc(Ptr32<char>, int, Ptr32<char>);
extern int fn_801a37a0(Ptr32<char>, Ptr32<char>);

int w3d_s20_notify_then_apply_801d6550(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    fn_801d60cc(base, 3, item);
    return fn_801a37a0(self, item);
}

}
