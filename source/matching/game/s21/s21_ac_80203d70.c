// desc: Appears to replace the held interface object, retaining the new one and releasing the old one, unless the object is locked, in which case it returns 0x80004005.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Holder { char pad[20]; struct S21Ref *held; int locked; };
int w3d_s21_set_held_80203d70(struct S21Holder *self, struct S21Ref *fresh)
{
    if (self->locked)
        return 0x80004005;
    if (fresh)
        fresh->methods->retain(fresh);
    if (self->held)
        self->held->methods->release(self->held);
    self->held = fresh;
    return 0;
}
