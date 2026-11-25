// desc: Appears to format a double with width and precision taken from the writer's format bits into a stack buffer, write it through the stream slot and return the writer.
struct S21Stream;
struct S21StreamMethods { void (*reserved[6])(void); int (*write)(struct S21Stream *, const char *, unsigned, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Writer { struct S21Stream *stream; unsigned format; };
extern const char lbl_803b3258[];
extern int fn_8035cb74(char *, const char *, ...);
extern unsigned fn_802ef9c0(const char *);
struct S21Writer *w3d_s21_write_double_8020dd44(struct S21Writer *self, double value)
{
    char buffer[64];
    struct S21Stream *stream;
    struct S21StreamMethods *methods;
    char *text;
    fn_8035cb74(buffer, lbl_803b3258, *(unsigned char *)((char *)self + 5), (self->format >> 11) & 31, value);
    stream = self->stream;
    text = buffer;
    methods = stream->methods;
    methods->write(stream, text, fn_802ef9c0(text), 0);
    return self;
}
