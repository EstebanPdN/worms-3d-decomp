#include "w3d_ptr.h"
#line 1 "s21_q_80200c44.cpp"
// desc: Appears to finish a child, notify its registered listener, clear a link field and return the finish result.
struct S21Listener;
struct S21ListenerMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<S21Listener>, Ptr32<void>)> notify; };
struct S21Listener { Ptr32<S21ListenerMethods> methods; };
struct S21Node { char pad[8]; Ptr32<void> child; char pad1[12]; Ptr32<S21Listener> listener; int link; };
extern int fn_80200ca4(Ptr32<void>);
extern "C" int w3d_s21_finish_node_80200c44(Ptr32<S21Node> self)
{
    int result = fn_80200ca4(self->child);
    if (self->listener)
        self->listener->methods->notify(self->listener, self);
    self->link = 0;
    return result;
}


