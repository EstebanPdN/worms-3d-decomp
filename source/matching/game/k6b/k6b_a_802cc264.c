struct K6bString { char *text; };
extern void w3d_string_default(struct K6bString *string);
extern void w3d_string_format(struct K6bString *string, const char *format, ...);
extern void fn_802cc0ac(void *sink, const char *text, void *context);
extern void w3d_string_base_finish(struct K6bString *string);
extern void w3d_string_release(struct K6bString *string);
extern char lbl_803d944c[];
void w3d_k6b_sink_write_int_802cc264(void *sink, int value, void *context)
{
    struct { struct K6bString h; char spare[0]; } text;
    struct K6bString *s;
    w3d_string_default(&text.h);
    s = &text.h;
    w3d_string_format(s, lbl_803d944c, value);
    fn_802cc0ac(sink, s->text, context);
    w3d_string_base_finish(s);
    w3d_string_release(s);
}
// desc: w3d_k6b_sink_write_int_802cc264: Appears to format an integer with 0x803d944c into a temporary shared string, pass its text to 0x802cc0ac and release it.
