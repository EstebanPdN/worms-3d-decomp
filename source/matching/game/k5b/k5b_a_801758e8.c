struct K5bIface { void **vtable; };
struct K5bSlotTable {
    char head[20];
    int active;
    struct K5bIface **slots;
    char body[2064];
    unsigned int used;
    char mid[20];
    unsigned int capacity;
};
int w3d_k5b_slot_table_release_all_801758e8(struct K5bSlotTable *self)
{
    unsigned int i;
    for (i = 0; i < self->capacity; i++) {
        struct K5bIface **slots = self->slots;
        if (slots[i] != 0)
            ((void (*)(struct K5bIface *))slots[i]->vtable[4])(slots[i]);
        slots[i] = 0;
    }
    self->active = 0;
    self->used = self->capacity;
    return 0;
}
// desc: w3d_k5b_slot_table_release_all_801758e8: Appears to release every interface in the slot array at +24 through virtual slot 4, clear the slots, reset +20 and copy the capacity at +2116 to +2092.
