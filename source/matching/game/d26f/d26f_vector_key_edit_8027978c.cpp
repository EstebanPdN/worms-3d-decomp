// GWMP8P rev0 0x8027978c. Vector property editor key handler. Copies the
// edited Vec3 from the receiver's reflected field; X/Y/Z select a component,
// digits 4 6 8 2 9 3 step it by the editor's step, 0 cycles the step through
// five constants, escape leaves. On a change the vector is stored back and
// the page refreshed. Non-empty text goes to the sink. Field pointer goes
// through a local address of the receiver, as in the sibling at 0x80279dc0.
struct D26fObject { void **methods; };
struct D26fField { unsigned char reserved[4]; unsigned short offset; };
struct D26fFieldRef { D26fField *field; };
struct D26fEditor {
    unsigned char reserved[32];
    void *sink;                        // +32
    unsigned char pad24[8];
    int vector_component;              // +44
    unsigned char pad30[44];
    D26fObject *receiver;              // +92
    int key;                           // +96
    float step;                        // +100
};
struct D26fVec3 {
    float x, y, z;
    D26fVec3(const D26fVec3 &o) { float a = o.x; float b = o.y; float c = o.z; x = a; y = b; z = c; }
};
extern "C" {
D26fFieldRef *w3d_s21_vector_get_801e9db8(void *, int);
void w3d_auto_8027a98c(D26fEditor *);
void w3d_s21_state_dispatch_8027ae00(D26fEditor *);
void w3d_string_default(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_s21_append_position_802cd26c(void *, int, int);
void w3d_cc32b_append_lines_v2_802cc0ac(void *, const char *, int);
void w3d_auto_802cbf2c(void *, const char *, int);
void w3d_k8c_log_float_802cc2d8(void *, float, int);
void w3d_s21_sink_write_indexed_802cbdf8(int, const char *, int);
void w3d_cx7b_script_flag_set_8027a934(D26fEditor *, int);
}
extern char lbl_803ce594[], lbl_803ce5b4[], lbl_803ce5d4[], lbl_803cdfec[], lbl_803ce014[], lbl_803ce020[];
extern float lbl_803ce5f4[], lbl_803ce5f8[], lbl_803ce5fc[], lbl_803ce600[], lbl_803ce604[];
struct D26fText_803426b8 {
    const char *text;
    D26fText_803426b8();
    D26fText_803426b8(const D26fText_803426b8 &);
    ~D26fText_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    unsigned short length() const { return *(unsigned short *)(text - 4); }
    const char *c_str() const { return text; }
};
#define D26F_TYPE(o) (((void *(*)(D26fObject *))(o)->methods[5])(o))
#define D26F_FIELD(T, o, ref) (*(T *)((char *)(o) + (ref)->field->offset))
static inline void store_vec(D26fEditor *self, const D26fVec3 &v) {
    D26fObject *o = self->receiver;
    D26fFieldRef *r = w3d_s21_vector_get_801e9db8(D26F_TYPE(o), self->key);
    D26fObject **slot = &o;
    D26F_FIELD(D26fVec3, *slot, r) = v;
}
extern "C" void d26f_vector_key_edit_8027978c(D26fEditor *self, int key) {
    D26fText_803426b8 text;
    int changed = 0;
    D26fObject *receiver = self->receiver;
    D26fFieldRef *ref = w3d_s21_vector_get_801e9db8(D26F_TYPE(receiver), self->key);
    D26fObject **slot = &receiver;
    D26fVec3 v = D26F_FIELD(D26fVec3, *slot, ref);
    switch (key) {
    case 88: case 120:
        w3d_s21_append_position_802cd26c(&text, 0, 4);
        w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803ce594, 7);
        w3d_s21_append_position_802cd26c(&text, 3, 4);
        self->vector_component = 0;
        w3d_cx7b_script_flag_set_8027a934(self, 0);
        break;
    case 89: case 121:
        w3d_s21_append_position_802cd26c(&text, 0, 5);
        w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803ce5b4, 7);
        w3d_s21_append_position_802cd26c(&text, 3, 5);
        self->vector_component = 1;
        w3d_cx7b_script_flag_set_8027a934(self, 0);
        break;
    case 90: case 122:
        w3d_s21_append_position_802cd26c(&text, 0, 6);
        w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803ce5d4, 7);
        w3d_s21_append_position_802cd26c(&text, 3, 6);
        self->vector_component = 2;
        w3d_cx7b_script_flag_set_8027a934(self, 0);
        break;
    case 27:
        w3d_s21_state_dispatch_8027ae00(self);
        break;
    case 52:
        v.x -= self->step;
        changed = 1;
        w3d_s21_append_position_802cd26c(&text, 3, 4);
        w3d_k8c_log_float_802cc2d8(&text, v.x, 9);
        w3d_s21_append_position_802cd26c(&text, 0, 14);
        break;
    case 54:
        v.x += self->step;
        changed = 1;
        w3d_s21_append_position_802cd26c(&text, 3, 4);
        w3d_k8c_log_float_802cc2d8(&text, v.x, 9);
        w3d_s21_append_position_802cd26c(&text, 0, 14);
        break;
    case 56:
        v.y += self->step;
        changed = 1;
        w3d_s21_append_position_802cd26c(&text, 3, 5);
        w3d_k8c_log_float_802cc2d8(&text, v.y, 9);
        w3d_s21_append_position_802cd26c(&text, 0, 14);
        break;
    case 50:
        v.y -= self->step;
        changed = 1;
        w3d_s21_append_position_802cd26c(&text, 3, 5);
        w3d_k8c_log_float_802cc2d8(&text, v.y, 9);
        w3d_s21_append_position_802cd26c(&text, 0, 14);
        break;
    case 57:
        v.z -= self->step;
        changed = 1;
        w3d_s21_append_position_802cd26c(&text, 3, 6);
        w3d_k8c_log_float_802cc2d8(&text, v.z, 9);
        w3d_s21_append_position_802cd26c(&text, 0, 14);
        break;
    case 51:
        v.z += self->step;
        changed = 1;
        w3d_s21_append_position_802cd26c(&text, 3, 6);
        w3d_k8c_log_float_802cc2d8(&text, v.z, 9);
        w3d_s21_append_position_802cd26c(&text, 0, 14);
        break;
    case 48:
        if (self->step == lbl_803ce5f4[0]) self->step = lbl_803ce5f8[0];
        else if (self->step == lbl_803ce5f8[0]) self->step = lbl_803ce5fc[0];
        else if (self->step == lbl_803ce5fc[0]) self->step = lbl_803ce600[0];
        else if (self->step == lbl_803ce600[0]) self->step = lbl_803ce604[0];
        else if (self->step == lbl_803ce604[0]) self->step = lbl_803ce5f4[0];
        w3d_s21_append_position_802cd26c(&text, 0, 12);
        w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cdfec, 9);
        w3d_k8c_log_float_802cc2d8(&text, self->step, 9);
        w3d_auto_802cbf2c(&text, lbl_803ce014, 9);
        w3d_auto_802cbf2c(&text, lbl_803ce020, 9);
        break;
    }
    if (changed) {
        store_vec(self, v);
        w3d_auto_8027a98c(self);
    }
    if (text.length())
        w3d_s21_sink_write_indexed_802cbdf8((int)self->sink, text.c_str(), 9);
}
