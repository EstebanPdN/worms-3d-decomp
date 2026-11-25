#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19IfaceFn)(S19Iface *self);
extern unsigned char lbl_8040ddb8[];
extern void w3d_handle_storage_release(void *);
extern void w3d_actor_base_destroy(void *, int);

void s19_destroy_800222b8(void *self, int flags)
{
    FIELD(self, void *, 0) = lbl_8040ddb8;
    if (FIELD(self, void *, 48)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 48)->vtable[4])(FIELD(self, S19Iface *, 48));
    }
    if (FIELD(self, void *, 44)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 44)->vtable[4])(FIELD(self, S19Iface *, 44));
    }
    if (FIELD(self, void *, 40)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 40)->vtable[4])(FIELD(self, S19Iface *, 40));
    }
    if (FIELD(self, void *, 28))
        w3d_handle_storage_release(FIELD(self, void *, 28));
    w3d_actor_base_destroy(self, flags);
}
