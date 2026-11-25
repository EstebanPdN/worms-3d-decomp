#include "w3d_ptr.h"
#line 1 "d25c_resource_load_800fd504.cpp"
// d25c: 0x800fd504. Load a resource by name: strip any extension, add the default one and call the loader
// service (virtual +176 of 0x804b1788 +100). Names are inferred.
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" Ptr32<String> string_append_8020bf2c(Ptr32<String>, Ptr32<const char>);
extern "C" Ptr32<char> strchr(Ptr32<const char>, int);
extern "C" void string_truncate_8020c3a0(Ptr32<String>, int);
struct Loader { struct V { Ptr32<void> u[44]; Ptr32<int (Ptr32<Loader>, Ptr32<const char>, int, unsigned char)> load; }; Ptr32<struct V> vtable; };
struct Services { char u[100]; Ptr32<Loader> loader; };
extern Ptr32<Services> services_804b1788;
inline void add_extension(String &path, unsigned flags) {
    if (!strchr(path.text, '.')) {
        if (flags & 1) string_append_8020bf2c(&path, ".xom");
        else if (flags & 2) string_append_8020bf2c(&path, ".xml");
    }
}
extern "C" int d25c_resource_load_800fd504(Ptr32<const char> name, int arg, unsigned flags) {
    String path(name);
    flags &= ~2;
    flags |= 1;
    Ptr32<const char> dot = strchr(name, '.');
    if (dot) string_truncate_8020c3a0(&path, dot - name);
    add_extension(path, flags);
    return services_804b1788->loader->vtable->load(services_804b1788->loader, path.text, arg, flags);
}


