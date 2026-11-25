// func: w3d_test_8008c280 0x8008c280
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
struct K1bIface { void **vtable; };
struct K1bHandle {
    K1bIface *p;
    int unused;
    K1bHandle() {}
    ~K1bHandle() { if (p) ((void (*)(K1bIface *))p->vtable[4])(p); }
};
extern "C" K1bIface *w3d_s10_service_forward_8020b680(void *);
extern "C" void FUN_80164514(void *, void *, int);
extern unsigned char lbl_8040e708[];
extern void *lbl_804b178c;
extern "C" void w3d_test_8008c280(void *self)
{
    K1bHandle h;
    h.p = w3d_s10_service_forward_8020b680(lbl_8040e708);
    if (h.p)
        ((void (*)(K1bIface *))h.p->vtable[3])(h.p);
    FUN_80164514(lbl_804b178c, h.p, FIELD(self, int, 20));
}
