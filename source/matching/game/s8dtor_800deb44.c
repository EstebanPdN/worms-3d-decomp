#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_8040ff68[];
void fn_800e0400(void *);
void fn_8020c5c4(void *);
void fn_80341588(void *);
void fn_800de958(void *);

void s8_destroy_800deb44(void *self, int flags)
{
    FIELD(self, void *, 228) = w3d_vtable_8040ff68;
    fn_800e0400(self);
    if (FIELD(self, void *, 216)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 216)->vtable[4])(FIELD(self, W3dInterface *, 216));
    }
    if (FIELD(self, void *, 212)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 212)->vtable[4])(FIELD(self, W3dInterface *, 212));
    }
    if (FIELD(self, void *, 208)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 208)->vtable[4])(FIELD(self, W3dInterface *, 208));
    }
    fn_8020c5c4((char *)self + 140);
    fn_80341588((char *)self + 140);
    if (FIELD(self, void *, 136)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 136)->vtable[4])(FIELD(self, W3dInterface *, 136));
    }
    if (FIELD(self, void *, 132)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 132)->vtable[4])(FIELD(self, W3dInterface *, 132));
    }
    if (FIELD(self, void *, 128)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 128)->vtable[4])(FIELD(self, W3dInterface *, 128));
    }
    if (flags & 1) {
        fn_800de958(self);
    }
}
