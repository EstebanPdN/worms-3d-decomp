#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19IfaceFn)(S19Iface *self);
extern void w3d_handle_member_destroy_801265a4(void *, int);

void s19_release_members_80093780(void *self)
{
    void *zero = 0;
    if (FIELD(self, void *, 32)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 32)->vtable[4])(FIELD(self, S19Iface *, 32));
    }
    FIELD(self, void *, 32) = zero;
    if (FIELD(self, void *, 36)) {
        w3d_handle_member_destroy_801265a4(FIELD(self, void *, 36), 3);
        FIELD(self, void *, 36) = zero;
    }
}
