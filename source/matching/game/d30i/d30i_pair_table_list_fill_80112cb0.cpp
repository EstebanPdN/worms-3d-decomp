// d30i: 0x80112cb0. Fills an option list from a seven-entry key and value table, translating each key for the label column.
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
struct Pair { const char *key; const char *value; };
struct PairTable { Pair pairs[7]; };
struct Field { unsigned char unknown00[24]; int count; };
struct List {
    unsigned char unknown00[28];
    ArrayRef values;    // +28
    Field *field;       // +32
};
struct Labels {
    unsigned char unknown00[24];
    ArrayRef names;     // +24
    unsigned char unknown1c[12];
    char *title;        // +40
    unsigned char unknown2c[4];
    ArrayRef ids;       // +48
};
struct String {
    char *text;
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
struct Owner {
    unsigned char unknown00[32];
    int id;             // +32
    unsigned char unknown24[48];
    Object *source;     // +84
};
extern "C" void *as_table_80341584(Object *);
extern "C" Object *table_get_80179598(void *, Descriptor_80178474 *);
extern "C" void list_begin_801ef380(Object *, int, int, int, int);
extern "C" char **array_lock_801ef048(ArrayRef *, int, int, int);
extern "C" Object *create_8020b680(const void *);
extern "C" void string_release_8020bb2c(void *);
extern "C" void string_assign_8020bd38(char **, const char *);
extern "C" int read_key_800fc2b0(Pair *, Key *);
extern "C" void list_append_801ef174(Object *, int, int, Object *);
extern const char class_80419e68[], n_8039a448[];
extern const PairTable table_8039a5b8;
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
extern "C" void d30i_pair_table_list_fill_80112cb0(Owner *self) {
    Descriptor_80178474 descriptor;
    PairTable table = table_8039a5b8; Pair *pp = table.pairs;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    List *l = (List *)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((List *)list.value)->values);
    Handle entry;
    Handle labels(create_8020b680(class_80419e68));
    {
        Labels *t = (Labels *)labels.value;
        String name(n_8039a448);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    for (int i = 0; pp[i].key; i++) {
        ArrayRef *names = &((Labels *)labels.value)->names;
        int count = names->header->count;
        char **s0 = grow(names, count + 1);
        char **slot = s0;
        s0 = 0;
        Key out;
        read_key_800fc2b0(&pp[i], &out);
        string_assign_8020bd38(slot + count, out.name);
        ArrayRef *values = &((List *)list.value)->values;
        int count2 = values->header->count;
        char **vslot = grow(values, count2 + 1);
        string_assign_8020bd38(vslot + count2, pp[i].value);
        ArrayRef *ids = &((Labels *)labels.value)->ids;
        int count3 = ids->header->count;
        int *idslot = (int *)grow(ids, count3 + 1);
        idslot[count3] = self->id;
    }
    list_append_801ef174(list.value, 32, 0, labels.value);
}
