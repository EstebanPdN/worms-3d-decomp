#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*S19Apply)(void *self, void *a, void *b);

void s19_apply_camera_80091970(void *self, void *other)
{
    if (FIELD(self, void *, 532) != other) {
        ((S19Apply)FIELD(self, void **, 2792)[8])(self, (char *)other + 240, (char *)other + 192);
        FIELD(self, void *, 532) = other;
        FIELD(self, int, 536) = 1;
    }
}
