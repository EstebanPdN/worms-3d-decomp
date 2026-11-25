typedef struct K2aSlotInfo { char pad0[128]; int kind; unsigned int state; char pad88[84]; int valid; } K2aSlotInfo;
typedef struct K2aOwner { char pad0[84]; void *current; } K2aOwner;
extern void *w3d_empty_803426b4(void *);
extern unsigned int w3d_auto_80178c48(void *);
extern K2aSlotInfo *s8_index_query_800fc6dc(unsigned int);

int k2a_owner_state_set_8013e8f8(K2aOwner *self)
{
    unsigned int index = w3d_auto_80178c48(w3d_empty_803426b4(self->current));
    K2aSlotInfo *info;
    if (index > 15)
        return 0;
    info = s8_index_query_800fc6dc(index);
    if (info->valid == 0)
        return 0;
    if (info->kind != 10)
        return 0;
    switch (info->state) {
    case 0: case 1: case 2: case 5: case 6: case 8: case 9: case 0x12: case 0x18:
        return 1;
    default:
        return 0;
    }
}
