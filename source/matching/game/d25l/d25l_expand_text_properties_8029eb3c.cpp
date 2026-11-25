// GWMP8P rev0 0x8029eb3c. Copies text to the output pointer at 0x804b0e6c,
// replacing each /*NAME*/ marker with the text of the property NAME,
// recursively.
struct PropertyKey { const char *name; PropertyKey(const char *n) : name(n) {} };
struct Item;
struct ItemVt { void *s0[4]; void (*release)(Item *); };
struct Item { ItemVt *vt; };
struct IRef { Item *value; IRef() : value(0) {} IRef(const IRef &); ~IRef() { if (value) value->vt->release(value); } };
extern "C" int w3d_lookup_800fc1b0(const PropertyKey &, Item **);
extern "C" void *w3d_empty_80343744(Item *);
extern "C" const char **w3d_auto_80179170(void *);
extern char *lbl_804b0e6c;
extern "C" void d25l_expand_text_properties_8029eb3c(const char *s)
{
 IRef ref;
 char **out = &lbl_804b0e6c;
 char nul = 0;
 for (;;) {
  signed char c = s[0]; if (c == 0) return; signed char d = s[1];
  if (d == 0) { *(*out)++ = *s; return; }
  if (c == 47 && d == 42) {
   s += 2;
   char buf[128];
   int i = 0; buf[0] = nul; while (1) { signed char a = s[0]; signed char b = s[1]; if (a == 42 && b == 47) { s += 2; break; } buf[i++] = *s; s++; }
   buf[i] = nul;
   if (w3d_lookup_800fc1b0(PropertyKey(buf), &ref.value) >= 0)
    d25l_expand_text_properties_8029eb3c(*w3d_auto_80179170(w3d_empty_80343744(ref.value)));
  } else {
   *(*out)++ = *s; s++;
  }
 }
}
