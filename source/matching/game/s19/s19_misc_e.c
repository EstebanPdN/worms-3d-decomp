struct S19Svc;
struct S19SvcVT { char pad0[100]; void (*queue)(struct S19Svc *, void *, int); };
struct S19Svc { struct S19SvcVT *vt; };
struct S19Ctx { char pad0[108]; struct S19Svc *svc; };
struct S19Slot { int handle; };
struct S19Pair { char pad0[28]; struct S19Slot a; struct S19Slot b; };
extern struct S19Ctx *lbl_804b1788;
static inline void s19_q(struct S19Slot *s) {
    if (s->handle)
        lbl_804b1788->svc->vt->queue(lbl_804b1788->svc, s, 1000);
}
void s19_notify_two_8002a040(struct S19Pair *p) {
    s19_q(&p->a);
    s19_q(&p->b);
}
