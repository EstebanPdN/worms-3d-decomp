struct S19V3 { float x, y, z; };
struct S19Actor { void *vt; char pad4[48]; struct S19V3 vec52; float f64; char pad68[8]; int f76, f80, f84, f88, f92, f96, f100, f104, f108; };
extern unsigned char lbl_8040e8b8[];
extern struct S19V3 lbl_8045e788;
extern int w3d_actor_base_initialize(struct S19Actor *);
extern void * w3d_actor_handle_member_initialize(void *);

struct S19Actor *s19_actor_ctor_8003dde0(struct S19Actor *p)
{
    w3d_actor_base_initialize(p);
    p->vt = (void *)lbl_8040e8b8;
    w3d_actor_handle_member_initialize((char *)p + 68);
    p->f64 = 0.0f;
    p->f96 = 0;
    p->f100 = 0;
    p->f104 = 0;
    p->f108 = 0;
    p->f76 = 0;
    p->f80 = 0;
    p->f88 = 0;
    p->f92 = 0;
    p->vec52 = lbl_8045e788;
    p->f84 = 1;
    return p;
}
