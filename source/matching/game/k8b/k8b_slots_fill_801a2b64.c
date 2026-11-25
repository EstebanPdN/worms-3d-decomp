struct K8bSlot { char pad0[20]; unsigned short index; };
struct K8bSlotVector { struct K8bSlot **begin; struct K8bSlot **end; };
struct K8bSlotOwner { char pad0[36]; struct K8bSlotVector slots; };
struct K8bSlotTable { char pad0[20]; struct K8bSlot **defaults; };
extern struct K8bSlotTable *lbl_804ab74c;
static inline unsigned k8b_slot_count(struct K8bSlotVector *v) { return v->end - v->begin; }

int w3d_k8b_slots_fill_801a2b64(struct K8bSlotOwner *self, struct K8bSlot **items, unsigned count)
{
    unsigned i;
    unsigned j;
    int off;
    struct K8bSlotTable *table;
    for (i = 0; i < k8b_slot_count(&self->slots); i++) {
        table = lbl_804ab74c;
        off = i * 4;
        *(struct K8bSlot **)((char *)self->slots.begin + off) = *(struct K8bSlot **)((char *)table->defaults + off);
    }
    for (j = 0; j < count; j++) {
        struct K8bSlot *item = *items++;
        *(struct K8bSlot **)((char *)self->slots.begin + (item->index << 2)) = item;
    }
    return 0;
}
