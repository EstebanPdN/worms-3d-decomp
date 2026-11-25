// desc: Appears to write a length-prefixed text buffer through a virtual slot of its stream object with a trailing zero and return itself.
struct S21Stream;
struct S21StreamMethods { void (*reserved[6])(void); void (*write)(struct S21Stream *, char *, unsigned, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Writer { struct S21Stream *stream; };
struct S21Writer *w3d_s21_write_text_8020d82c(struct S21Writer *self, char **text)
{
    char *data = *text;
    self->stream->methods->write(self->stream, data, *(unsigned short *)(data - 4), 0);
    return self;
}
