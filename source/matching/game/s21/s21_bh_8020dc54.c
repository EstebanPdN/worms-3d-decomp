// desc: Appears to format an unsigned value as hexadecimal into a stack buffer, write the text through the writer's stream slot and return the writer.
struct S21Stream;
struct S21StreamMethods { void (*reserved[6])(void); int (*write)(struct S21Stream *, const char *, unsigned, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Writer { struct S21Stream *stream; };
extern const char lbl_803b3250[];
extern int fn_80355a44(char *, const char *, ...);
extern unsigned fn_802ef9c0(const char *);
struct S21Writer *w3d_s21_write_hex_8020dc54(struct S21Writer *self, unsigned value)
{
    char buffer[16];
    struct S21Stream *stream;
    struct S21StreamMethods *methods;
    char *text;
    fn_80355a44(buffer, lbl_803b3250, value);
    stream = self->stream;
    text = buffer;
    methods = stream->methods;
    methods->write(stream, text, fn_802ef9c0(text), 0);
    return self;
}
