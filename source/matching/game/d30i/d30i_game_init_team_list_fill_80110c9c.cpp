// d30i: 0x80110c9c. Fills the four-column team list from GM.GameInitData: name, skill icon, worm count and team colour for each of up to four teams.
struct Type { unsigned char unknown00[20]; const Type *parent; };
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
    const Type *(*type)(Object *);  // +20
    int (*kind)(Object *);          // +24
    void *unknown1c;
    const char *(*name)(Object *);  // +32
};
struct Object { ObjectVtable *vtable; };
struct Key { const char *name; };
// Owned type descriptor released through 0x80178474 (two written words).
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
struct ArrayHeader {
    unsigned char unknown00[4];
    unsigned short kind;   // +4
    unsigned char unknown06[18];
    int count;             // +24
    unsigned short locks;  // +28
    unsigned char unknown1e[2];
    char *data[1];         // +32
};
struct ArrayRef { ArrayHeader *header; };
struct Field { unsigned char unknown00[24]; int count; };
struct List {
    unsigned char unknown00[28];
    ArrayRef values;    // +28
    Field *field;       // +32
};
struct Labels {
    unsigned char unknown00[24];
    ArrayRef names;     // +24
    unsigned char unknown1c[8];
    float width;        // +36
    char *title;        // +40
    unsigned char unknown2c[4];
    ArrayRef ids;       // +48
};
struct String {
    char *text;
    String();
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
extern "C" void *as_table_80341584(Object *);
extern "C" Object *table_get_80179598(void *, Descriptor_80178474 *);
extern "C" void list_begin_801ef380(Object *, int, int, int, int);
extern "C" char **array_lock_801ef048(ArrayRef *, int, int, int);
extern "C" Object *create_8020b680(const void *);
extern "C" void string_release_8020bb2c(void *);
extern "C" char **string_assign_8020bd38(char **, const char *);
extern "C" void string_format_8020c510(String *, const char *, ...);
extern "C" void list_append_801ef174(Object *, int, int, Object *);
static inline char **grow(ArrayRef *array, int count) {
    ArrayHeader *header = array->header;
    if (header->kind == 1 && count == header->count) {
        ++header->locks;
        return header->data;
    }
    return array_lock_801ef048(array, count, 4, 2);
}
static inline void clear(ArrayRef *array) {
    ArrayHeader *header = array->header;
    if (header->kind == 1 && header->count == 0)
        ++header->locks;
    else
        array_lock_801ef048(array, 0, 4, 0);
}
struct Pair { const char *key; const char *value; };
struct PairTable { Pair pairs[7]; };
extern "C" int read_key_800fc2b0(Pair *, Key *);
static inline char **size_to(ArrayRef *array, int count) {
    ArrayHeader *header = array->header;
    if (header->kind == 1 && count == header->count) {
        ++header->locks;
        return header->data;
    }
    return array_lock_801ef048(array, count, 4, 0);
}
static inline void set(Handle &h, Object *next) {
    if (next) next->vtable->retain(next);
    if (h.value) h.value->vtable->release(h.value);
    h.value = next;
}
static inline void store(int index, char **slot, const String &s) {
    char *text = s.text;
    ++*(unsigned short *)(text - 6);
    char *old = *(char **)(index + (int)slot);
    unsigned short *header = (unsigned short *)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    *(char **)(index + (int)slot) = s.text;
}
struct Owner { unsigned char unknown00[104]; Object *source; };
struct GameInit {
    unsigned char unknown00[28];
    int skill0;         // +28
    unsigned char unknown20[24];
    int worms0;         // +56
    unsigned char unknown3c[4];
    String name0;       // +64 (value at +64, sic)
    unsigned char unknown44[24];
    unsigned count;     // +92
    unsigned char unknown60[12];
    int skill1;         // +108
    unsigned char unknown70[24];
    int worms1;         // +136
    unsigned char unknown8c[4];
    String name1;       // +144
    unsigned char unknown94[4];
    int team0;          // +152
    unsigned char unknown9c[24];
    int skill2;         // +180
    unsigned char unknownb8[24];
    int worms2;         // +208
    unsigned char unknownd4[4];
    String name2;       // +216
    unsigned char unknowndc[4];
    int team1;          // +224
    int team2;          // +228
    unsigned char unknowne8[4];
    int team3;          // +236
    unsigned char unknownf0[16];
    int skill3;         // +256
    unsigned char unknown104[24];
    int worms3;         // +284
    unsigned char unknown120[4];
    String name3;       // +292
};
extern int colours_8044d254[];
extern const char class_80419e68[], class_80419e88[], n_8039a478[], n_8039a448[], n_8039a454[], n_8039a488[], n_8039a490[], f_8039a464[], n_8039a49c[], f_8039a4ac[];
extern "C" int read_setting_800fc1b0(Key *, Handle *);
static inline void clear0(ArrayRef *array, int n) {
    ArrayHeader *header = array->header;
    if (header->kind == 1 && n == header->count)
        ++header->locks;
    else
        array_lock_801ef048(array, n, 4, 0);
}
static inline void copy(String &to, const String &from) {
    char *text = from.text;
    ++*(unsigned short *)(text - 6);
    char *old = to.text;
    unsigned short *header = (unsigned short *)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    to.text = from.text;
}
extern "C" void d30i_game_init_team_list_fill_80110c9c(Owner *self) {
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    Descriptor_80178474 descriptor2;
    List *l = (List *)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear0(&((List *)list.value)->values, 0);
    Handle lookup;
    Key key;
    key.name = n_8039a478;
    if (read_setting_800fc1b0(&key, &lookup) < 0) return;
    Handle init;
    {
        Handle value(table_get_80179598(as_table_80341584(lookup.value), &descriptor2));
        init.assign(value.value);
    }
    unsigned count = ((GameInit *)init.value)->count;
    if (count == 0) return;
    const char *cls_a = class_80419e68;
    Handle a(create_8020b680(cls_a));
    {
        Labels *t = (Labels *)a.value;
        String name(n_8039a448);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Labels *)a.value)->width = 59.0f;
    const char *cls_b = class_80419e88;
    Handle b(create_8020b680(cls_b));
    {
        Labels *t = (Labels *)b.value;
        String name(n_8039a454);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Labels *)b.value)->width = 26.0f;
    Handle c(create_8020b680(cls_a));
    {
        Labels *t = (Labels *)c.value;
        String name(n_8039a488);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    Handle d(create_8020b680(cls_b));
    {
        Labels *t = (Labels *)d.value;
        String name(n_8039a490);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Labels *)d.value)->width = 24.0f;
    int skill = 0;
    int team = 0;
    int worms = 1;
    String t;
    String name;
    for (unsigned i = 0; i < count; i++) {
        ArrayRef *r1 = &((Labels *)a.value)->names;
        int c1 = r1->header->count;
        char **sa = grow(r1, c1 + 1);
        ArrayRef *r2 = &((Labels *)b.value)->names;
        int c2 = r2->header->count;
        char **sb = grow(r2, c2 + 1);
        ArrayRef *r3 = &((Labels *)d.value)->names;
        int c3 = r3->header->count;
        char **sd = grow(r3, c3 + 1);
        ArrayRef *r4 = &((Labels *)c.value)->names;
        int c4 = r4->header->count;
        char **sc = grow(r4, c4 + 1);
        switch (i) {
        case 0: {
            GameInit *g = (GameInit *)init.value;
            skill = g->skill0;
            copy(name, g->name0);
            team = ((GameInit *)init.value)->team0;
            worms = ((GameInit *)init.value)->worms0;
            break;
        }
        case 1: {
            GameInit *g = (GameInit *)init.value;
            skill = g->skill1;
            copy(name, g->name1);
            team = ((GameInit *)init.value)->team1;
            worms = ((GameInit *)init.value)->worms1;
            break;
        }
        case 2: {
            GameInit *g = (GameInit *)init.value;
            skill = g->skill2;
            copy(name, g->name2);
            team = ((GameInit *)init.value)->team2;
            worms = ((GameInit *)init.value)->worms2;
            break;
        }
        case 3: {
            GameInit *g = (GameInit *)init.value;
            skill = g->skill3;
            copy(name, g->name3);
            team = ((GameInit *)init.value)->team3;
            worms = ((GameInit *)init.value)->worms3;
            break;
        }
        }
        string_format_8020c510(&t, f_8039a464, skill);
        int k2 = c2 << 2;
        store(k2, sb, t);
        int k1 = c1 << 2;
        store(k1, sa, name);
        ArrayRef *v = &((List *)list.value)->values;
        int c5 = v->header->count;
        char **sv = grow(v, c5 + 1);
        c5 <<= 2;
        store(c5, sv, name);
        ArrayRef *i1 = &((Labels *)a.value)->ids;
        int c6 = i1->header->count;
        int *ids1 = (int *)grow(i1, c6 + 1);
        ids1[c6] = *(int *)((char *)colours_8044d254 + (team << 2));
        string_assign_8020bd38(&t.text, n_8039a49c);
        int k3 = c3 << 2;
        store(k3, sd, t);
        string_format_8020c510(&t, f_8039a4ac, worms);
        int k4 = c4 << 2;
        store(k4, sc, t);
        ArrayRef *i2 = &((Labels *)c.value)->ids;
        int c7 = i2->header->count;
        int *ids2 = (int *)grow(i2, c7 + 1);
        ids2[c7] = *(int *)((team << 2) + (char *)colours_8044d254);
    }
    list_append_801ef174(list.value, 32, 0, b.value);
    list_append_801ef174(list.value, 32, 0, a.value);
    list_append_801ef174(list.value, 32, 0, d.value);
    list_append_801ef174(list.value, 32, 0, c.value);
}
