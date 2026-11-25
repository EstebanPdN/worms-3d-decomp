// GWMP8P rev0 0x80263e18. Fills the FE.TempList resource list with generated
// label strings: twenty plain names, then eight groups of indexed names and
// colours. Names are inferred from use; List, Labels and Colour are partial
// views.
struct Object;
struct ObjectVtable { void *u0[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Key { const char *name; };
struct Descriptor_80178474 {
 void *value; unsigned tag;
 Descriptor_80178474() : value(0), tag(58280) {}
 ~Descriptor_80178474();
};
struct Handle {
 Object *value;
 Handle() : value(0) {}
 Handle(Object *next) : value(next) { if (value) value->vtable->retain(value); }
 Handle(const Handle &);
 ~Handle() { if (value) value->vtable->release(value); }
};
struct ArrayHeader { unsigned char u0[4]; unsigned short kind; unsigned char u6[18]; int count; unsigned short locks; unsigned char u1e[2]; char *data[1]; };
struct ArrayRef { ArrayHeader *header; };
struct List { unsigned char u0[28]; ArrayRef values; };
struct Labels { unsigned char u0[24]; ArrayRef names; unsigned char u1c[8]; float width; char *title; unsigned char u2c[4]; ArrayRef ids; };
struct Str_803426b8 { char *text; Str_803426b8(); Str_803426b8(const Str_803426b8 &); ~Str_803426b8(); };
typedef Str_803426b8 String;
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline Str_803426b8::~Str_803426b8() { string_finish_8020c5c4(this); string_release_80341588(this); }
extern "C" void *as_table_80341584(Object *);
extern "C" Object *table_get_80179598(void *, Descriptor_80178474 *);
extern "C" char **array_lock_801ef048(ArrayRef *, int, int, int);
extern "C" Labels *create_8020b680(const void *);
extern "C" void string_release_8020bb2c(void *);
extern "C" void string_format_8020c510(String *, const char *, ...);
extern "C" void list_append_801ef174(Object *, int, int, Labels *);
extern "C" int read_setting_800fc1b0(Key *, Handle *);
extern const char class_80419e68[], class_80419e88[], n_803cb20c[], f_803cb23c[], f_803cb24c[], f_803cb258[], f_803cb264[];
struct Colour { unsigned char r, g, b; signed char a; };
static inline char **grow(ArrayRef *array, int count) {
 ArrayHeader *header = array->header;
 if (header->kind == 1 && count == header->count) { ++header->locks; return header->data; }
 return array_lock_801ef048(array, count, 4, 2);
}
static inline void set(Handle &h, Object *next) {
 if (next) { next->vtable->retain(next); if (h.value) h.value->vtable->release(h.value); h.value = next; }
}
static inline void fetch(Handle &list, Object *src, Descriptor_80178474 *d) {
 Handle value(table_get_80179598(as_table_80341584(src), d));
 set(list, value.value);
}
static inline void store(char *&to, const String &s) {
 char *text = s.text;
 ++*(unsigned short *)(text - 6);
 char *old = to;
 unsigned short *header = (unsigned short *)(old - 6);
 unsigned short n = --*header;
 if (n == 0) string_release_8020bb2c(header);
 to = s.text;
}
inline Labels *Make(const char *c) { return create_8020b680(c); }
extern "C" void w3d_d40k_temp_list_labels_80263e18() {
 Handle lookup;
 Key key;
 key.name = n_803cb20c;
 if (read_setting_800fc1b0(&key, &lookup) < 0) return;
 Descriptor_80178474 descriptor;
 Handle list;
 set(list, Handle(table_get_80179598(as_table_80341584(lookup.value), &descriptor)).value);
 String name;

 ArrayRef *r = &((List *)list.value)->values;
 char **v = grow(r, r->header->count + 20);
 for (unsigned i = 0; i < 20; i++) {
  string_format_8020c510(&name, f_803cb23c, i);
  store(v[i], name);
 }
 for (unsigned j = 0; j < 8; j++) {
  string_format_8020c510(&name, f_803cb24c, j);
  if (j > 2) {
   Labels *a = Make(class_80419e68);
   store(a->title, name);
   a->width = 16.666666f;
   char **n = grow(&a->names, a->names.header->count + 20);
   Colour *c = (Colour *)grow(&a->ids, a->ids.header->count + 20);
   unsigned char k = (unsigned char)j * 25;
   for (unsigned i = 0; i < 20; i++) {
    string_format_8020c510(&name, f_803cb258, i, j);
    store(n[i], name);
    c[i].r = k;
    c[i].g = (unsigned char)i * 12;
    c[i].b = 100;
    c[i].a = -1;
   }
   list_append_801ef174(list.value, 32, 0, a);
  } else {
   Labels *a = Make(class_80419e88);
   store(a->title, name);
   a->width = 28.0f;
   char **n = grow(&a->names, a->names.header->count + 20);
   for (unsigned i = 0; i < 20; i++) {
    string_format_8020c510(&name, f_803cb264, i + j);
    store(n[i], name);
   }
   list_append_801ef174(list.value, 32, 0, a);
  }
 }
}
