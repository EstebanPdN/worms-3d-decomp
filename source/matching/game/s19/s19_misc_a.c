struct S19Cell { int a, b, c; };
struct S19Grid { char pad0[52]; int stride[2]; struct S19Cell *cells[2]; };

int *s19_grid_cell_ref4_800203a0(struct S19Grid *g, int k, int x, int y) {
    return &g->cells[k][x + y * g->stride[k]].b;
}

int *s19_grid_cell_ref8_800203cc(struct S19Grid *g, int k, int x, int y) {
    return &g->cells[k][x + y * g->stride[k]].c;
}

struct S19BitGrid { int base; char pad4[16]; int stride; };

void s19_bitgrid_set_8002c6dc(struct S19BitGrid *g, int x, int bit, int y) {
    ((unsigned *)g)[g->base + x + y * g->stride] |= 1u << bit;
}

void s19_bitgrid_clear_8002c70c(struct S19BitGrid *g, int x, int bit, int y) {
    ((unsigned *)g)[g->base + x + y * g->stride] &= ~(1u << bit);
}

struct S19Limit { char pad0[820]; float limit; };
extern int FUN_80035714(struct S19Limit *, float, void *);

void s19_limit_forward_800356e0(struct S19Limit *p, float v, float w, void * arg_r4) {
    if (v >= p->limit)
        FUN_80035714(p, w, arg_r4);
}

struct S19Rec { char pad0[213]; unsigned char kind; };
extern struct S19Rec *s8_index_query_800fc6dc(int);
extern int lbl_804aa6cc;

int s19_slot_matches_global_80015400(int index) {
    return s8_index_query_800fc6dc(index)->kind == lbl_804aa6cc;
}
