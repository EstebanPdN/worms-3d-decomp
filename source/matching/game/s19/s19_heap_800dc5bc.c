extern unsigned w3d_auto_80209a20(void *);
extern void *w3d_heap_allocate(void *, unsigned);
extern int lbl_804aecac;
void *s19_heap_try_allocate_800dc5bc(unsigned size)
{
    if (size > w3d_auto_80209a20(&lbl_804aecac))
        return 0;
    return w3d_heap_allocate(&lbl_804aecac, size);
}
