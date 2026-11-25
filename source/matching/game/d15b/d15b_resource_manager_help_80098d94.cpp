// Graphical Resource Manager debug page: reserves the page's endpoint name and
// builds its key-help line. The original text pieces alternate between two
// line attributes (7 for the key letter, 8 for the rest) and are referenced
// by address; the finished text is copied into a fixed original buffer.
// Partial native views; no owned initialized data.
struct d15b_Text {
    char *text;
    int unknown;
    d15b_Text();
    ~d15b_Text();
};
struct d15b_ResourcePage {
    unsigned char unknown00[32];
    int endpoint;
};
extern "C" int w3d_cx12b_endpoint_name_reserve_802cc4f0(const char *);
extern "C" void w3d_cc32b_append_lines_v2_802cc0ac(d15b_Text *, const char *, int);
extern "C" void w3d_string_base_finish(d15b_Text *);
extern "C" void w3d_string_release(d15b_Text *);
extern "C" char *strcpy(char *, const char *);
inline d15b_Text::~d15b_Text() { w3d_string_base_finish(this); w3d_string_release(this); }
extern const char w3d_text_8037fed8[], w3d_text_8037fef4[], w3d_text_8037ff00[],
    w3d_text_8037ff04[], w3d_text_8037ff0c[], w3d_text_8037ff10[], w3d_text_8037ff1c[],
    w3d_text_8037ff20[], w3d_text_8037ff28[], w3d_text_8037ff2c[], w3d_text_8037ff38[],
    w3d_text_8037ff3c[], w3d_text_8037ff4c[], w3d_text_8037ff50[], w3d_text_8037ff5c[],
    w3d_text_8037ff60[];
extern char w3d_help_line_80435bbc[];

extern "C" void d15b_resource_manager_help_80098d94(d15b_ResourcePage *self) {
    self->endpoint = w3d_cx12b_endpoint_name_reserve_802cc4f0(w3d_text_8037fed8);
    d15b_Text help;
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037fef4, 8);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff00, 7);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff04, 8);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff0c, 7);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff10, 8);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff1c, 7);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff20, 8);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff28, 7);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff2c, 8);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff38, 7);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff3c, 8);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff4c, 7);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff50, 8);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff5c, 7);
    w3d_cc32b_append_lines_v2_802cc0ac(&help, w3d_text_8037ff60, 8);
    strcpy(w3d_help_line_80435bbc, help.text);
}
