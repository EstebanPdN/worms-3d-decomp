// desc: Appears to call the error callback of the owner with this object and a global message literal.
struct S21Callbacks { char pad[28]; void (*report)(void *, const char *); };
struct S21Object { char pad[180]; struct S21Callbacks *callbacks; };
extern const char lbl_803d7afc[];
void w3d_s21_report_error_802b22b0(struct S21Object *self)
{
    self->callbacks->report(self, lbl_803d7afc);
}
