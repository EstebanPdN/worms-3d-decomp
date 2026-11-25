#include "w3d_ptr.h"
#line 1 "d32f_unlock_lists_rebuild_80280370.cpp"
// GWMP8P rev0 0x80280370. Rebuilds the five front-end string lists: clears
// them, reads the indexed FE properties through 0x800fc69c into local
// tables, appends every non-empty entry to its list, and appends the fixed
// FE.Unlocked landscape names to the last list. By-value String parameters
// are destroyed by the callee 0x8028496c. Observed partial layouts, roles
// inferred. Uses unmodified STLport 4.5.3 vectors.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct String_803426b8;
typedef String_803426b8 String;
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    template <class W3dU> String_803426b8(Ptr32<W3dU> w3d_p) : String_803426b8((const char *)w3d_p.get()) {}
 String_803426b8(const char *);
    String_803426b8(const String_803426b8 &o) { w3d_string_base_init(this); text = o.text; ++*w3d_string_header(this); }
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    String_803426b8 &operator=(const String_803426b8 &);
    unsigned Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
};
extern "C" Ptr32<String> w3d_string_assign(Ptr32<String>, Ptr32<const char>);
struct Type { char u[20]; Ptr32<Type> parent; };
struct Value;
struct ValueVt { Ptr32<void> u[5]; Ptr32<Ptr32<Type> (Ptr32<Value>)> type; };
struct Value { Ptr32<ValueVt> vt; char u4[24]; String name; unsigned index; char u36[8]; int kind; };
struct Prop;
struct PropVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Prop>)> retain; Ptr32<void (Ptr32<Prop>)> release; Ptr32<void> u20; Ptr32<int (Ptr32<Prop>)> kind; Ptr32<void> u28; Ptr32<Ptr32<const char> (Ptr32<Prop>)> text; };
struct Prop { Ptr32<PropVt> vt; };
struct Handle {
    Ptr32<Prop> p;
    Handle() : p(0) {}
    Handle(const Handle &);
    ~Handle() { if (p) p->vt->release(p); }
};
extern "C" Ptr32<Prop> w3d_empty_80341584(Ptr32<Prop>);
extern "C" Ptr32<Value> w3d_auto_801797b4(Ptr32<Prop>);
extern "C" int w3d_auto_800fc69c(Ptr32<unsigned int>, Ptr32<Handle>);
extern "C" int fn_8028496c(Ptr32<void>, String);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern Type lbl_803667a8[];
extern char lbl_803cee88[], lbl_803cee9c[], lbl_803ceeb0[], lbl_803ceec8[], lbl_803ceedc[], lbl_803ceef0[], lbl_803cef00[], lbl_803cef18[], lbl_803cef2c[], lbl_803cef48[], lbl_803ceb40[];
template <Type *T> inline bool IsKind(Ptr32<Value> o) {
    Ptr32<Type> c = o->vt->type(o);
    Ptr32<Type> t = T;
    while (c != t) {
        Ptr32<Type> p = c->parent;
        if (c == p) return false;
        c = p;
    }
    return true;
}
inline bool Differs(const String &s, Ptr32<const char> t) { return strcmp(s.text, t) != 0; }
struct Lists { char u[28]; std::vector<String> a, b, c, d, e; };
extern "C" void d32f_unlock_lists_rebuild_80280370(Ptr32<Lists> self) {
    self->a.clear();
    self->b.clear();
    self->c.clear();
    self->d.clear();
    self->e.clear();
    String A[70], B[70], C[20], D[70], E[70];
    unsigned k;
    unsigned iter = 0;
    Handle prop;
    while (w3d_auto_800fc69c(&iter, &prop)) {
        if (prop.p->vt->kind(prop.p) == 5 && IsKind<lbl_803667a8>(w3d_auto_801797b4(w3d_empty_80341584(prop.p)))) {
            Ptr32<Value> v = w3d_auto_801797b4(w3d_empty_80341584(prop.p));
            unsigned i = v->index;
            if (!fn_8028496c(self, v->name)) {
                switch (v->kind) {
                case 0:
                    if (i != 99) w3d_string_assign(&A[i], prop.p->vt->text(prop.p));
                    break;
                case 4:
                    if (i != 99) w3d_string_assign(&B[i], prop.p->vt->text(prop.p));
                    break;
                case 3:
                    if (i != 99) w3d_string_assign(&C[i], prop.p->vt->text(prop.p));
                    break;
                case 5:
                    if (i != 99) w3d_string_assign(&D[i], prop.p->vt->text(prop.p));
                    break;
                }
            }
            if (v->kind == 5 && i < 99)
                w3d_string_assign(&E[i], prop.p->vt->text(prop.p));
        }
    }
    for (k = 0; k < 70; k++)
        if (A[k].Length()) self->a.push_back(String(A[k]));
    for (k = 0; k < 70; k++)
        if (B[k].Length()) self->b.push_back(String(B[k]));
    for (k = 0; k < 20; k++)
        if (C[k].Length()) self->c.push_back(String(C[k]));
    for (k = 0; k < 70; k++)
        if (D[k].Length()) self->d.push_back(String(D[k]));
    int n = 0;
    String names[] = { lbl_803cee88, lbl_803cee9c, lbl_803ceeb0, lbl_803ceec8, lbl_803ceedc, lbl_803ceef0, lbl_803cef00, lbl_803cef18, lbl_803cef2c, lbl_803cef48, lbl_803ceb40 };
    for (; Differs(names[n], lbl_803ceb40); n++)
        self->e.push_back(names[n]);
}


