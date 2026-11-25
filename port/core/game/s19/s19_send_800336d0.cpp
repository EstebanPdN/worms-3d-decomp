#include "w3d_ptr.h"
#line 1 "s19_send_800336d0.cpp"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
struct S19Iface { Ptr32<Ptr32<void>> vtable; };
struct S19Handle {
    Ptr32<S19Iface> p;
    int unused;
    S19Handle() {}
    ~S19Handle() { if (p) ((Ptr32<void (Ptr32<S19Iface>)>)p->vtable[4])(p); }
};
struct S19Ctx { char pad0[48]; Ptr32<S19Iface> sink; };
extern "C" Ptr32<S19Iface> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern Ptr32<S19Ctx> lbl_804b1788;
extern unsigned char lbl_804140d0[];

extern "C" void s19_send_range_800336d0(Ptr32<void> self)
{
    if (FIELD(self, int, 804)) {
        S19Handle h;
        h.p = w3d_s10_service_forward_8020b680(lbl_804140d0);
        if (h.p)
            ((Ptr32<void (Ptr32<S19Iface>)>)h.p->vtable[3])(h.p);
        ((Ptr32<void (Ptr32<S19Iface>, int)>)h.p->vtable[12])(h.p, FIELD(self, int, 804));
        ((Ptr32<void (Ptr32<S19Iface>, int)>)h.p->vtable[6])(h.p, FIELD(self, int, 800));
        ((Ptr32<void (Ptr32<S19Iface>, int, int, int)>)lbl_804b1788->sink->vtable[17])(lbl_804b1788->sink, FIELD(self, int, 796), FIELD(self, int, 800), FIELD(self, int, 804));
    }
}


