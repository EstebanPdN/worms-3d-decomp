// desc: Appears to store a changed float value, notifying the linked object through a helper pair while a busy flag is raised.
struct S21Linked;
struct S21Object { char pad[568]; float value; int busy; char pad1[156]; struct S21Linked *linked; };
extern struct S21Linked *fn_80342a74(struct S21Linked *);
extern int fn_80178dfc(struct S21Linked *, float *);
void w3d_s21_set_value_notify_802683b8(struct S21Object *self, float value)
{
    if (self->value != value) {
        if (self->linked) {
            self->busy = 1;
            fn_80178dfc(fn_80342a74(self->linked), &value);
            self->busy = 0;
        }
        self->value = value;
    }
}
