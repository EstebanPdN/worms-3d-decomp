// d30i: 0x80110450. Fills a team list from DATA.TeamBarracks, skipping locked teams and inserting each team sorted by skill text, then name.
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
struct Owner { unsigned char unknown00[28]; int id; unsigned char unknown20[60]; Object *source; };
struct Team { unsigned char unknown00[40]; int skill; unsigned char unknown2c[16]; String name; int locked; };
struct TeamList { int unknown00; ArrayHeader *list; Team **Items() { return (Team **)list->data; } };
struct Definition { unsigned char unknown00[4]; Object base; unsigned char unknown08[12]; TeamList teams; };
extern const char class_80419e68[], class_80419e88[], n_8039a410[], n_8039a448[], n_8039a454[], f_8039a460[], f_8039a464[];
extern "C" int read_setting_800fc1b0(Key *, Handle *);
extern "C" int strcmp(const char *, const char *);
static inline void clear0(ArrayRef *array, int n) {
    ArrayHeader *header = array->header;
    if (header->kind == 1 && n == header->count)
        ++header->locks;
    else
        array_lock_801ef048(array, n, 4, 0);
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
static inline void fetch(Handle &out, Object *src, Descriptor_80178474 &d) {
    Handle value(table_get_80179598(as_table_80341584(src), &d));
    out.assign(value.value);
}
static inline void fetch(Handle &out, Object *src, Descriptor_80178474 *d) {
    Handle value(table_get_80179598(as_table_80341584(src), d));
    out.assign(value.value);
}
static inline void fetch2(Handle &out, const Handle &src, Descriptor_80178474 &d) {
    Handle value(table_get_80179598(as_table_80341584(src.value), &d));
    out.assign(value.value);
}
extern "C" void d30i_barracks_team_sorted_list_fill_80110450(Owner *self) {
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
    Handle barracks;
    Key key;
    key.name = n_8039a410;
    do { if (read_setting_800fc1b0(&key, &barracks) < 0) return; } while (0);
    Handle teams_handle;
    {
        Handle value(table_get_80179598(as_table_80341584(barracks.value), &descriptor2));
        teams_handle.assign(value.value);
    }
    Definition *def = (Definition *)teams_handle.value;
    unsigned count = def->teams.list->count;
    Team **teams = def->teams.Items();
    if (count == 0) return;
    Handle a(create_8020b680(class_80419e68));
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
    Handle b(create_8020b680(class_80419e88));
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
    ((Labels *)b.value)->width = 32.0f;
    String skill;
    String title;
    for (unsigned i = 0; i < count; i++) {
        if (teams[i]->locked != 0) continue;
        string_format_8020c510(&title, f_8039a460, teams[i]->name.text);
        string_format_8020c510(&skill, f_8039a464, teams[i]->skill);
        ArrayRef *n1 = &((Labels *)a.value)->names;
        char **sa = grow(n1, n1->header->count + 1);
        ArrayRef *n2 = &((Labels *)b.value)->names;
        char **sb = grow(n2, n2->header->count + 1);
        ArrayRef *v = &((List *)list.value)->values;
        char **sv = grow(v, v->header->count + 1);
        ArrayRef *idr = &((Labels *)a.value)->ids;
        int n = idr->header->count;
        int *ids = (int *)grow(idr, n + 1);
        unsigned j;
        int c;
        for (j = 0; j < (unsigned)n && (c = strcmp(skill.text, sb[j])) >= 0; j++) {
            if (c == 0 && strcmp(title.text, sa[j]) < 0) goto found;
        }
        found:
        for (int m = n; m > (int)j; m--) {
            move_up(sa, m);
            move_up(sv, m);
            move_up(sb, m);
            ids[m] = ids[m - 1];
        }
        int k = j << 2;
        store(k, sa, title);
        store(k, sb, skill);
        store(k, sv, teams[i]->name);
        *(int *)(k + (int)ids) = self->id;
    }
    list_append_801ef174(list.value, 32, 0, b.value);
    list_append_801ef174(list.value, 32, 0, a.value);
}
