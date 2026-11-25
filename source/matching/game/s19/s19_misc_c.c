extern int w3d_auto_80178d1c(void *);
extern void s8_visibility_800a3c24(void *);

struct S19A { char pad0[96]; void *handle; };

int s19_handle_is_one_800a14f4(struct S19A *p) {
    return w3d_auto_80178d1c(p->handle) == 1;
}

struct S19Vis { char pad0[28]; int visible; };

void s19_visibility_hide_800a3bb4(struct S19Vis *p) {
    if (p->visible) {
        p->visible = 0;
        s8_visibility_800a3c24(p);
    }
}

void s19_visibility_show_800a3bec(struct S19Vis *p) {
    if (!p->visible) {
        p->visible = 1;
        s8_visibility_800a3c24(p);
    }
}

struct S19Mode { char pad0[44]; int mode; };

int s19_mode_is_two_800cfc98(struct S19Mode *p) {
    return p->mode == 2;
}

struct S19V3 { float x, y, z; };
struct S19Pts { char pad0[28]; struct S19V3 *items; };
struct S19PtsRec { char pad0[28]; char *items; };

struct S19V3 *s19_vec3_copy_800d0f74(struct S19V3 *dst, struct S19PtsRec *src, int i) {
    struct S19V3 *s = (struct S19V3 *)(src->items + i * 28);
    float x = s->x;
    float y = s->y;
    float z = s->z;
    dst->x = x;
    dst->y = y;
    dst->z = z;
    return dst;
}

struct S19Pair { char pad0[84]; struct S19V3 a; struct S19V3 b; };

void s19_set_vec_pair_800dc3dc(struct S19Pair *p, struct S19V3 *va, struct S19V3 *vb) {
    p->b = *va;
    p->a = *vb;
}

struct S19Inner { int x, y, z; };
struct S19Reset { int pad0; int a, b, pad12, c; struct S19Inner in; };

static inline void s19_clear_inner(struct S19Inner *q) {
    q->z = 0;
    q->y = 0;
    q->x = 0;
}

struct S19Reset *s19_reset_800b12c8(struct S19Reset *p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
    s19_clear_inner(&p->in);
    return p;
}
