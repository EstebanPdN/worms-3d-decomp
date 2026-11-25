// desc: Appears to return minus one when a field of the linked record is zero, else the float at offset 208 of the record converted to an integer.
struct S21Record { char pad[160]; int valid; char pad1[44]; float value; };
struct S21Object { char pad[4]; struct S21Record *record; };
int w3d_s21_value_int_802e0c20(struct S21Object *self)
{
    struct S21Record *record = self->record;
    if (record->valid != 0)
        return (int)record->value;
    return -1;
}
