#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_80410520[];
extern int lbl_804aaf64;
void fn_801628ec(void *, int);

void s8_destroy_800fd964(void *self, int flags)
{
    W3dInterface *firstInterface = FIELD(self, W3dInterface *, 36);
    FIELD(self, void *, 0) = w3d_vtable_80410520;
    lbl_804aaf64 = 0;
    if (firstInterface) {
        ((W3dInterfaceFn)firstInterface->vtable[4])(firstInterface);
    }
    if (FIELD(self, void *, 32)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 32)->vtable[4])(FIELD(self, W3dInterface *, 32));
    }
    if (FIELD(self, void *, 28)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 28)->vtable[4])(FIELD(self, W3dInterface *, 28));
    }
    fn_801628ec(self, flags);
}
