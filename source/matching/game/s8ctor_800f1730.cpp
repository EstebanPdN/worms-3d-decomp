#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern "C" {
int fn_8015fef0(void *);
extern char w3d_vtable_80410368[];
}
struct s8_Constructed_800f1730 { char observed[48]; s8_Constructed_800f1730(); };
s8_Constructed_800f1730::s8_Constructed_800f1730()
{
    fn_8015fef0(this);
    FIELD(this, void *, 0) = w3d_vtable_80410368;
    FIELD(this, int, 44) = 0;
    FIELD(this, int, 28) = 0;
    FIELD(this, int, 32) = 0;
}
