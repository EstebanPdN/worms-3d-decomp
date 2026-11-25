// GWMP8P rev0 0x80274328. Debug editor page for a scroll list: prints fields
// and colours through the colour stream and formats an RGBA colour; final
// reads through an inline accessor. The text formatter returns nothing.
extern "C" void w3d_string_base_finish(void *);
extern "C" void w3d_string_release(void *);
extern "C" void w3d_string_release_header(void *);
struct D26fText_803426b8 {
    char *text;
    D26fText_803426b8();
    D26fText_803426b8(const D26fText_803426b8 &);
    const char *c_str() const { return text; }
    D26fText_803426b8 &operator=(const D26fText_803426b8 &other) {
        ++*(unsigned short *)(other.text - 6);
        char *old = text;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
    ~D26fText_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" void w3d_tagged_construct_8020d318(void *, D26fText_803426b8 *);
extern "C" void w3d_dtor_node_8020d36c(void *, int);
extern "C" unsigned short w3d_registry_retain_8020d2b8(void *);
struct D26fReader;
extern "C" int w3d_auto_8020d4b8(D26fReader *, int, int, int *);
extern D26fText_803426b8 lbl_804b06a0[];
struct D26fReaderTable { void *s0[3]; void (*retain)(D26fReader *); void (*release)(D26fReader *); };
struct D26fReader {
    D26fReaderTable *vt;
    unsigned words[4];
    D26fText_803426b8 *buffer;
    unsigned size;
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
struct D26fProperty;
struct D26fPropertyTable { void *s0[5]; void (*read)(D26fProperty *, D26fDescriptor *, void *); };
struct D26fProperty { void *w0; D26fPropertyTable *vt; };
struct D26fRgba { unsigned char r, g, b, a; };
struct D26fVec { float v[3]; };
struct D26fButton;
struct D26fButtonTable { void *s0[5]; void *(*type_info)(D26fButton *); };
struct D26fButton {
    D26fButtonTable *vt;
    char pad4[112];
    D26fRgba text_colour;
    float border_width;
    char pad124[12];
    const char *text_game_data_id;
    const char *resource_name;
    int animate;
    int auto_scale;
    int auto_scroll;
};
struct D26fEditor { char pad0[32]; void *sink; int mode; char pad40[52]; D26fButton *target; };
extern "C" void w3d_cx7b_script_flag_set_8027a934(D26fEditor *, int);
extern "C" void w3d_s21_repeat_request_802cd220(D26fText_803426b8 *);
extern "C" void w3d_auto_802cd128(D26fText_803426b8 *);
extern "C" void w3d_auto_802cbf2c(D26fText_803426b8 *, const char *, int);
extern "C" void w3d_cc32b_append_lines_v2_802cc0ac(D26fText_803426b8 *, const char *, int);
extern "C" void w3d_s21_append_position_802cd26c(D26fText_803426b8 *, int, int);
extern "C" void w3d_s21_sink_write_indexed_802cbdf8(int, const char *, int);
extern "C" D26fProperty *w3d_s21_vector_get_801e9db8(void *, int);
extern "C" void w3d_auto_802cbfa4(D26fText_803426b8 *, float, int);
extern "C" void w3d_string_format(D26fText_803426b8 *, const char *, ...);
extern char lbl_803cc0d8[], lbl_803cc7a4[], lbl_803cc864[], lbl_803cc86c[], lbl_803cc8b4[], lbl_803ccbb8[], lbl_803cd20c[], lbl_803cd21c[], lbl_803cd22c[], lbl_803cd24c[], lbl_803cd26c[], lbl_803cd28c[], lbl_803cd2ac[], lbl_803cd2cc[], lbl_803cd2ec[], lbl_803cd30c[];
extern "C" void d26f_scroll_list_edit_page_80274328(D26fEditor *self) {
    w3d_cx7b_script_flag_set_8027a934(self, 1);
    D26fText_803426b8 text;
    w3d_s21_repeat_request_802cd220(&text);
    w3d_auto_802cd128(&text);
    self->mode = 10;
    w3d_auto_802cbf2c(&text, lbl_803cd20c, 7);
    w3d_auto_802cbf2c(&text, lbl_803cd21c, 7);
    w3d_auto_802cbf2c(&text, lbl_803cc0d8, 9);
    D26fButton *target = self->target;
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc7a4, 9);
    w3d_auto_802cbf2c(&text, target->resource_name, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd22c, 9);
    w3d_auto_802cbf2c(&text, target->text_game_data_id, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd24c, 9);
    D26fText_803426b8 colour;
    D26fTextStream stream(colour);
    D26fProperty *property = w3d_s21_vector_get_801e9db8(target->vt->type_info(target), 23);
    property->vt->read(property, &stream.descriptor, target);
    w3d_auto_802cbf2c(&text, colour.c_str(), 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd26c, 9);
    w3d_auto_8020d4b8(&stream.reader, 0, 0, 0);
    *stream.reader.buffer = lbl_804b06a0[0];
    D26fProperty *property2 = w3d_s21_vector_get_801e9db8(target->vt->type_info(target), 24);
    property2->vt->read(property2, &stream.descriptor, target);
    w3d_auto_802cbf2c(&text, colour.c_str(), 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd28c, 9);
    w3d_auto_802cbfa4(&text, target->border_width, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd2ac, 9);
    w3d_auto_802cbf2c(&text, target->auto_scroll == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd2cc, 9);
    w3d_auto_802cbf2c(&text, target->auto_scale == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd2ec, 9);
    const D26fRgba *c = &target->text_colour;
    w3d_string_format(&colour, lbl_803ccbb8, c->r, c->g, c->b, c->a);
    /*FORMAT*/
    w3d_auto_802cbf2c(&text, colour.c_str(), 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd30c, 9);
    w3d_auto_802cbf2c(&text, target->animate == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_s21_append_position_802cd26c(&text, 0, 24);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc8b4, 7);
    w3d_s21_sink_write_indexed_802cbdf8((int)self->sink, text.c_str(), 9);
}
