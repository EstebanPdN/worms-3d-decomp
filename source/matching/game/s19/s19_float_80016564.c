struct S19Entry { char pad0[8]; int owner; };
struct S19Registry { struct S19Entry **items; };
struct S19Link { char pad0[8]; int target; int group; int owner; };
struct S19Probe { char pad0[16]; int entry; int target; };
extern struct S19Registry *lbl_804aa750;
extern int lbl_804aa6c0;

float s19_pair_factor_80016564(struct S19Link *a, struct S19Probe *b) {
    if (lbl_804aa6c0 != a->group
        || (*(struct S19Entry **)((char *)lbl_804aa750->items + (b->entry << 2)))->owner != a->owner)
        return 0.0f;
    if (b->target != a->target)
        return 0.2f;
    return 1.0f;
}
