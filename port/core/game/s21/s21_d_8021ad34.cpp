#include "w3d_ptr.h"
#line 1 "s21_d_8021ad34.cpp"
struct S21Interface;
struct S21InterfaceMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<S21Interface>)> retain; Ptr32<void (Ptr32<S21Interface>)> release; };
struct S21Interface { Ptr32<S21InterfaceMethods> methods; };
struct S21Target { char pad[32]; int ready; int cleared; char pad2[20]; Ptr32<S21Interface> service; };
struct S21Owner { char pad[24]; Ptr32<S21Target> target; };
struct S21Holder { char pad[36]; Ptr32<S21Owner> owner; };
extern Ptr32<S21Interface> fn_8020b680(Ptr32<void>);
extern char lbl_8041ca50[];
extern "C" void w3d_s21_refresh_service_8021ad34(Ptr32<S21Holder> self)
{
    Ptr32<S21Target> target = self->owner->target;
    target->cleared = 0;
    Ptr32<S21Interface> fresh = fn_8020b680(lbl_8041ca50);
    Ptr32<S21Interface> old = target->service;
    target->service = fresh;
    if (fresh)
        fresh->methods->retain(fresh);
    if (old)
        old->methods->release(old);
    target->ready = 1;
}


