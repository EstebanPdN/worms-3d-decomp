// d24d: 0x80157afc (348 bytes). Rebuild per-worm handles: gather two local lists
// (0x80158358), construct 16 eight-byte handle members (ctor 0x80126184, stride
// witnessed by the array loop), and for each worm process the lists (0x80157c58)
// and configure its handle: word 0 (0x8012632c), slot word 1 (0x801262e4), the
// float 10.0 (0x8012629c, this function's pool) and the worm's field +80
// (0x801262c0). Then clears the first list, destroys the handles (0x80126230,
// in-charge 0) in reverse order and releases both lists.
#include "d24d_int_list_range.h"
struct d24d_LocalList : d24d_RangeList {
    d24d_LocalList() { end = 0; finish = 0; start = 0; }
    ~d24d_LocalList() { if (start) d24d_storage_release_802134fc(start); }
};
struct d24d_HandleMember {
    int a, b;
    d24d_HandleMember();
    ~d24d_HandleMember();
};
struct d24d_WormInfo { char pad[80]; int value; };
struct d24d_Turns;
extern "C" int d24d_turns_gather_80158358(d24d_Turns *, d24d_LocalList *, d24d_LocalList *);
extern "C" void d24d_turns_process_80157c58(d24d_Turns *, unsigned, d24d_LocalList *, d24d_LocalList *);
extern "C" d24d_WormInfo *d24d_worm_info_800fc6dc(unsigned);
extern "C" void d24d_member_set_word_8012632c(d24d_HandleMember *, int);
extern "C" void d24d_member_set_slot_801262e4(d24d_HandleMember *, int);
extern "C" void d24d_member_set_float_8012629c(d24d_HandleMember *, float);
extern "C" void d24d_member_set_field_801262c0(d24d_HandleMember *, int *);
extern "C" void d24d_turns_rebuild_80157afc(d24d_Turns *self) {
    d24d_LocalList x, y;
    d24d_turns_gather_80158358(self, &x, &y);
    d24d_HandleMember m[16];
    for (unsigned i = 0; i <= 15; i++) {
        d24d_turns_process_80157c58(self, i, &x, &y);
        d24d_WormInfo *w = d24d_worm_info_800fc6dc(i);
        d24d_member_set_word_8012632c(&m[i], 0);
        d24d_member_set_slot_801262e4(&m[i], 1);
        d24d_member_set_float_8012629c(&m[i], 10.0f);
        d24d_member_set_field_801262c0(&m[i], &w->value);
    }
    x.clear();
}
