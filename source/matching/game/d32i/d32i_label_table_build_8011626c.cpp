// d32i: 0x8011626c. Fills a list panel's label columns from the settings
// pair table: one row per key, with the key's saved value, a numbered id
// text and the pair's default value.
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
struct Owner { unsigned char unknown00[32]; int id; unsigned char unknown24[52]; Object *source; };
extern const char class_80419e68[], class_80419e88[], n_8039a7a0[], n_8039a8f4[], f_8039a4c8[];
extern const PairTable table_8039a8bc;
inline void Assign(char **d, const char *s) { string_assign_8020bd38(d, s); }
inline void Fmt(String *t, const char *f, unsigned i) { string_format_8020c510(t, f, i); }
extern "C" void d32i_label_table_build_8011626c(Owner *self) {
    PairTable table = table_8039a8bc;
    Pair *pp = table.pairs;
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    List *l = (List *)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((List *)list.value)->values);
    const char *cls = class_80419e68;
    Handle a(create_8020b680(cls));
    Handle b(create_8020b680(class_80419e88));
    Handle c(create_8020b680(cls));
    unsigned n = 0;
    for (; table.pairs[n].key; n++) {}
    char **sa = size_to(&((Labels *)a.value)->names, n);
    char **sc = size_to(&((Labels *)c.value)->names, n);
    char **sb = size_to(&((Labels *)b.value)->names, n);
    char **sv = size_to(&((List *)list.value)->values, n);
    ArrayRef *idr = &((Labels *)a.value)->ids;
    int *ids = (int *)grow(idr, idr->header->count + n);
    ((Labels *)b.value)->width = 32.0f;
    ((Labels *)c.value)->width = 2.0f;
    unsigned i = 0;
    if (i < n) do {
        Key out;
        if (read_key_800fc2b0(&pp[i], &out) >= 0)
            Assign(&sa[i], out.name);
        else
            Assign(&sa[i], n_8039a7a0);
        Assign(&sc[i], n_8039a8f4);
        String t;
        Fmt(&t, f_8039a4c8, i);
        Assign(&sv[i], t.text);
        Assign(&sb[i], pp[i].value);
        ids[i] = self->id;
        i++;
    } while (i < n);
    list_append_801ef174(list.value, 32, 0, b.value);
    list_append_801ef174(list.value, 32, 0, c.value);
    list_append_801ef174(list.value, 32, 0, a.value);
}
