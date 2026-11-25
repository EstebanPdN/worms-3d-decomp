struct K4aIface;
typedef struct K4aIfaceVtable { void (*unknown_00[22])(void); int (*set_enabled)(struct K4aIface *self, int enabled); } K4aIfaceVtable;
typedef struct K4aIface { const K4aIfaceVtable *vtable; } K4aIface;
typedef struct K4aToggler { char pad0[28]; K4aIface *iface; void *source; } K4aToggler;
extern void *w3d_constructor_native_cast(void *);
extern int w3d_auto_80178d1c(void *);
extern int w3d_constant_8015fb2c(void *self, int arg);

int k4a_toggler_update_8012bd08(K4aToggler *self, int arg)
{
    int mode = w3d_auto_80178d1c(w3d_constructor_native_cast(self->source));
    self->iface->vtable->set_enabled(self->iface, mode != 2);
    w3d_constant_8015fb2c(self, arg);
    return 0;
}
