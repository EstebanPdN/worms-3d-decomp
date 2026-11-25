struct S21Path;
extern void fn_8020c5c0(S21Path *);
extern unsigned short *fn_80341884(S21Path *);
extern void fn_8020c5c4(S21Path *);
extern void fn_80341588(S21Path *);
struct S21Path {
    char *data;
    S21Path(const S21Path &other) { fn_8020c5c0(this); data=other.data; ++*fn_80341884(this); }
    ~S21Path() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S21Stream;
struct S21StreamMethods { void (*reserved[3])(); void (*retain)(S21Stream *); };
struct S21Stream { S21StreamMethods *methods; };
struct S21ResourceDirectory { char reserved[24]; S21Path directory; };
extern void *fn_801fe1d8(int);
extern S21Stream *fn_80218300(void *);
extern void fn_8020bd38(S21Path *, const char *);
extern void fn_8020bf2c(S21Path *, const char *);
extern void fn_80218194(S21Path *);
extern void fn_80218774(S21Stream *, S21ResourceDirectory *, S21Path *);
extern const char lbl_803b387c[];
static inline void append_sep(S21Path *p, const char *s) { fn_8020bf2c(p, s); }
extern "C" int w3d_s21_open_child_resource_80218608(S21ResourceDirectory *object, const char *name, int flags, S21Stream **output)
{
    *output = 0;
    S21Path path(object->directory);
    unsigned short length = *(unsigned short *)(path.data - 4);
    if (length) {
        unsigned char last = *(unsigned char *)(path.data + length - 1);
        if (last != '/' && last != '\\')
            fn_8020bf2c(&path, lbl_803b387c);
    }
    if (flags == 2)
        fn_8020bd38(&path, name);
    else
        fn_8020bf2c(&path, name);
    fn_80218194(&path);
    S21Stream *stream = fn_80218300(fn_801fe1d8(28));
    stream->methods->retain(stream);
    length = *(unsigned short *)(path.data - 4);
    if (length) {
        unsigned char last = *(unsigned char *)(path.data + length - 1);
        if (last != '/' && last != '\\' && last != ':')
            append_sep(&path, lbl_803b387c);
    }
    fn_80218774(stream, object, &path);
    *output = stream;
    return 0;
}
