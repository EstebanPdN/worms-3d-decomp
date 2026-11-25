#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_u_802700a8.c"
// desc: Appears to clamp a stored value below a limit from the engine context and apply it to two linked gauge objects while active.
struct S21Limits { char pad[24]; unsigned limit; };
struct S21Engine { char pad[28]; Ptr32<struct S21Limits> limits; };
struct S21Panel { char pad[176]; int mode; char pad1[104]; int active; int bar; char pad2[8]; unsigned value; };
extern Ptr32<void> fn_80341584(int);
extern Ptr32<struct S21Engine> fn_801797b4(Ptr32<void>);
extern void fn_802bc8b4(Ptr32<void>, unsigned);
extern void fn_8026f948(Ptr32<struct S21Panel>, unsigned, int);
void w3d_s21_panel_update_802700a8(Ptr32<struct S21Panel> self)
{
    if (self->active) {
        unsigned limit;limit = fn_801797b4((Ptr32<void>)fn_80341584(self->active))->limits->limit;
        if (limit <= self->value) {
            int clamped = limit - 1;
            self->value = clamped;
            if (clamped < 0)
                self->value = 0;
        }
        if (self->bar) {
            if (self->mode == 1)
                fn_802bc8b4(w3d::G(self->bar), self->value);
            if (self->bar)
                fn_8026f948(self, self->value, 1);
        }
    }
}

}
