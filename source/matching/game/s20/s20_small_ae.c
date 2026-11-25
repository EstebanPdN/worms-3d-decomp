/* Release of two held objects and a range setter. */
typedef struct S20Object { void **vtable; } S20Object;

typedef struct S20HeldPair { char pad0[24]; unsigned int flags; char pad1[20]; S20Object *first; S20Object *second; } S20HeldPair;

int w3d_s20_clear_held_pair_801882c8(S20HeldPair *self) {
    int result = 0;
    self->flags &= 0xffff7fff;
    if (self->first != 0)
        ((void (*)(S20Object *))self->first->vtable[4])(self->first);
    self->first = (S20Object *)result;
    if (self->second != 0)
        ((void (*)(S20Object *))self->second->vtable[4])(self->second);
    self->second = (S20Object *)result;
    return result;
}

int w3d_s20_set_range_8017dfb4(char *self, unsigned int low, unsigned int high) {
    if (low >= ((unsigned int (*)(char *))(*(void ***)self)[44])(self) || high >= ((unsigned int (*)(char *))(*(void ***)self)[44])(self))
        return 0x80004005;
    *(unsigned char *)(self + 9808) = low;
    *(unsigned char *)(self + 9809) = high;
    return 0;
}
