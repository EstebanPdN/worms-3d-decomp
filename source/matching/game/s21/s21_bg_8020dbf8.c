// desc: Appears to write a C string through the writer's stream slot using its length and return the writer.
struct S21Stream;
struct S21StreamMethods { void (*reserved[6])(void); int (*write)(struct S21Stream *, const char *, unsigned, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Writer { struct S21Stream *stream; };
extern unsigned fn_802ef9c0(const char *);
struct S21Writer *w3d_s21_write_text_8020dbf8(struct S21Writer *self, const char *text)
{
    unsigned length = fn_802ef9c0(text);
    struct S21Stream *stream = self->stream;
    stream->methods->write(stream, text, length, 0);
    return self;
}
