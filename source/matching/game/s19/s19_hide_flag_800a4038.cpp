struct S19Iface { void **vtable; };
struct S19Handle {
    S19Iface *p;
    int unused;
    S19Handle() {}
    ~S19Handle() { if (p) ((void (*)(S19Iface *))p->vtable[4])(p); }
};
extern "C" S19Iface *w3d_constructor_native_cast(void *);
extern "C" int w3d_auto_80178d1c(void *);
extern "C" void s19_visibility_hide_800a3bb4(void *);

extern "C" int s19_hide_when_flagged_800a4038(void *owner, void *target)
{
    S19Handle h;
    h.p = w3d_constructor_native_cast(owner);
    if (h.p)
        ((void (*)(S19Iface *))h.p->vtable[3])(h.p);
    if (w3d_auto_80178d1c(h.p))
        s19_visibility_hide_800a3bb4(target);
    return 0;
}
