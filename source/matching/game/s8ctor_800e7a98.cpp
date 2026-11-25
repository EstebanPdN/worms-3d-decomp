#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern "C" {
int fn_801628b0(void *);
extern char w3d_vtable_80410170[];
}
struct s8_Constructed_800e7a98 { char observed[40]; s8_Constructed_800e7a98(); };
s8_Constructed_800e7a98::s8_Constructed_800e7a98()
{
    fn_801628b0(this);
    FIELD(this, void *, 0) = w3d_vtable_80410170;
    FIELD(this, int, 28) = 0;
    FIELD(this, int, 32) = 0;
    FIELD(this, int, 36) = 0;
}
