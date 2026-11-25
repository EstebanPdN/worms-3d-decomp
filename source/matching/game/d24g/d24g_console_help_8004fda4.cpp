/* Worms 3D GameCube PAL 0x8004fda4. Debug options console help: clears and resets the sink at +28 (0x802cd14c, 0x802cd07c), appends every line of the null-terminated help table 0x803f3f7c to a temporary text with colour 7, writes it to the sink with colour 9, and zeroes +32 and +36. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Text {
    char *text;
    Text();
    ~Text();
    Text(const Text &);
};
extern "C" {
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_clear_802cd14c(int);
void w3d_flush_802cd07c(int);
void w3d_append_802cbf2c(void *, const char *, int);
void w3d_write_802cbdf8(int, const char *, int);
}
inline Text::~Text() { w3d_string_base_finish(this); w3d_string_release(this); }
struct Console { char unknown[28]; void *sink; unsigned a, b; };
extern const char *help_lines_803f3f7c[];
extern "C" void w3d_d24g_console_help_8004fda4(Console *self)
{
    w3d_clear_802cd14c((int)self->sink);
    w3d_flush_802cd07c((int)self->sink);
    Text t;
    for (int i = 0; help_lines_803f3f7c[i]; i++)
        w3d_append_802cbf2c(&t, help_lines_803f3f7c[i], 7);
    w3d_write_802cbdf8((int)self->sink, t.text, 9);
    self->b = 0;
    self->a = 0;
}
