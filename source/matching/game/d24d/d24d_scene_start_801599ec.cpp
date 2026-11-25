// d24d: 0x801599ec (568 bytes). Scene start for the sender object: sets +64 and
// +68 to 1, saves the global flag 0x804ab40c in +72 and sets it, posts four plain
// messages (cached ids), then acquires nine pooled messages (0x80162024) into the
// references +28..+60, and posts a final 12-byte message built by 0x800c1620 from
// the value at +20, wrapped in a one-word temporary. Each cached id is a temporary short passed by const reference.
extern void *d24d_arena_804b1754;
extern "C" void *d24d_arena_alloc_801613f0(void *, int);
extern "C" unsigned short d24d_message_id_8015f5a0(int *, int);
extern "C" int d24d_message_post_8016239c(void *);
struct d24d_Value { int value; d24d_Value(int v) { value = v; } };
extern "C" void *d24d_value_message_800c1620(void *, const d24d_Value &);
extern char d24d_message_vtable_8040db38[];
extern int d24d_flag_804ab40c;
extern int d24d_key_804aff88;
extern int d24d_key_804aff90;
extern int d24d_key_804affa0;
extern int d24d_key_804affa8;
extern int d24d_key_804affb0;
extern int d24d_key_804affb8;
extern int d24d_key_804affd0;
extern int d24d_key_804affd8;
extern int d24d_key_804affe0;
extern int d24d_key_804affe8;
extern int d24d_key_804b0008;
extern int d24d_key_804b0010;
struct d24d_Message { unsigned short id; void *data; };
struct d24d_Scene;
extern "C" int d24d_acquire_message_80162024(d24d_Scene *, const unsigned short &, void **);
struct d24d_Scene {
    unsigned char unknown00[20];
    int value;                           // +20
    unsigned char unknown18[4];
    void *refs[9];                       // +28
    int started_a;                       // +64
    int started_b;                       // +68
    int saved_flag;                      // +72
};

extern "C" void d24d_scene_start_801599ec(d24d_Scene *self) {
    self->started_b = 1;
    self->started_a = 1;
    {
        d24d_Message *m = (d24d_Message *)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
        m->id = d24d_message_id_8015f5a0(&d24d_key_804affd0, 1);
        m->data = d24d_message_vtable_8040db38;
        d24d_message_post_8016239c(m);
    }
    self->saved_flag = d24d_flag_804ab40c;
    d24d_flag_804ab40c = 1;
    {
        d24d_Message *m = (d24d_Message *)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
        m->id = d24d_message_id_8015f5a0(&d24d_key_804affe8, 1);
        m->data = d24d_message_vtable_8040db38;
        d24d_message_post_8016239c(m);
    }
    {
        d24d_Message *m = (d24d_Message *)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
        m->id = d24d_message_id_8015f5a0(&d24d_key_804b0010, 1);
        m->data = d24d_message_vtable_8040db38;
        d24d_message_post_8016239c(m);
    }
    {
        d24d_Message *m = (d24d_Message *)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
        m->id = d24d_message_id_8015f5a0(&d24d_key_804b0008, 1);
        m->data = d24d_message_vtable_8040db38;
        d24d_message_post_8016239c(m);
    }
    d24d_acquire_message_80162024(self, d24d_message_id_8015f5a0(&d24d_key_804aff88, 1), &self->refs[0]);
    d24d_acquire_message_80162024(self, d24d_message_id_8015f5a0(&d24d_key_804aff90, 1), &self->refs[1]);
    d24d_acquire_message_80162024(self, d24d_message_id_8015f5a0(&d24d_key_804affa0, 1), &self->refs[2]);
    d24d_acquire_message_80162024(self, d24d_message_id_8015f5a0(&d24d_key_804affa8, 1), &self->refs[3]);
    d24d_acquire_message_80162024(self, d24d_message_id_8015f5a0(&d24d_key_804affb8, 1), &self->refs[4]);
    d24d_acquire_message_80162024(self, d24d_message_id_8015f5a0(&d24d_key_804affb0, 1), &self->refs[5]);
    d24d_acquire_message_80162024(self, d24d_message_id_8015f5a0(&d24d_key_804affd8, 1), &self->refs[6]);
    d24d_acquire_message_80162024(self, d24d_message_id_8015f5a0(&d24d_key_804affe0, 1), &self->refs[7]);
    d24d_acquire_message_80162024(self, d24d_message_id_8015f5a0(&d24d_key_804affd0, 1), &self->refs[8]);
    void *last = d24d_arena_alloc_801613f0(d24d_arena_804b1754, 12);
    d24d_message_post_8016239c(d24d_value_message_800c1620(last, self->value));
}
