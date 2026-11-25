struct S21Interface;
struct S21InterfaceMethods { void (*reserved[3])(); void (*retain)(S21Interface *); void (*release)(S21Interface *); };
struct S21Interface { S21InterfaceMethods *methods; };
struct S21Target { char pad[32]; int ready; int cleared; char pad2[20]; S21Interface *service; };
struct S21Owner { char pad[24]; S21Target *target; };
struct S21Holder { char pad[36]; S21Owner *owner; };
extern S21Interface *fn_8020b680(void *);
extern char lbl_8041ca50[];
extern "C" void w3d_s21_refresh_service_8021ad34(S21Holder *self)
{
    S21Target *target = self->owner->target;
    target->cleared = 0;
    S21Interface *fresh = fn_8020b680(lbl_8041ca50);
    S21Interface *old = target->service;
    target->service = fresh;
    if (fresh)
        fresh->methods->retain(fresh);
    if (old)
        old->methods->release(old);
    target->ready = 1;
}
