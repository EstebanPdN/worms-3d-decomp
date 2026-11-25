// cc17d: vector component editor 0x80279dc0 (sibling of cc17d 0x80279f54).
// Observed: the editor holds the edited object at +92 and a property key at
// +96 (field located as in cc17d_prop_edit_8027a2c4), a component index at
// +44 (vector) / +48 (colour) and an output sink at +32.  After storing, a
// default string is passed through 0x802cd26c / 0x802cc0ac (with the original
// blank literal at 0x803ce688 and 7) / 0x802cd26c, written to the sink with
// 9, and 0x8027a934 is called with 1 (inferred: refresh of the edit line).
struct Cc17dObject { void **methods; };
struct Cc17dField { unsigned char reserved[4]; unsigned short offset; };
struct Cc17dFieldRef { Cc17dField *field; };
struct Cc17dEditor {
    unsigned char reserved[32];
    void *sink;                        // +32
    unsigned char pad24[8];
    int vector_component;              // +44
    int color_component;               // +48
    unsigned char pad34[40];
    Cc17dObject *receiver;             // +92
    int key;                           // +96
};
struct Cc17dColor { unsigned char c[4]; };
struct Cc17dVec3 {
    float x, y, z;
    Cc17dVec3(const Cc17dVec3 &o) : x(o.x), y(o.y), z(o.z) {}
    void operator=(const Cc17dVec3 &o) { x = o.x; y = o.y; z = o.z; }
};
extern "C" {
long atol(const char *);
double atof(const char *);
Cc17dFieldRef *w3d_s21_vector_get_801e9db8(void *, int);
void w3d_auto_8027a98c(Cc17dEditor *);
void w3d_string_default(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_s21_append_position_802cd26c(void *, int, int);
void fn_802cc0ac(void *, const char *, int);
void w3d_s21_sink_write_indexed_802cbdf8(void *, const char *, int);
void w3d_cx7b_script_flag_set_8027a934(Cc17dEditor *, int);
}
extern "C" const char w3d_str_803ce688[];
struct Cc17dText {
    const char *text;
    int unknown;
    Cc17dText() { w3d_string_default(this); }
    ~Cc17dText() { w3d_string_base_finish(this); w3d_string_release(this); }
    void position(int a, int b) { w3d_s21_append_position_802cd26c(this, a, b); }
    void pad(const char *s, int n) { fn_802cc0ac(this, s, n); }
};
#define CC17D_TYPE(o) (((void *(*)(Cc17dObject *))(o)->methods[5])(o))
#define CC17D_FIELD(T, o, ref) (*(T *)((char *)(o) + (ref)->field->offset))
static inline void cc17d_store_vec(Cc17dEditor *self, const Cc17dVec3 &v)
{
    Cc17dObject *receiver = self->receiver;
    Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
    Cc17dObject **slot = &receiver;
    CC17D_FIELD(Cc17dVec3, *slot, ref) = v;
}
extern "C" void w3d_cc17d_vector_edit_80279dc0(Cc17dEditor *self, const char *text)
{
    if (*text) {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver;
        Cc17dVec3 v = CC17D_FIELD(Cc17dVec3, *slot, ref);
        switch (self->vector_component) {
        case 0: v.x = atof(text); break;
        case 1: v.y = atof(text); break;
        case 2: v.z = atof(text); break;
        }
        cc17d_store_vec(self, v);
    }
    Cc17dText line;
    line.position(0, 14);
    line.pad(w3d_str_803ce688, 7);
    line.position(0, 14);
    w3d_s21_sink_write_indexed_802cbdf8(self->sink, line.text, 9);
    w3d_cx7b_script_flag_set_8027a934(self, 1);
    w3d_auto_8027a98c(self);
}
