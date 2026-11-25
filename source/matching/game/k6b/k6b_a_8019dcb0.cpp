struct K6bIface { void **vtable; };
struct K6bIfaceRef {
    K6bIface *p;
    K6bIfaceRef() : p(0) {}
    ~K6bIfaceRef() { if (p != 0) ((void (*)(K6bIface *))p->vtable[4])(p); }
};
struct K6bObjectFactory { void **vtable; };
struct K6bScriptHost { void **vtable; };
extern "C" K6bObjectFactory *w3d_auto_8020b648(void);
extern "C" char lbl_8040ebd8[];
extern "C" K6bIface *w3d_k6b_script_host_create_object_8019dcb0(K6bScriptHost *self, const char *name)
{
    K6bIfaceRef object;
    K6bObjectFactory *factory = w3d_auto_8020b648();
    if (((int (*)(K6bObjectFactory *, const char *, void *, K6bIface **))factory->vtable[22])(factory, name, lbl_8040ebd8, &object.p) < 0
        || ((int (*)(K6bScriptHost *, K6bIface *))self->vtable[7])(self, object.p) < 0)
        return 0;
    return object.p;
}
// desc: w3d_k6b_script_host_create_object_8019dcb0: Appears to create the named object through slot 22 of the 0x8020b648 factory with interface 0x8040ebd8, register it through slot 7 and return it.
