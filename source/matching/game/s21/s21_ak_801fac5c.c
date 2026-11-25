// desc: Appears to report whether the signed byte at offset 10 of the selected twelve-byte table entry differs from minus one.
struct S21Entry { char pad[10]; signed char slot; char pad1; };
struct S21Selector { char pad[128]; int index; };
extern struct S21Entry lbl_8045e824[];
int w3d_s21_has_slot_801fac5c(struct S21Selector *self){struct S21Entry *e = lbl_8045e824 + self->index; if (e->slot == -1) return 0; return 1; }