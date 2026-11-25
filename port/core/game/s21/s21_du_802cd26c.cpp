#include "w3d_ptr.h"
#line 1 "s21_du_802cd26c.cpp"
// desc: Appears to format a message from two one-based numbers into a temporary string and append it to the first argument's text.
struct S21Text;
extern void fn_8020c5c4(Ptr32<S21Text>);
extern void fn_80341588(Ptr32<S21Text>);
struct S21Text {
    Ptr32<char> data;
    S21Text();
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
extern const char lbl_803d94bc[];
extern void fn_8020c510(Ptr32<S21Text>, Ptr32<const char>, ...);
extern Ptr32<void> fn_8020bf2c(Ptr32<void>, Ptr32<char>);
extern "C" void w3d_s21_append_position_802cd26c(Ptr32<void> target, int row, int column)
{
    S21Text text;
    fn_8020c510(&text, lbl_803d94bc, column + 1, row + 1);
    fn_8020bf2c(target, text.data);
}


