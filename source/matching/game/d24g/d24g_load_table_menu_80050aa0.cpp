/* Worms 3D GameCube PAL 0x80050aa0. Load-data table menu text: writes the introduction, a line per save bank (14 banks), a positioned prompt and the current loading format (Binary, XML, or Unknown, which resets the format to XML), then writes it to the sink and moves to state 4. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Text {
    char *text;
    Text();
    ~Text();
    Text(const Text &);
};
struct Console { char u0[28]; void *sink; char u32[4]; int state; char u40[16]; int format; };
extern "C" {
void text_reset_802cd220(void *);
void text_clear_802cd128(void *);
void text_append_802cbf2c(void *, const char *, int);
void text_format_8020c510(void *, const char *, ...);
void string_finish_8020c5c4(void *);
void string_release_80341588(void *);
void text_position_802cd26c(void *, int, int);
void text_lines_802cc0ac(void *, const char *, int);
void sink_write_802cbdf8(int, const char *, int);
}
inline Text::~Text() { string_finish_8020c5c4(this); string_release_80341588(this); }
extern char s_80378020[], s_80377fdc[], s_80377fe0[], s_80378064[], s_803780b4[], s_803780d4[], s_803780f4[];
extern const char *labels_803fcc90[];
extern const char *keys_804aa9fc;
extern "C" void w3d_d24g_load_table_menu_80050aa0(Console *self)
{
    unsigned bank = 0;
    Text menu;
    text_reset_802cd220(&menu);
    text_clear_802cd128(&menu);
    text_append_802cbf2c(&menu, s_80378020, 1);
    text_append_802cbf2c(&menu, s_80377fdc, 9);
    const char **label = labels_803fcc90;
    do {
        Text line;
        const char *name = *label;
        char key = keys_804aa9fc[bank];
        ++label;
        ++bank;
        text_format_8020c510(&line, s_80377fe0, (int)key, name);
        text_append_802cbf2c(&menu, line.text, 9);
    } while (bank < 14);
    text_position_802cd26c(&menu, 0, 23);
    text_append_802cbf2c(&menu, s_80378064, 1);
    switch (self->format) {
    case 1:
        text_lines_802cc0ac(&menu, s_803780b4, 9);
        break;
    case 2:
        text_lines_802cc0ac(&menu, s_803780d4, 9);
        break;
    default:
        text_lines_802cc0ac(&menu, s_803780f4, 9);
        self->format = 2;
        break;
    }
    sink_write_802cbdf8((int)self->sink, menu.text, 9);
    self->state = 4;
}
