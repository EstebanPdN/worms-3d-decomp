#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_80410778[];
void fn_801628ec(void *, int);

void s8_destroy_801091a4(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80410778;
    if (FIELD(self, void *, 80)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 80)->vtable[4])(FIELD(self, W3dInterface *, 80));
    }
    if (FIELD(self, void *, 76)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 76)->vtable[4])(FIELD(self, W3dInterface *, 76));
    }
    if (FIELD(self, void *, 72)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 72)->vtable[4])(FIELD(self, W3dInterface *, 72));
    }
    if (FIELD(self, void *, 68)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 68)->vtable[4])(FIELD(self, W3dInterface *, 68));
    }
    if (FIELD(self, void *, 64)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 64)->vtable[4])(FIELD(self, W3dInterface *, 64));
    }
    if (FIELD(self, void *, 60)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 60)->vtable[4])(FIELD(self, W3dInterface *, 60));
    }
    if (FIELD(self, void *, 56)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 56)->vtable[4])(FIELD(self, W3dInterface *, 56));
    }
    if (FIELD(self, void *, 52)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 52)->vtable[4])(FIELD(self, W3dInterface *, 52));
    }
    if (FIELD(self, void *, 48)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 48)->vtable[4])(FIELD(self, W3dInterface *, 48));
    }
    if (FIELD(self, void *, 44)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 44)->vtable[4])(FIELD(self, W3dInterface *, 44));
    }
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    if (FIELD(self, void *, 36)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 36)->vtable[4])(FIELD(self, W3dInterface *, 36));
    }
    if (FIELD(self, void *, 32)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 32)->vtable[4])(FIELD(self, W3dInterface *, 32));
    }
    if (FIELD(self, void *, 28)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 28)->vtable[4])(FIELD(self, W3dInterface *, 28));
    }
    fn_801628ec(self, flags);
}
