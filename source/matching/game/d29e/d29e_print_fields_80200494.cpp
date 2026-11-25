// (Worms 3D GameCube PAL, 0x80200494).
//
// Formats an object as text: if the global service (0x804b063c) knows the
// type it prints it (slots 3 and 4); otherwise assigns the opening text to
// out, gets the type's field table from 0x80200460 and for each of its count
// fields (byte at +17, 12-byte records at +28) has the field's printer (slot
// 15) write the field value into a temporary string, appends a separator or
// the closing text, formats name and value into a line and appends it.
// Returns 0. Names are inferred.

struct String;
extern "C" String *w3d_string_assign(String *, const char *);
extern "C" String *w3d_string_append(String *, const char *);
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

struct Field {
  const char *name;
  unsigned short pad;
  unsigned short offset;
  struct Ops *ops;
};
struct Ops {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14();virtual void print(String &, void *, void *, int);
};
struct Type { char p[17]; unsigned char count; char q[10]; Field *fields; };
struct Service {
  virtual void v0(); virtual void v1(); virtual void v2();
  virtual int has(void *, void *);
  virtual int print(void *, void *, void *, void *);
};
extern Service *lbl_804b063c;
extern char lbl_8045ed94[];
extern "C" Type *w3d_forward_virtual_80200460(void *);
extern const char lbl_803b2a68[], lbl_803b2a6c[], lbl_803b2a70[], lbl_803b2a74[];
extern "C" int w3d_d29e_print_fields_80200494(void *type, String *out, char *data, void *ctx) {
  if (lbl_804b063c->has(type, lbl_8045ed94))
    return lbl_804b063c->print(data, type, out, lbl_8045ed94);
  String text;
  unsigned i = 0;
  w3d_string_assign(out, lbl_803b2a68);
  Type *t = w3d_forward_virtual_80200460(type);
  unsigned n = t->count;
  while (i < n) {
    Field &fd = t->fields[i];
    fd.ops->print(text, data + fd.offset, ctx, 0);
    if ((int)(i + 1) != (int)n) w3d_string_append(&text, lbl_803b2a6c); else w3d_string_append(&text, lbl_803b2a70); String line; i++;
    w3d_string_format(&line, lbl_803b2a74, fd.name, text.p);
    w3d_string_append(out, line.p);
  }
  return 0;
}
