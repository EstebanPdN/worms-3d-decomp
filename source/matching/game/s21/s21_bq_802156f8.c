// desc: Appears to call a logging helper with the value two and then call a second helper when bit 8 of the first word of the object's field at offset 48 is set.
struct S21Flags { unsigned flags; };
struct S21Object { char pad[48]; struct S21Flags *state; };
extern int fn_802e3244(int, ...);
extern void fn_802ed798(void);
void w3d_s21_check_state_802156f8(struct S21Object *self)
{
    struct S21Flags *state = self->state;
    fn_802e3244(2);
    if (state->flags & 8)
        fn_802ed798();
}
