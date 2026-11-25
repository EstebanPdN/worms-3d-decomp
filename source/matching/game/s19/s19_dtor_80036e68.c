#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef void (*S19IfaceFn)(S19Iface *self);
extern unsigned char lbl_8040e5e8[];
extern void w3d_auto_8025e0c4(void *, int);
extern void w3d_s4_scroll_handle_destroy(void *, int);
extern void w3d_service_destroy_801628ec(void *, int);

void s19_screen_destroy_80036e68(void *self, int flags)
{
    unsigned i;
    FIELD(self, void *, 0) = lbl_8040e5e8;
    for (i = 0; i <= 9; i++) {
        if (FIELD(self, void *, 36 + i * 4))
            w3d_auto_8025e0c4(FIELD(self, void *, 36 + i * 4), 3);
    }
    if (FIELD(self, void *, 76))
        w3d_s4_scroll_handle_destroy(FIELD(self, void *, 76), 3);
    if (FIELD(self, void *, 32)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 32)->vtable[4])(FIELD(self, S19Iface *, 32));
    }
    if (FIELD(self, void *, 28)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 28)->vtable[4])(FIELD(self, S19Iface *, 28));
    }
    w3d_service_destroy_801628ec(self, flags);
}
