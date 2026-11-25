#include "w3d_ptr.h"
#line 1 "d27h_inventory_setup_800a57b0.cpp"
// GWMP8P rev0 0x800a57b0. Worm, team and alliance inventory setup. Names are
// inferred. Reads the three default tags, then for sixteen worms, four teams
// and four alliances resolves the object and inventory through descriptors,
// sets team fields from the constant count and name tables and spawns the
// team worms.
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   // +12
    Ptr32<void (Ptr32<Object>)> release;  // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
extern "C" void string_finish_8020c5c4(Ptr32<void>);
extern "C" void string_release_80341588(Ptr32<void>);
extern "C" void release_header_8020bb2c(Ptr32<unsigned short>);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    String &operator=(const String &other) {
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};
struct Worm : Object { char u4[216] __attribute__((aligned(__alignof__(Object)))); int active; };  // +220
struct Team : Object {
    char u4[24] __attribute__((aligned(__alignof__(Object))));
    String name;   // +28
    char u32[20];
    int local;     // +52
    char u56[12];
    unsigned char index;  // +68
    int used;      // +72
    void SetLocal(int on) { local = on; }
};
struct WormRef {
    Ptr32<Worm> value;
    template <class W3dU> WormRef(Ptr32<W3dU> w3d_p) : WormRef((Worm *)w3d_p.get()) {}
 WormRef(Worm *next) : value(next) { if (value) value->vtable->retain(value); }
    WormRef(const WormRef &);
    ~WormRef() { if (value) value->vtable->release(value); }
};
struct TeamRef {
    Ptr32<Team> value;
    template <class W3dU> TeamRef(Ptr32<W3dU> w3d_p) : TeamRef((Team *)w3d_p.get()) {}
 TeamRef(Team *next) : value(next) { if (value) value->vtable->retain(value); }
    TeamRef(const TeamRef &);
    ~TeamRef() { if (value) value->vtable->release(value); }
};
struct PropertyKey { Ptr32<const char> name; };
extern "C" int unsigned_read_800fc330(Ptr32<PropertyKey>, Ptr32<unsigned int>);
extern "C" void propagate_tag_801ea4c8(Ptr32<Object>, Ptr32<void>);
extern "C" Ptr32<Worm> worm_800fc710(unsigned, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<Object> worm_inventory_800fca64(unsigned, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<Team> team_800fc82c(unsigned, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<Object> team_inventory_800fcc9c(unsigned, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<Object> alliance_inventory_800fcdb8(unsigned, Ptr32<Descriptor_80178474>);
struct Game;
extern "C" void spawn_800a5a94(Ptr32<Game>, int, unsigned);
struct Services { char u0[188]; unsigned flags; };
extern Ptr32<Services> g_services_804b1788;
extern const unsigned team_counts_80381260[];
extern Ptr32<const char> team_names_803f4c40[];
extern const char text_803811ec[], text_80381204[], text_8038121c[];
inline unsigned ReadTag(Ptr32<const char> name) {
    PropertyKey key;
    key.name = name;
    unsigned tag;
    unsigned_read_800fc330(&key, &tag);
    return tag;
}
extern "C" void d27h_inventory_setup_800a57b0(Ptr32<Game> self) {
    unsigned wormTag = ReadTag(text_803811ec);
    unsigned teamTag = ReadTag(text_80381204);
    unsigned allianceTag = ReadTag(text_8038121c);
    for (unsigned i = 0; i < 16; i++) {
        Descriptor_80178474 d;
        WormRef worm(worm_800fc710(i, &d));
        worm.value->active = 0;
        propagate_tag_801ea4c8(worm_inventory_800fca64(i, &d), (Ptr32<void>)w3d::G(wormTag));
    }
    int next = 0;
    for (unsigned t = 0; t < 4; t++) {
        Descriptor_80178474 d;
        TeamRef team(team_800fc82c(t, &d));
        team.value->used = team_counts_80381260[t] != 0;
        { Ptr32<Team> p = team.value; p->name = String(team_names_803f4c40[t]); }
        team.value->index = t;
        if (g_services_804b1788->flags & 0x2000000) team.value->SetLocal(1);
        for (unsigned j = 0; j < team_counts_80381260[t]; j++) {
            spawn_800a5a94(self, next, t);
            next++;
        }
        propagate_tag_801ea4c8(team_inventory_800fcc9c(t, &d), (Ptr32<void>)w3d::G(teamTag));
    }
    for (unsigned a = 0; a < 4; a++) {
        Descriptor_80178474 d;
        propagate_tag_801ea4c8(alliance_inventory_800fcdb8(a, &d), (Ptr32<void>)w3d::G(allianceTag));
    }
}


