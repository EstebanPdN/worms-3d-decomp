struct K4aHeld;
typedef struct K4aHeldVtable { void (*unknown_00[4])(void); void (*release)(struct K4aHeld *self); } K4aHeldVtable;
typedef struct K4aHeld { const K4aHeldVtable *vtable; } K4aHeld;
typedef struct K4aTeamRecord { char pad0[213]; unsigned char team; } K4aTeamRecord;
typedef struct K4aTick { char pad0[8]; int source; int amount; } K4aTick;
typedef struct K4aCountdown { char pad0[20]; int source; char pad1[48]; int remaining; char pad2[48]; int active; char pad3[12]; int team_filter; char pad4[100]; K4aHeld *held; } K4aCountdown;
extern char w3d_string_803772bc[];
extern int w3d_auto_800fc1f0(const char **name, int *value);
extern K4aTeamRecord *s8_index_query_800fc6dc(int index);
extern void FUN_8004c850(K4aCountdown *self);

void k4a_countdown_tick_8004d044(K4aCountdown *self, K4aTick *tick)
{
    if (self->active == 0) {
        if (self->team_filter != -1) {
            const char *name;
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
