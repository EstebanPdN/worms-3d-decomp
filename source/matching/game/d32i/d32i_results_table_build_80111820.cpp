// d32i: 0x80111820. Fills the end-of-game results list: reads the game init
// object, builds the label columns, then inserts each team in order of
// rounds won, colour, skill and name.
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
struct Owner { unsigned char unknown00[92]; Object *source; };
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
extern const char class_80419e68[], class_80419e88[], n_8039a478[], n_8039a448[], n_8039a4bc[], n_8039a490[], f_8039a464[], f_8039a4c8[], n_8039a0e0[];
struct Result { unsigned char unknown00[20]; int rounds; };
extern "C" Result *result_800fc914(unsigned);
extern "C" void * string_append_8020bf2c(String *, const char *);
extern "C" void string_init_8020c5c0(String *);
extern "C" unsigned short *string_header_80341884(String *);
extern "C" int strcmp(const char *, const char *);
struct Colour { unsigned char b0, b1, b2, b3; };
extern "C" int read_setting_800fc1b0(Key *, Handle *);
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    struct H { unsigned short refs, length, capacity; } *h = (H *)string_header_80341884(this);
    ++h->refs;
}
static inline String join_v(String a, const String &b) {
    string_append_8020bf2c(&a, b.text);
    return a;
}
static inline String join(const String &a, const String &b) {
    return join_v(a, b);
}
static inline void move_up(char **a, int m) {
    char *text = a[m - 1];
    ++*(unsigned short *)(text - 6);
    char *old = a[m];
    unsigned short *header = (unsigned short *)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    a[m] = a[m - 1];
}
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
static inline bool same(const Colour &a, const Colour &b) { return a.b1 == b.b1; }
static inline char **grow_by(ArrayRef *array, const unsigned &n) {
    ArrayHeader *header = array->header;
    int c = header->count;
    int size = n + c;
    if (header->kind == 1 && size == header->count) {
        ++header->locks;
        return header->data;
    }
    return array_lock_801ef048(array, size, 4, 2);
}
inline char **GrowBy(ArrayRef &r, unsigned n) { return grow(&r, r.header->count + n); }
extern "C" void d32i_results_table_build_80111820(Owner *self) {
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
    ((Labels *)a.value)->width = 75.0f;
    Handle b(create_8020b680(cls_a));
    {
        Labels *t = (Labels *)b.value;
        String name(n_8039a4bc);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Labels *)b.value)->width = 100.0f;
    Handle c(create_8020b680(class_80419e88));
    {
        Labels *t = (Labels *)c.value;
        String name(n_8039a490);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Labels *)c.value)->width = 32.0f;
    Colour *ids_a = (Colour *)GrowBy(((Labels *)a.value)->ids, count);
    Colour *ids_b = (Colour *)GrowBy(((Labels *)b.value)->ids, count);
    char **sa = GrowBy(((Labels *)a.value)->names, count);
    char **sb = GrowBy(((Labels *)b.value)->names, count);
    char **sc = GrowBy(((Labels *)c.value)->names, count);
    char **sv = GrowBy(((List *)list.value)->values, count);
    int team = 0;
    int skill_value;
    String skill;
    String won;
    String name;
    for (unsigned i = 0; i < count; i++) {
        switch (i) {
        case 0:
            copy(name, ((GameInit *)init.value)->name0);
            skill_value = ((GameInit *)init.value)->skill0;
            team = ((GameInit *)init.value)->team0;
            break;
        case 1:
            copy(name, ((GameInit *)init.value)->name1);
            skill_value = ((GameInit *)init.value)->skill1;
            team = ((GameInit *)init.value)->team1;
            break;
        case 2:
            copy(name, ((GameInit *)init.value)->name2);
            skill_value = ((GameInit *)init.value)->skill2;
            team = ((GameInit *)init.value)->team2;
            break;
        case 3:
            copy(name, ((GameInit *)init.value)->name3);
            skill_value = ((GameInit *)init.value)->skill3;
            team = ((GameInit *)init.value)->team3;
            break;
        }
        string_format_8020c510(&won, f_8039a4c8, result_800fc914(i)->rounds);
        string_format_8020c510(&skill, f_8039a464, skill_value);
        Colour colour = *(Colour *)((team << 2) + (char *)colours_8044d254);
        copy(name, join(String(n_8039a0e0), name));
        unsigned j;
        int cmp;
        for (j = 0; j < i && (cmp = strcmp(won.text, sb[j])) <= 0; j++) {
            if (cmp == 0) {
                if (same(colour, ids_a[j])) {
                    if (strcmp(skill.text, sc[j]) < 0) goto found;
                    if (strcmp(name.text, sa[j]) < 0) goto found;
                } else {
                    if (strcmp(skill.text, sc[j]) < 0) goto found;
                    if (strcmp(name.text, sa[j]) < 0) goto found;
                }
            }
        }
        found:
        for (int m = i; m > (int)j; m--) {
            move_up(sa, m);
            move_up(sb, m);
            move_up(sv, m);
            move_up(sc, m);
            ids_a[m] = ids_a[m - 1];
            ids_b[m] = ids_b[m - 1];
        }
        int k = j << 2;
        store(k, sc, skill);
        store(k, sb, won);
        store(k, sa, name);
        store(k, sv, name);
        *(int *)(k + (int)ids_a) = *(int *)((team << 2) + (char *)colours_8044d254);
        *(int *)(k + (int)ids_b) = *(int *)((team << 2) + (char *)colours_8044d254);
    }
    list_append_801ef174(list.value, 32, 0, c.value);
    list_append_801ef174(list.value, 32, 0, a.value);
    list_append_801ef174(list.value, 32, 0, b.value);
}
