#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*S19Step)(void *self, float t);
extern int w3d_auto_80178c48(void *);
extern void w3d_motion_step_800d3160(void *, float, int);
extern void FUN_800d4584(void *, float, void *);
extern void FUN_800d40f4(void *, float, void *);

void s19_step_all_800931ac(void *self, float t, int arg)
{
    if (w3d_auto_80178c48(FIELD(self, int, 216)) != 0) {
        w3d_motion_step_800d3160(self, t, arg);
    } else {
        ((S19Step)FIELD(self, void **, 72)[8])(self, t);
        FUN_800d4584(self, t, arg);
        FUN_800d40f4(self, t, arg);
    }
}
