#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_p_802af894.c"
// desc: Appears to initialize an embedded component from the engine context, call two virtual setup slots on it and post a cached message.
struct S21ComponentMethods { Ptr32<void (Ptr32<void>, int)> reserved[5]; Ptr32<void (Ptr32<void>, int)> enable; char pad[28]; Ptr32<void (Ptr32<void>, int)> start; };
struct S21Clock { char pad[52]; int tick; };
struct S21Entity { char pad[28]; char component[180]; Ptr32<struct S21ComponentMethods> methods; char pad1[12]; char target[4]; };
extern Ptr32<struct S21Clock> fn_80165254(void);
extern void fn_802b0b84(Ptr32<void>, Ptr32<void>, int);
extern short fn_8015f5a0(Ptr32<void>, int);
extern int fn_80162024(Ptr32<void>, Ptr32<short>, Ptr32<void>);
struct S21Id { int word; };
extern struct S21Id lbl_804b0f44;
void w3d_s21_entity_start_802af894(Ptr32<struct S21Entity> self)
{
    short message;
    Ptr32<void> component = self->component;
    fn_802b0b84(component, self, fn_80165254()->tick);
    self->methods->enable(component, 1);
    self->methods->start(component, 1);
    message = fn_8015f5a0(&lbl_804b0f44, 1);
    fn_80162024(self, &message, self->target);
}

}
