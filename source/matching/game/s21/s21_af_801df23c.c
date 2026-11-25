// desc: Appears to return a float from a virtual slot of the linked object, or a default constant when there is no link.
struct S21Link;
struct S21LinkMethods { void (*reserved[12])(void); float (*value)(struct S21Link *); };
struct S21Link { struct S21LinkMethods *methods; };
struct S21Object { char pad[28]; struct S21Link *link; };
extern float lbl_803b0378[];
float w3d_s21_link_value_801df23c(struct S21Object *self){if (self->link != 0) return self->link->methods->value(self->link); return lbl_803b0378[0]; }