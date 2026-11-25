// d24i: 0x8012f77c (472 bytes). Finish a pending bounds selection (+76 set). Clears
// +16 of the object at +172, stores the component-wise minimum and maximum of the
// corners +188 and +200 in the globals 0x804668d0 and 0x804668dc, posts the arena
// messages 0x804af6a4, 0x804af66c (with the shared text 0x8039d9b0) and 0x804af664,
// selects slot 3 (0x800a7e14), clears +76 and updates the value at +60 with 0.
struct d24i_Vec3 { float x, y, z; };
static inline const float &d24i_min(const float &a, const float &b) { return b < a ? b : a; }
static inline const float &d24i_max(const float &a, const float &b) { return a < b ? b : a; }
struct d24i_Notification {
    unsigned short id;
    const void *vtable;
};
struct d24i_Selection {
    unsigned char unknown00[60];
    void *value;                         // +60
    unsigned char unknown40[12];
    int pending;                         // +76
    unsigned char unknown50[92];
    int *target;                         // +172, a record whose +16 is cleared
    unsigned char unknownb0[12];
    d24i_Vec3 first;                     // +188
    d24i_Vec3 second;                    // +200
};
struct d24i_Marker {
    unsigned char unknown00[16];
    int active;                          // +16
};
extern "C" void *d24i_arena_alloc_801613f0(void *, int);
extern "C" int d24i_cached_id_8015f5a0(void *, int);
extern "C" int d24i_post_8016239c(void *);
extern "C" void *d24i_text_message_8010a8e0(void *, unsigned short, const char *);
extern "C" void d24i_select_slot_800a7e14(int, int);
extern "C" int d24i_update_value_80178d28(void *, int *);
extern void *d24i_arena_804b1754;
extern unsigned int d24i_message_804af6a4, d24i_message_804af66c, d24i_message_804af664;
extern const void *const d24i_notification_vtable_8040db38[];
extern const char d24i_text_8039d9b0[];
extern d24i_Vec3 d24i_low_804668d0[], d24i_high_804668dc[];

extern "C" void d24i_select_bounds_finish_8012f77c(d24i_Selection *self) {
    if (self->pending) {
        int none = 0;
        ((d24i_Marker *)self->target)->active = none;
        d24i_low_804668d0[0].x = d24i_min(self->first.x, self->second.x);
        d24i_Vec3 *low = d24i_low_804668d0;
        low->y = d24i_min(self->first.y, self->second.y);
        low->z = d24i_min(self->first.z, self->second.z);
        d24i_high_804668dc[0].x = d24i_max(self->first.x, self->second.x);
        d24i_Vec3 *high = d24i_high_804668dc;
        high->y = d24i_max(self->first.y, self->second.y);
        high->z = d24i_max(self->first.z, self->second.z);
        {
            d24i_Notification *note = (d24i_Notification *)d24i_arena_alloc_801613f0(d24i_arena_804b1754, 8);
            note->id = d24i_cached_id_8015f5a0(&d24i_message_804af6a4, 1);
            note->vtable = d24i_notification_vtable_8040db38;
            d24i_post_8016239c(note);
        }
        d24i_post_8016239c(d24i_text_message_8010a8e0(d24i_arena_alloc_801613f0(d24i_arena_804b1754, 12),
            d24i_cached_id_8015f5a0(&d24i_message_804af66c, 1), d24i_text_8039d9b0));
        {
            d24i_Notification *note = (d24i_Notification *)d24i_arena_alloc_801613f0(d24i_arena_804b1754, 8);
            note->id = d24i_cached_id_8015f5a0(&d24i_message_804af664, 1);
            note->vtable = d24i_notification_vtable_8040db38;
            d24i_post_8016239c(note);
        }
        d24i_select_slot_800a7e14(3, 0);
        self->pending = none;
        int zero = none;
        d24i_update_value_80178d28(self->value, &zero);
    }
}
