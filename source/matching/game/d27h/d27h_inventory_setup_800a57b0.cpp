// GWMP8P rev0 0x800a57b0. Worm, team and alliance inventory setup. Names are
// inferred. Reads the three default tags, then for sixteen worms, four teams
// and four alliances resolves the object and inventory through descriptors,
// sets team fields from the constant count and name tables and spawns the
// team worms.
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);   // +12
    void (*release)(Object *);  // +16
};
struct Object { ObjectVtable *vtable; };
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
extern "C" void string_finish_8020c5c4(void *);
extern "C" void string_release_80341588(void *);
extern "C" void release_header_8020bb2c(unsigned short *);
struct String {
    char *text;
    String(const char *);
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    String &operator=(const String &other) {
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
        if (--*header == 0) {
            release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};
struct Worm : Object { char u4[216]; int active; };  // +220
struct Team : Object {
    char u4[24];
    String name;   // +28
    char u32[20];
    int local;     // +52
    char u56[12];
    unsigned char index;  // +68
    int used;      // +72
    void SetLocal(int on) { local = on; }
};
struct WormRef {
    Worm *value;
    WormRef(Worm *next) : value(next) { if (value) value->vtable->retain(value); }
    WormRef(const WormRef &);
    ~WormRef() { if (value) value->vtable->release(value); }
};
struct TeamRef {
    Team *value;
    TeamRef(Team *next) : value(next) { if (value) value->vtable->retain(value); }
    TeamRef(const TeamRef &);
    ~TeamRef() { if (value) value->vtable->release(value); }
};
struct PropertyKey { const char *name; };
extern "C" int unsigned_read_800fc330(PropertyKey *, unsigned *);
extern "C" void propagate_tag_801ea4c8(Object *, void *);
extern "C" Worm *worm_800fc710(unsigned, Descriptor_80178474 *);
extern "C" Object *worm_inventory_800fca64(unsigned, Descriptor_80178474 *);
extern "C" Team *team_800fc82c(unsigned, Descriptor_80178474 *);
extern "C" Object *team_inventory_800fcc9c(unsigned, Descriptor_80178474 *);
extern "C" Object *alliance_inventory_800fcdb8(unsigned, Descriptor_80178474 *);
struct Game;
extern "C" void spawn_800a5a94(Game *, int, unsigned);
struct Services { char u0[188]; unsigned flags; };
extern Services *g_services_804b1788;
extern const unsigned team_counts_80381260[];
extern const char *team_names_803f4c40[];
extern const char text_803811ec[], text_80381204[], text_8038121c[];
inline unsigned ReadTag(const char *name) {
    PropertyKey key;
    key.name = name;
    unsigned tag;
    unsigned_read_800fc330(&key, &tag);
    return tag;
}
extern "C" void d27h_inventory_setup_800a57b0(Game *self) {
    unsigned wormTag = ReadTag(text_803811ec);
    unsigned teamTag = ReadTag(text_80381204);
    unsigned allianceTag = ReadTag(text_8038121c);
    for (unsigned i = 0; i < 16; i++) {
        Descriptor_80178474 d;
        WormRef worm(worm_800fc710(i, &d));
        worm.value->active = 0;
        propagate_tag_801ea4c8(worm_inventory_800fca64(i, &d), (void *)wormTag);
    }
    int next = 0;
    for (unsigned t = 0; t < 4; t++) {
        Descriptor_80178474 d;
        TeamRef team(team_800fc82c(t, &d));
        team.value->used = team_counts_80381260[t] != 0;
        { Team *p = team.value; p->name = String(team_names_803f4c40[t]); }
        team.value->index = t;
        if (g_services_804b1788->flags & 0x2000000) team.value->SetLocal(1);
        for (unsigned j = 0; j < team_counts_80381260[t]; j++) {
            spawn_800a5a94(self, next, t);
            next++;
        }
        propagate_tag_801ea4c8(team_inventory_800fcc9c(t, &d), (void *)teamTag);
    }
    for (unsigned a = 0; a < 4; a++) {
        Descriptor_80178474 d;
        propagate_tag_801ea4c8(alliance_inventory_800fcdb8(a, &d), (void *)allianceTag);
    }
}
