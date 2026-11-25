/* Land damage accumulator (0x8009d430): adds the amount to the entry of the current
 * cell (globals 0x804b17a8, 0x804b17ac) in the list at +56; when the total or a new
 * amount reaches the limit, posts the land clear message (0x801040d0) and the blast
 * message at the position 0x8043ae20 (0x800b92a4) and returns 1, otherwise stores a new
 * 16-byte entry. Field and type names are inferred from the original instructions.
 * Owns its float literals at 0x803802a0. */
extern "C" char *w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(void *);
extern "C" void *w3d_copy_802eee50(...);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct Vec3 {
    float x, y, z;
    Vec3(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; }
};
struct Entry { char unknown00[4]; int x; int y; float amount; };
struct EntryList {
    Entry **begin, **end, **capacity;
    Entry **End() const { return end; }
    void push(Entry *const &value) {
        if (end == capacity) {
            unsigned old = (char *)end - (char *)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 2;
            char *p = w3d_allocate_80212fd4(bytes);
            if (begin) {
                w3d_copy_802eee50(p, begin, minimum(bytes, old));
                w3d_release_802134fc(begin);
            }
            begin = (Entry **)p;
            end = (Entry **)(p + old);
            capacity = (Entry **)(p + bytes);
        }
        *end = value;
        end++;
    }
};
struct LandDamage { char unknown00[56]; EntryList entries; };
extern Vec3 w3d_position_8043ae20;
extern int w3d_cell_x_804b17a8, w3d_cell_y_804b17ac;
extern void *w3d_message_arena_804b1754;
extern char w3d_pool_804af5bc[8];
extern "C" void *w3d_arena_alloc_801613f0(void *, int);
extern "C" void *w3d_heap_allocate_802098d8(void *, int);
extern "C" void *w3d_land_clear_801040d0(void *, int, int);
extern "C" void *w3d_blast_800b92a4(void *, Vec3, float);
extern "C" int w3d_message_post_8016239c(void *);

inline Entry *AllocEntry() { return (Entry *)w3d_heap_allocate_802098d8(w3d_pool_804af5bc, 16); }

extern "C" int w3d_d24b_land_damage_add_8009d430(LandDamage *self, float amount)
{
    Vec3 position(w3d_position_8043ae20);
    int x = w3d_cell_x_804b17a8;
    int y = w3d_cell_y_804b17ac;
    Entry **p = self->entries.begin;
    Entry **e = self->entries.End();
    for (; p != self->entries.End(); p++) {
        if ((*p)->x == x) {
            (*p)->amount += amount;
            if ((*p)->amount >= 15.0f) {
                w3d_message_post_8016239c(w3d_land_clear_801040d0(w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8), (*p)->x, (*p)->y));
                w3d_message_post_8016239c(w3d_blast_800b92a4(w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 24), position, 10.0f));
                (*p)->amount = 0.0f;
                return 1;
            }
            return 0;
        }
    }
    if (amount >= 15.0f) {
        w3d_message_post_8016239c(w3d_land_clear_801040d0(w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8), x, y));
        w3d_message_post_8016239c(w3d_blast_800b92a4(w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 24), position, 10.0f));
        return 1;
    }
    Entry *entry = AllocEntry();
    entry->x = x;
    entry->y = y;
    entry->amount = amount;
    self->entries.push(entry);
    return 1;
}
