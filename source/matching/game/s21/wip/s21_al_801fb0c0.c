struct S21Object { char pad[264]; unsigned flags; };
int w3d_s21_flag_or_force_801fb0c0(struct S21Object *self, int force){if (force || (self->flags & 0x20000000)) return 1; return 0; }