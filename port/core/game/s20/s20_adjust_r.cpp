#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_r.c"
/* Method on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
typedef struct S20Holder96 { char pad[96]; Ptr32<S20Object> current; } S20Holder96;
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20HandlerS;
extern Ptr32<char> fn_801ad108(Ptr32<char>, Ptr32<char>);

int w3d_s20_replace_current_801adc14(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 80);
    if (target != 0) {
        Ptr32<S20Object> saved;
        Ptr32<char> sub;
        Ptr32<char> other;
        Ptr32<S20Object> previous;
        Ptr32<S20Object> kept;
        if (((Ptr32<S20Holder96>)base)->current != 0)
            ((Ptr32<void (Ptr32<S20Object>)>)((Ptr32<S20Holder96>)base)->current->vtable[4])(((Ptr32<S20Holder96>)base)->current);
        *(Ptr32<int>)(base + 96) = 0;
        sub = base + 4;
        ((S20HandlerS)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
        saved = ((Ptr32<S20Holder96>)base)->current;
        if (saved != 0) {
            other = fn_801ad108(base, item);
            previous = *(Ptr32<Ptr32<S20Object>>)(other + 80);
            *(Ptr32<Ptr32<S20Object>>)(other + 80) = saved;
            ((Ptr32<void (Ptr32<S20Object>)>)saved->vtable[3])(saved);
            if (previous != 0)
                ((Ptr32<void (Ptr32<S20Object>)>)previous->vtable[4])(previous);
            kept = (Ptr32<S20Object>)other;
            if (kept != 0)
                ((Ptr32<void (Ptr32<S20Object>)>)kept->vtable[3])(kept);
            if (((Ptr32<S20Holder96>)base)->current != 0)
                ((Ptr32<void (Ptr32<S20Object>)>)((Ptr32<S20Holder96>)base)->current->vtable[4])(((Ptr32<S20Holder96>)base)->current);
            *(Ptr32<Ptr32<S20Object>>)(base + 96) = kept;
        }
    }
    return 0;
}

}
