#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19IfaceFn)(S19Iface *self);
extern void FUN_800ae7d4(void *, int, int);
void s19_start_channels_800ae220(void *self)
{
    FUN_800ae7d4(self, 0, 0);
    FUN_800ae7d4(self, 1, 0);
    FUN_800ae7d4(self, 2, 0);
    ((S19IfaceFn)FIELD(self, S19Iface *, 84)->vtable[6])(FIELD(self, S19Iface *, 84));
    ((S19IfaceFn)FIELD(self, S19Iface *, 88)->vtable[6])(FIELD(self, S19Iface *, 88));
}
