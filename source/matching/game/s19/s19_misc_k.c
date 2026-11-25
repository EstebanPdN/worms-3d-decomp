struct S19Entry { char pad0[12]; float weight; };
struct S19Registry { struct S19Entry **items; };
struct S19Globals { char pad0[96]; float scale; char pad100[328]; float damp; };
struct S19Unit { char pad0[4]; float pos; char pad8[8]; int entry; char pad20[80]; float rate; };
extern struct S19Registry *lbl_804aa750;
extern struct S19Globals *lbl_804aa6d8;
extern void w3d_auto_8000b2f8(struct S19Unit *, int);
extern int w3d_cached_name_lookup_80341710(struct S19Unit *, int);

void s19_unit_step_8000d568(struct S19Unit *p) {
    w3d_auto_8000b2f8(p, 0);
    w3d_cached_name_lookup_80341710(p, 1);
    p->pos = (*(struct S19Entry **)((char *)lbl_804aa750->items + (p->entry << 2)))->weight * lbl_804aa6d8->scale + p->pos;
    p->pos = p->pos * lbl_804aa6d8->damp * p->rate;
}
