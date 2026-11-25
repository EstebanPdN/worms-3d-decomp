struct Entry { const char *name; const char *value; };
extern struct Entry *fn_802068fc(const char *, int *);
extern int fn_802ef074(const char *, const char *);
extern int atoi(const char *);
int tsonnet_c26_lookup_int_80206920(const char *key, int *out) {
 struct Entry *e = fn_802068fc(key, out);
 if (e == 0) return 0x80004005;
 while (e->name) {
  if (fn_802ef074(e->name, key) == 0) { *out = atoi(e->value); return 0; }
  e++;
 }
 return 0x80004005;
}
