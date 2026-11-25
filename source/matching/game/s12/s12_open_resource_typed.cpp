/* Inferred shared-string and stream interfaces; method slots follow the original calls. */
struct S12Path;
extern void fn_8020c5c0(S12Path *);
extern unsigned short *fn_80341884(S12Path *);
extern void fn_8020c5c4(S12Path *);
extern void fn_80341588(S12Path *);
struct S12Path {
    char *data;
    S12Path(const S12Path &other) {
        fn_8020c5c0(this);
        data = other.data;
        ++*fn_80341884(this);
    }
    ~S12Path() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S12Stream;
struct S12StreamMethods {
    void (*reserved[3])();
    void (*retain)(S12Stream *);
    void (*release)(S12Stream *);
};
struct S12Stream { S12StreamMethods *methods; };
struct S12ResourceDirectory { char reserved[24]; S12Path directory; };
extern void *fn_801fe1d8(int);
extern S12Stream *fn_80218ec4(void *);
extern S12Stream *fn_802187dc(void *);
extern void fn_8020bd38(S12Path *, const char *);
extern void fn_8020bf2c(S12Path *, const char *);
extern void fn_80218194(S12Path *);
extern int fn_802eedc0(const char *, const char *, int);
extern void fn_802192b8(S12Stream *, S12ResourceDirectory *);
extern void fn_80218d78(S12Stream *, S12ResourceDirectory *);
extern int fn_80219184(S12Stream *, const char *, int);
extern int fn_80218c50(S12Stream *, const char *, int);
extern const char lbl_803b387c[], lbl_803b3880[];
extern "C" int w3d_s12_open_resource_8021840c(S12ResourceDirectory *object, const char *name, int flags, S12Stream **output)
{
    S12Path path(object->directory);
    int status;
    int result;
    S12Stream *stream;
    unsigned short length = *(unsigned short *)(path.data - 4);
    if (length) {
        unsigned char last = *(unsigned char *)(path.data + length - 1);
        if (last != '/' && last != '\\' && last != ':')
            fn_8020bf2c(&path, lbl_803b387c);
    }
    if (flags & 2)
        fn_8020bd38(&path, name);
    else
        fn_8020bf2c(&path, name);
    fn_80218194(&path);
    if (fn_802eedc0(path.data, lbl_803b3880, 5) == 0) {
        stream = fn_80218ec4(fn_801fe1d8(28));
        if (stream) {
            stream->methods->retain(stream);
            fn_802192b8(stream, object);
            result = fn_80219184(stream, path.data + 5, flags);
            goto opened;
        }
        goto allocation_failed;
    }
    stream = fn_802187dc(fn_801fe1d8(112));
    if (stream) {
        stream->methods->retain(stream);
        fn_80218d78(stream, object);
        result = fn_80218c50(stream, path.data, flags);
opened:
        status = result;
        if (status < 0) {
            S12StreamMethods *methods = stream->methods;
            S12Stream *failed = stream;
            stream = 0;
            methods->release(failed);
        }
    } else {
allocation_failed:
        status = 0x80004005;
    }
    *output = stream;
    return status;
}
