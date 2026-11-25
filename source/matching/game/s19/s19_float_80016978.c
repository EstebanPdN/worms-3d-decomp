struct S19Item { char pad0[4]; float weight; char pad8[4]; int owner; };
struct S19List { struct S19Item **begin; struct S19Item **end; };
extern struct S19List *lbl_804aa700;
extern int lbl_804aa6c0;
float s19_owner_weight_inverse_80016978(void) {
    float sum = 0.0f;
    struct S19List *l = lbl_804aa700;
    struct S19Item **b = l->begin;
    int n = l->end - b;
    int i;
    for (i = 0; i < n; i++) {
        struct S19Item *e = b[i];
        if (lbl_804aa6c0 == e->owner)
            sum += e->weight;
    }
    return 1.0f / (sum * 5.0f + 1.0f);
}
