// desc: Appears to call virtual slot 16 of the described object with its arguments, the second adjusted by the descriptor offset when nonzero, descriptor fields and an optional linked value.
struct S21Target;
struct S21TargetMethods { void (*reserved[16])(void); int (*read)(struct S21Target *, int, int, int, int, int); };
struct S21Target { struct S21TargetMethods *methods; };
struct S21Link { char pad[8]; int value; };
struct S21Info { int first; char pad[4]; struct S21Target *target; struct S21Link *link; };
struct S21Object { struct S21Info *info; };
int w3d_s21_forward_read_801eb338(struct S21Object *self, int a, int b)
{
    struct S21Info *info = self->info;
    int value = 0;
    int position;
    if (info->link)
        value = info->link->value;
    position = b;
    if (position)
        position += *(unsigned short *)((char *)info + 4);
    return info->target->methods->read(info->target, a, position, info->first, 1, value);
}
