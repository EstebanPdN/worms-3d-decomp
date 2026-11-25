// desc: Appears to call a virtual slot of the second argument passing the first word read through this and two zero arguments.
struct S21Target;
struct S21TargetMethods { void (*reserved[21])(void); void (*apply)(struct S21Target *, int, int, int); };
struct S21Target { struct S21TargetMethods *methods; };
struct S21Source { int *value; };
void w3d_s21_apply_801ed550(struct S21Source *self, struct S21Target *target)
{
    target->methods->apply(target, 0, *self->value, 0);
}
