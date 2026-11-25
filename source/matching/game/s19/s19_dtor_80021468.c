#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern unsigned char lbl_8040dd88[];
extern void w3d_auto_80015264(void *);
void s19_dtor_80021468(void *self, int flags)
{
    FIELD(self, void *, 16) = lbl_8040dd88;
    FIELD(self, void *, 12) = 0;
    if (flags & 1)
        w3d_auto_80015264(self);
}
