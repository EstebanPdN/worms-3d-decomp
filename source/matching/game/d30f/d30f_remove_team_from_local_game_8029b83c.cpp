// GWMP8P rev0 0x8029b83c. Removes a team from the local game: finds its slot
// by name, shifts later team slots down, clears the barracks entry's used
// flag, then posts two status messages. The count is read directly through
// the embedded list holder and the items through its inline member, so CSE
// keeps a second load that the post-reload pass turns into a register copy.
struct Obj { void **table; };
inline void retain(Obj *p) { if (p) ((void (*)(Obj *))p->table[3])(p); }
inline void release(Obj *p) { if (p) ((void (*)(Obj *))p->table[4])(p); }
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(Obj *x) : p(x) { retain(p); }
    Handle(const Handle &o) : p(o.p) { retain(p); }
    ~Handle() { release(p); }
    Handle &operator=(const Handle &o) { Obj *next = o.p; if (next) { retain(next); release(p); p = next; } return *this; }
};
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *), w3d_auto_8015f558(void *, int), w3d_string_release_header(void *);
struct String {
    char *text;
    String(const char *);
    String(const String &);
    const char *c_str() const { return text; }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    String &operator=(const String &other) {
        ++*(unsigned short *)(other.text - 6);
        char *old = text;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};
struct CacheBase { int prefix[2]; ~CacheBase() { w3d_auto_8015f558(this, 2); } };
struct Cache_8015f704 : CacheBase { String name; Cache_8015f704(const char *); };
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct GameInit {
    char head[20];
    int f20;
    int f24;
    int f28;
    String f32;
    String f36;
    String f40;
    String f44;
    String f48;
    String f52;
    int f56;
    String f60;
    String f64;
    int gap68[5];
    String f88;
    unsigned f92;
    String f96;
    int f100;
    int f104;
    int f108;
    String f112;
    String f116;
    String f120;
    String f124;
    String f128;
    String f132;
    int f136;
    String f140;
    String f144;
    int gap148[1];
    int f152;
    String f156;
    String f160;
    String f164;
    String f168;
    int f172;
    int f176;
    int f180;
    String f184;
    String f188;
    String f192;
    String f196;
    String f200;
    String f204;
    int f208;
    String f212;
    String f216;
    int gap220[1];
    int f224;
    int f228;
    int gap232[1];
    int f236;
    String f240;
    String f244;
    int f248;
    int f252;
    int f256;
    String f260;
    String f264;
    String f268;
    String f272;
    String f276;
    String f280;
    int f284;
    String f288;
    String f292;
};
struct Team { char pad[60]; const char *name; int used; };
struct TeamList { char pad[24]; unsigned count; char pad2[4]; Team *items[1]; };
struct Sub { int a; TeamList *teams; Team **Items() { return teams->items; } unsigned Count() { return teams->count; } };
struct Barracks { char pad[20]; Sub sub; };
struct Message;
extern char lbl_803d0bf0[], lbl_803d097c[], lbl_803d09c4[], lbl_803d0c18[], lbl_803d09e0[];
extern void *lbl_804b1754;
extern "C" int strcmp(const char *, const char *);
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" Message *tsonnet_b33_arena_801613f0(void *, int), *w3d_message_string_init(Message *, unsigned short, const char *);
extern "C" unsigned w3d_cached_message_id(Cache_8015f704 *, int);
extern "C" int w3d_message_post_current(Message *);
extern "C" void d30f_remove_team_from_local_game_8029b83c(void *self, const char *text) {
    String current(text);
    Descriptor_80178474 tag1;
    Descriptor_80178474 tag2;
    Handle store;
    Handle barracks;
    unsigned count = 0;
    if (w3d_constructor_lookup_name(lbl_803d0bf0, store) < 0)
        return;
    Handle result;
    result = Handle(w3d_auto_80179598(w3d_empty_80341584(store.p), &tag1));
    int teams = ((GameInit *)result.p)->f92;
    if (teams == 0)
        return;
    unsigned index;
    if (strcmp(current.c_str(), ((GameInit *)result.p)->f64.text) == 0)
        index = 1;
    else if (strcmp(current.text, ((GameInit *)result.p)->f144.text) == 0)
        index = 2;
    else if (strcmp(current.text, ((GameInit *)result.p)->f216.text) == 0)
        index = 3;
    else if (strcmp(current.text, ((GameInit *)result.p)->f292.text) == 0)
        index = 4;
    else
        return;
    switch (index) {
    case 1:
        ((GameInit *)result.p)->f64 = ((GameInit *)result.p)->f144;
        ((GameInit *)result.p)->f96 = ((GameInit *)result.p)->f88;
        ((GameInit *)result.p)->f24 = ((GameInit *)result.p)->f104;
        ((GameInit *)result.p)->f28 = ((GameInit *)result.p)->f108;
        ((GameInit *)result.p)->f160 = ((GameInit *)result.p)->f156;
        ((GameInit *)result.p)->f20 = ((GameInit *)result.p)->f100;
        ((GameInit *)result.p)->f56 = ((GameInit *)result.p)->f136;
        ((GameInit *)result.p)->f264 = ((GameInit *)result.p)->f132;
        ((GameInit *)result.p)->f48 = ((GameInit *)result.p)->f128;
        ((GameInit *)result.p)->f44 = ((GameInit *)result.p)->f164;
        ((GameInit *)result.p)->f40 = ((GameInit *)result.p)->f120;
        ((GameInit *)result.p)->f36 = ((GameInit *)result.p)->f116;
        ((GameInit *)result.p)->f32 = ((GameInit *)result.p)->f112;
        ((GameInit *)result.p)->f152 = ((GameInit *)result.p)->f224;
    case 2:
        ((GameInit *)result.p)->f144 = ((GameInit *)result.p)->f216;
        ((GameInit *)result.p)->f88 = ((GameInit *)result.p)->f168;
        ((GameInit *)result.p)->f104 = ((GameInit *)result.p)->f176;
        ((GameInit *)result.p)->f108 = ((GameInit *)result.p)->f180;
        ((GameInit *)result.p)->f156 = ((GameInit *)result.p)->f192;
        ((GameInit *)result.p)->f100 = ((GameInit *)result.p)->f172;
        ((GameInit *)result.p)->f136 = ((GameInit *)result.p)->f208;
        ((GameInit *)result.p)->f132 = ((GameInit *)result.p)->f204;
        ((GameInit *)result.p)->f128 = ((GameInit *)result.p)->f200;
        ((GameInit *)result.p)->f164 = ((GameInit *)result.p)->f196;
        ((GameInit *)result.p)->f120 = ((GameInit *)result.p)->f124;
        ((GameInit *)result.p)->f116 = ((GameInit *)result.p)->f188;
        ((GameInit *)result.p)->f112 = ((GameInit *)result.p)->f184;
        ((GameInit *)result.p)->f224 = ((GameInit *)result.p)->f228;
    case 3:
        ((GameInit *)result.p)->f216 = ((GameInit *)result.p)->f292;
        ((GameInit *)result.p)->f168 = ((GameInit *)result.p)->f244;
        ((GameInit *)result.p)->f176 = ((GameInit *)result.p)->f252;
        ((GameInit *)result.p)->f180 = ((GameInit *)result.p)->f256;
        ((GameInit *)result.p)->f192 = ((GameInit *)result.p)->f240;
        ((GameInit *)result.p)->f172 = ((GameInit *)result.p)->f248;
        ((GameInit *)result.p)->f208 = ((GameInit *)result.p)->f284;
        ((GameInit *)result.p)->f204 = ((GameInit *)result.p)->f280;
        ((GameInit *)result.p)->f200 = ((GameInit *)result.p)->f276;
        ((GameInit *)result.p)->f196 = ((GameInit *)result.p)->f272;
        ((GameInit *)result.p)->f124 = ((GameInit *)result.p)->f268;
        ((GameInit *)result.p)->f188 = ((GameInit *)result.p)->f52;
        ((GameInit *)result.p)->f184 = ((GameInit *)result.p)->f260;
        ((GameInit *)result.p)->f228 = ((GameInit *)result.p)->f236;
    case 4:
        ((GameInit *)result.p)->f284 = 0;
    }
    ((GameInit *)result.p)->f92 = teams - 1;
    Team *team = 0;
    if (w3d_constructor_lookup_name(lbl_803d097c, barracks) < 0)
        return;
    Handle list;
    list = Handle(w3d_auto_80179598(w3d_empty_80341584(barracks.p), &tag2));
    count = ((Barracks *)list.p)->sub.teams->count;
    Team **items = ((Barracks *)list.p)->sub.Items();
    unsigned i = 0;
    if (i < count)
        do {
            team = items[i];
            if (strcmp(current.text, team->name) == 0) {
                team->used = 0;
                break;
            }
            i++;
        } while (i < count);
    Cache_8015f704 cache(lbl_803d09c4);
    {
        Message *m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
        w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803d0c18));
    }
    {
        Message *m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
        w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803d09e0));
    }
}
