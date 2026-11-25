/* Handle table lookup, bounds-checked vector read and service forwarding. */
typedef struct S20Slot { char pad0[12]; void *object; char pad1[4]; int id; char pad3[12]; } S20Slot;
typedef struct S20SlotVector { S20Slot *slots; } S20SlotVector;
typedef struct S20HandleTable { char pad[28]; S20SlotVector *vector; } S20HandleTable;
extern S20HandleTable *lbl_804b178c;

void *w3d_s20_lookup_handle_object_80164fc8(int handle) {
    S20HandleTable *table = lbl_804b178c;
    S20SlotVector *vector = table->vector;
    S20Slot *found;
    if (handle == -1) {
        found = 0;
    } else {
        S20Slot *slot = vector->slots + (handle & 4095);
        found = slot->id == handle ? slot : 0;
    }
    if (found == 0)
        return 0;
    return found->object;
}

int w3d_s20_get_vector_item_800ffca4(char *self, unsigned int index, int *out) {
    int *begin = *(int **)(self + 4);
    unsigned int count = (*(int *)(self + 8) - (int)begin) >> 2;
    if (index < count) {
        { unsigned int offset = index << 2; *out = *(int *)((char *)begin + offset); }
        return 0;
    }
    return 0x80004005;
}

typedef struct S20Registry { int words[4]; } S20Registry;
extern S20Registry *lbl_804b1754;

S20Registry *w3d_s20_init_registry_8016130c(S20Registry *self) {
    self->words[0] = 0;
    self->words[1] = 0;
    self->words[2] = 0;
    self->words[3] = 0;
    lbl_804b1754 = self;
    return self;
}
