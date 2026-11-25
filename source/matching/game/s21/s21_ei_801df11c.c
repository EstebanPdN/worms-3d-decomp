// desc: Appears to copy state from another object: it retains the other's held interface, releases its own, then copies the interface pointer, a word and two bytes, returning one, or zero for a null source.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { char pad[28]; struct S21Ref *held; char pad1[12]; int value; char pad2[20]; unsigned char flag_a; unsigned char flag_b; };
int w3d_s21_copy_from_801df11c(struct S21Object *self, struct S21Object *other)
{
    if (!other)
        return 0;
    if (other->held)
        other->held->methods->retain(other->held);
    if (self->held)
        self->held->methods->release(self->held);
    self->held = other->held;
    self->value = other->value;
    self->flag_a = other->flag_a;
    self->flag_b = other->flag_b;
    return 1;
}
