#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
float s19_time_fraction_800de5b4(void *self, unsigned t)
{
    return (float)(t - FIELD(self, unsigned, 100)) / (float)(FIELD(self, unsigned, 100) + FIELD(self, unsigned, 92));
}
