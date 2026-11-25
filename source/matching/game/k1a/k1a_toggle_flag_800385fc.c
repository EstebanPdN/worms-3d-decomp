struct K1aToggler { char pad0[48]; void *target; char pad52[28]; unsigned char flag; char pad81[11]; int mode; };
extern int w3d_s20_store_byte_value_80173f88(void *, unsigned char *);

void k1a_toggler_flip_800385fc(struct K1aToggler *self)
{
    if (self->mode == 0 || self->mode == 2) {
        self->flag = (self->flag + 1) & 1;
        w3d_s20_store_byte_value_80173f88(self->target, &self->flag);
    }
}
