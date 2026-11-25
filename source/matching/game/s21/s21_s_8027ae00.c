// desc: Appears to dispatch on a state field, calling one handler for the primary states and others for the remaining ranges.
struct S21Machine { char pad[96]; unsigned state; };
extern void fn_8027aa3c(void *);
extern void fn_80275f18(void *);
extern void fn_80278e38(struct S21Machine *, int);
void w3d_s21_state_dispatch_8027ae00(struct S21Machine *self)
{
    switch (self->state) {
    case 0 ... 1:
    case 4 ... 7:
    case 16 ... 19:
        fn_8027aa3c((void *)self);
        break;
    default:
        if (self->state <= 19)
            fn_80275f18((void *)self);
        else
            fn_80278e38(self, 32);
        break;
    }
}
