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
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Key { const char *text; };
extern "C" int read_800fc1b0(Key *, void *);

struct Holder {
    Object *value;
    Holder() {}
    Holder(const Holder &o) : value(o.value) { if (value) value->vtable->retain(value); }
};
struct Script {
    unsigned char u0[44];
    Object *a, *b, *c, *d;   // +44..+56
};
extern "C" int sub_801037a8(Script *);
extern "C" int build_8010391c(Script *);
extern "C" void fn_80100748(Script *);
extern "C" int fn_8010273c(Script *);
extern "C" void set_run_8010272c(Script *, int);
extern "C" void call_801036f0(Script *, const char *);
extern "C" int flag_802ccb00(int);
extern void *flag_804aaf88;
extern void *arena_804b1754;
extern int cache_804af164;
extern "C" void *arena_801613f0(void *, int);
extern "C" short message_id_8015f5a0(int *, int);
extern "C" void *msg_init_8010a8e0(void *, unsigned short, const char *);
extern "C" int post_8016239c(void *);
extern "C" Object *as_80343744(Object *);
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
extern "C" void d24c_script_start_80100490(Script *self) {
    Holder h;
    Holder *out = &h;
    Object *none = 0;
    sub_801037a8(self);
    build_8010391c(self);
    READ(a, n1_80398770)
    READ(b, n2_80398788)
    READ(c, n3_8039879c)
    READ(d, n4_803987b0)
    fn_80100748(self);
    if (fn_8010273c(self) < 0) {
        void *m = arena_801613f0(arena_804b1754, 12);
        post_8016239c(msg_init_8010a8e0(m, message_id_8015f5a0(&cache_804af164, 1), fail_803987c8));
    } else {
        set_run_8010272c(self, 1);
        if (flag_802ccb00((int)flag_804aaf88)) set_run_8010272c(self, 0);
        call_801036f0(self, init_803987e8);
    }
}
