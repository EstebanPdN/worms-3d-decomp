struct K2bSlot { int id; float weight; };
struct K2bSlotTable { struct K2bSlot *slots; int count; int head; float total; int cursor; int last; };
void w3d_k2b_slot_table_reset_8015cfa0(struct K2bSlotTable *t)
{
    int i;
    if (t->slots != 0) {
        for (i = 0; i < t->count; i++) {
            t->slots[i].weight = 0.0f;
            t->slots[i].id = 0;
        }
    }
    t->head = 0;
    t->cursor = 0;
    t->last = -1;
    t->total = 0.0f;
}
// desc: Appears to clear every slot of a table to zero weight and reset its cursor, total and head fields.
