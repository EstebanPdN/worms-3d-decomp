extern void FUN_800ddb28(void *, float, void *, void *, int, void *);

void s19_start_timed_800ddcbc(void *self, unsigned t, int a, int b, int c, int d)
{
    FUN_800ddb28(self, (float)(t - *(unsigned *)((char *)self + 100)), a, b, c, d);
}
