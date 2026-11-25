// desc: Appears to assign a shared string pointer from the argument into the field at offset 32, adjusting reference counts and releasing the old header at zero, returning zero.
struct S21Object { char pad[32]; char *text; };
extern void fn_8020bb2c(void *);
int w3d_s21_set_text_80211520(struct S21Object *self, char **source)
{
    unsigned short *incoming = (unsigned short *)(*source - 6);
    ++*incoming;
    {
        unsigned short *old = (unsigned short *)(self->text - 6);
        unsigned short remaining = --*old;
        if (remaining == 0)
            fn_8020bb2c(old);
    }
    self->text = *source;
    return 0;
}
