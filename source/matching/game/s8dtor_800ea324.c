#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_804101f8[];
void fn_8020c5c4(void *);
void fn_80341588(void *);
void fn_802134fc(void *);
void fn_80161050(void *, int);

void s8_destroy_800ea324(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804101f8;
    fn_8020c5c4((char *)self + 304);
    fn_80341588((char *)self + 304);
    if (FIELD(self, void *, 260)) {
        fn_802134fc(FIELD(self, void *, 260));
    }
    if (FIELD(self, void *, 212)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 212)->vtable[4])(FIELD(self, W3dInterface *, 212));
    }
    if (FIELD(self, void *, 208)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 208)->vtable[4])(FIELD(self, W3dInterface *, 208));
    }
    if (FIELD(self, void *, 204)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 204)->vtable[4])(FIELD(self, W3dInterface *, 204));
    }
    if (FIELD(self, void *, 200)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 200)->vtable[4])(FIELD(self, W3dInterface *, 200));
    }
    if (FIELD(self, void *, 196)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 196)->vtable[4])(FIELD(self, W3dInterface *, 196));
    }
    if (FIELD(self, void *, 192)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 192)->vtable[4])(FIELD(self, W3dInterface *, 192));
    }
    if (FIELD(self, void *, 188)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 188)->vtable[4])(FIELD(self, W3dInterface *, 188));
    }
    if (FIELD(self, void *, 184)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 184)->vtable[4])(FIELD(self, W3dInterface *, 184));
    }
    if (FIELD(self, void *, 180)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 180)->vtable[4])(FIELD(self, W3dInterface *, 180));
    }
    if (FIELD(self, void *, 176)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 176)->vtable[4])(FIELD(self, W3dInterface *, 176));
    }
    if (FIELD(self, void *, 172)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 172)->vtable[4])(FIELD(self, W3dInterface *, 172));
    }
    if (FIELD(self, void *, 168)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 168)->vtable[4])(FIELD(self, W3dInterface *, 168));
    }
    if (FIELD(self, void *, 164)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 164)->vtable[4])(FIELD(self, W3dInterface *, 164));
    }
    if (FIELD(self, void *, 160)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 160)->vtable[4])(FIELD(self, W3dInterface *, 160));
    }
    if (FIELD(self, void *, 100)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 100)->vtable[4])(FIELD(self, W3dInterface *, 100));
    }
    fn_80161050(self, flags);
}
