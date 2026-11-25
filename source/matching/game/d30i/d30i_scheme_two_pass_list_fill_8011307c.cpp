// d30i: 0x8011307c. Fills the scheme list from DATA.Schemes and DATA.LockedSchemes, translating names on the second pass and adding the current GM.SchemeData scheme when no entry matched it.
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
struct Owner { unsigned char unknown00[28]; int id_a; int id_b; unsigned char unknown20[8]; int id_new; unsigned char unknown30[24]; Object *source; };
struct Scheme {
    unsigned char unknown00[20];
    String name;     // +20
    unsigned char unknown18[60];
    String title;    // +84
    unsigned char unknown58[244];
    int kind;        // +332
};
struct SchemeList { unsigned char unknown00[24]; unsigned count; unsigned char unknown1c[4]; Scheme *items[1]; };
struct Definition { unsigned char unknown00[20]; SchemeList *list; String name() ; };
extern const char class_80419e68[], n_8039a5f0[], n_8039a604[], n_8039a614[], n_8039a620[];
extern "C" int read_setting_800fc1b0(Key *, Handle *);
extern "C" int read_setting2_800fc1b0(String *, Handle *);
extern "C" Definition *definition_801797b4(void *);
extern "C" int read_key2_800fc2b0(Key *, Key *);
extern "C" void string_init_8020c5c0(String *);
extern "C" unsigned short *string_header_80341884(String *);
extern "C" int locked_8028496c(void *, String);
extern "C" int strcmp(const char *, const char *);
extern void *lbl_804abbac;
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    struct H { unsigned short refs, length, capacity; } *h = (H *)string_header_80341884(this);
    ++h->refs;
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
static inline char *name_of(const String &p) { return p.text; }
extern "C" void d30i_scheme_two_pass_list_fill_8011307c(Owner *self) {
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
    String paths[2];
    string_assign_8020bd38(&paths[1].text, n_8039a5f0);
    string_assign_8020bd38(&paths[0].text, n_8039a604);
    Handle table(create_8020b680(class_80419e68));
    {
        Labels *t = (Labels *)table.value;
        String name(n_8039a614);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    bool found = false;
    String current;
    Handle data;
    {
        Key key;
        key.name = n_8039a620;
        if (read_setting_800fc1b0(&key, &data) >= 0) {
            Scheme *s = (Scheme *)definition_801797b4(as_table_80341584(data.value));
            copy(current, s->name);
        }
    }
    String display;
    for (unsigned pass = 0; pass <= 1; pass++) {
        Key key;
        key.name = name_of(paths[pass]);
        if (read_setting_800fc1b0(&key, &lookup) < 0) continue;
        Definition *def = definition_801797b4(as_table_80341584(lookup.value));
        SchemeList *h = def->list;
        unsigned count = h->count;
        Scheme **items = h->items;
        if (count == 0) continue;
        for (unsigned i = 0; i < count; i++) {
            if (locked_8028496c(lbl_804abbac, String(items[i]->title)) == 1) continue;
            ArrayRef *names = &((Labels *)table.value)->names;
            int c1 = names->header->count;
            char **s0 = grow(names, c1 + 1);
            char **sa = s0;
            s0 = 0;
            copy(display, items[i]->name);
            if (strcmp(current.text, display.text) == 0) found = true;
            if (pass == 1) {
                Key k;
                k.name = items[i]->name.text;
                Key out;
                read_key2_800fc2b0(&k, &out);
                string_assign_8020bd38(&display.text, out.name);
            }
            int k1 = c1 << 2;
            store(k1, sa, display);
            ArrayRef *values = &((List *)list.value)->values;
            int c2 = values->header->count;
            char **sv = grow(values, c2 + 1);
            c2 <<= 2;
            store(c2, sv, items[i]->name);
            ArrayRef *idr = &((Labels *)table.value)->ids;
            int c3 = idr->header->count;
            int *ids = (int *)grow(idr, c3 + 1);
            int value;
            if (items[i]->kind == 0) value = self->id_a; else value = self->id_b;
            ids[c3] = value;
        }
    }
    if (!found) {
        ArrayRef *names = &((Labels *)table.value)->names;
        int c1 = names->header->count;
        char **s0 = grow(names, c1 + 1);
        char **sa = s0;
        s0 = 0;
        c1 <<= 2;
        store(c1, sa, current);
        ArrayRef *values = &((List *)list.value)->values;
        int c2 = values->header->count;
        char **sv = grow(values, c2 + 1);
        c2 <<= 2;
        store(c2, sv, current);
        ArrayRef *idr = &((Labels *)table.value)->ids;
        int c3 = idr->header->count;
        int *ids = (int *)grow(idr, c3 + 1);
        ids[c3] = self->id_new;
    }
    list_append_801ef174(list.value, 32, 0, table.value);
}
