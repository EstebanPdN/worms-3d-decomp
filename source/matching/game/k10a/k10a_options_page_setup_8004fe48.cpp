// Appears to build an options page line: after two sink preparation calls it
// composes a string from three text pieces (the third repeated twenty times),
// writes it to the sink at index 9, resets the page state and refreshes the page.
extern "C" void * w3d_string_default(void *string);
extern "C" void w3d_string_base_finish(void *string);
extern "C" void w3d_string_release(void *string);
struct K10aOptionsString
{
    char *text;
    unsigned int storage;
    K10aOptionsString() {}
    ~K10aOptionsString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K10aOptions
{
    char pad0[28];
    void *sink;              // +28
    int first;               // +32
    int mode;                // +36
    int second;              // +40
};
extern const char *w3d_pieces_803f3fc4[];
extern "C" void w3d_auto_802cd14c(int sink);
extern "C" void w3d_auto_802cd07c(int sink);
extern "C" void w3d_auto_802cbf2c(K10aOptionsString *line, const char *piece, int mode);
extern "C" void w3d_s21_sink_write_indexed_802cbdf8(int sink, char *text, int index);
extern "C" void fn_80050534(K10aOptions *self);
extern "C" void fn_8004ff24(K10aOptions *self);
extern "C" void w3d_show_options_line_80050620(K10aOptions *self);
extern "C" void w3d_k10a_options_page_setup_8004fe48(K10aOptions *self)
{
    K10aOptionsString line;
    unsigned int i = 0;
    w3d_auto_802cd14c((int)self->sink);
    w3d_auto_802cd07c((int)self->sink);
    w3d_string_default(&line);
    w3d_auto_802cbf2c(&line, w3d_pieces_803f3fc4[0], 2);
    w3d_auto_802cbf2c(&line, w3d_pieces_803f3fc4[1], 2);
    for (; i < 20; i++)
        w3d_auto_802cbf2c(&line, w3d_pieces_803f3fc4[2], 2);
    w3d_s21_sink_write_indexed_802cbdf8((int)self->sink, line.text, 9);
    fn_80050534(self);
    self->mode = 1;
    self->second = 0;
    self->first = 0;
    fn_8004ff24(self);
    w3d_show_options_line_80050620(self);
}
