// desc: Appears to assign a shared string pointer through the output pointer from the source pointer, adjusting reference counts and releasing the old header at zero, returning zero.
extern void fn_8020bb2c(void *);
int w3d_s21_assign_text_801ff304(void *self, char **dest, char **source)
{
    unsigned short *incoming = (unsigned short *)(*source - 6);
    ++*incoming;
    {
        unsigned short *old = (unsigned short *)(*dest - 6);
        unsigned short remaining = --*old;
        if (remaining == 0)
            fn_8020bb2c(old);
    }
    *dest = *source;
    return 0;
}
