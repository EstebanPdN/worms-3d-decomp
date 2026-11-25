// GWMP8P rev0 0x80274e4c. Debug editor page for a drop-down list: prints
// fields, colour, booleans, the item background type by switch, item metrics
// and audio names; final reads through an inline accessor.
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
struct D26fRgba { unsigned char r, g, b, a; };
struct D26fVec { float v[3]; };
struct D26fButton;
struct D26fButtonTable { void *s0[5]; void *(*type_info)(D26fButton *); };
struct D26fButton {
    D26fButtonTable *vt;
    char pad4[112];
    float border_size;
    const char *close_audio;
    const char *open_audio;
    float main_control_font_size;
    float button_area;
    float item_height;
    float drop_height;
    int item_background_type;
    char pad148[4];
    const char *control_highlight_message;
    const char *item_selected_message;
    const char *item_highlight_message;
    const char *index_data_id;
    const char *game_data_id;
    int keep_combo_open;
    int scrollbar_tab_expanding;
    int scrollbar_always_visible;
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
extern char lbl_803cc0d8[], lbl_803cc864[], lbl_803cc86c[], lbl_803cc8b4[], lbl_803ccf30[], lbl_803cd47c[], lbl_803cd544[], lbl_803cd564[], lbl_803cd56c[], lbl_803cd574[], lbl_803cd588[], lbl_803cd5f0[], lbl_803cd604[], lbl_803cd624[], lbl_803cd644[], lbl_803cd664[], lbl_803cd684[], lbl_803cd6a4[], lbl_803cd6c4[], lbl_803cd6e4[], lbl_803cd704[], lbl_803cd724[], lbl_803cd744[], lbl_803cd764[], lbl_803cd784[], lbl_803cd7a4[], lbl_803cd7c4[];
extern "C" void d26f_drop_list_edit_page_80274e4c(D26fEditor *self) {
    w3d_cx7b_script_flag_set_8027a934(self, 1);
    D26fText_803426b8 text;
    w3d_s21_repeat_request_802cd220(&text);
    w3d_auto_802cd128(&text);
    self->mode = 15;
    w3d_auto_802cbf2c(&text, lbl_803cd5f0, 7);
    w3d_auto_802cbf2c(&text, lbl_803ccf30, 7);
    w3d_auto_802cbf2c(&text, lbl_803cc0d8, 9);
    D26fButton *target = self->target;
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd604, 9);
    w3d_auto_802cbf2c(&text, target->game_data_id, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd624, 9);
    w3d_auto_802cbf2c(&text, target->index_data_id, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd47c, 9);
    w3d_auto_802cbf2c(&text, target->item_highlight_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd644, 9);
    w3d_auto_802cbf2c(&text, target->control_highlight_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd664, 9);
    w3d_auto_802cbf2c(&text, target->item_selected_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd684, 9);
    D26fText_803426b8 colour;
    D26fTextStream stream(colour);
    D26fProperty *property = w3d_s21_vector_get_801e9db8(target->vt->type_info(target), 25);
    property->vt->read(property, &stream.descriptor, target);
    w3d_auto_802cbf2c(&text, colour.c_str(), 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd6a4, 9);
    w3d_auto_802cbf2c(&text, target->scrollbar_always_visible == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd6c4, 9);
    w3d_auto_802cbf2c(&text, target->scrollbar_tab_expanding == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd544, 9);
    switch (target->item_background_type) {
    case 0:
        w3d_auto_802cbf2c(&text, lbl_803cd564, 9);
        break;
    case 1:
        w3d_auto_802cbf2c(&text, lbl_803cd56c, 9);
        break;
    case 2:
        w3d_auto_802cbf2c(&text, lbl_803cd574, 9);
        break;
    case 3:
        w3d_auto_802cbf2c(&text, lbl_803cd588, 9);
        break;
    }
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd6e4, 9);
    w3d_auto_802cbfa4(&text, target->drop_height, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd704, 9);
    w3d_auto_802cbfa4(&text, target->item_height, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd724, 9);
    w3d_auto_802cbfa4(&text, target->button_area, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd744, 9);
    w3d_auto_802cbfa4(&text, target->main_control_font_size, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd764, 9);
    w3d_auto_802cbf2c(&text, target->open_audio, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd784, 9);
    w3d_auto_802cbf2c(&text, target->close_audio, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd7a4, 9);
    w3d_auto_802cbfa4(&text, target->border_size, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd7c4, 9);
    w3d_auto_802cbf2c(&text, target->keep_combo_open == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_s21_append_position_802cd26c(&text, 0, 24);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc8b4, 7);
    w3d_s21_sink_write_indexed_802cbdf8((int)self->sink, text.c_str(), 9);
}
