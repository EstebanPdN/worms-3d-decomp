// desc: Appears to increment or decrement the counter of a slot below twenty depending on a flag argument.
struct S21Slots { char pad[220]; int slots[20]; };
void w3d_s21_adjust_slot_80264658(struct S21Slots *self, int increment, unsigned index)
{
    if (index > 19)
        return;
    if (increment == 1)
        self->slots[index]++;
    else
        self->slots[index]--;
}
