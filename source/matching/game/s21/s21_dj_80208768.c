// desc: Appears to assign a shared string pointer from the argument into the field at offset 32, adjusting reference counts, then destroy the source string object.
struct S21Text { char *data; };
struct S21Object { char pad[32]; char *text; };
extern void fn_8020bb2c(void *);
extern void fn_8020c5c4(struct S21Text *);
extern void fn_80341588(struct S21Text *);
void w3d_s21_take_text_80208768(struct S21Object *self, struct S21Text *source)
{
    unsigned short *incoming = (unsigned short *)(source->data - 6);
    ++*incoming;
    {
        unsigned short *old = (unsigned short *)(self->text - 6);
        unsigned short remaining = --*old;
        if (remaining == 0)
            fn_8020bb2c(old);
    }
    self->text = source->data;
    fn_8020c5c4(source);
    fn_80341588(source);
}
