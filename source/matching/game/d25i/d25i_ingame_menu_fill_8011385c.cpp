// d25i: 0x8011385c. In-game quit menu fill: resolves the list from +108, reads
// GameOver.GameType, uses three entries for Multiplayer and Network games and
// two otherwise, and fills Lang.Continue, Lang.Quit and optionally
// Lang.DrawRound with their pop-up commands and id +40.
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
    ArrayRef commands;  // +28
    Field *field;       // +32
};
struct Labels {
    unsigned char unknown00[24];
    ArrayRef names;     // +24
    unsigned char unknown1c[20];
    ArrayRef ids;       // +48
};
struct Owner {
    unsigned char unknown00[40];
    int id;             // +40
    unsigned char unknown2c[64];
    Object *source;     // +108
};
extern "C" void *as_table_80341584(Object *);
extern "C" Object *table_get_80179598(void *, Descriptor_80178474 *);
extern "C" void list_begin_801ef380(Object *, int, int, int, int);
extern "C" char **array_lock_801ef048(ArrayRef *, int, int, int);
extern "C" Object *create_8020b680(const void *);
extern "C" void string_assign_8020bd38(char **, const char *);
extern "C" int read_key_800fc2b0(Key *, Key *);
extern "C" void list_append_801ef174(Object *, int, int, Object *);
extern "C" int strcmp_802ef234(const char *, const char *);
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
extern const char class_80419e68[], n_8039a630[], n_8039a644[], n_8039a650[], n_8039a658[], n_8039a668[], n_8039a680[], n_8039a68c[], n_8039a6c0[], n_8039a6d0[];
static inline char **size_to(ArrayRef *array, int count) {
    ArrayHeader *header = array->header;
    if (header->kind == 1 && count == header->count) {
        ++header->locks;
        return header->data;
    }
    return array_lock_801ef048(array, count, 4, 0);
}
static inline void clear(ArrayRef *array) {
    ArrayHeader *header = array->header;
    if (header->kind == 1 && header->count == 0)
        ++header->locks;
    else
        array_lock_801ef048(array, 0, 4, 0);
}
static inline bool same(const String &a, const char *b) { return strcmp_802ef234(a.text, b) == 0; }
extern "C" void d25i_ingame_menu_fill_8011385c(Owner *self) {
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    List *l = (List *)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((List *)list.value)->commands);
    Handle labels(create_8020b680(class_80419e68));
    Key out;
    Key type_key;
    type_key.name = n_8039a630;
    read_key_800fc2b0(&type_key, &out);
    int count = 2;
    String type(out.name);
    if (same(type, n_8039a644) || same(type, n_8039a650))
        count = 3;
    char **names = size_to(&((Labels *)labels.value)->names, count);
    char **commands = size_to(&((List *)list.value)->commands, count);
    int *ids = (int *)size_to(&((Labels *)labels.value)->ids, count);
    Key key;
    key.name = n_8039a658;
    read_key_800fc2b0(&key, &out);
    string_assign_8020bd38(names, out.name);
    string_assign_8020bd38(commands, n_8039a668);
    ids[0] = self->id;
    Key key2;
    key2.name = n_8039a680;
    read_key_800fc2b0(&key2, &out);
    string_assign_8020bd38(names + 1, out.name);
    string_assign_8020bd38(commands + 1, n_8039a68c);
    ids[1] = self->id;
    if ((unsigned)count > 2) {
        Key key3;
        key3.name = n_8039a6c0;
        read_key_800fc2b0(&key3, &out);
        string_assign_8020bd38(names + 2, out.name);
        string_assign_8020bd38(commands + 2, n_8039a6d0);
        ids[2] = self->id;
    }
    list_append_801ef174(list.value, 32, 0, labels.value);
}
