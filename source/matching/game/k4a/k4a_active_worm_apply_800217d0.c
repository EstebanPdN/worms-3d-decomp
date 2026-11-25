typedef struct K4aTeamRecord { char pad0[112]; int value; } K4aTeamRecord;
typedef struct K4aSetter { char pad0[4]; int flag; char pad1[16]; float amount; } K4aSetter;
extern char w3d_string_active_worm_index_8036c014[];
extern int w3d_auto_800fc1f0(const char **name, int *value);
extern K4aTeamRecord *s8_index_query_800fc6dc(int index);

int k4a_active_worm_apply_800217d0(K4aSetter *self)
{
    const char *name;
    int index;
    name = w3d_string_active_worm_index_8036c014;
    w3d_auto_800fc1f0(&name, &index);
    s8_index_query_800fc6dc(index)->value = (int)self->amount;
    self->flag = 1;
    return 0;
}
