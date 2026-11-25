// desc: Appears to optionally store an entry of one indexed table through an output pointer and return the entry of a second indexed table.
struct S21Tables { char pad[44]; int *primary; int *secondary; };
int w3d_s21_lookup_pair_802067bc(struct S21Tables *self, int index, int *out)
{
    if (out)
        *out = *(int *)((char *)self->secondary + (index << 2));
    return self->primary[index];
}
