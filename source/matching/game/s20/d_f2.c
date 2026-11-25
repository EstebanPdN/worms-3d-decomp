/* Appears to apply the referenced object's pending step to an actor, or post a message. */
typedef struct S20Msg { short id; short pad; void *table; } S20Msg;
typedef struct S20Actor {
    unsigned char pad0[0x230]; float v230[3]; float vel23c; unsigned char pad240[0x2a4 - 0x240];
    float v2a4[3]; unsigned char pad2b0[0x2cc - 0x2b0]; int flag2cc; unsigned char pad2d0[0x314 - 0x2d0];
    int handle; unsigned char pad318[0x338 - 0x318]; int mode338;
} S20Actor;
typedef struct S20Obj { unsigned char pad0[0x78]; int flag78; unsigned char pad7c[0x10c - 0x7c]; float rate; } S20Obj;
extern int fn_800CFC98(void *);
extern void fn_800CFE68(void *, void *, void *, void *);
extern short fn_8015F5A0(void *, int);
extern S20Msg *fn_801613F0(int, int);
extern void fn_8016239C(void *);
extern S20Obj *fn_80164FC8(int);
extern float lbl_803A1688[];
extern float lbl_803A168C[];
extern char lbl_8040DB38[];
extern char lbl_804AFBF8;
extern int lbl_804B1754;
int w3d_s20_actor_step_8014dd18(S20Actor *a) {
    S20Obj *o;
    int r;
    if (a->handle == -1)
        return 0;
    o = fn_80164FC8(a->handle);
    if (o == 0) {
        a->handle = -1;
        return 0;
    }
    r = fn_800CFC98(o);
    if (r) {
        fn_800CFE68(o, a->v230, a->v2a4, &a->vel23c);
    } else if (a->flag2cc != 0 || a->mode338 < 0) {
        if (o->flag78 != 0) {
            S20Msg *m = fn_801613F0(lbl_804B1754, 8);
            m->id = fn_8015F5A0(&lbl_804AFBF8, 1);
            m->table = lbl_8040DB38;
            fn_8016239C(m);
            return 0;
        }
    } else {
        a->vel23c += o->rate * lbl_803A1688[0] * lbl_803A168C[0];
    }
    return r;
}
