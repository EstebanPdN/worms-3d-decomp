// desc: Appears to count down a hold counter and, when it reaches zero with a held object, notify it and send an event.
struct S21Hold { int pad; void *held; int count; int enabled; int handle; };
extern int fn_801df1ac(void *);
extern int fn_80322838(int, int, int);
int w3d_s21_hold_tick_801e4f38(struct S21Hold *self)
{
    int count = self->count;
    if (count > 0) {
        int next = count - 1;
        self->count = next;
        if (next == 0) {
            void *held;
            if (self->enabled == 0)
                return 0;
            held = self->held;
            if (held == 0)
                return 0;
            if (fn_801df1ac(held))
                fn_80322838(self->handle, 7, 127);
            return 1;
        }
        return 1;
    }
}
