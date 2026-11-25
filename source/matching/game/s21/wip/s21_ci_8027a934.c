// desc: Appears to switch a linked object on or off for mode zero or one through a helper and remember the mode, ignoring other values.
struct S21Object { char pad[32]; int link; char pad1[4]; int mode; };
extern void fn_802cd2e0(int, int);
void w3d_s21_set_mode_8027a934(struct S21Object *self, int mode)
{
    switch (mode) {
    case 0:
        fn_802cd2e0(self->link, 1);
        break;
    case 1:
        fn_802cd2e0(self->link, 0);
        break;
    default:
        return;
    }
    self->mode = mode;
}
