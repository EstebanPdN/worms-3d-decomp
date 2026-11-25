#include "w3d_ptr.h"
#line 1 "d25i_ingame_menu_fill_8011385c.cpp"
// d25i: 0x8011385c. In-game quit menu fill: resolves the list from +108, reads
// GameOver.GameType, uses three entries for Multiplayer and Network games and
// two otherwise, and fills Lang.Continue, Lang.Quit and optionally
// Lang.DrawRound with their pop-up commands and id +40.
struct Type { unsigned char unknown00[20]; Ptr32<const Type> parent; };
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
    Ptr32<Ptr32<const Type> (Ptr32<Object>)> type;  // +20
    Ptr32<int (Ptr32<Object>)> kind;          // +24
    Ptr32<void> unknown1c;
    Ptr32<Ptr32<const char> (Ptr32<Object>)> name;  // +32
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
// Owned type descriptor released through 0x80178474 (two written words).
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Handle {
    Ptr32<Object> value;
    Handle() : value(0) {}
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Object *)w3d_p.get()) {}
 Handle(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
    void assign(Ptr32<Object> next) {
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
    Ptr32<char> data[1];         // +32
};
struct ArrayRef { Ptr32<ArrayHeader> header; };
struct Field { unsigned char unknown00[24]; int count; };
struct List {
    unsigned char unknown00[28];
    ArrayRef commands;  // +28
    Ptr32<Field> field;       // +32
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
    Ptr32<Object> source;     // +108
};
extern "C" Ptr32<void> as_table_80341584(Ptr32<Object>);
extern "C" Ptr32<Object> table_get_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" void list_begin_801ef380(Ptr32<Object>, int, int, int, int);
extern "C" Ptr32<Ptr32<char>> array_lock_801ef048(Ptr32<ArrayRef>, int, int, int);
extern "C" Ptr32<Object> create_8020b680(Ptr32<const void>);
extern "C" void string_assign_8020bd38(Ptr32<Ptr32<char>>, Ptr32<const char>);
extern "C" int read_key_800fc2b0(Ptr32<Key>, Ptr32<Key>);
extern "C" void list_append_801ef174(Ptr32<Object>, int, int, Ptr32<Object>);
extern "C" int strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern const char class_80419e68[], n_8039a630[], n_8039a644[], n_8039a650[], n_8039a658[], n_8039a668[], n_8039a680[], n_8039a68c[], n_8039a6c0[], n_8039a6d0[];
static inline Ptr32<Ptr32<char>> size_to(Ptr32<ArrayRef> array, int count) {
    Ptr32<ArrayHeader> header = array->header;
    if (header->kind == 1 && count == header->count) {
        ++header->locks;
        return header->data;
    }
    return array_lock_801ef048(array, count, 4, 0);
}
static inline void clear(Ptr32<ArrayRef> array) {
    Ptr32<ArrayHeader> header = array->header;
    if (header->kind == 1 && header->count == 0)
        ++header->locks;
    else
        array_lock_801ef048(array, 0, 4, 0);
}
static inline bool same(const String &a, Ptr32<const char> b) { return strcmp_802ef234(a.text, b) == 0; }
extern "C" void d25i_ingame_menu_fill_8011385c(Ptr32<Owner> self) {
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    Ptr32<List> l = (Ptr32<List>)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((Ptr32<List>)list.value)->commands);
    Handle labels(create_8020b680(class_80419e68));
    Key out;
    Key type_key;
    type_key.name = n_8039a630;
    read_key_800fc2b0(&type_key, &out);
    int count = 2;
    String type(out.name);
    if (same(type, n_8039a644) || same(type, n_8039a650))
        count = 3;
    Ptr32<Ptr32<char>> names = size_to(&((Ptr32<Labels>)labels.value)->names, count);
    Ptr32<Ptr32<char>> commands = size_to(&((Ptr32<List>)list.value)->commands, count);
    Ptr32<int> ids = (Ptr32<int>)size_to(&((Ptr32<Labels>)labels.value)->ids, count);
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


