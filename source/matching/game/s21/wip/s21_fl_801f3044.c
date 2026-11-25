// desc: Appears to replace the held interface at offset 36: it retains the new one, releases the old one, stores it, clears the top bit of the flag word and returns zero.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { char pad[32]; unsigned flags; struct S21Ref *held; };
int w3d_s21_set_held_clear_801f3044(struct S21Object *self, struct S21Ref *fresh)
{
    if (fresh)
        fresh->methods->retain(fresh);
    if (self->held)
        self->held->methods->release(self->held);
    self->flags &= 0x7fffffff;
    self->held = fresh;
    return 0;
}
