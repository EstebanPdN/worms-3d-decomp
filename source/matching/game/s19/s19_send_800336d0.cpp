#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
struct S19Iface { void **vtable; };
struct S19Handle {
    S19Iface *p;
    int unused;
    S19Handle() {}
    ~S19Handle() { if (p) ((void (*)(S19Iface *))p->vtable[4])(p); }
};
struct S19Ctx { char pad0[48]; S19Iface *sink; };
extern "C" S19Iface *w3d_s10_service_forward_8020b680(void *);
extern S19Ctx *lbl_804b1788;
extern unsigned char lbl_804140d0[];

extern "C" void s19_send_range_800336d0(void *self)
{
    if (FIELD(self, int, 804)) {
        S19Handle h;
        h.p = w3d_s10_service_forward_8020b680(lbl_804140d0);
        if (h.p)
            ((void (*)(S19Iface *))h.p->vtable[3])(h.p);
        ((void (*)(S19Iface *, int))h.p->vtable[12])(h.p, FIELD(self, int, 804));
        ((void (*)(S19Iface *, int))h.p->vtable[6])(h.p, FIELD(self, int, 800));
        ((void (*)(S19Iface *, int, int, int))lbl_804b1788->sink->vtable[17])(lbl_804b1788->sink, FIELD(self, int, 796), FIELD(self, int, 800), FIELD(self, int, 804));
    }
}
