// desc: Appears to return one when the described object's kind is not two, else call virtual slot 8 of the described object.
// desc: Appears to return one when the described object's kind is not two, else call virtual slot 8 of the described object.
struct S21Target;
struct S21TargetMethods { void (*reserved[8])(void); int (*apply)(struct S21Target *); };
struct S21Target { struct S21TargetMethods *methods; };
struct S21Info { char pad[8]; struct S21Target *target; };
struct S21Object { struct S21Info *info; };
extern int fn_801fff94(struct S21Target *);
int w3d_s21_apply_unless_two_801eb240(struct S21Object *self)
{
    if (fn_801fff94(self->info->target) != 0)
        return self->info->target->methods->apply(self->info->target);
    return 1;
}
