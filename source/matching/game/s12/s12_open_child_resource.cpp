struct S12Path;
extern void fn_8020c5c0(S12Path *);
extern unsigned short *fn_80341884(S12Path *);
extern void fn_8020c5c4(S12Path *);
extern void fn_80341588(S12Path *);
struct S12Path {
    char *data;
    S12Path(const S12Path &other) { fn_8020c5c0(this); data=other.data; ++*fn_80341884(this); }
    ~S12Path() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S12Stream;
struct S12StreamMethods { void (*reserved[3])(); void (*retain)(S12Stream *); };
struct S12Stream { S12StreamMethods *methods; };
struct S12ResourceDirectory { char reserved[24]; S12Path directory; };
extern void *fn_801fe1d8(int);
extern S12Stream *fn_80218300(void *);
extern void fn_8020bd38(S12Path *, const char *);
extern void fn_8020bf2c(S12Path *, const char *);
extern void fn_80218194(S12Path *);
extern void fn_80218774(S12Stream *, S12ResourceDirectory *, S12Path *);
extern const char lbl_803b387c[];
extern "C" int w3d_s12_open_child_resource_80218608(S12ResourceDirectory *object, const char *name, int flags, S12Stream **output)
{
    *output = 0;
    S12Path path(object->directory);
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
    S12Stream *stream = fn_80218300(fn_801fe1d8(28));
    stream->methods->retain(stream);
    length = *(unsigned short *)(path.data - 4);
    if (length) {
        unsigned char last = *(unsigned char *)(path.data + length - 1);
        if (last != '/' && last != '\\' && last != ':')
            fn_8020bf2c(&path, lbl_803b387c);
    }
    fn_80218774(stream, object, &path);
    *output = stream;
    return 0;
}
