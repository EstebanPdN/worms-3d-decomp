#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4a_countdown_tick_8004d044.c"
struct K4aHeld;
typedef struct K4aHeldVtable { Ptr32<void (void)> unknown_00[4]; Ptr32<void (Ptr32<struct K4aHeld>)> release; } K4aHeldVtable;
typedef struct K4aHeld { Ptr32<const K4aHeldVtable> vtable; } K4aHeld;
typedef struct K4aTeamRecord { char pad0[213]; unsigned char team; } K4aTeamRecord;
typedef struct K4aTick { char pad0[8]; int source; int amount; } K4aTick;
typedef struct K4aCountdown { char pad0[20]; int source; char pad1[48]; int remaining; char pad2[48]; int active; char pad3[12]; int team_filter; char pad4[100]; Ptr32<K4aHeld> held; } K4aCountdown;
extern char w3d_string_803772bc[];
extern int w3d_auto_800fc1f0(Ptr32<Ptr32<const char>> name, Ptr32<int> value);
extern Ptr32<K4aTeamRecord> s8_index_query_800fc6dc(int index);
extern void FUN_8004c850(Ptr32<K4aCountdown> self);

void k4a_countdown_tick_8004d044(Ptr32<K4aCountdown> self, Ptr32<K4aTick> tick)
{
    if (self->active == 0) {
        if (self->team_filter != -1) {
            Ptr32<const char> name;
            int index;
            name = w3d_string_803772bc;
            w3d_auto_800fc1f0(&name, &index);
            if (s8_index_query_800fc6dc(index)->team != self->team_filter)
                return;
        }
        if (tick->source == self->source) {
            self->remaining -= tick->amount;
            if (self->remaining <= 0)
                FUN_8004c850(self);
        }
        if (self->held != 0)
            self->held->vtable->release(self->held);
        self->held = 0;
    }
}

}
