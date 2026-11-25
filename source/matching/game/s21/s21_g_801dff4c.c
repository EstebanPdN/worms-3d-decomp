extern int fn_801e507c(void *);
extern int fn_801e4e6c(void *);
struct S21Slots { char pad[48]; int slots[32]; };
int w3d_s21_flush_slots_801dff4c(struct S21Slots *self)
{
    int *slot = self->slots;
    unsigned i;
    for (i = 0; i < 32; i++, slot++) {
        if (*slot && fn_801e507c(*slot))
            fn_801e4e6c(*slot);
    }
    return 0;
}
