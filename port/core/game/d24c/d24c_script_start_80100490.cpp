#include "w3d_ptr.h"
#line 1 "d24c_script_start_80100490.cpp"
// d24c: 0x80100490 (692 bytes). Start a script object: subscribe its messages
// and build its entries; read four string settings (String.S*, String.D*,
// String.S*, String.R*) into retained references at +44..+56, releasing previous
// values; then run the setup call. On failure post a "FAIL" string message;
// otherwise set the run state to 1 (0 when the debug flag is set) and call the
// initialise handler. Names are inferred. The holder is one function-
// level stack object with no destructor, cleared and released by hand around
// each read: this is what keeps its address and the zero in saved registers from
// before the first call. One-word String and handle classes with user copy
// constructors (d24r).
typedef unsigned int size_t;
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
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> text; };
extern "C" int read_800fc1b0(Ptr32<Key>, Ptr32<void>);

struct Holder {
    Ptr32<Object> value;
    Holder() {}
    Holder(const Holder &o) : value(o.value) { if (value) value->vtable->retain(value); }
};
struct Script {
    unsigned char u0[44];
    Ptr32<Object> a; Ptr32<Object> b; Ptr32<Object> c; Ptr32<Object> d;   // +44..+56
};
extern "C" int sub_801037a8(Ptr32<Script>);
extern "C" int build_8010391c(Ptr32<Script>);
extern "C" void fn_80100748(Ptr32<Script>);
extern "C" int fn_8010273c(Ptr32<Script>);
extern "C" void set_run_8010272c(Ptr32<Script>, int);
extern "C" void call_801036f0(Ptr32<Script>, Ptr32<const char>);
extern "C" int flag_802ccb00(int);
extern Ptr32<void> flag_804aaf88;
extern Ptr32<void> arena_804b1754;
extern int cache_804af164;
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" short message_id_8015f5a0(Ptr32<int>, int);
extern "C" Ptr32<void> msg_init_8010a8e0(Ptr32<void>, unsigned short, Ptr32<const char>);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" Ptr32<Object> as_80343744(Ptr32<Object>);
extern const char n1_80398770[], n2_80398788[], n3_8039879c[], n4_803987b0[], fail_803987c8[], init_803987e8[];
#define READ(slot, name) { \
    out->value = none; \
    Key key; \
    key.text = name; \
    read_800fc1b0(&key, out); \
    Object *o = as_80343744(out->value); \
    if (o) o->vtable->retain(o); \
    if (self->slot) self->slot->vtable->release(self->slot); \
    self->slot = o; \
    if (out->value) out->value->vtable->release(out->value); \
}
extern "C" void d24c_script_start_80100490(Ptr32<Script> self) {
    Holder h;
    Ptr32<Holder> out = &h;
    Ptr32<Object> none = 0;
    sub_801037a8(self);
    build_8010391c(self);
    READ(a, n1_80398770)
    READ(b, n2_80398788)
    READ(c, n3_8039879c)
    READ(d, n4_803987b0)
    fn_80100748(self);
    if (fn_8010273c(self) < 0) {
        Ptr32<void> m = arena_801613f0(arena_804b1754, 12);
        post_8016239c(msg_init_8010a8e0(m, message_id_8015f5a0(&cache_804af164, 1), fail_803987c8));
    } else {
        set_run_8010272c(self, 1);
        if (flag_802ccb00((int)w3d::H(flag_804aaf88))) set_run_8010272c(self, 0);
        call_801036f0(self, init_803987e8);
    }
}


