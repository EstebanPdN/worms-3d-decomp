// Asset finish (Worms 3D GameCube PAL, 0x8021dd04).
// 
// Copies the asset name and two owner property strings into discarded by-value
// temporaries, releases the file reader at +76 (0x8020810c) and sets the state to 3.
// The temporaries are the arguments of an empty inline sink in one comma expression,
// which is what keeps their stack slots separate at sp+8, sp+16 and sp+24: most
// likely trace output compiled away in the shipped build.

struct SharedString;
extern "C" void string_init_8020c5c0(SharedString *);
extern "C" unsigned short *string_header_80341884(SharedString *);
extern "C" void string_finish_8020c5c4(SharedString *);
extern "C" void string_release_80341588(SharedString *);
extern "C" void release_header_8020bb2c(unsigned short *);
extern "C" SharedString *string_from_text_8020bb54(SharedString *, const char *);
struct SharedString {
    char *text;
    SharedString(const char *s) { string_from_text_8020bb54(this, s); }
    SharedString(const SharedString &other) {
        string_init_8020c5c0(this);
        text = other.text;
        ++*string_header_80341884(this);
    }
    ~SharedString() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
    SharedString &operator=(const SharedString &other) {
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
struct Props { char pad0[44]; SharedString second; char pad1[52 - 48]; SharedString first;
};
struct Asset { char pad0[36]; void *owner; char pad1[48 - 40]; int state; char pad2[68 - 52]; SharedString name; char pad3[76 - 72]; char held[4]; };
extern "C" Props *object_80240994(void *);
extern "C" int release_held_8020810c(void *);
inline void use(SharedString s) { }
extern "C" void w3d_d26k_asset_finish_8021dd04(Asset *self) {
use(self->name), use(object_80240994(self->owner)->first), use(object_80240994(self->owner)->second); release_held_8020810c(self->held); self->state = 3; }
