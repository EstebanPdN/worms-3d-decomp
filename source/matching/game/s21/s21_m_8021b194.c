// desc: Appears to dispatch on a flag of the target's owner and a lookup predicate, calling one of two handlers.
struct S21Owner { char pad[32]; unsigned flags; };
struct S21Target { char pad[24]; struct S21Owner *owner; };
struct S21Holder { char pad[36]; struct S21Target *target; };
extern void *fn_8021ec2c(void *);
extern void *fn_80240994(void *);
extern int fn_8021ed14(void *);
extern void fn_8021b1f8(struct S21Holder *);
extern void fn_8021b388(struct S21Holder *);
void w3d_s21_dispatch_8021b194(struct S21Holder *self)
{
    if (self->target->owner->flags & 1) {
        if (fn_8021ed14(fn_80240994(fn_8021ec2c(self->target))))
            fn_8021b1f8(self);
        else
            fn_8021b388(self);
    }
}
