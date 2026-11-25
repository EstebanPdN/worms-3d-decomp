// Appears to build a menu line: it composes a request string from a fixed list of
// text pieces, writes it to the menu's sink at index 9 and clears two menu fields.
extern "C" void w3d_string_default(void *string);
extern "C" void w3d_string_base_finish(void *string);
extern "C" void w3d_string_release(void *string);
struct K9aString
{
    char *text;
    unsigned int storage;
    K9aString() {}
    ~K9aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K9aMenu
{
    char pad0[32];
    void *sink;              // +32
    int first;               // +36
    int second;              // +40
};
extern const char *w3d_pieces_803f4b50[];
extern "C" void w3d_s21_repeat_request_802cd220(K9aString *line);
extern "C" void w3d_auto_802cd128(K9aString *line);
extern "C" void w3d_auto_802cbf2c(K9aString *line, const char *piece, int mode);
extern "C" void w3d_s21_sink_write_indexed_802cbdf8(void *sink, char *text, int index);
extern "C" void w3d_k9a_menu_line_write_80098f24(K9aMenu *self)
{
    K9aString line;
    w3d_string_default(&line);
    w3d_s21_repeat_request_802cd220(&line);
    w3d_auto_802cd128(&line);
    for (const char **piece = w3d_pieces_803f4b50; *piece; piece++)
        w3d_auto_802cbf2c(&line, *piece, 7);
    w3d_s21_sink_write_indexed_802cbdf8(self->sink, line.text, 9);
    self->first = 0;
    self->second = 0;
}
