// d25i: 0x8010fd08. Fill a settings list: resolves the list object from the
// table at +60 through a descriptor, clears its value array, creates the label
// table, then walks all settings; for each object setting whose definition has
// type 0x803667a8 and group 2, it appends the setting's name and the
// definition's text (or the key it names). Finally attaches the table to the
// list. Descriptor_80178474 has two written words.
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
    unsigned char unknown00[24];
    ArrayRef labels;    // +24
    ArrayRef values;    // +28
    Field *field;       // +32
};
struct Definition { unsigned char unknown00[44]; int group; unsigned char unknown30[24]; char *text; };
struct Owner { unsigned char unknown00[60]; Object *source; };
extern "C" void *as_table_80341584(Object *);
extern "C" Object *table_get_80179598(void *, Descriptor_80178474 *);
extern "C" void list_begin_801ef380(Object *, int, int, int, int);
extern "C" char **array_lock_801ef048(ArrayRef *, int, int, int);
extern "C" Object *create_8020b680(const void *);
extern "C" Definition *definition_801797b4(void *);
extern "C" int next_setting_800fc69c(int *, Handle *);
extern "C" void string_release_8020bb2c(void *);
extern "C" void string_assign_8020bd38(char **, const char *);
extern "C" int read_key_800fc2b0(Key *, Key *);
extern "C" void list_append_801ef174(Object *, int, int, Object *);
extern const char class_80419e68[];
extern const Type type_803667a8[];

inline bool is_a(const Type *t, const Type *target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
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
extern "C" void d25i_weapon_list_fill_8010fd08(Owner *self) {
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
        if (def->group != 2) continue;
        ArrayRef *labels = &((List *)table.value)->labels;
        int index = labels->header->count;
        char **label = grow(labels, index + 1);
        ArrayRef *values = &((List *)list.value)->values;
        int count = values->header->count;
        char **value = grow(values, count + 1);
        {
            char *text = def->text;
            ++*(unsigned short *)(text - 6);
            index <<= 2;
            char *old = *(char **)(index + (int)label);
            unsigned short *header = (unsigned short *)(old - 6);
            unsigned short n = --*header;
            if (n == 0) string_release_8020bb2c(header);
            *(char **)(index + (int)label) = def->text;
        }
        string_assign_8020bd38((char **)((int)value + index), entry.value->vtable->name(entry.value));
        Key key;
        key.name = def->text;
        Key out;
        if (read_key_800fc2b0(&key, &out) >= 0)
            string_assign_8020bd38((char **)((int)label + index), out.name);
    }
    list_append_801ef174(list.value, 32, 0, table.value);
}
