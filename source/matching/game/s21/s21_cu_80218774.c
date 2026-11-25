// desc: Appears to assign a shared string pointer from the third argument into the field at offset 24, adjusting reference counts and releasing the old header at zero.
struct S21Object { char pad[24]; char *text; };
extern void fn_8020bb2c(void *);
void w3d_s21_assign_text_80218774(struct S21Object *self, int unused, char **source)
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
}
