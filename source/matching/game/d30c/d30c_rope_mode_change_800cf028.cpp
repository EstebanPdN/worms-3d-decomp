// d30c: 0x800cf028. Switches the rope out of or into its active mode: posts the named messages, resets its motion fields and clears the point list. Names are inferred; classes are partial views.
struct V { float x, y, z; };
extern "C" void *memcpy_802eee50(...);
struct Trail {
    char *start, *finish, *eos;
    void clear() { char *last = finish; int n = last - start; memcpy_802eee50(start, last, 0); finish -= n; }
};
struct Rope {
    char u0[28]; Trail trail; char u40[4]; int mode; int count; char u52[12]; V v64; char u76[12]; int u88; int u92; float u96; char u100[8]; float u108; char u112[12]; int started; char u128[168]; V v296;
};
struct Msg8 { unsigned short id; void *vt; };
extern void *heap_804b1754;
extern int id_804ae938, id_804ae960, id_804ae970, id_804ae950, id_804ae948, id_804ae968, id_804ae978, id_804ae8c8;
extern char vt_8040db38[], fire_803880a8[], ufire_803880b0[];
extern V zero_8045e788[];
extern "C" void show_800cf2e8(Rope *);
extern "C" void exit_800d0e60(Rope *);
extern "C" void enter_800d0d6c(Rope *);
extern "C" void vel_800d0fa0(Rope *);
extern "C" V campos_800cfcac(Rope *);
extern "C" void *alloc_801613f0(void *, int);
extern "C" short msg_id_8015f5a0(void *, int);
extern "C" void *init_80126000(void *, unsigned short, const V &);
extern "C" void *init_8010a8e0(void *, unsigned short, const char *);
extern "C" int post_8016239c(void *);
inline void post8(int *id) {
    Msg8 *m = (Msg8 *)alloc_801613f0(heap_804b1754, 8);
    m->id = msg_id_8015f5a0(id, 1);
    m->vt = vt_8040db38;
    post_8016239c(m);
}
extern "C" void d30c_rope_mode_change_800cf028(Rope *self) {
    int started = self->started;
    if (started == 0) {
        int mode = self->mode;
        self->started = 1;
        if (mode == 0) {
            if (self->count > 0 || self->count == -1) {
                self->mode = 1;
                show_800cf2e8(self);
                exit_800d0e60(self);
                post_8016239c(init_80126000(alloc_801613f0(heap_804b1754, 20), msg_id_8015f5a0(&id_804ae938, 1), campos_800cfcac(self)));
                post8(&id_804ae960);
                post8(&id_804ae970);
                self->v296 = zero_8045e788[0];
            }
        } else {
            if (mode == 2) {
                vel_800d0fa0(self);
                post_8016239c(init_8010a8e0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&id_804ae950, 1), fire_803880a8));
                post_8016239c(init_8010a8e0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&id_804ae948, 1), ufire_803880b0));
            }
            self->mode = started;
            post8(&id_804ae968);
            post8(&id_804ae978);
            if (self->count == 0) post8(&id_804ae8c8);
            self->u88 = started;
            float k = 0.0f;
            self->u92 = started;
            self->u96 = k;
            self->u108 = k;
            self->v64 = zero_8045e788[0];
            enter_800d0d6c(self);
            self->trail.clear();
        }
    }
}
