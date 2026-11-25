struct S19Entry { char pad0[12]; float weight; };
struct S19Registry { struct S19Entry **items; };
struct S19Mover { char pad0[4]; float pos; char pad8[36]; int entry; };
extern struct S19Registry *lbl_804aa750;
extern void FUN_80017380(struct S19Mover *);

void s19_advance_by_weight_800179ac(struct S19Mover *p) {
    p->pos = (*(struct S19Entry **)((char *)lbl_804aa750->items + (p->entry << 2)))->weight * 10.0f + p->pos;
    FUN_80017380(p);
}
