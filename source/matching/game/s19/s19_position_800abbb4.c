#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19IfaceFn)(S19Iface *self);
typedef void (*S19IfaceFn2)(S19Iface *self, int arg);
struct S19V3 { float x, y, z; };
void s19_set_position_800abbb4(void *self, struct S19V3 *v)
{
    if (FIELD(self, void *, 120)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 120)->vtable[10])(FIELD(self, S19Iface *, 120));
    }
    FIELD(self, struct S19V3, 132) = *v;
}
