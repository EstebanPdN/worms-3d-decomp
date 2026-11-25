// desc: Appears to advance a cursor field a given number of steps, starting it from the owner when empty and stepping from the current value otherwise, returning zero.
struct S21Object { char pad[20]; int owner; char pad1[4]; int cursor; };
extern int fn_801f8de0(void *);
extern int fn_801f8df8(void *, int);
int w3d_s21_advance_801f90e8(struct S21Object *self, unsigned steps)
{
    unsigned i = 0;
    for (; i < steps; i++) {
        if (self->cursor == 0)
            self->cursor = fn_801f8de0(self->owner);
        else
            self->cursor = fn_801f8df8(self->owner, self->cursor);
    }
    return 0;
}
