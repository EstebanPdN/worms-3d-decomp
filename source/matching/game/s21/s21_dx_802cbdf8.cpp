// desc: Appears to build a text from two arguments and pass it to a virtual method of the sink registered for an index, when the subsystem is enabled and the index has a sink.
// desc: Appears to build a text from two arguments and pass it to a virtual method of the sink registered for an index, when the subsystem is enabled and the index has a sink.
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
extern S21Sink *lbl_80473724[];
extern "C" void w3d_s21_sink_write_indexed_802cbdf8(unsigned index, int a, int b)
{
    if (lbl_804abce4 && index <= 15) {
        unsigned offset = index << 2;
        if (*(S21Sink **)(offset + (unsigned)lbl_80473724)) {
        S21Text text;
        text.fill(a, b);
        S21Sink *sink = *(S21Sink **)(offset + (unsigned)lbl_80473724);
        sink->methods->reserved[6](sink, text.data, *(unsigned short *)(text.data - 4), 0);
        }
    }
}
