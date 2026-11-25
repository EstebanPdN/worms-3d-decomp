// GWMP8P rev0 0x802761b8. Debug editor page for one reflected property of
// the selected item. The property's type code chooses the prompt: string,
// colour or vector, named enumerations, and the plain integer, float and
// boolean editors. Each sets the editor's mode and whether the prompt echoes
// keys, then writes the text to the sink.
extern "C" void w3d_string_base_finish(void *);
extern "C" void w3d_string_release(void *);
struct D26fText_803426b8 {
    char *text;
    D26fText_803426b8();
    D26fText_803426b8(const D26fText_803426b8 &);
    const char *c_str() const { return text; }
    ~D26fText_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" void w3d_tagged_construct_8020d318(void *, D26fText_803426b8 *);
extern "C" void w3d_dtor_node_8020d36c(void *, int);
extern "C" unsigned short w3d_registry_retain_8020d2b8(void *);
struct D26fReader;
struct D26fReaderTable { void *s0[3]; void (*retain)(D26fReader *); void (*release)(D26fReader *); };
struct D26fReader {
    D26fReaderTable *vt;
    unsigned words[6];
    D26fReader(D26fText_803426b8 &t) { w3d_tagged_construct_8020d318(this, &t); }
    ~D26fReader() { w3d_dtor_node_8020d36c(this, 2); }
};
struct D26fDescriptor {
    D26fReader *p;
    unsigned type : 7;
    unsigned flag : 1;
    unsigned size : 8;
    unsigned format : 5;
    unsigned tail : 11;
    D26fDescriptor(const D26fDescriptor &);
    D26fDescriptor(D26fReader &r) : p(&r) {
        if (p) p->vt->retain(p);
        type = 10;
        flag = 0;
        size = 0;
        format = 6;
        w3d_registry_retain_8020d2b8(&r);
    }
    ~D26fDescriptor() { if (p) p->vt->release(p); }
};
struct D26fTextStream {
    D26fReader reader;
    D26fDescriptor descriptor;
    D26fTextStream(D26fText_803426b8 &t) : reader(t), descriptor(reader) {}
};

struct D26fObject;
struct D26fFieldName { const char *name; };
struct D26fField { char pad0[4]; unsigned short offset; char pad6[2]; void *type_key; D26fFieldName *name; };
struct D26fProperty;
struct D26fPropertyTable { void *s0[5]; void (*read)(D26fProperty *, D26fDescriptor *, void *); };
struct D26fProperty { D26fField *field; D26fPropertyTable *vt; };
struct D26fObjectTable { void *s0[5]; void *(*type_info)(D26fObject *); };
struct D26fObject { D26fObjectTable *vt; };
struct D26fEditor { char pad0[32]; void *sink; int mode; char pad40[56]; int key; float step; };
struct D26fColor { unsigned char r, g, b, a; };
struct D26fVec { float x, y, z; };
extern "C" void w3d_cx7b_script_flag_set_8027a934(D26fEditor *, int);
extern "C" void w3d_s21_repeat_request_802cd220(D26fText_803426b8 *);
extern "C" void w3d_auto_802cd128(D26fText_803426b8 *);
extern "C" void w3d_auto_802cbf2c(D26fText_803426b8 *, const char *, int);
extern "C" void w3d_cc32b_append_lines_v2_802cc0ac(D26fText_803426b8 *, const char *, int);
extern "C" void w3d_auto_802cbf68(D26fText_803426b8 *, int, int);
extern "C" void w3d_auto_802cbfa4(D26fText_803426b8 *, float, int);
extern "C" void w3d_k8c_log_float_802cc2d8(D26fText_803426b8 *, float, int);
extern "C" void w3d_s21_sink_write_indexed_802cbdf8(int, const char *, int);
extern "C" D26fProperty *w3d_s21_vector_get_801e9db8(void *, int);
extern "C" int w3d_auto_801fffc8(void *);
extern "C" int w3d_auto_801ffea8(void *);
extern "C" int strcmp(const char *, const char *);
extern char lbl_8045e23c[];
#define L(a) extern char lbl_##a[];
L(803cc0d8) L(803cde24) L(803cde3c) L(803cde54) L(803cde68) L(803cde80) L(803cdeb8) L(803cdec4) L(803cded0) L(803cdedc) L(803cdee8)
L(803cdf10) L(803cdf14) L(803cdf18) L(803cdf1c) L(803cdf50) L(803cdf84) L(803cdfb8) L(803cdfec) L(803ce014) L(803ce020)
L(803ce048) L(803ce05c) L(803ce06c) L(803ce084) L(803ce094) L(803ce09c) L(803ce0a8) L(803ce0b4) L(803ce0c0) L(803ce0c8) L(803ce0e0) L(803ce0f4) L(803ce114) L(803ce120) L(803ce130) L(803ce140) L(803ce150) L(803ce164) L(803ce174) L(803ce184) L(803ce198) L(803ce1a8) L(803ce1c0) L(803ce1d4) L(803ce1e4) L(803ce1f8) L(803ce208) L(803ce21c) L(803ce238) L(803ce25c) L(803ce264) L(803ce270) L(803ce284) L(803ce2d0) L(803ce2e4) L(803ce300) L(803ce314) L(803ce32c) L(803ce340)
#undef L
#define GET(o, k) w3d_s21_vector_get_801e9db8((o)->vt->type_info(o), k)
#define P(s) w3d_auto_802cbf2c(&text, lbl_##s, 9)
#define N(s) w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_##s, 9)
#define READ(o, k) { D26fProperty *rp = GET(o, k); rp->vt->read(rp, &stream.descriptor, o); }
extern "C" void d26f_property_value_page_802761b8(D26fEditor *self, D26fObject *target, int key) {
    D26fText_803426b8 text;
    D26fText_803426b8 value;
    D26fTextStream stream(value);
    self->key = key;
    w3d_s21_repeat_request_802cd220(&text);
    w3d_auto_802cd128(&text);
    w3d_auto_802cbf2c(&text, lbl_803cde24, 7);
    w3d_auto_802cbf2c(&text, lbl_803cde3c, 7);
    P(803cc0d8);
    switch (w3d_auto_801fffc8(GET(target, key)->field->type_key)) {
    case 15:
        N(803cde54);
        READ(target, key);
        w3d_auto_802cbf2c(&text, value.c_str(), 9);
        P(803cde68);
        w3d_cx7b_script_flag_set_8027a934(self, 0);
        self->mode = 20;
        break;
    case 29:
        if (GET(target, key)->field->type_key == lbl_8045e23c) {
            unsigned offset = GET(target, key)->field->offset;
            P(803cde80);
            N(803cdeb8);
            D26fColor *c = (D26fColor *)((char *)target + offset);
            w3d_auto_802cbf68(&text, c->r, 9);
            N(803cdec4);
            w3d_auto_802cbf68(&text, c->g, 9);
            N(803cded0);
            w3d_auto_802cbf68(&text, c->b, 9);
            N(803cdedc);
            w3d_auto_802cbf68(&text, c->a, 9);
            P(803cc0d8);
            P(803cdee8);
            w3d_cx7b_script_flag_set_8027a934(self, 1);
            self->mode = 22;
        } else {
            unsigned offset = GET(target, key)->field->offset;
            P(803cde80);
            N(803cdf10);
            D26fVec *v = (D26fVec *)((char *)target + offset);
            w3d_auto_802cbfa4(&text, v->x, 9);
            N(803cdf14);
            w3d_auto_802cbfa4(&text, v->y, 9);
            N(803cdf18);
            w3d_auto_802cbfa4(&text, v->z, 9);
            P(803cc0d8);
            P(803cdf1c);
            P(803cdf50);
            P(803cdf84);
            P(803cdfb8);
            N(803cdfec);
            w3d_k8c_log_float_802cc2d8(&text, self->step, 9);
            P(803ce014);
            P(803ce020);
            w3d_cx7b_script_flag_set_8027a934(self, 1);
            self->mode = 21;
        }
        break;
    case 22: {
        D26fProperty *rp = GET(target, key);
        if (!strcmp(rp->field->name->name, lbl_803ce048)) {
            READ(target, key);
            N(803ce05c);
            w3d_auto_802cbf2c(&text, value.c_str(), 9);
            P(803ce06c); P(803ce084); P(803ce094); P(803ce09c); P(803ce0a8); P(803ce0b4); P(803ce0c0);
            w3d_cx7b_script_flag_set_8027a934(self, 1);
            self->mode = 23;
        } else if (!strcmp(rp->field->name->name, lbl_803ce0c8)) {
            READ(target, key);
            N(803ce0e0);
            w3d_auto_802cbf2c(&text, value.c_str(), 9);
            P(803ce0f4); P(803ce114); P(803ce120); P(803ce130); P(803ce140); P(803ce150); P(803ce164); P(803ce174); P(803ce184); P(803ce198);
            w3d_cx7b_script_flag_set_8027a934(self, 1);
            self->mode = 27;
        } else if (!strcmp(rp->field->name->name, lbl_803ce1a8)) {
            READ(target, key);
            N(803ce1c0);
            w3d_auto_802cbf2c(&text, value.c_str(), 9);
            P(803ce0f4); P(803ce114); P(803ce120); P(803ce130); P(803ce1d4); P(803ce1e4); P(803ce1f8);
            w3d_cx7b_script_flag_set_8027a934(self, 1);
            self->mode = 28;
        } else if (!strcmp(rp->field->name->name, lbl_803ce208)) {
            READ(target, key);
            N(803ce21c);
            w3d_auto_802cbf2c(&text, value.c_str(), 9);
            P(803ce238); P(803ce25c); P(803ce264); P(803ce270); P(803ce284);
            w3d_cx7b_script_flag_set_8027a934(self, 1);
            self->mode = 17;
        }
        break;
    }
    case 8:
        N(803ce2d0);
        READ(target, key);
        w3d_auto_802cbf2c(&text, value.c_str(), 9);
        P(803ce2e4);
        w3d_cx7b_script_flag_set_8027a934(self, 0);
        self->mode = 24;
        break;
    case 11:
        N(803ce300);
        READ(target, key);
        w3d_auto_802cbf2c(&text, value.c_str(), 9);
        P(803ce314);
        w3d_cx7b_script_flag_set_8027a934(self, 0);
        self->mode = 25;
        break;
    case 1:
        N(803ce32c);
        READ(target, key);
        w3d_auto_802cbf2c(&text, value.c_str(), 9);
        P(803ce340);
        self->mode = 26;
        break;
    default:
        w3d_auto_801ffea8(GET(target, key)->field->type_key);
        w3d_auto_801fffc8(GET(target, key)->field->type_key);
        break;
    }
    w3d_s21_sink_write_indexed_802cbdf8((int)self->sink, text.c_str(), 9);
}
