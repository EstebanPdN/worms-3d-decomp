// desc: Appears to report whether a poll helper succeeded, no count remains and the handle field equals minus one.
struct S21Counter { char pad[8]; int remaining; int pad1; int handle; };
extern int fn_801e4fcc(struct S21Counter *);
int w3d_s21_is_idle_801e5024(struct S21Counter *self)
{
    if (fn_801e4fcc(self) != 0 || self->remaining > 0)
        return 0;
    return self->handle == -1;
}
