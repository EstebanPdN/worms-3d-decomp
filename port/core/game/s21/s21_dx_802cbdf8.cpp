#include "w3d_ptr.h"
#line 1 "s21_dx_802cbdf8.cpp"
// desc: Appears to build a text from two arguments and pass it to a virtual method of the sink registered for an index, when the subsystem is enabled and the index has a sink.
// desc: Appears to build a text from two arguments and pass it to a virtual method of the sink registered for an index, when the subsystem is enabled and the index has a sink.
struct S21Text;
extern void fn_8020c5c4(Ptr32<S21Text>);
extern void fn_80341588(Ptr32<S21Text>);
struct S21Text {
    Ptr32<char> data;
    S21Text();
    void fill(int a, int b);
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S21Sink;
struct S21SinkMethods { Ptr32<void (Ptr32<S21Sink>, Ptr32<const char>, unsigned int, int)> reserved[6]; };
struct S21Sink { Ptr32<S21SinkMethods> methods; };
extern int lbl_804abce4;
extern Ptr32<S21Sink> lbl_80473724[];
extern "C" void w3d_s21_sink_write_indexed_802cbdf8(unsigned index, int a, int b)
{
    if (lbl_804abce4 && index <= 15) {
        unsigned offset = index << 2;
        if (*(Ptr32<Ptr32<S21Sink>>)w3d::G((offset + (unsigned)w3d::H(lbl_80473724)))) {
        S21Text text;
        text.fill(a, b);
        Ptr32<S21Sink> sink = *(Ptr32<Ptr32<S21Sink>>)w3d::G((offset + (unsigned)w3d::H(lbl_80473724)));
        sink->methods->reserved[6](sink, text.data, *(Ptr32<unsigned short>)(text.data - 4), 0);
        }
    }
}


