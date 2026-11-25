// desc: Appears to release the held interface at offset 20 and clear it, returning zero, or 0x80004005 when nothing is held.
struct S21Ref;
struct S21RefMethods { void (*reserved[4])(void); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { char pad[20]; struct S21Ref *held; };
int w3d_s21_release_held_8020810c(struct S21Object *self)
{
    if (self->held != 0) {
        self->held->methods->release(self->held);
        self->held = 0;
        return 0;
    }
    return 0x80004005;
}
