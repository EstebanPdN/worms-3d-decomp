typedef struct Interface Interface;
struct Interface { void (**vtable)(Interface *); };
extern Interface *fn_8020fcb4(char *);
extern char lbl_80363b54[];
extern char lbl_80363ba4[];
int terra_only_b_mode_801a92c8(char *self, int mode)
{
    if (mode != *(int *)(self + 160)) {
        Interface *fresh;
        { char *which;
        if (mode == 0) which = lbl_80363b54; else which = lbl_80363ba4;
        fresh = fn_8020fcb4(which); }
        if (fresh) fresh->vtable[3](fresh);
        if (*(Interface **)(self + 176)) {
            Interface *old = *(Interface **)(self + 176);
            old->vtable[4](old);
        }
        *(Interface **)(self + 176) = fresh;
    }
    *(int *)(self + 160) = mode;
    return 0;
}
