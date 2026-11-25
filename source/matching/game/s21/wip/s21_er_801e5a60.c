// desc: Appears to reset a voice manager: it installs a vtable pointer, clears flag bits, sets handles to minus one, zeroes its two slots and clears the top two bits of the flag word of each of sixteen global records.
struct S21Record { char pad[60]; unsigned flags; };
struct S21Object { char pad[4]; short ids[2]; unsigned flags; char pad1[32]; int zero44; char pad2[4]; int zero52; int handle; int slots[2]; char pad3[96]; int zero164; void *vtable; };
extern char lbl_80416f78[];
extern struct S21Record lbl_8045dbc8[];
void w3d_s21_reset_801e5a60(struct S21Object *self)
{
    int i;
    unsigned flags = self->flags & ~0x00e00000;
    int none = -1;
    int zero = 0;
    self->vtable = lbl_80416f78;
    self->handle = none;
    self->flags = flags;
    self->zero164 = zero;
    self->zero44 = zero;
    self->zero52 = zero;
    {
        unsigned k = 0;
        int *slot = self->slots;
        short *id = self->ids;
        do {
            *slot = 0;
            k++;
            *id = -1;
            slot++;
            id++;
        } while (k <= 1);
    }
    for (i = 0; i < 16; i++)
        lbl_8045dbc8[i].flags &= 0x3fffffff;
}
