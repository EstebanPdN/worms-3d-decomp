// d25c: 0x800fd504. Load a resource by name: strip any extension, add the default one and call the loader
// service (virtual +176 of 0x804b1788 +100). Names are inferred.
struct String {
    char *text;
    String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" String *string_append_8020bf2c(String *, const char *);
extern "C" char *strchr(const char *, int);
extern "C" void string_truncate_8020c3a0(String *, int);
struct Loader { struct V { void *u[44]; int (*load)(Loader *, const char *, int, unsigned char); } *vtable; };
struct Services { char u[100]; Loader *loader; };
extern Services *services_804b1788;
inline void add_extension(String &path, unsigned flags) {
    if (!strchr(path.text, '.')) {
        if (flags & 1) string_append_8020bf2c(&path, ".xom");
        else if (flags & 2) string_append_8020bf2c(&path, ".xml");
    }
}
extern "C" int d25c_resource_load_800fd504(const char *name, int arg, unsigned flags) {
    String path(name);
    flags &= ~2;
    flags |= 1;
    const char *dot = strchr(name, '.');
    if (dot) string_truncate_8020c3a0(&path, dot - name);
    add_extension(path, flags);
    return services_804b1788->loader->vtable->load(services_804b1788->loader, path.text, arg, flags);
}
