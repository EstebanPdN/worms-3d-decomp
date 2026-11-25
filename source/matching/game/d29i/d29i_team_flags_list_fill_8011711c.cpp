// d29i: 0x8011711c. Team flag list fill: resolves the list from +116, builds a
// label table titled Flags sized 30.0 by 36.0, reads User.Skill and picks flag
// range 115..119 when the skill is set, or 0..109 otherwise, keeping User.Flag
// valid, then adds FE.TeamFlags:%d rows with %d values.
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
struct Owner { unsigned char unknown00[116]; Object *source; };
extern const char class_80419e88[], n_8039a188[], n_8039a958[], n_8039a964[], n_8039a970[], f_8039a974[], f_8039a4c8[];
extern "C" int read_int_800fc230(Key *, int *);
extern "C" int write_800fc550(Key *, const char *);
extern "C" int read_key2_800fc2b0(Key *, Key *);
extern "C" int atoi_802ed89c(const char *);
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
extern "C" void d29i_team_flags_list_fill_8011711c(Owner *self) {
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    List *l = (List *)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((List *)list.value)->values);
    String text;
    Handle a;
    set(a, create_8020b680(class_80419e88));
    {
        Labels *t = (Labels *)a.value;
        String name(n_8039a188);
        char *text = name.text;
        ++*(unsigned short *)(text - 6);
        char *old = t->title;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    unsigned last = 110, first = 0;
    ((Labels *)a.value)->width = 30.0f;
    *(float *)((char *)a.value + 32) = 36.0f;
    Key skill_key;
    skill_key.name = n_8039a958;
    int skill;
    read_int_800fc230(&skill_key, &skill);
    if (skill) {
        String t;
        last = 120;
        first = 115;
        string_format_8020c510(&t, f_8039a4c8, skill + 114);
        Key flag_key;
        flag_key.name = n_8039a964;
        write_800fc550(&flag_key, t.text);
    } else {
        const char *flag = n_8039a964;
        Key flag_key;
        flag_key.name = flag;
        Key out;
        read_key2_800fc2b0(&flag_key, &out);
        if (atoi_802ed89c(out.name) > 114) {
            Key flag_key2;
            flag_key2.name = flag;
            write_800fc550(&flag_key2, n_8039a970);
        }
    }
    ArrayRef *names = &((Labels *)a.value)->names;
    char **s1 = grow(names, names->header->count + (last - first));
    ArrayRef *values = &((List *)list.value)->values;
    char **s2 = grow(values, values->header->count + (last - first));
    for (unsigned i = first; i < last; i++) {
        string_format_8020c510(&text, f_8039a974, i);
        int k = (i - first) * 4;
        store(k, s1, text);
        String t;
        string_format_8020c510(&t, f_8039a4c8, i);
        store(k, s2, t);
    }
    list_append_801ef174(list.value, 32, 0, a.value);
}
