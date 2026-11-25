// desc: Appears to store the low bit of the argument into the top bit of the flag word at offset 8.
struct S21Flags { unsigned top : 1; unsigned rest : 31; };
struct S21Object { char pad[8]; struct S21Flags flags; };
void w3d_s21_set_top_bit_801fdfb8(struct S21Object *self, int value)
{
    self->flags.top = value;
}
