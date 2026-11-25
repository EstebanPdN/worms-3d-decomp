#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19IfaceFn)(S19Iface *self);
extern unsigned char lbl_8040e8b8[];
extern void w3d_actor_handle_member_destroy(void *, int);
extern void w3d_actor_base_destroy(void *, int);

void s19_actor_destroy_8003de80(void *self, int flags)
{
    FIELD(self, void *, 0) = lbl_8040e8b8;
    if (FIELD(self, void *, 108)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 108)->vtable[4])(FIELD(self, S19Iface *, 108));
    }
    if (FIELD(self, void *, 104)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 104)->vtable[4])(FIELD(self, S19Iface *, 104));
    }
    if (FIELD(self, void *, 100)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 100)->vtable[4])(FIELD(self, S19Iface *, 100));
    }
    if (FIELD(self, void *, 96)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 96)->vtable[4])(FIELD(self, S19Iface *, 96));
    }
    w3d_actor_handle_member_destroy((char *)self + 68, 2);
    w3d_actor_base_destroy(self, flags);
}
