struct S19Obj;
struct S19ObjVT { char pad0[20]; void (*slot5)(struct S19Obj *); };
struct S19Obj { struct S19ObjVT *vt; };
struct S19Lookup;
struct S19LookupVT { char pad0[92]; void (*find)(struct S19Lookup *, const char *, struct S19Obj **); };
struct S19Lookup { struct S19LookupVT *vt; };
struct S19Ctx { char pad0[108]; struct S19Lookup *lookup; };
struct S19Holder { char pad0[860]; struct S19Obj *target; };
extern struct S19Ctx *lbl_804b1788;

void s19_no_target_800358b4(struct S19Holder *p) {
    struct S19Lookup *l = lbl_804b1788->lookup;
    if (l) {
        l->vt->find(l, "NoTargetAquired", &p->target);
        p->target->vt->slot5(p->target);
    }
}
