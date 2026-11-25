extern void w3d_auto_800158b8(float *p, float v);

void s19_randomize_three_80015910(float *p, float v) {
    w3d_auto_800158b8(p, v);
    w3d_auto_800158b8(p + 1, v);
    w3d_auto_800158b8(p + 2, v);
}

struct S19Poll;
struct S19PollVT { char pad0[8]; int (*ready)(struct S19Poll *); };
struct S19Poll { char pad0[12]; struct S19PollVT *vt; };
extern void FUN_80015f80(struct S19Poll *);
extern void FUN_80016494(struct S19Poll *);

void s19_poll_then_80015f38(struct S19Poll *p) {
    if (p->vt->ready(p))
        FUN_80015f80(p);
}

void s19_poll_then_8001644c(struct S19Poll *p) {
    if (p->vt->ready(p))
        FUN_80016494(p);
}
