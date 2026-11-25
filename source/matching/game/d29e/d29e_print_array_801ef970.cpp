// (Worms 3D GameCube PAL, 0x801ef970).
//
// Writes the elements of the array property at the prop's offset in object:
// through the type's write slot if 0x801fff60 says it is a kind-three type,
// otherwise printing each element into a temporary string and writing that;
// elements are separated by the text at 0x803b0d60 plus an optional line
// break and indent, and printing stops with the text at 0x803b0d68 at the
// given limit. Names are inferred.

struct String;
extern "C" void w3d_string_assign(String *, const char *);
extern "C" void w3d_string_append(String *, const char *);
extern "C" void w3d_string_format(String *, const char *, ...);
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
struct String {
  char *p;
  String();
  String(const char *);
  String(const String &);
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};

struct Writer;
struct TypeInfo {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14();
  virtual void print(String &, char *, int, int);
  virtual void a16(); virtual void a17(); virtual void a18();
  virtual void write(Writer *, char *, int);
};
struct Prop { int p0; unsigned short offset; short p6; TypeInfo *type; };
struct PropRef { Prop *prop; };
struct Array { char p[24]; unsigned count; char q[4]; char data[1]; };
extern "C" int w3d_auto_80200050(TypeInfo *);
extern "C" int w3d_s21_kind_is_three_801fff60(TypeInfo *);
extern "C" Writer *w3d_s21_write_text_8020d82c(Writer *, const String &);
extern "C" Writer *w3d_cx8b_text_line_break_8020d5a8(Writer *);
extern "C" Writer *w3d_s21_write_text_8020dbf8(Writer *, const char *);
extern const char lbl_803b0d60[], lbl_803b0d68[];
extern "C" void w3d_d29e_print_array_801ef970(PropRef *self, Writer *w, char *object, unsigned limit, const char *indent) {
  if (!object) return;
  Array *a = *(Array **)(object + self->prop->offset);
  unsigned n = a->count;
  char *p = a->data;
  int size = w3d_auto_80200050(self->prop->type);
  TypeInfo *printer = 0;
  if (w3d_s21_kind_is_three_801fff60(self->prop->type)) printer = self->prop->type;
  String s;
  unsigned i = 0;
  for (;;) {
  goto test;
next:
  if (printer) {
    printer->write(w, p, 0);
  } else {
    self->prop->type->print(s, p, 0, 0);
    w3d_s21_write_text_8020d82c(w, s);
  }
  p += size;
  if (i < n - 1) {
    w3d_s21_write_text_8020dbf8(w, lbl_803b0d60);
    if (indent) w3d_s21_write_text_8020dbf8(w3d_cx8b_text_line_break_8020d5a8(w), indent);
  }
  i++;
test:
  if (i < n) {
    if (i != limit) goto next;
    w3d_s21_write_text_8020dbf8(w, lbl_803b0d68);
  }
  break;
  }
}
