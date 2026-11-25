// GWMP8P rev0 0x8029a5b4. Adds a team to the local game: looks up the
// GameInit object, fills the next team slot from the team and its info
// record, then posts two string messages.
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
    String(const String &);
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
struct Info { char pad[32]; String f32, f36, f40, f44, f48, f52; };
struct Team { char pad[20]; String f20, f24, f28; int f32, f36, f40; int pad44[3]; Info *info; String name; int used; };
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
struct Table { int v[6]; };
struct Message;
extern const Table lbl_803d0c00;
extern char lbl_803d0bf0[], lbl_803d09c4[], lbl_803d0c18[];
extern void *lbl_804b1754;
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" int w3d_s4_team_first_unused_side(void *);
extern "C" Message *tsonnet_b33_arena_801613f0(void *, int), *w3d_message_string_init(Message *, unsigned short, const char *);
extern "C" unsigned w3d_cached_message_id(Cache_8015f704 *, int);
extern "C" int w3d_message_post_current(Message *);
extern "C" void d30f_add_team_to_local_game_8029a5b4(void *self, Team *team, const char *text) {
    int count = 0;
    Descriptor_80178474 tag;
    Descriptor_80178474 *d = &tag;
    Handle store;
    if (w3d_constructor_lookup_name(lbl_803d0bf0, store) < 0)
        return;
    Handle result;
    result = Handle(w3d_auto_80179598(w3d_empty_80341584(store.p), d));
    Table table = lbl_803d0c00;
    Info *info;
    count = 0;
    switch (((GameInit *)result.p)->f92) {
    case 4:
        count += ((GameInit *)result.p)->f284;
    case 3:
        count += ((GameInit *)result.p)->f208;
    case 2:
        count += ((GameInit *)result.p)->f136;
    case 1:
        count += ((GameInit *)result.p)->f56;
    }
    count = 16 - count;
    if ((unsigned)count > 4)
        count = 4;
    if (count == 0)
        return;
    switch (((GameInit *)result.p)->f92) {
    case 0:
        ((GameInit *)result.p)->f64 = team->name;
        ((GameInit *)result.p)->f96 = team->f28;
        ((GameInit *)result.p)->f24 = team->f36;
        ((GameInit *)result.p)->f28 = team->f40;
        ((GameInit *)result.p)->f160 = team->f24;
        ((GameInit *)result.p)->f20 = table.v[team->f32];
        ((GameInit *)result.p)->f56 = count;
        ((GameInit *)result.p)->f60 = team->f20;
        info = team->info;
        ((GameInit *)result.p)->f264 = info->f32;
        ((GameInit *)result.p)->f48 = info->f36;
        ((GameInit *)result.p)->f44 = info->f40;
        ((GameInit *)result.p)->f40 = info->f44;
        ((GameInit *)result.p)->f36 = info->f48;
        ((GameInit *)result.p)->f32 = info->f52;
        { GameInit *g = (GameInit *)result.p; g->f152 = w3d_s4_team_first_unused_side(self); }
        break;
    case 1:
        ((GameInit *)result.p)->f144 = team->name;
        ((GameInit *)result.p)->f88 = team->f28;
        ((GameInit *)result.p)->f104 = team->f36;
        ((GameInit *)result.p)->f108 = team->f40;
        ((GameInit *)result.p)->f156 = team->f24;
        ((GameInit *)result.p)->f100 = table.v[team->f32];
        ((GameInit *)result.p)->f136 = count;
        ((GameInit *)result.p)->f140 = team->f20;
        info = team->info;
        ((GameInit *)result.p)->f132 = info->f32;
        ((GameInit *)result.p)->f128 = info->f36;
        ((GameInit *)result.p)->f164 = info->f40;
        ((GameInit *)result.p)->f120 = info->f44;
        ((GameInit *)result.p)->f116 = info->f48;
        ((GameInit *)result.p)->f112 = info->f52;
        { GameInit *g = (GameInit *)result.p; g->f224 = w3d_s4_team_first_unused_side(self); }
        break;
    case 2:
        ((GameInit *)result.p)->f216 = team->name;
        ((GameInit *)result.p)->f168 = team->f28;
        ((GameInit *)result.p)->f176 = team->f36;
        ((GameInit *)result.p)->f180 = team->f40;
        ((GameInit *)result.p)->f192 = team->f24;
        ((GameInit *)result.p)->f172 = table.v[team->f32];
        ((GameInit *)result.p)->f208 = count;
        ((GameInit *)result.p)->f212 = team->f20;
        info = team->info;
        ((GameInit *)result.p)->f204 = info->f32;
        ((GameInit *)result.p)->f200 = info->f36;
        ((GameInit *)result.p)->f196 = info->f40;
        ((GameInit *)result.p)->f124 = info->f44;
        ((GameInit *)result.p)->f188 = info->f48;
        ((GameInit *)result.p)->f184 = info->f52;
        { GameInit *g = (GameInit *)result.p; g->f228 = w3d_s4_team_first_unused_side(self); }
        break;
    case 3:
        ((GameInit *)result.p)->f292 = team->name;
        ((GameInit *)result.p)->f244 = team->f28;
        ((GameInit *)result.p)->f252 = team->f36;
        ((GameInit *)result.p)->f256 = team->f40;
        ((GameInit *)result.p)->f240 = team->f24;
        ((GameInit *)result.p)->f248 = table.v[team->f32];
        ((GameInit *)result.p)->f284 = count;
        ((GameInit *)result.p)->f288 = team->f20;
        info = team->info;
        ((GameInit *)result.p)->f280 = info->f32;
        ((GameInit *)result.p)->f276 = info->f36;
        ((GameInit *)result.p)->f272 = info->f40;
        ((GameInit *)result.p)->f268 = info->f44;
        ((GameInit *)result.p)->f52 = info->f48;
        ((GameInit *)result.p)->f260 = info->f52;
        { GameInit *g = (GameInit *)result.p; g->f236 = w3d_s4_team_first_unused_side(self); }
        break;

    default:
        return;
    }
    team->used = 1;
    ((GameInit *)result.p)->f92++;
    Cache_8015f704 cache(lbl_803d09c4);
    {
        Message *m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
        w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), text));
    }
    {
        Message *m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
        w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803d0c18));
    }
}
