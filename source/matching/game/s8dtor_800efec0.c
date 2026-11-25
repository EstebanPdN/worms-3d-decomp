#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_804102e8[];
void fn_8015ff2c(void *, int);

void s8_destroy_800efec0(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804102e8;
    if (FIELD(self, void *, 116)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 116)->vtable[4])(FIELD(self, W3dInterface *, 116));
    }
    if (FIELD(self, void *, 112)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 112)->vtable[4])(FIELD(self, W3dInterface *, 112));
    }
    if (FIELD(self, void *, 108)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 108)->vtable[4])(FIELD(self, W3dInterface *, 108));
    }
    if (FIELD(self, void *, 104)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 104)->vtable[4])(FIELD(self, W3dInterface *, 104));
    }
    if (FIELD(self, void *, 100)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 100)->vtable[4])(FIELD(self, W3dInterface *, 100));
    }
    if (FIELD(self, void *, 96)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 96)->vtable[4])(FIELD(self, W3dInterface *, 96));
    }
    if (FIELD(self, void *, 92)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 92)->vtable[4])(FIELD(self, W3dInterface *, 92));
    }
    if (FIELD(self, void *, 88)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 88)->vtable[4])(FIELD(self, W3dInterface *, 88));
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
    if (FIELD(self, void *, 28)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 28)->vtable[4])(FIELD(self, W3dInterface *, 28));
    }
    fn_8015ff2c(self, flags);
}
