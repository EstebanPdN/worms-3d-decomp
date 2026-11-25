#include "w3d_ptr.h"
#line 1 "s12_open_resource_typed.cpp"
/* Inferred shared-string and stream interfaces; method slots follow the original calls. */
struct S12Path;
extern void fn_8020c5c0(Ptr32<S12Path>);
extern Ptr32<unsigned short> fn_80341884(Ptr32<S12Path>);
extern void fn_8020c5c4(Ptr32<S12Path>);
extern void fn_80341588(Ptr32<S12Path>);
struct S12Path {
    Ptr32<char> data;
    S12Path(const S12Path &other) {
        fn_8020c5c0(this);
        data = other.data;
        ++*fn_80341884(this);
    }
    ~S12Path() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S12Stream;
struct S12StreamMethods {
    Ptr32<void (void)> reserved[3];
    Ptr32<void (Ptr32<S12Stream>)> retain;
    Ptr32<void (Ptr32<S12Stream>)> release;
};
struct S12Stream { Ptr32<S12StreamMethods> methods; };
struct S12ResourceDirectory { char reserved[24]; S12Path directory; };
extern Ptr32<void> fn_801fe1d8(int);
extern Ptr32<S12Stream> fn_80218ec4(Ptr32<void>);
extern Ptr32<S12Stream> fn_802187dc(Ptr32<void>);
extern void fn_8020bd38(Ptr32<S12Path>, Ptr32<const char>);
extern void fn_8020bf2c(Ptr32<S12Path>, Ptr32<const char>);
extern void fn_80218194(Ptr32<S12Path>);
extern int fn_802eedc0(Ptr32<const char>, Ptr32<const char>, int);
extern void fn_802192b8(Ptr32<S12Stream>, Ptr32<S12ResourceDirectory>);
extern void fn_80218d78(Ptr32<S12Stream>, Ptr32<S12ResourceDirectory>);
extern int fn_80219184(Ptr32<S12Stream>, Ptr32<const char>, int);
extern int fn_80218c50(Ptr32<S12Stream>, Ptr32<const char>, int);
extern const char lbl_803b387c[], lbl_803b3880[];
extern "C" int w3d_s12_open_resource_8021840c(Ptr32<S12ResourceDirectory> object, Ptr32<const char> name, int flags, Ptr32<Ptr32<S12Stream>> output)
{
    S12Path path(object->directory);
    int status;
    int result;
    Ptr32<S12Stream> stream;
    unsigned short length = *(Ptr32<unsigned short>)(path.data - 4);
    if (length) {
        unsigned char last = *(Ptr32<unsigned char>)(path.data + length - 1);
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
            Ptr32<S12StreamMethods> methods = stream->methods;
            Ptr32<S12Stream> failed = stream;
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


