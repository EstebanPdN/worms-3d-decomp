#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*S19Fn)(void *self, float t, int a, int b, int c);

void s19_start_timed_virtual_800ddd14(void *self, unsigned t, int a, int b, int c)
{
    ((S19Fn)FIELD(self, void **, 112)[8])(self, (float)(t - FIELD(self, unsigned, 100)), a, b, c);
}
