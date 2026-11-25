typedef struct K8bIface { void (**vtable)(struct K8bIface *); } K8bIface;
extern K8bIface *w3d_r24b_invoke_ready_callback_8020fcb4(char *object);
extern char lbl_80363b54[];
extern char lbl_80363ba4[];

int w3d_k8b_mode_set_801a92c8(char *self, int mode)
{
    if (mode != *(int *)(self + 160)) {
        K8bIface *fresh;
        K8bIface *old;
        fresh = w3d_r24b_invoke_ready_callback_8020fcb4(mode ? lbl_80363ba4 : lbl_80363b54);
        if (fresh)
            fresh->vtable[3](fresh);
        old = *(K8bIface **)(self + 176);
        if (old)
            old->vtable[4](old);
        *(K8bIface **)(self + 176) = fresh;
    }
    *(int *)(self + 160) = mode;
    return 0;
}
