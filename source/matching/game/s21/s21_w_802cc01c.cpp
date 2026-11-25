// desc: Appears to build a text from two arguments and pass it to a virtual method of the object when the subsystem is enabled.
struct S21Text;
extern void fn_8020c5c4(S21Text *);
extern void fn_80341588(S21Text *);
struct S21Text {
    char *data;
    S21Text();
    void fill(int a, int b);
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S21Sink;
struct S21SinkMethods { void (*reserved[6])(S21Sink *, const char *, unsigned, int); };
struct S21Sink { S21SinkMethods *methods; };
extern int lbl_804abce4;
extern "C" void w3d_s21_sink_write_802cc01c(S21Sink *sink, int a, int b)
{
    if (lbl_804abce4 && sink) {
        S21Text text;
        text.fill(a, b);
        sink->methods->reserved[6](sink, text.data, *(unsigned short *)(text.data - 4), 0);
    }
}
