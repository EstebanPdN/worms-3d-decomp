// d30i: 0x801175c8. Fills the worm list for FE.SelectedTeam by finding its team in GM.GameInitData, listing the six worm names and colouring those in play with the team colour.
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
struct Owner { unsigned char unknown00[76]; Object *source; };
struct GameInit {
    unsigned char unknown0[32];
    String t0_worm5;  // +32
    String t0_worm4;  // +36
    String t0_worm3;  // +40
    String t0_worm2;  // +44
    String t0_worm1;  // +48
    String t3_worm4;  // +52
    int t0_worms;  // +56
    unsigned char unknown3c[4];
    String t0_name;  // +64
    unsigned char unknown44[24];
    unsigned count;  // +92
    unsigned char unknown60[16];
    String t1_worm5;  // +112
    String t1_worm4;  // +116
    String t1_worm3;  // +120
    String t2_worm3;  // +124
    String t1_worm1;  // +128
    String t1_worm0;  // +132
    int t1_worms;  // +136
    unsigned char unknown8c[4];
    String t1_name;  // +144
    unsigned char unknown94[4];
    int t0_team;  // +152
    unsigned char unknown9c[8];
    String t1_worm2;  // +164
    unsigned char unknowna8[16];
    String t2_worm5;  // +184
    String t2_worm4;  // +188
    unsigned char unknownc0[4];
    String t2_worm2;  // +196
    String t2_worm1;  // +200
    String t2_worm0;  // +204
    int t2_worms;  // +208
    unsigned char unknownd4[4];
    String t2_name;  // +216
    unsigned char unknowndc[4];
    int t1_team;  // +224
    int t2_team;  // +228
    unsigned char unknowne8[4];
    int t3_team;  // +236
    unsigned char unknownf0[20];
    String t3_worm5;  // +260
    String t0_worm0;  // +264
    String t3_worm3;  // +268
    String t3_worm2;  // +272
    String t3_worm1;  // +276
    String t3_worm0;  // +280
    int t3_worms;  // +284
    unsigned char unknown120[4];
    String t3_name;  // +292
};
extern int colours_8044d254[];
extern const char class_80419e68[], n_8039a478[], n_8039a98c[], n_8039a750[];
extern "C" int read_setting_800fc1b0(Key *, Handle *);
extern "C" GameInit *definition_801797b4(void *);
extern "C" int read_key2_800fc2b0(Key *, Key *);
extern "C" int strcmp(const char *, const char *);
struct Colour { unsigned char b0, b1, b2, b3; void set(unsigned char v, unsigned char a) { b0 = v; b1 = v; b2 = v; b3 = a; } };
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
extern "C" void d30i_selected_team_worm_list_fill_801175c8(Owner *self) {
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
    GameInit *g = definition_801797b4(as_table_80341584(lookup.value));
    unsigned count = g->count;
    if (count == 0) return;
    Handle a(create_8020b680(class_80419e68));
    {
        Labels *t = (Labels *)a.value;
        String name(n_8039a98c);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    *(int *)((char *)a.value + 28) = 4;
    ((Labels *)a.value)->width = 100.0f;
    Key selected;
    selected.name = n_8039a750;
    Key out;
    read_key2_800fc2b0(&selected, &out);
    String worms[6];
    unsigned worm_count = 1;
    bool found = false;
    int team = 0;
    if (count > 0 && strcmp(out.name, g->t0_name.text) == 0) {
        copy(worms[0], g->t0_worm0);
        copy(worms[1], g->t0_worm1);
        copy(worms[2], g->t0_worm2);
        copy(worms[3], g->t0_worm3);
        copy(worms[4], g->t0_worm4);
        copy(worms[5], g->t0_worm5);
        found = true;
        worm_count = g->t0_worms;
        team = g->t0_team;
    }
    if (count > 1 && !found && strcmp(out.name, g->t1_name.text) == 0) {
        copy(worms[0], g->t1_worm0);
        copy(worms[1], g->t1_worm1);
        copy(worms[2], g->t1_worm2);
        copy(worms[3], g->t1_worm3);
        copy(worms[4], g->t1_worm4);
        copy(worms[5], g->t1_worm5);
        found = true;
        worm_count = g->t1_worms;
        team = g->t1_team;
    }
    if (count > 2 && !found && strcmp(out.name, g->t2_name.text) == 0) {
        copy(worms[0], g->t2_worm0);
        copy(worms[1], g->t2_worm1);
        copy(worms[2], g->t2_worm2);
        copy(worms[3], g->t2_worm3);
        copy(worms[4], g->t2_worm4);
        copy(worms[5], g->t2_worm5);
        found = true;
        worm_count = g->t2_worms;
        team = g->t2_team;
    }
    if (count > 3 && !found && strcmp(out.name, g->t3_name.text) == 0) {
        copy(worms[0], g->t3_worm0);
        copy(worms[1], g->t3_worm1);
        copy(worms[2], g->t3_worm2);
        copy(worms[3], g->t3_worm3);
        copy(worms[4], g->t3_worm4);
        copy(worms[5], g->t3_worm5);
        found = true;
        worm_count = g->t3_worms;
        team = g->t3_team;
    }
    if (!found) return;
    ArrayRef *r1 = &((Labels *)a.value)->names;
    char **sa = grow(r1, r1->header->count + 6);
    ArrayRef *r2 = &((Labels *)a.value)->ids;
    Colour *ids = (Colour *)grow(r2, r2->header->count + 6);
    Colour grey;
    grey.set(128, 255);
    for (unsigned i = 0; i <= 5; i++) {
        store(i << 2, sa, worms[i]);
        if (i < worm_count) *(int *)&ids[i] = *(int *)((team << 2) + (char *)colours_8044d254); else ids[i] = grey;
    }
    list_append_801ef174(list.value, 32, 0, a.value);
}
