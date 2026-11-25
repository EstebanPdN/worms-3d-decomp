// GWMP8P rev0 0x8027e390. Selects the team for the tutorial flow: resolves
// the name or the first team with the most progress, marks it in
// DATA.TeamBarracks, copies its fields into the game init data, clamps the
// current mission through a small inline helper, refreshes the page and
// posts the populate message.
// Observed handle, descriptor, string and team record views; roles inferred.
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
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *), w3d_string_release_header(void *);
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const char *);
    String_803426b8(const String_803426b8 &);
    const char *c_str() const { return text; }
    unsigned Length() const { return ((unsigned short *)text)[-2]; }
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    String_803426b8 &operator=(const String_803426b8 &other) {
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
typedef String_803426b8 String;
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
inline String_803426b8::String_803426b8(const String_803426b8 &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
inline void DebugNote(String) {}
extern "C" void w3d_auto_8015f558(void *, int);
struct CacheBase { int prefix[2]; ~CacheBase() { w3d_auto_8015f558(this, 2); } };
struct Cache_8015f704 : CacheBase { String name; Cache_8015f704(const char *); };
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct NameList { char pad[24]; unsigned count; };
struct Fort { char pad[32]; String s32; String s36; String s40; String s44; String s48; String s52; };
struct Team {
    char pad[24]; String s24; String s28; int v32; int v36; int v40; char pad2[4]; unsigned v48; NameList *names; Fort *fort; String name; int selected;
};
struct TeamList { char pad[24]; unsigned count; char pad2[4]; Team *items[1]; };
struct Data { char pad[24]; TeamList *list; };
struct Info {
    char pad[20]; int v20; int v24; int v28; String s32; String s36; String s40; String s44; String s48; char pad2[4]; int v56; char pad3[4]; String s64;
    char pad4[24]; int v92; String s96; char pad5[60]; String s160; char pad6[100]; String s264;
};
extern char lbl_803cea38[], lbl_803cea44[], lbl_803cea5c[], lbl_803cea68[], lbl_803ceaa0[], lbl_803ceab4[], lbl_803ceac8[], lbl_803cecd0[];
extern void *lbl_804b1754;
struct Message;
extern "C" int w3d_constructor_lookup_name(const char *const &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" Data *w3d_auto_801797b4(Obj *);
extern "C" int w3d_auto_800fc230(const char *const &, unsigned *);
extern "C" int w3d_auto_800fc2b0(const char *const &, const char **);
extern "C" int s8_property_read_800fc550(const char *const &, const char *);
extern "C" int s8_property_write_800fc43c(const char *const &, unsigned);
extern "C" void w3d_string_assign(String *, const char *);
extern "C" int strcmp(const char *, const char *);
extern "C" int w3d_barracks_team_available_80281c04(void *, const char *);
extern "C" unsigned w3d_r25b_category_count_8027be7c(void *, int);
extern "C" void fn_8027d2ac(void *);
extern "C" Message *tsonnet_b33_arena_801613f0(void *, int), *w3d_message_string_init(Message *, unsigned short, const char *);
extern "C" unsigned w3d_cached_message_id(Cache_8015f704 *, int);
extern "C" int w3d_message_post_current(Message *);
inline void Read(unsigned *last) { unsigned level; w3d_auto_800fc230(lbl_803ceab4, &level); if (level == 9999 || level > *last) s8_property_write_800fc43c(lbl_803ceab4, *last); }
extern "C" void d31f_select_tutorial_team_8027e390(void *self, const char *text) {
    Descriptor_80178474 descriptor;
    Handle game;
    Handle teams;
    s8_property_write_800fc43c(lbl_803cea38, 0);
    if (strcmp(text, lbl_803cea44) == 0) {
        const char *current;
        w3d_auto_800fc2b0(lbl_803cea5c, &current);
        if (w3d_barracks_team_available_80281c04(self, current) == 1)
            text = current;
    }
    String name(text);
    if (w3d_constructor_lookup_name(lbl_803cea68, game) < 0)
        return;
    Handle info;
    Obj *converted;
    converted = w3d_auto_80179598(w3d_empty_80341584(game.p), &descriptor);
    info = Handle(converted);
    if (w3d_constructor_lookup_name(lbl_803ceaa0, teams) < 0)
        return;
    Data *data = w3d_auto_801797b4(w3d_empty_80341584(teams.p));
    unsigned count = data->list->count;
    if (name.Length() == 0) {
        const char *current;
        w3d_auto_800fc2b0(lbl_803cea5c, &current);
        w3d_string_assign(&name, current);
    }
    Team **items = data->list->items;
    unsigned best = 0;
    unsigned chosen = 0;
    if (strcmp(name.text, lbl_803cea44) == 0 || name.Length() == 0) {
        for (unsigned j = 0; j < count; j++) {
            Team *team = items[j];
            if (team->v40 == 0 && team->v48 > best) {
                best = team->v48;
                chosen = j;
            }
        }
        name = items[chosen]->name;
    }
    unsigned i = 0;
    unsigned index = 0;
    for (; i < count; i++) {
        items[i]->selected = 0;
        if (strcmp(name.text, items[i]->name.c_str()) == 0) {
            index = i;
            items[i]->selected = 1;
        }
    }
    ((Info *)info.p)->v92 = 1;
    i = index;
    { Team *t = items[i]; Info *g = (Info *)info.p; g->s64 = t->name; }
    { Team *t = items[i]; Info *g = (Info *)info.p; g->s96 = t->s28; }
    ((Info *)info.p)->v24 = items[i]->v36;
    ((Info *)info.p)->v28 = items[i]->v40;
    { Team *t = items[i]; Info *g = (Info *)info.p; g->s160 = t->s24; }
    ((Info *)info.p)->v20 = items[i]->v32;
    ((Info *)info.p)->v56 = 4;
    {
        Fort *f = items[i]->fort;
        { Info *g = (Info *)info.p; g->s264 = *(String *)&f->s32; }
        { Info *g = (Info *)info.p; g->s48 = f->s36; }
        { Info *g = (Info *)info.p; g->s44 = f->s40; }
        { Info *g = (Info *)info.p; g->s40 = f->s44; }
        { Info *g = (Info *)info.p; g->s36 = f->s48; }
        { Info *g = (Info *)info.p; g->s32 = f->s52; }
    }
    s8_property_read_800fc550(lbl_803cea5c, items[i]->name.c_str());
    unsigned last = items[i]->v48;
    if (last >= w3d_r25b_category_count_8027be7c(self, 3))
        last = w3d_r25b_category_count_8027be7c(self, 3) - 1;
    Read(&last);
    fn_8027d2ac(self);
    Cache_8015f704 cache(lbl_803ceac8);
    Message *m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
    w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803cecd0));
}
