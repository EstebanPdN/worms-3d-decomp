// GWMP8P rev0 0x8028496c. Looks up a named object and returns its team value
// when it is kind 5 and its type chain reaches the team type. Handle,
// string, value and type views are observed; roles are inferred. The empty
// do/while after the early return emits nothing: see the caveat in
// d34f.json.
// Observed handle, string and team list views; roles inferred.
struct Obj { void **table; };
inline void release(Obj *p) { if (p) ((void (*)(Obj *))p->table[4])(p); }
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(const Handle &);
    ~Handle() { release(p); }
};
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *);
struct String_8020bb54 {
    char *text;
    String_8020bb54(const char *);
    String_8020bb54(const String_8020bb54 &);
    ~String_8020bb54() { w3d_string_base_finish(this); w3d_string_release(this); }
};
typedef String_8020bb54 String;
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
inline String_8020bb54::String_8020bb54(const String_8020bb54 &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct Type { char pad[20]; Type *parent; };
struct Value;
struct ValueTable { void *s0[5]; Type *(*type)(Value *); };
struct Value { ValueTable *vt; char pad[24]; int number; };
struct App { char pad[188]; unsigned flags; };
extern App *lbl_804b1788;
extern Type lbl_80366208[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Value *w3d_auto_801797b4(Obj *);
inline void DebugNote(String) {}
template <Type *T> inline bool IsKind(Value *o) {
    Type *c = o->vt->type(o);
    Type *t = T;
    while (c != t) {
        Type *p = c->parent;
        if (c == p) return false;
        c = p;
    }
    return true;
}
extern "C" int d34f_team_value_lookup_8028496c(void *, String name) {
    if (((unsigned short *)name.text)[-2] != 0) {
        if ((lbl_804b1788->flags & 16) != 0) { return 0; do {} while (0); }
        
        Handle h;
        if (w3d_constructor_lookup_name(name.text, h) >= 0) {
            if (((int (*)(Obj *))h.p->table[6])(h.p) == 5 && IsKind<lbl_80366208>(w3d_auto_801797b4(w3d_empty_80341584(h.p))))
                return w3d_auto_801797b4(w3d_empty_80341584(h.p))->number;
            DebugNote(name);
        } else
            DebugNote(name);
    }
    return 0;
}
