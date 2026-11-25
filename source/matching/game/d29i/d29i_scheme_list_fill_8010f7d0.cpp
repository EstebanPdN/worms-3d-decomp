// d29i: 0x8010f7d0. Sorted settings list fill: walks settings of kind 5 whose
// definition derives from type 0x803667a8, skips hidden ones, translates the
// name, finds the sorted position with 0x80347194, shifts the three parallel
// arrays up and stores name, setting name and id +32.
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
struct Owner { unsigned char unknown00[32]; int id; unsigned char unknown24[32]; Object *source; };
struct Definition {
    unsigned char unknown00[28];
    String title;   // +28
    unsigned char unknown20[12];
    int hidden;     // +44
    unsigned char unknown30[24];
    String name;    // +72
};
extern "C" Definition *definition_801797b4(void *);
extern "C" int next_setting_800fc69c(int *, Handle *);
extern "C" int read_key2_800fc2b0(Key *, Key *);
extern "C" void string_init_8020c5c0(String *);
extern "C" unsigned short *string_header_80341884(String *);
extern "C" char **name_find_80347194(char **, int, String *);
extern const char class_80419e68[];
extern const Type type_803667a8[];
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    ++*string_header_80341884(this);
}
inline bool is_a(const Type *t, const Type *target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
static inline void move_up(char **p) {
    char *text = p[-1];
    ++*(unsigned short *)(text - 6);
    char *old = p[0];
    unsigned short *header = (unsigned short *)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    p[0] = p[-1];
}
extern "C" void d29i_scheme_list_fill_8010f7d0(Owner *self) {
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    List *l = (List *)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((List *)list.value)->values);
    Handle table(create_8020b680(class_80419e68));
    int cursor = 0;
    Handle entry;
    while (next_setting_800fc69c(&cursor, &entry)) {
        if (entry.value->vtable->kind(entry.value) != 5) continue;
        {
            Object *o = (Object *)definition_801797b4(as_table_80341584(entry.value));
            if (!is_a(o->vtable->type(o), type_803667a8)) continue;
        }
        Definition *def = definition_801797b4(as_table_80341584(entry.value));
        String title(def->title);
        if (def->hidden == 0) {
            ArrayRef *labels = &((Labels *)table.value)->names;
            int count = labels->header->count;
            char **sa = grow(labels, count + 1);
            ArrayRef *values = &((List *)list.value)->values;
            char **sv = grow(values, values->header->count + 1);
            ArrayRef *idr = &((Labels *)table.value)->ids;
            int *ids = (int *)grow(idr, idr->header->count + 1);
            String name(def->name);
            Key key;
            key.name = name.text;
            Key out;
            if (read_key2_800fc2b0(&key, &out) >= 0)
                string_assign_8020bd38(&name.text, out.name);
            int pos = name_find_80347194(sa, count, &name) - sa;
            for (int j = count; j > pos; j--) {
                move_up(&sa[j]);
                move_up(&sv[j]);
                ids[j] = ids[j - 1];
            }
            int k = pos << 2;
            store(k, sa, name);
            string_assign_8020bd38((char **)((int)sv + k), entry.value->vtable->name(entry.value));
            *(int *)(k + (int)ids) = self->id;
        }
    }
    list_append_801ef174(list.value, 32, 0, table.value);
}
