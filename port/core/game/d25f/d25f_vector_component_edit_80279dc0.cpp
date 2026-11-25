#include "w3d_ptr.h"
#line 1 "d25f_vector_component_edit_80279dc0.cpp"
// GWMP8P rev0 0x80279dc0. Vector component editor, sibling of the admitted
// colour editor at 0x80279f54. Observed: edited object at +92, property key
// at +96, component index at +44, sink at +32. The edited Vec3 and the later
// text share the stack slot at +8 because the text lives in an inline
// helper; the text is one word with a user copy constructor. The Vec3 copy
// goes through float temporaries and its assignment is the default one,
// which matches the word copies.
struct D25fObject { Ptr32<Ptr32<void>> methods; };
struct D25fField { unsigned char reserved[4]; unsigned short offset; };
struct D25fFieldRef { Ptr32<D25fField> field; };
struct D25fEditor {
    unsigned char reserved[32];
    Ptr32<void> sink;                        // +32
    unsigned char pad24[8];
    int vector_component;              // +44
    int color_component;               // +48
    unsigned char pad34[40];
    Ptr32<D25fObject> receiver;             // +92
    int key;                           // +96
};
struct D25fColor { unsigned char c[4]; };
struct D25fVec3 {
    float x, y, z;
    D25fVec3(const D25fVec3 &o) { float a = o.x; float b = o.y; float c = o.z; x = a; y = b; z = c; }
};
extern "C" {
double atof(Ptr32<const char>);
Ptr32<D25fFieldRef> w3d_s21_vector_get_801e9db8(Ptr32<void>, int);
void w3d_auto_8027a98c(Ptr32<D25fEditor>);
Ptr32<void> w3d_string_default(Ptr32<void>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_s21_append_position_802cd26c(Ptr32<void>, int, int);
void fn_802cc0ac(Ptr32<void>, Ptr32<const char>, int);
void w3d_s21_sink_write_indexed_802cbdf8(int, Ptr32<const char>, int);
void w3d_cx7b_script_flag_set_8027a934(Ptr32<D25fEditor>, int);
}
extern "C" const char w3d_str_803ce688[];
struct D25fText {
    Ptr32<const char> text;
    D25fText() { w3d_string_default(this); }
    D25fText(const D25fText &);
    ~D25fText() { w3d_string_base_finish(this); w3d_string_release(this); }
    void position(int a, int b) { w3d_s21_append_position_802cd26c(this, a, b); }
    void pad(Ptr32<const char> s, int n) { fn_802cc0ac(this, s, n); }
};
#define D25F_TYPE(o) (((void *(*)(D25fObject *))(o)->methods[5])(o))
#define D25F_FIELD(T, o, ref) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(o) + (ref)->field->offset))
static inline void d25f_store_vec(Ptr32<D25fEditor> self, const D25fVec3 &v)
{
    Ptr32<D25fObject> receiver = self->receiver;
    Ptr32<D25fFieldRef> ref = w3d_s21_vector_get_801e9db8(D25F_TYPE(receiver), self->key);
    Ptr32<Ptr32<D25fObject>> slot = &receiver;
    D25F_FIELD(D25fVec3, *slot, ref) = v;
}
inline void d25f_show(Ptr32<D25fEditor> self) {
    D25fText line;
    line.position(0, 14);
    line.pad(w3d_str_803ce688, 7);
    line.position(0, 14);
    w3d_s21_sink_write_indexed_802cbdf8((int)w3d::H(self->sink), line.text, 9);
    w3d_cx7b_script_flag_set_8027a934(self, 1);
    w3d_auto_8027a98c(self);
}
extern "C" void d25f_vector_component_edit_80279dc0(Ptr32<D25fEditor> self, Ptr32<const char> text) {
    if (*text) {
    Ptr32<D25fObject> receiver = self->receiver;
    Ptr32<D25fFieldRef> ref = w3d_s21_vector_get_801e9db8(D25F_TYPE(receiver), self->key);
    Ptr32<Ptr32<D25fObject>> slot = &receiver;
    D25fVec3 v = D25F_FIELD(D25fVec3, *slot, ref);
    switch (self->vector_component) {
    case 0: v.x = atof(text); break;
    case 1: v.y = atof(text); break;
    case 2: v.z = atof(text); break;
    }
    d25f_store_vec(self, v);
    }
    d25f_show(self);
}


