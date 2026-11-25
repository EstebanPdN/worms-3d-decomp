extern int FUN_80015400(void *);
extern int w3d_auto_800154b4(void *);
extern int lbl_804aa6d0;

int s19_check_pair_80015434(void *p) {
    if (FUN_80015400(p) != 0)
        return 0;
    if (w3d_auto_800154b4(p) == lbl_804aa6d0)
        return 0;
    return 1;
}

struct S19Actor { void *vt; char pad4[24]; int f28, f32, f36, f40, f44, f48, f52, f56, f60; };
extern int w3d_actor_base_initialize(struct S19Actor *);
extern unsigned char lbl_8040e310[];

struct S19Actor *s19_actor_init_8002a914(struct S19Actor *p) {
    w3d_actor_base_initialize(p);
    p->vt = (void *)lbl_8040e310;
    p->f28 = 0;
    p->f32 = 0;
    p->f36 = 0;
    p->f40 = 0;
    p->f52 = 0;
    p->f48 = 0;
    p->f56 = 0;
    p->f60 = 0;
    p->f44 = 0;
    return p;
}
