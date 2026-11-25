#include "w3d_ptr.h"
#line 1 "s21_open_child_resource.cpp"
struct S21Path;
extern void fn_8020c5c0(Ptr32<S21Path>);
extern Ptr32<unsigned short> fn_80341884(Ptr32<S21Path>);
extern void fn_8020c5c4(Ptr32<S21Path>);
extern void fn_80341588(Ptr32<S21Path>);
struct S21Path {
    Ptr32<char> data;
    S21Path(const S21Path &other) { fn_8020c5c0(this); data=other.data; ++*fn_80341884(this); }
    ~S21Path() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<S21Stream>)> retain; };
struct S21Stream { Ptr32<S21StreamMethods> methods; };
struct S21ResourceDirectory { char reserved[24]; S21Path directory; };
extern Ptr32<void> fn_801fe1d8(int);
extern Ptr32<S21Stream> fn_80218300(Ptr32<void>);
extern void fn_8020bd38(Ptr32<S21Path>, Ptr32<const char>);
extern void fn_8020bf2c(Ptr32<S21Path>, Ptr32<const char>);
extern void fn_80218194(Ptr32<S21Path>);
extern void fn_80218774(Ptr32<S21Stream>, Ptr32<S21ResourceDirectory>, Ptr32<S21Path>);
extern const char lbl_803b387c[];
static inline void append_sep(Ptr32<S21Path> p, Ptr32<const char> s) { fn_8020bf2c(p, s); }
extern "C" int w3d_s21_open_child_resource_80218608(Ptr32<S21ResourceDirectory> object, Ptr32<const char> name, int flags, Ptr32<Ptr32<S21Stream>> output)
{
    *output = 0;
    S21Path path(object->directory);
    unsigned short length = *(Ptr32<unsigned short>)(path.data - 4);
    if (length) {
        unsigned char last = *(Ptr32<unsigned char>)(path.data + length - 1);
        if (last != '/' && last != '\\')
            fn_8020bf2c(&path, lbl_803b387c);
    }
    if (flags == 2)
        fn_8020bd38(&path, name);
    else
        fn_8020bf2c(&path, name);
    fn_80218194(&path);
    Ptr32<S21Stream> stream = fn_80218300(fn_801fe1d8(28));
    stream->methods->retain(stream);
    length = *(Ptr32<unsigned short>)(path.data - 4);
    if (length) {
        unsigned char last = *(Ptr32<unsigned char>)(path.data + length - 1);
        if (last != '/' && last != '\\' && last != ':')
            append_sep(&path, lbl_803b387c);
    }
    fn_80218774(stream, object, &path);
    *output = stream;
    return 0;
}


