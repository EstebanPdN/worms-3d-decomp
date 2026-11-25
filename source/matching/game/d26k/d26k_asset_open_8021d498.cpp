// Asset open (Worms 3D GameCube PAL, 0x8021d498).
// 
// Stores the path as the shared name at +68 (temporary built by the string
// constructor 0x8020bb54), replaces the retained object at +36, sets the kind to
// 3 and probes the file: a missing file sets state 5, otherwise the extent and
// the value read through the first property field are stored and state becomes 0.
// The zero is a local kept in a saved register across the calls.

struct String_8020bb54;
extern "C" void string_init_8020c5c0(String_8020bb54 *);
extern "C" unsigned short *string_header_80341884(String_8020bb54 *);
extern "C" void string_finish_8020c5c4(String_8020bb54 *);
extern "C" void string_release_80341588(String_8020bb54 *);
extern "C" void release_header_8020bb2c(unsigned short *);
struct String_8020bb54 {
    char *text;
    String_8020bb54(const char *s);
    String_8020bb54(const String_8020bb54 &other) {
        string_init_8020c5c0(this);
        text = other.text;
        ++*string_header_80341884(this);
    }
    ~String_8020bb54() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
    String_8020bb54 &operator=(const String_8020bb54 &other) {
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
        if (--*header == 0) {
            release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};
struct Interface;
struct InterfaceTable {
    void *reserved[3];
    int (*retain)(Interface *);
    int (*release)(Interface *);
};
struct Interface { InterfaceTable *table; };
struct Ref {
    Interface *p;
    Ref(Interface *o) : p(o) { if (p) p->table->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->table->release(p); }
};
struct Asset {
    char pad0[36]; Interface *object; int kind; char pad1[44 - 44]; int value; int state; char pad2[60 - 52];
    int zero; int size; String_8020bb54 name;
    void setObject(Interface *o) {
        Interface *old = object;
        object = o;
        if (o) o->table->retain(o);
        if (old) old->table->release(old);
    }
};
extern "C" int probe_8021d8b4(const char *);
extern "C" void **field_80240700(Asset *);
extern "C" int extent_8021d830(void *);
extern "C" int read_8021d5c4(void *, int);
extern "C" void w3d_d26k_asset_open_8021d498(Asset *self, Interface *object, const char *path) {
    int zero;
    self->name = String_8020bb54(path);
    zero = 0;
    self->setObject(object);
    self->kind = 3;
    if (probe_8021d8b4(path) == 0) {
        self->state = 5;
    } else {
        int size = extent_8021d830(*field_80240700(self));
        self->zero = zero;
        self->size = size;
        int value = read_8021d5c4(*field_80240700(self), size);
        self->value = value;
        self->state = zero;
    }
}
