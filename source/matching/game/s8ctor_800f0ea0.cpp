#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern "C" {
int fn_80161014(void *);
extern char w3d_vtable_80410328[];
}
struct s8_Constructed_800f0ea0 { char observed[44]; s8_Constructed_800f0ea0(); };
s8_Constructed_800f0ea0::s8_Constructed_800f0ea0()
{
    fn_80161014(this);
    FIELD(this, void *, 0) = w3d_vtable_80410328;
    FIELD(this, int, 28) = 0;
    FIELD(this, int, 32) = 0;
    FIELD(this, int, 36) = 0;
    FIELD(this, int, 40) = 0;
}
