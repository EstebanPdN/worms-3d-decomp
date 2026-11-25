// desc: Appears to return the word at an index of the array pointed to at offset 28.
struct S21Table { char pad[28]; int *items; };
int w3d_s21_table_item_802071e0(struct S21Table *self, int index)
{
    return self->items[index];
}
