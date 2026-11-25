// d30i: 0x801167d4. Fills the unlocks list with every entry of the expected type, sorted by lock state, skill text and name, then writes the unlocked percentage to Lock.Percent.
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
struct Id { unsigned char b0, b1, b2, b3; void set(unsigned char v, unsigned char a) { b0 = v; b1 = v; b2 = v; b3 = a; } };
struct Owner { unsigned char unknown00[32]; Id id; unsigned char unknown24[76]; Object *source; };
struct Definition {
    Object base;
    unsigned char unknown04[16];
    int skill;      // +20
    String name;    // +24
    int state;      // +28
};
extern const char class_80419e68[], class_80419e88[], n_8039a448[], n_8039a454[], f_8039a900[], f_8039a460[], f_8039a914[], f_8039a924[], n_8039a92c[];
extern const Type type_80366208[];
extern float width_8039a93c[];
extern "C" Definition *definition_801797b4(void *);
extern "C" int next_setting_800fc69c(int *, Handle *);
extern "C" int read_key2_800fc2b0(Key *, Key *);
extern "C" int write_value_800fc550(Key *, const char *);
extern "C" int strcmp(const char *, const char *);
inline bool is_a(const Type *t, const Type *target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
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
static inline void copy(String &to, const String &from) {
    char *text = from.text;
    ++*(unsigned short *)(text - 6);
    char *old = to.text;
    unsigned short *header = (unsigned short *)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    to.text = from.text;
}
static inline float ratio(const unsigned &a) { return (float)a; }
extern "C" void d30i_unlock_list_fill_801167d4(Owner *self) {
    unsigned total = 0;
    Descriptor_80178474 descriptor;
    unsigned unlocked = 0;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    List *l = (List *)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((List *)list.value)->values);
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
    ((Labels *)b.value)->width = width_8039a93c[0];
    int cursor = 0;
    Handle entry;
    String skill;
    String title;
    String key_name;
    while (next_setting_800fc69c(&cursor, &entry)) {
        if (entry.value->vtable->kind(entry.value) != 5) continue;
        {
            Object *o = (Object *)definition_801797b4(as_table_80341584(entry.value));
            if (!is_a(o->vtable->type(o), type_80366208)) continue;
        }
        total++;
        Definition *def = definition_801797b4(as_table_80341584(entry.value));
        ArrayRef *n1 = &((Labels *)a.value)->names;
        char **sa = grow(n1, n1->header->count + 1);
        ArrayRef *n2 = &((Labels *)b.value)->names;
        char **sb = grow(n2, n2->header->count + 1);
        ArrayRef *v = &((List *)list.value)->values;
        char **sv = grow(v, v->header->count + 1);
        ArrayRef *idr = &((Labels *)a.value)->ids;
        int n = idr->header->count;
        Id *ids = (Id *)grow(idr, n + 1);
        int state = def->state;
        int value = 6;
        if (state == 0) {
            value = def->skill;
            unlocked++;
        }
        string_format_8020c510(&skill, f_8039a900, value);
        Key key;
        key.name = def->name.text;
        Key out;
        if (read_key2_800fc2b0(&key, &out) >= 0)
            string_format_8020c510(&title, f_8039a460, out.name);
        else
            string_format_8020c510(&title, f_8039a914, entry.value->vtable->name(entry.value));
        copy(key_name, def->name);
        int priority = 255;
        if (state == 1) priority = 128;
        Id colour;
        if (state != 0) colour.set(128, 255); else colour = self->id;
        unsigned j;
        for (j = 0; j < (unsigned)n && (unsigned)priority <= ids[j].b0; j++) {
            if (priority == ids[j].b0) {
                int c = strcmp(skill.text, sb[j]);
                if (c > 0) goto found;
                if (c == 0 && strcmp(title.text, sa[j]) < 0) goto found;
            }
        }
        found:
        int k = j << 2;
        for (int m = n; m > (int)j; m--) {
            move_up(sa, m);
            move_up(sv, m);
            move_up(sb, m);
            ids[m] = ids[m - 1];
        }
        store(k, sa, title);
        store(k, sb, skill);
        store(k, sv, key_name);
        *(Id *)(k + (int)ids) = colour;
    }
    list_append_801ef174(list.value, 32, 0, b.value);
    list_append_801ef174(list.value, 32, 0, a.value);
    String percent;
    string_format_8020c510(&percent, f_8039a924, (unsigned)(ratio(unlocked) / (float)total * 100.0f));
    Key lock;
    lock.name = n_8039a92c;
    write_value_800fc550(&lock, percent.text);
}
