// desc: Appears to return the word at an index of the counted array inside the object at offset 20, or zero when the index is out of range.
struct S21Array { char pad[24]; unsigned count; char pad1[4]; int items[1]; };
struct S21Holder { char pad[20]; struct S21Array *array; };
int w3d_s21_get_item_8021eb48(struct S21Holder *self, unsigned index)
{
    struct S21Array *array = self->array;
    int *items = array->items;
    if (index < array->count)
        return items[index];
    return 0;
}
