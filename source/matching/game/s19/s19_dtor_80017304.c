#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*S19Fn2)(void *self, int arg);
extern unsigned char lbl_8040d990[];
extern void w3d_path_cost_destroy(void *, int);
extern void w3d_auto_80015264(void *);

void s19_path_owner_destroy_80017304(void *self, int flags)
{
    FIELD(self, void *, 12) = lbl_8040d990;
    if (FIELD(self, void *, 32)) {
        ((S19Fn2)FIELD(FIELD(self, void *, 32), void **, 16)[2])(FIELD(self, void *, 32), 3);
    }
    FIELD(self, void *, 32) = 0;
    w3d_path_cost_destroy(self, 0);
    if (flags & 1)
        w3d_auto_80015264(self);
}
