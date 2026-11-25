// desc: Appears to call virtual slot 15 of the described object with its arguments, the offset-adjusted second argument, descriptor fields and an optional linked value.
struct S21Target;
struct S21TargetMethods { void (*reserved[15])(void); int (*write)(struct S21Target *, int, int, int, int, int); };
struct S21Target { struct S21TargetMethods *methods; };
struct S21Link { char pad[8]; int value; };
struct S21Info { int first; char pad[4]; struct S21Target *target; struct S21Link *link; };
struct S21Object { struct S21Info *info; };
int w3d_s21_forward_write_801eb398(struct S21Object *self, int a, int b)
{
    struct S21Info *info = self->info;
    int value = 0;
    if (info->link)
        value = info->link->value;
    return info->target->methods->write(info->target, a, b + *(unsigned short *)((char *)info + 4), info->first, 1, value);
}
