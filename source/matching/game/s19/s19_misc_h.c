struct S19Cfg { char pad0[584]; int a584; int a588; int a592; int a596; };
struct S19Obj { char pad0[28]; void *src; char pad32[144]; int f176; int f180; char pad184[4]; int f188; };
extern void * FUN_80341584(void *);
extern struct S19Cfg *FUN_801797b4(void *);
extern void FUN_800e9830(struct S19Obj *, int);
extern void FUN_800e8ee0(struct S19Obj *, void *, int *);
extern int FUN_800e8f40(struct S19Obj *, void *);
void s19_init_from_config_8007070c(struct S19Obj *p) {
    struct S19Cfg *c;c = FUN_801797b4((void *)FUN_80341584(p->src));
    FUN_800e9830(p, c->a596);
    FUN_800e8ee0(p, c->a592, &p->f176);
    FUN_800e8ee0(p, c->a588, &p->f180);
    p->f188 = FUN_800e8f40(p, c->a584);
}

struct S19Message { unsigned short id; unsigned short pad2; void *type; };
struct S19Dispatcher { char pad0[20]; void *target; };
struct S19Cache { int words[2]; };
extern unsigned char lbl_8040db38[];
extern void *lbl_804b1754;
extern struct S19Dispatcher *lbl_804b1760;
extern struct S19Cache lbl_804aca0c;
extern void *FUN_801613f0(void *, int);
extern short w3d_cached_message_id(struct S19Cache *, int);
extern void w3d_message_dispatch(void *, void *, int);
struct S19Owner { char pad0[4]; int posted; };

int s19_post_message_80021898(struct S19Owner *p) {
    struct S19Message *m = (struct S19Message *)FUN_801613f0(lbl_804b1754, 8);
    m->id = w3d_cached_message_id(&lbl_804aca0c, 1);
    m->type = lbl_8040db38;
    w3d_message_dispatch(m, lbl_804b1760->target, 0);
    p->posted = 1;
    return 0;
}
