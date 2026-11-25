#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef const char *(*S19NameFn)(void *self);
extern int strcmp(const char *, const char *);
extern void w3d_auto_8002709c(void *);

int s19_on_name_8002732c(void *self, void *target)
{
    if (target) {
        if (strcmp(((S19NameFn)FIELD(self, void **, 0)[8])(self), "ActiveWormIndex") == 0)
            w3d_auto_8002709c(target);
    }
    return 0;
}
