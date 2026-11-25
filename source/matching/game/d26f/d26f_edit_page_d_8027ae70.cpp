// GWMP8P rev0 0x8027ae70. Debug editor page: prints title and object fields,
// including colour through its property reader, to the text sink; final
// reads through an inline accessor.
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
struct D26fProperty;
struct D26fPropertyTable { void *s0[5]; void (*read)(D26fProperty *, D26fDescriptor *, void *); };
struct D26fProperty { void *w0; D26fPropertyTable *vt; };
struct D26fVec { float v[3]; };
struct D26fButton;
struct D26fButtonTable { void *s0[5]; void *(*type_info)(D26fButton *); };
struct D26fButton {
    D26fButtonTable *vt;
    char pad4[112];
    const char *audio_resource;
    const char *volume_resource;
    float max_equaliser_offset;
    float min_equaliser_offset;
    char pad132[4];
    const char *border_resource;
    const char *selected_message;
    const char *highlighted_message;
    const char *resource_name;
    int border_behind_graphic;
    int square_button;
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
extern char lbl_803cc0d8[], lbl_803cc68c[], lbl_803cc7a4[], lbl_803cc7c4[], lbl_803cc7e4[], lbl_803cc804[], lbl_803cc824[], lbl_803cc844[], lbl_803cc864[], lbl_803cc86c[], lbl_803cc874[], lbl_803cc8b4[], lbl_803cd21c[], lbl_803ce898[], lbl_803ce8b8[], lbl_803ce8d8[], lbl_803ce8f8[];
extern "C" void d26f_edit_page_d_8027ae70(D26fEditor *self) {
    w3d_cx7b_script_flag_set_8027a934(self, 1);
    D26fText_803426b8 text;
    w3d_s21_repeat_request_802cd220(&text);
    w3d_auto_802cd128(&text);
    self->mode = 30;
    w3d_auto_802cbf2c(&text, lbl_803cc68c, 7);
    w3d_auto_802cbf2c(&text, lbl_803cd21c, 7);
    w3d_auto_802cbf2c(&text, lbl_803cc0d8, 9);
    D26fButton *target = self->target;
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc7a4, 9);
    w3d_auto_802cbf2c(&text, target->resource_name, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc7c4, 9);
    w3d_auto_802cbf2c(&text, target->highlighted_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc7e4, 9);
    w3d_auto_802cbf2c(&text, target->selected_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc804, 9);
    w3d_auto_802cbf2c(&text, target->border_resource, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc824, 9);
    D26fText_803426b8 colour;
    D26fTextStream stream(colour);
    D26fProperty *property = w3d_s21_vector_get_801e9db8(target->vt->type_info(target), 24);
    property->vt->read(property, &stream.descriptor, target);
    w3d_auto_802cbf2c(&text, colour.c_str(), 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc844, 9);
    w3d_auto_802cbf2c(&text, target->square_button == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc874, 9);
    w3d_auto_802cbf2c(&text, target->border_behind_graphic == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803ce898, 9);
    w3d_auto_802cbfa4(&text, target->min_equaliser_offset, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803ce8b8, 9);
    w3d_auto_802cbfa4(&text, target->max_equaliser_offset, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803ce8d8, 9);
    w3d_auto_802cbf2c(&text, target->volume_resource, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803ce8f8, 9);
    w3d_auto_802cbf2c(&text, target->audio_resource, 9);
    w3d_s21_append_position_802cd26c(&text, 0, 24);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc8b4, 7);
    w3d_s21_sink_write_indexed_802cbdf8((int)self->sink, text.c_str(), 9);
}
