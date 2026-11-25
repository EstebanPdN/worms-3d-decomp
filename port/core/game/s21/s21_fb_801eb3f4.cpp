#include "w3d_ptr.h"
#line 1 "s21_fb_801eb3f4.cpp"
// desc: Appears to read an element of a described object into an output: without a position it copies a default text, otherwise it calls the target's read slot, directly when it is of kind three or via a temporary text.
struct S21Text;
extern void fn_8020c5c4(Ptr32<S21Text>);
extern void fn_80341588(Ptr32<S21Text>);
struct S21Text {
    Ptr32<char> data;
    S21Text();
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S21Target;
struct S21TargetMethods { Ptr32<void (void)> reserved[17]; Ptr32<int (Ptr32<S21Target>, Ptr32<S21Text>, int, int, int)> read_text; Ptr32<void (void)> reserved2[3]; Ptr32<int (Ptr32<S21Target>, int, int, int)> read_direct; };
struct S21Target { Ptr32<S21TargetMethods> methods; };
struct S21Link { char pad[8]; int value; };
struct S21Info { char pad[4]; unsigned short offset; char pad1[2]; Ptr32<S21Target> target; Ptr32<S21Link> link; };
struct S21Object { Ptr32<S21Info> info; };
extern const char lbl_803b0c58[];
extern int fn_801fff60(Ptr32<S21Target>);
extern int fn_8020dbf8(int, Ptr32<const char>);
extern int fn_8020d82c(int, Ptr32<S21Text>);
extern "C" void w3d_s21_read_element_801eb3f4(Ptr32<S21Object> self, int out, int position)
{
    if (position != 0) {
        Ptr32<S21Info> info = self->info;
        int value = 0;
        if (info->link)
            value = info->link->value;
        int offset = position + info->offset;
        if (fn_801fff60(info->target)) {
            Ptr32<S21Target> target = self->info->target;
            target->methods->read_direct(target, out, offset, value);
        } else {
            S21Text text;
            Ptr32<S21Target> target = self->info->target;
            target->methods->read_text(target, &text, offset, 0, value);
            fn_8020d82c(out, &text);
        }
    } else {
        fn_8020dbf8(out, lbl_803b0c58);
    }
}


