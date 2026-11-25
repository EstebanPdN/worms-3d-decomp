#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_80410428[];
void fn_8002a978(void *, void *);

void s8_destroy_800f7028(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80410428;
    fn_8002a978(self, (void *)flags);
}
