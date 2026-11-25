/* Small virtual helpers on flag words. */
typedef struct S20Object { void **vtable; } S20Object;
typedef int (*S20Query)(void *);
typedef void (*S20Call0)(S20Object *);
typedef struct S20Holder { char pad0[24]; unsigned int flags; char pad1[4]; S20Query validate; char pad2[4]; S20Object *held; } S20Holder;

int w3d_s20_validate_and_flag_801745bc(S20Holder *self) {
    int result = self->validate(self);
    if (result >= 0)
        self->flags |= 0x8000;
    return result;
}

int w3d_s20_release_held_80174620(S20Holder *self) {
    int result = 0;
    if (self->held != 0)
        ((S20Call0)self->held->vtable[4])(self->held);
    self->held = 0;
    self->flags &= ~0x8000u;
    return result;
}
