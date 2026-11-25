// desc: Appears to allocate a 44-byte object, construct it, initialize it from two arguments and return it.
extern void *fn_801fe1d8(int);
extern void *fn_80208c0c(void *);
extern int fn_80208f48(void *, void *, void *);
void *w3d_s21_create_80208af8(void *a, void *b)
{
    void *object = fn_80208c0c(fn_801fe1d8(44));
    fn_80208f48(object, a, b);
    return object;
}
