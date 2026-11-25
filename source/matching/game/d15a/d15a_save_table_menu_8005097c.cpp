// Save-data table menu text (GWMP8P 0x8005097c, 292 bytes).
// Builds the save-bank menu: an introduction line, a blank separator, one
// "%c. %s" line per save bank (14 banks; key character from the small-data key
// table, label from the label table), a positioned footer prompt, then writes
// the text to the owner's sink and moves the menu to state 5.
// The formatter at 0x8020c510 is declared void here: its body ends in a call
// whose r3 it leaves unchanged, and this caller's original argument scheduling
// (receiver before format address) is reproduced only by a void declaration,
// as in other admitted callers.
// Strings and tables are original objects referenced by address; this unit
// owns no initialized data.

struct D15aText_803426b8
{
 D15aText_803426b8(const D15aText_803426b8 &);
    char *text;
    D15aText_803426b8();
    ~D15aText_803426b8();
};

struct D15aSaveMenu_8005097c
{
    char unknown0[28];
    void *sink;         // +28
    unsigned unknown32;
    unsigned state;     // +36
};

extern "C" {
void w3d_d15a_text_reset_802cd220(void *text);
void w3d_d15a_text_clear_802cd128(void *text);
void w3d_d15a_text_append_802cbf2c(void *text, const char *line, int colour);
void w3d_d15a_text_format_8020c510(void *text, const char *format, ...);
void w3d_string_base_finish(void *text);
void w3d_string_release(void *text);
void w3d_d15a_text_position_802cd26c(void *text, int x, int y);
void w3d_d15a_text_append_lines_802cc0ac(void *text, const char *lines, int colour);
void w3d_d15a_sink_write_802cbdf8(int sink, const char *text, int colour);
}

extern char w3d_d15a_intro_80377f98[];       // "Save Data Table : Please select ..."
extern char w3d_d15a_separator_80377fdc[];   // ""
extern char w3d_d15a_line_format_80377fe0[]; // "%c. %s"
extern char w3d_d15a_prompt_80377fe8[];      // "Press escape to cancel, or space to save everything."
extern const char *w3d_d15a_bank_labels_803fcc90[];
extern const char *w3d_d15a_bank_keys_804aa9fc;

inline D15aText_803426b8::~D15aText_803426b8()
{
    w3d_string_base_finish(this);
    w3d_string_release(this);
}

extern "C" void w3d_d15a_save_table_menu_8005097c(D15aSaveMenu_8005097c *menuOwner)
{
    unsigned bank = 0;
    D15aText_803426b8 menu;
    w3d_d15a_text_reset_802cd220(&menu);
    w3d_d15a_text_clear_802cd128(&menu);
    w3d_d15a_text_append_802cbf2c(&menu, w3d_d15a_intro_80377f98, 7);
    w3d_d15a_text_append_802cbf2c(&menu, w3d_d15a_separator_80377fdc, 9);
    const char **label = w3d_d15a_bank_labels_803fcc90;
    do
    {
        D15aText_803426b8 line;
        const char *name = *label;
        char key = w3d_d15a_bank_keys_804aa9fc[bank];
        ++label;
        ++bank;
        w3d_d15a_text_format_8020c510(&line, w3d_d15a_line_format_80377fe0, (int)key, name);
        w3d_d15a_text_append_802cbf2c(&menu, line.text, 9);
    } while (bank < 14);
    w3d_d15a_text_position_802cd26c(&menu, 0, 24);
    w3d_d15a_text_append_lines_802cc0ac(&menu, w3d_d15a_prompt_80377fe8, 7);
    w3d_d15a_sink_write_802cbdf8((int)menuOwner->sink, menu.text, 9);
    menuOwner->state = 5;
}
