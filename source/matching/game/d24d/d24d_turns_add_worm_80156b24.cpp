// d24d: 0x80156b24 (1092 bytes). Add a worm to the turn tables unless it already
// has an actor (+312, -1 means none): create an actor through the service
// 0x8020b680, store the worm id in it (+584) and register it (0x80164514, owner
// +20). A live worm (+188 == 1) joins its team's list (+52), and the team joins
// the list (+100) chosen by the team record's index byte unless already present.
// Then applies the worm's scene value (0x80158810), gathers two local lists
// (0x80158358, declared with its status return) and processes them (0x80157c58).
// The first list is cleared explicitly before both are released.
#include "d24d_int_list_range.h"
struct d24d_LocalList : d24d_RangeList {
    d24d_LocalList() { end = 0; finish = 0; start = 0; }
    ~d24d_LocalList() { if (start) d24d_storage_release_802134fc(start); }
};
struct d24d_Queue : d24d_RangeList { int *last() { return finish; } };
struct d24d_WormInfo { char pad[108]; char scene[80]; int live; char pad2[21]; unsigned char team; };
struct d24d_TeamRecord { char pad[60]; unsigned char index; };
struct d24d_Actor { char pad[584]; unsigned worm; };
struct d24d_Turns;
extern "C" d24d_WormInfo *d24d_worm_info_800fc6dc(unsigned);
extern "C" d24d_TeamRecord *d24d_team_record_800fc7f8(unsigned);
extern "C" d24d_Actor *d24d_create_actor_8020b680(unsigned char *);
extern "C" int d24d_register_actor_80164514(void *, d24d_Actor *, int);
extern "C" void d24d_turns_apply_scene_80158810(d24d_Turns *, char *);
extern "C" int d24d_turns_gather_80158358(d24d_Turns *, d24d_LocalList *, d24d_LocalList *);
extern "C" void d24d_turns_process_80157c58(d24d_Turns *, unsigned, d24d_LocalList *, d24d_LocalList *);
extern void *d24d_registry_804b178c;
extern unsigned char d24d_actor_id_80410ef0[];
struct d24d_Turns { char pad[20]; int owner; char pad1[28]; d24d_RangeList lists[4]; d24d_Queue other[4]; char pad2[164]; int actors[16]; };
extern "C" void d24d_turns_add_worm_80156b24(d24d_Turns *self, unsigned i) {
    if (self->actors[i] != -1) return;
    d24d_WormInfo *w = d24d_worm_info_800fc6dc(i);
    d24d_Actor *a = d24d_create_actor_8020b680(d24d_actor_id_80410ef0);
    a->worm = i;
    self->actors[i] = d24d_register_actor_80164514(d24d_registry_804b178c, a, self->owner);
    if (w->live == 1) {
        self->lists[w->team].push_back(i);
        unsigned team = w->team;
        int idx = d24d_team_record_800fc7f8(team)->index;
        if (self->other[idx].empty()) self->other[idx].push_back(team);
        else {
            int found = 0;
            for (int *p = self->other[idx].begin(); p != self->other[idx].last(); ++p) if (*p == (int)team) found = 1;
            if (found != 1) self->other[idx].push_back(team);
        }
    }
    d24d_turns_apply_scene_80158810(self, w->scene);
    d24d_LocalList x, y;
    d24d_turns_gather_80158358(self, &x, &y);
    d24d_turns_process_80157c58(self, i, &x, &y);
    x.clear();
}
