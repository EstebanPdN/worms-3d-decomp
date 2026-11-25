#include "w3d_ptr.h"
#line 1 "s21_o_802a1bf4.cpp"
// desc: Appears to store a text value and show it masked with asterisks when the owner's mode is one, then refresh the widget.
struct S21Text;
extern void fn_8020c5c4(Ptr32<S21Text>);
extern void fn_80341588(Ptr32<S21Text>);
struct S21Text {
    Ptr32<char> data;
    S21Text();
    Ptr32<void> assign(Ptr32<const char> source, unsigned length);
    void set(int value);
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S21Settings { char pad[184]; int mode; };
struct S21Widget { char pad[40]; Ptr32<S21Settings> settings; char pad1[368]; S21Text text; };
extern void fn_8029ec80(Ptr32<S21Widget>, int);
extern void fn_802a21ec(Ptr32<S21Widget>);
extern const char lbl_803d1f04[];
extern "C" void w3d_s21_widget_set_text_802a1bf4(Ptr32<S21Widget> self, int value)
{
    Ptr32<S21Settings> settings = self->settings;
    self->text.set(value);
    if (settings->mode == 1) {
        S21Text masked;
        masked.assign(lbl_803d1f04, *(Ptr32<unsigned short>)(self->text.data - 4));
        fn_8029ec80(self, (int)w3d::H(masked.data));
    } else {
        fn_8029ec80(self, value);
    }
    fn_802a21ec(self);
}


