struct K1aState { char pad0[84]; int state; };
extern void k1a_fn_8003ed10(struct K1aState *);

void k1a_state_dispatch_8003e370(struct K1aState *self)
{
    if (self->state == 0)
        goto done;
    if (self->state != 1)
        goto done;
    k1a_fn_8003ed10(self);
done:
    return;
}
