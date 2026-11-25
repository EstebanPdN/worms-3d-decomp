#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19IfaceFn)(S19Iface *self);
extern void FUN_8008dc28(void *);
int s19_reset_slot_80088f28(void *self)
{
    void *zero;
    if (FIELD(self, void *, 356)) {
        zero = 0;
        ((S19IfaceFn)FIELD(self, S19Iface *, 356)->vtable[4])(FIELD(self, S19Iface *, 356));
        FIELD(self, void *, 356) = zero;
    }
    FUN_8008dc28(self);
    return 20;
}
