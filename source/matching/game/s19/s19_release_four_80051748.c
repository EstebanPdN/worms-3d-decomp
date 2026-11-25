#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19IfaceFn)(S19Iface *self);
void s19_release_four_80051748(void *self)
{
    int i;
    void *zero = 0;
    for (i = 4; i != 0; i--) {
        if (FIELD(self, void *, 60 - i * 4))
            ((S19IfaceFn)FIELD(self, S19Iface *, 60 - i * 4)->vtable[4])(FIELD(self, S19Iface *, 60 - i * 4));
        FIELD(self, void *, 60 - i * 4) = zero;
    }
}
