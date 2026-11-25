// d24d: 0x8014dd18 (264 bytes). Update motion from the tracked object (+788): an
// empty handle returns 0, a stale one is cleared. In the object's mode two
// (0x800cfc98) adjust the motion (0x800cfe68 with +560, +676, +572) and return
// the mode result. Otherwise, with +716 set or +824 negative, an active object
// (+120) gets a posted message and 0 is returned; if neither holds, the object's
// speed (+268) times 20.0 * 0.5 is added to +572. Names are inferred.
struct d24d_Message { unsigned short id; void *data; };
struct d24d_Tracked { char pad[120]; int active; char pad2[144]; float speed; };
extern "C" d24d_Tracked *d24d_lookup_80164fc8(int);
extern "C" int d24d_mode_two_800cfc98(d24d_Tracked *);
extern "C" void d24d_adjust_motion_800cfe68(d24d_Tracked *, void *, void *, void *);
extern void *d24d_arena_804b1754;
extern int d24d_message_key_804afbf8;
extern "C" d24d_Message *d24d_arena_alloc_801613f0(void *, int);
extern "C" unsigned short d24d_message_id_8015f5a0(int *, int);
extern "C" int d24d_message_post_8016239c(d24d_Message *);
extern char d24d_message_vtable_8040db38[];
struct d24d_Motion { char pad[560]; char a[12]; float y; char pad2[100]; char b[40]; int f716; char pad3[68]; int target; char pad4[32]; int f824; };
extern "C" int d24d_follow_target_8014dd18(d24d_Motion *self) {
    int result;
    if (self->target == -1) { result = 0; goto done; }
    {
    d24d_Tracked *e = d24d_lookup_80164fc8(self->target);
    if (!e) { self->target = -1; result = 0; goto done; }
    int r = d24d_mode_two_800cfc98(e);
    if (r) {
        d24d_adjust_motion_800cfe68(e, self->a, self->b, &self->y);
    } else if (self->f716 != 0 || self->f824 < 0) {
        if (e->active) {
            d24d_Message *m = d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
            m->id = d24d_message_id_8015f5a0(&d24d_message_key_804afbf8, 1);
            m->data = d24d_message_vtable_8040db38;
            d24d_message_post_8016239c(m);
            result = 0; goto done;
        }
    } else {
        self->y = e->speed * 20.0f * 0.5f + self->y;
    }
    result = r;
    }
 done:
    return result;
}
