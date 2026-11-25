typedef struct K4aTeamRecord { char pad0[213]; unsigned char team; } K4aTeamRecord;
typedef struct K4aCountdown { char pad0[72]; int remaining; char pad1[48]; int active; char pad2[12]; int team_filter; } K4aCountdown;
extern char w3d_string_803772bc[];
extern int w3d_auto_800fc1f0(const char **name, int *value);
extern K4aTeamRecord *s8_index_query_800fc6dc(int index);
extern void FUN_8004c850(K4aCountdown *self);

void k4a_countdown_step_8004cc60(K4aCountdown *self, float amount)
{
    if (self->team_filter != -1) {
        struct { const char *name; int index; int gap[2]; } local;
        local.name = w3d_string_803772bc;
        w3d_auto_800fc1f0(&local.name, &local.index);
        if (s8_index_query_800fc6dc(local.index)->team != self->team_filter)
            return;
    }
    self->remaining -= (int)amount;
    if (self->remaining <= 0 && self->active == 0)
        FUN_8004c850(self);
}
