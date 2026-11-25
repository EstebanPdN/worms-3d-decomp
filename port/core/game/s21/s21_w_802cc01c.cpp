#include "w3d_ptr.h"
#line 1 "s21_w_802cc01c.cpp"
// desc: Appears to build a text from two arguments and pass it to a virtual method of the object when the subsystem is enabled.
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
extern "C" void w3d_s21_sink_write_802cc01c(Ptr32<S21Sink> sink, int a, int b)
{
    if (lbl_804abce4 && sink) {
        S21Text text;
        text.fill(a, b);
        sink->methods->reserved[6](sink, text.data, *(Ptr32<unsigned short>)(text.data - 4), 0);
    }
}


