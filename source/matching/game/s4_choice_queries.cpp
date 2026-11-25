/* Observed selection bounds and optional description handle. */
extern "C" {
struct ChoiceQueries {
    char pad_00[240];
    void *description;
    char pad_f4[500-244];
    char *names[10];
    char pad_21c[584-540];
    unsigned count;
    unsigned descriptionCount;
    char pad_250[600-592];
    unsigned index;
};
int w3d_s4_choice_has_weapon(ChoiceQueries *self)
{
    return self->index < self->count;
}
#if 0 /* Branch layout differs after two checks. */
void *w3d_s4_choice_description(ChoiceQueries *self)
{
    unsigned index = self->index;
    if (index < self->descriptionCount) goto available;
    return 0;
available:
    if (*(unsigned short *)(*(char **)((char *)self + index*4 + 500)-4) == 0) goto empty;
    return self->description;
empty:
    return 0;
}
#endif
}
