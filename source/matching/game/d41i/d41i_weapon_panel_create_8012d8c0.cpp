// d41i: 0x8012d8c0. Builds the weapon selection panel: frame, icon grid,
// tooltips and the buffalo-round listing.
struct String {
    char *text;
    String();
    String(const char *);
    String(const String &);
    ~String();
    void operator=(const String &o);
    bool operator!=(const char *o) const;
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" void string_release_8020bb2c(void *);
extern "C" void string_format_8020c510(String *, const char *, ...);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
inline void String::operator=(const String &o) {
    ++*(unsigned short *)(o.text - 6);
    unsigned short *h = (unsigned short *)(text - 6);
    unsigned short n = --*h;
    if (n == 0) string_release_8020bb2c(h);
    text = o.text;
}
extern "C" int strcmp(const char *, const char *);
inline bool String::operator!=(const char *o) const { return strcmp(text, o) != 0; }
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);
    void (*release)(Object *);
    void *unknown14[3];
    const char *(*name)(Object *);
};
struct Object { ObjectVtable *vtable; };
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Handle {
    Object *value;
    Handle() : value(0) {}
    Handle(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
    void assign(Object *next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { x = o.x; y = o.y; z = o.z; }
};
struct Word3 { int a, b, c; };
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline const float &lesser(const float &a, const float &b) { return b < a ? b : a; }
inline const float &greater(const float &a, const float &b) { return a < b ? b : a; }
struct Flags { unsigned char unknown00[7]; unsigned char bits; void Show() { bits |= 4; } void Hide() { bits &= 251; } };
struct Frame {
    unsigned char unknown00[20];
    Vec3 size;      // +20
    Vec3 pos;       // +32
    unsigned char unknown2c[24];
    String text;     // +68
    unsigned char unknown48[16];
    String name;     // +88
    unsigned char unknown5c[28];
    int layer;       // +120 unused view
    int style;       // +124
    int kind;        // +128
    String sub;      // +132
    String sprite;   // +136
    unsigned char unknown8c[8];
    int flag;        // +148
};
struct Icon {
    Object base;
    Flags flags;     // +4
    unsigned char unknown0c[8];
    Vec3 size;      // +20
    Vec3 pos;       // +32
    unsigned char unknown2c[16];
    String tip;      // +60
    unsigned char unknown40[4];
    String text;     // +68
    String up;       // +72
    String down;     // +76
    String right;    // +80
    String left;     // +84
    String name;     // +88
    unsigned char unknown5c[4];
    String sound;    // +96
    unsigned char unknown64[16];
    float scale;     // +116
    int layer;       // +120
    String highlight;// +124
    String action;   // +128
    unsigned char unknown84[4];
    String sprite;   // +136
    unsigned char unknown8c[4];
    int enabled;     // +144
};
struct ArrayHeader { unsigned char unknown00[24]; int count; unsigned char unknown1c[4]; Icon *data[1];
    Icon **At(const int &i) { if (i < 0) return 0; return &data[i]; }
};
struct Group {
    unsigned char unknown00[20];
    ArrayHeader *items;  // +20
    unsigned char unknown18[16];
    String current;      // +40
};
struct Key { const char *name; Key(const char *n) { name = n; } };
struct Inner { unsigned char unknown00[60]; unsigned char u; };
struct Team { unsigned char unknown00[132]; int weapon; unsigned char unknown88[77]; unsigned char index; };
struct Service { unsigned char unknown00[100]; struct Sink *sink; };
struct SinkVt { unsigned char unknown00[128]; void (*bind)(struct Sink *, const Key &, int (*)(void *, void *), void *, void *); };
struct Sink { SinkVt *vt; };
struct Bump { unsigned char unknown00[16]; int on; };
struct Message { unsigned short id; void *vt; };
struct Panel {
    unsigned char unknown00[28];
    Object *o28, *o32, *o36;
    unsigned char unknown28[20];
    void *o60;
    unsigned char unknown40[12];
    int created;     // +76
    unsigned char unknown50[92];
    Bump *bump;      // +172 (held below)
    int tip;         // +176
    unsigned char unknownb4[8];
    Vec3 lo;        // +188
    Vec3 hi;        // +200
};
extern Vec3 box_804668d0, box_804668dc;
extern "C" void grid_8012fa4c(Panel *);
extern "C" void *arena_801613f0(void *, int);
extern void *arena_804b1754;
extern int msg_804af6ac, msg_804af66c;
extern "C" int message_id_8015f5a0(void *, int);
extern "C" int post_8016239c(void *);
extern void *vt_8040db38[];
extern "C" int read_float_800fc270(Key *, float *);
extern "C" int read_int_800fc1f0(Key *, int *);
extern "C" int read_uint_800fc230(Key *, int *);
extern "C" void *as_table_80341584(Object *);
extern "C" Object *table_get_80179598(void *, Descriptor_80178474 *);
extern "C" void *inner_801797b4(void *);
extern "C" int inner_80178c48(void *);
extern "C" void list_begin_801ef380(Object *, int, int, int, int);
extern "C" Object *create_8020b680(const void *);
extern "C" void list_append_801ef174(Object *, int, int, Object *);
extern "C" Team *team_800fc6dc(int);
extern "C" Inner *q_800fc7f8(int);
extern "C" void *q_800fca30(int);
extern "C" void *q_800fcc68(int);
extern "C" void *q_800fcd84(int);
extern "C" void tag_801ea4c8(Object *, void *);
extern "C" void add_8025cb4c(Object *, void *);
extern "C" int has_8025cbe0(Object *, int);
extern "C" int attr_800fd014(Team *, int);
extern "C" int unsigned_8025c3a8(void *, int);
extern "C" unsigned random_80161080(Panel *);
extern "C" const char *reason_8012f0f8(Panel *, int);
extern "C" void slot_8012f180(Panel *, int, Icon **, int, int);
extern "C" int strcmp(const char *, const char *);
extern "C" void named_800a7e14(int, const char *);
extern "C" void *message_string_init_8010a8e0(void *, int, const char *);
extern "C" int update_80178d28(void *, int *);
extern "C" int callback_8012f368(void *event, void *panel);
extern Service *service_804b1788;
extern int weapons_803fd9e4[], buffalo_803fdadc[];
extern unsigned char icons_80451a9c[];
extern const char *names_803eb63c[];
extern const char class_80419d78[], class_80419cf8[], class_8041b958[];
extern const char s_8039dae0[], s_8039daf4[], s_8039db04[], s_8039db14[], s_8039db24[], s_8039db38[], s_8039db50[], s_8039d9a4[];
extern const char s_8039db60[], s_8039db74[], s_8039db80[], s_8039d9e0[], s_8039da50[], s_8039db94[], s_8039da40[], s_8039dba8[], s_8039dbc0[], s_8039dbd4[];
extern const char s_8039dbf8[], s_8039dc10[], s_8039dc24[], s_8039dc38[], s_8039dc40[], s_8039dc58[], s_8039dc68[], s_8039dc80[], s_8039dcb8[], s_8039d9b0[];

inline void setv(Vec3 &to, const Vec3 &from) { to = from; }
inline void Tag(Handle &h, void *q) { tag_801ea4c8(h.value, q); }
inline void Add(Handle &h, void *q) { add_8025cb4c(h.value, q); }
inline void Set(Vec3 &v, float a, float b, float c) { v.x = a; v.y = b; v.z = c; }
inline void Bind(Sink *sink, Panel *self) { void (*f)(struct Sink *, const Key &, int (*)(void *, void *), void *, void *) = sink->vt->bind; f(sink, Key(s_8039d9e0), callback_8012f368, self, &self->tip); }
inline void Upd(void *o, int v) { update_80178d28(o, &v); }
inline Frame *F(Handle &h) { return (Frame *)h.value; }
inline Icon *I(Handle &h) { return (Icon *)h.value; }

extern "C" void d41i_weapon_panel_create_8012d8c0(Panel *self) {
    if (self->created == 0) {
        grid_8012fa4c(self);
        self->lo = box_804668d0;
        self->hi = box_804668dc;
        unsigned cols = 6, rows = 9;
        Message *m = (Message *)arena_801613f0(arena_804b1754, 8);
        m->id = message_id_8015f5a0(&msg_804af6ac, 1);
        m->vt = vt_8040db38;
        post_8016239c(m);
        float tipH = 40.0f, ext = 10.0f, border = 10.0f, iconW = 28.0f, iconH = 28.0f, spA = 2.0f, spU = 2.0f;
        int type = 0;
        Key k0(s_8039dae0); read_float_800fc270(&k0, &tipH);
        Key k1(s_8039daf4); read_float_800fc270(&k1, &ext);
        Key k2(s_8039db04); read_float_800fc270(&k2, &border);
        Key k3(s_8039db14); read_float_800fc270(&k3, &iconW);
        Key k4(s_8039db24); read_float_800fc270(&k4, &iconH);
        Key k5(s_8039db38); read_float_800fc270(&k5, &spA);
        Key k6(s_8039db50); read_float_800fc270(&k6, &spU);
        Key k7(s_8039d9a4); read_uint_800fc230(&k7, &type);
        int *weapons = weapons_803fd9e4;
        float w = (iconW + spA) * (float)cols + (border + border);
        float h = (iconH + spU) * (float)rows + (border + border);
        Vec3 pos;
        Vec3 *pp = &pos;
        pos.x = 320.0f - ext - w * 0.5f;
        pp->y = ext + -240.0f + h * 0.5f + tipH;
        pp->z = 0.0f;
        Vec3 half;
        half.set(w * 0.5f, h * 0.5f, 0.0f);
        Vec3 tipPos;
        tipPos.set(pos.x, tipH * 0.5f + (ext + -240.0f), 0.0f);
        Vec3 tipHalf;
        tipHalf.set(half.x, tipH * 0.5f, 0.0f);
        Vec3 inner;
        inner.set(half.x - (border + border), tipH * 0.5f - border, 0.0f);
        Vec3 iconHalf;
        iconHalf.set(iconW * 0.5f, iconH * 0.5f, 0.0f);
            Vec3 lo = *pp - half;
            Vec3 hi = *pp + half;
            lo.x += border; hi.x -= border;
            lo.y += border; hi.y -= border;
            box_804668d0.x = lesser(lo.x, hi.x);
            box_804668d0.y = lesser(lo.y, hi.y);
            box_804668d0.z = lesser(lo.z, hi.z);
            box_804668dc.x = greater(lo.x, hi.x);
            box_804668dc.y = greater(lo.y, hi.y);
            box_804668dc.z = greater(lo.z, hi.z);
        Descriptor_80178474 descriptor;
        Handle list;
        {
            Handle value(table_get_80179598(as_table_80341584(self->o32), &descriptor));
            list.assign(value.value);
        }
        void *other = inner_801797b4(as_table_80341584(self->o36));
        list_begin_801ef380(list.value, 20, 6, 0, ((Group *)list.value)->items->count);
        const void *frameClass = class_80419d78;
        Handle border1(create_8020b680(frameClass));
        F(border1)->kind = 1;
        F(border1)->name = String(s_8039db60);
        setv(F(border1)->pos, pos);
        setv(F(border1)->size, half);
        F(border1)->text = String(s_8039db74);
        Vec3 tipTextPos;
        tipTextPos.y = tipPos.y;
        tipTextPos.z = tipPos.z;
        tipTextPos.x = tipPos.x - border;
        Vec3 tipTextHalf;
        tipTextHalf.y = inner.y;
        tipTextHalf.z = inner.z;
        tipTextHalf.x = inner.x - border * 0.5f;
        Handle tip(create_8020b680(frameClass));
        F(tip)->kind = 0;
        F(tip)->name = String(s_8039db80);
        setv(F(tip)->pos, tipTextPos);
        setv(F(tip)->size, tipTextHalf);
        F(tip)->style = 3;
        F(tip)->sprite = String(s_8039d9e0);
        F(tip)->sub = String(s_8039da50);
        F(tip)->flag = 1;
        F(tip)->text = String(s_8039db74);
        Handle count(create_8020b680(frameClass));
        F(count)->kind = 1;
        F(count)->name = String(s_8039db94);
        setv(F(count)->pos, tipPos);
        setv(F(count)->size, tipHalf);
        F(count)->style = 5;
        F(count)->sprite = String(s_8039da40);
        F(count)->sub = String(s_8039da50);
        F(count)->text = String(s_8039db74);
        list_append_801ef174(list.value, 20, 6, border1.value);
        list_append_801ef174(list.value, 20, 6, tip.value);
        list_append_801ef174(list.value, 20, 6, count.value);
        Handle allowed(create_8020b680(class_8041b958));
        Team *team = team_800fc6dc(inner_80178c48(self->o28));
        int alliance = q_800fc7f8(team->index)->u;
        int index = team->index;
        Tag(allowed, q_800fca30(inner_80178c48(self->o28)));
        if (index >= 0) Add(allowed, q_800fcc68(index));
        if (alliance >= 0) Add(allowed, q_800fcd84(alliance));
        for (unsigned y = 0; y < rows; y++) {
            Vec3 at(0.0f, ext + -240.0f + h - border - (float)y * (iconH + spU) - iconH * 0.5f + tipH, 0.0f);
            for (unsigned x = 0; x < cols; x++) {
                int layer = 0, enabled = 1;
                unsigned left = x + cols - 1;
                const char *cls = class_80419cf8;
                at.x = (320.0f - ext - w + border) + (float)x * (iconW + spA) + iconW * 0.5f;
                Handle icon(create_8020b680(cls));
                String s;
                string_format_8020c510(&s, s_8039dba8, x, y);
                I(icon)->name = s;
                string_format_8020c510(&s, s_8039dba8, left % cols, y);
                I(icon)->left = s;
                string_format_8020c510(&s, s_8039dba8, (x + 1 + cols) % cols, y);
                I(icon)->right = s;
                string_format_8020c510(&s, s_8039dba8, x, (y - 1 + rows) % rows);
                I(icon)->down = s;
                string_format_8020c510(&s, s_8039dba8, x, (y + 1 + rows) % rows);
                I(icon)->up = s;
                I(icon)->layer = layer;
                I(icon)->flags.Show();
                setv(I(icon)->pos, at);
                I(icon)->sprite = String(s_8039dbc0);
                setv(I(icon)->size, iconHalf);
                I(icon)->highlight = String(s_8039dbd4);
                I(icon)->enabled = enabled;
                list_append_801ef174(list.value, 20, 6, icon.value);
            }
        }
        Group *g = (Group *)list.value;
        int *b = buffalo_803fdadc;
        Icon **items = g->items->At(3);
        unsigned row = 0;
        unsigned col = 0;
        unsigned n = 0;
        for (;;) { if (*b == 61) break; b++; n++; }
        unsigned i = 0;
        Key allianceKey(s_8039dbf8);
        int forced = -1;
        read_int_800fc1f0(&allianceKey, &forced);
        Key roundsKey(s_8039dc10);
        int rounds = 0;
        read_uint_800fc230(&roundsKey, &rounds);
        if (forced > -1 && alliance != forced && rounds != 0) {
            for (unsigned r = 0; r < rows; r++) {
                for (unsigned c = 0; c < cols; c++) {
                    int *tb = buffalo_803fdadc;
                    unsigned pick = random_80161080(self) % n;
                    Icon *it = items[r * cols + c];
                    int weapon = *(int *)((char *)tb + (pick << 2));
                    String s;
                    string_format_8020c510(&s, s_8039dc24, weapon);
                    it->sprite = s;
                    string_format_8020c510(&s, s_8039dc38, names_803eb63c[weapon]);
                    it->text = s;
                    it->action = String(s_8039dc40);
                    it->scale = 1.1f;
                    it->sound = String(s_8039dc58);
                    Group *g = (Group *)list.value;
                    if (*(unsigned short *)(g->current.text - 4) == 0 || weapon == team->weapon)
                        g->current = it->name;
                    it->flags.Hide();
                }
            }
            for (unsigned k = 0; weapons[k] != 60; k++) {
                int weapon = weapons[k];
                if (has_8025cbe0(allowed.value, weapon) && attr_800fd014(team, weapon))
                    slot_8012f180(self, weapon, items, cols, rows);
            }
        } else {
            while (weapons[i] != 60) {
                int weapon = weapons[i];
                Icon *it = items[row * cols + col];
                int used = 0;
                if (has_8025cbe0(allowed.value, weapon) && attr_800fd014(team, weapon)) {
                    used = 1;
                    String s;
                    string_format_8020c510(&s, s_8039dc24, icons_80451a9c[weapon]);
                    it->sprite = s;
                    string_format_8020c510(&s, s_8039dc38, names_803eb63c[weapon]);
                    it->text = s;
                    string_format_8020c510(&s, s_8039dc68, weapon);
                    it->action = s;
                    it->enabled = used;
                    it->highlight = String(s_8039dc80);
                    it->scale = 1.1f;
                    Group *g = (Group *)list.value;
                    if (*(unsigned short *)(g->current.text - 4) == 0 || weapon == team->weapon)
                        g->current = it->name;
                    if (unsigned_8025c3a8(other, weapon))
                        it->flags.Show();
                    else
                        it->flags.Hide();
                    const char *why = reason_8012f0f8(self, weapon);
                    if (String(why) != s_8039d9b0) it->tip = String(why);
                }
                i++;
                if (weapons[i] == 60) {
                    i++;
                    row++;
                    col = 0;
                } else if (used)
                    col++;
            }
        }
        Bind(service_804b1788->sink, self);
        named_800a7e14(3, s_8039dcb8);
        void *mem = arena_801613f0(arena_804b1754, 12);
        int id = (unsigned short)message_id_8015f5a0(&msg_804af66c, 1);
        post_8016239c(message_string_init_8010a8e0(mem, id, self->o32->vtable->name(self->o32)));
        self->created = 1;
        Upd(self->o60, 1);
        self->bump->on = 1;
    }
}
