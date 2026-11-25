// GWMP8P rev0 0x80279dc0. Vector component editor, sibling of the admitted
// colour editor at 0x80279f54. Observed: edited object at +92, property key
// at +96, component index at +44, sink at +32. The edited Vec3 and the later
// text share the stack slot at +8 because the text lives in an inline
// helper; the text is one word with a user copy constructor. The Vec3 copy
// goes through float temporaries and its assignment is the default one,
// which matches the word copies.
struct D25fObject { void **methods; };
struct D25fField { unsigned char reserved[4]; unsigned short offset; };
struct D25fFieldRef { D25fField *field; };
struct D25fEditor {
    unsigned char reserved[32];
    void *sink;                        // +32
    unsigned char pad24[8];
    int vector_component;              // +44
    int color_component;               // +48
    unsigned char pad34[40];
    D25fObject *receiver;             // +92
    int key;                           // +96
};
struct D25fColor { unsigned char c[4]; };
struct D25fVec3 {
    float x, y, z;
    D25fVec3(const D25fVec3 &o) { float a = o.x; float b = o.y; float c = o.z; x = a; y = b; z = c; }
};
extern "C" {
double atof(const char *);
D25fFieldRef *w3d_s21_vector_get_801e9db8(void *, int);
void w3d_auto_8027a98c(D25fEditor *);
void * w3d_string_default(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_s21_append_position_802cd26c(void *, int, int);
void fn_802cc0ac(void *, const char *, int);
void w3d_s21_sink_write_indexed_802cbdf8(int, const char *, int);
void w3d_cx7b_script_flag_set_8027a934(D25fEditor *, int);
}
extern "C" const char w3d_str_803ce688[];
struct D25fText {
    const char *text;
    D25fText() { w3d_string_default(this); }
    D25fText(const D25fText &);
    ~D25fText() { w3d_string_base_finish(this); w3d_string_release(this); }
    void position(int a, int b) { w3d_s21_append_position_802cd26c(this, a, b); }
    void pad(const char *s, int n) { fn_802cc0ac(this, s, n); }
};
#define D25F_TYPE(o) (((void *(*)(D25fObject *))(o)->methods[5])(o))
#define D25F_FIELD(T, o, ref) (*(T *)((char *)(o) + (ref)->field->offset))
static inline void d25f_store_vec(D25fEditor *self, const D25fVec3 &v)
{
    D25fObject *receiver = self->receiver;
    D25fFieldRef *ref = w3d_s21_vector_get_801e9db8(D25F_TYPE(receiver), self->key);
    D25fObject **slot = &receiver;
    D25F_FIELD(D25fVec3, *slot, ref) = v;
}
inline void d25f_show(D25fEditor *self) {
    D25fText line;
    line.position(0, 14);
    line.pad(w3d_str_803ce688, 7);
    line.position(0, 14);
    w3d_s21_sink_write_indexed_802cbdf8((int)self->sink, line.text, 9);
    w3d_cx7b_script_flag_set_8027a934(self, 1);
    w3d_auto_8027a98c(self);
}
extern "C" void d25f_vector_component_edit_80279dc0(D25fEditor *self, const char *text) {
    if (*text) {
    D25fObject *receiver = self->receiver;
    D25fFieldRef *ref = w3d_s21_vector_get_801e9db8(D25F_TYPE(receiver), self->key);
    D25fObject **slot = &receiver;
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
