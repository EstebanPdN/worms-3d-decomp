// d29i: 0x80115088. Ally count list fill: reads FE.SelectedTeam and
// GM.GameInitData, sums the worm counts of the other teams through a fall-
// through switch on the team count, limits 16 minus that sum to 1..6, and
// fills Worms and Number tables with one row each (FE.Skills:12, ' x %d',
// value %d).
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
extern "C" void string_assign_8020bd38(char **, const char *);
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
struct Owner { unsigned char unknown00[96]; Object *source; };
struct GameInit {
    unsigned char unknown00[56];
    int n0;             // +56
    unsigned char unknown3c[4];
    const char *t0;     // +64
    unsigned char unknown44[24];
    unsigned teams;     // +92
    unsigned char unknown60[40];
    int n1;             // +136
    unsigned char unknown8c[4];
    const char *t1;     // +144
    unsigned char unknown94[60];
    int n2;             // +208
    unsigned char unknownd4[4];
    const char *t2;     // +216
    unsigned char unknowndc[64];
    int n3;             // +284
    unsigned char unknown120[4];
    const char *t3;     // +292
};
extern const char class_80419e68[], class_80419e88[], n_8039a750[], n_8039a478[], n_8039a488[], n_8039a760[], n_8039a49c[], f_8039a768[], f_8039a4c8[];
extern "C" int read_key2_800fc2b0(Key *, Key *);
extern "C" int read_setting_800fc1b0(Key *, Handle *);
extern "C" GameInit *definition_801797b4(void *);
extern "C" int strcmp_802ef234(const char *, const char *);
extern "C" void d29i_ally_count_list_fill_80115088(Owner *self) {
    Descriptor_80178474 descriptor;
    String selected;
    Key out;
    Key selected_key;
    selected_key.name = n_8039a750;
    read_key2_800fc2b0(&selected_key, &out);
    string_assign_8020bd38(&selected.text, out.name);
    unsigned used = 0;
    Handle game;
    Key game_key;
    game_key.name = n_8039a478;
    if (read_setting_800fc1b0(&game_key, &game) < 0) return;
    GameInit *init = definition_801797b4(as_table_80341584(game.value));
    switch (init->teams) {
    case 4:
        if (strcmp_802ef234(init->t3, out.name)) used += init->n3;
    case 3:
        if (strcmp_802ef234(init->t2, out.name)) used += init->n2;
    case 2:
        if (strcmp_802ef234(init->t1, out.name)) used += init->n1;
    default:
        if (strcmp_802ef234(init->t0, out.name)) used += init->n0;
    }
    unsigned n = 16 - used;
    if (n > 6) n = 6;
    if (n == 0) n = 1;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    List *l = (List *)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((List *)list.value)->values);
    Handle a, unused, b;
    set(a, create_8020b680(class_80419e88));
    {
        Labels *t = (Labels *)a.value;
        String name(n_8039a488);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short c = --*header;
        if (c == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Labels *)a.value)->width = 25.0f;
    set(b, create_8020b680(class_80419e68));
    {
        Labels *t = (Labels *)b.value;
        String name(n_8039a760);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short c = --*header;
        if (c == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Labels *)b.value)->width = 100.0f;
    ArrayRef *n1 = &((Labels *)a.value)->names;
    char **s1 = grow(n1, n1->header->count + n);
    ArrayRef *n2 = &((Labels *)b.value)->names;
    char **s2 = grow(n2, n2->header->count + n);
    for (unsigned i = 0; i < n; i++) {
        String s(n_8039a49c);
        int k = i * 4;
        store(k, s1, s);
        string_format_8020c510(&s, f_8039a768, i + 1);
        store(k, s2, s);
        ArrayRef *v = &((List *)list.value)->values;
        k = v->header->count;
        char **s3 = grow(v, k + 1);
        {
            String t;
            k <<= 2;
            string_format_8020c510(&t, f_8039a4c8, i + 1);
            store(k, s3, t);
        }
    }
    list_append_801ef174(list.value, 32, 0, a.value);
    list_append_801ef174(list.value, 32, 0, b.value);
}
