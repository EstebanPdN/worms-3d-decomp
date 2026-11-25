#include "w3d_ptr.h"
#line 1 "cc17d_str_edit_802796d4.cpp"
// cc17d: string property setters (0x802796d4 editor, 0x8027a8a4 name).
// Observed: strings are pointers to text preceded by a 16-bit reference
// count at -6; assignment retains the new text, releases the old one through
// w3d_string_release_header when its count drops to 0, and stores the new
// pointer.  The editor layout matches cc17d_prop_edit_8027a2c4.
extern "C" {
Ptr32<void> w3d_string_from_text(Ptr32<void>, Ptr32<const char>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_string_release_header(Ptr32<void>);
}
struct Cc17dStr {
    Ptr32<char> text;
    int unknown;
    template <class W3dU> Cc17dStr(Ptr32<W3dU> w3d_p) : Cc17dStr((const char *)w3d_p.get()) {}
 Cc17dStr(const char *s) { w3d_string_from_text(this, s); }
    ~Cc17dStr() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Cc17dStrRef {
    Ptr32<char> text;
    void operator=(const Cc17dStr &o)
    {
        ++*(Ptr32<unsigned short>)(o.text - 6);
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(text - 6);
        unsigned int remaining = *header - 1;
        *header = remaining;
        if (!(unsigned short)remaining)
            w3d_string_release_header(header);
        text = o.text;
    }
};
struct Cc17dObject { Ptr32<Ptr32<void>> methods; };
struct Cc17dField { unsigned char reserved[4]; unsigned short offset; };
struct Cc17dFieldRef { Ptr32<Cc17dField> field; };
struct Cc17dNamed { unsigned char reserved[28]; Cc17dStrRef name; };
struct Cc17dEditor {
    unsigned char reserved[88];
    Ptr32<Cc17dNamed> target;                // +88
    Ptr32<Cc17dObject> receiver;             // +92
    int key;                           // +96
};
extern "C" Ptr32<Cc17dFieldRef> w3d_s21_vector_get_801e9db8(Ptr32<void>, int);
extern "C" void w3d_s21_state_dispatch_8027ae00(Ptr32<Cc17dEditor>);
extern "C" void w3d_auto_8027a98c(Ptr32<Cc17dEditor>);
extern "C" void fn_80271518(Ptr32<Cc17dEditor>, int);
#define CC17D_TYPE(o) (((void *(*)(Cc17dObject *))(o)->methods[5])(o))
#define CC17D_FIELD(T, o, ref) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(o) + (ref)->field->offset))
// The temporary string lives in inline helpers: written directly in the
// caller, GCC computes its address into a saved register too early.
static inline void cc17d_store_text(Ptr32<Cc17dObject> receiver, Ptr32<Cc17dEditor> self, Ptr32<const char> text)
{
    Cc17dStr value(text);
    Ptr32<Cc17dFieldRef> ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(self->receiver), self->key);
    CC17D_FIELD(Cc17dStrRef, receiver, ref) = value;
}
extern "C" void w3d_cc17d_string_edit_802796d4(Ptr32<Cc17dEditor> self, Ptr32<const char> text)
{
    cc17d_store_text(self->receiver, self, text);
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}
static inline void cc17d_set_name(Ptr32<Cc17dNamed> target, Ptr32<const char> text)
{
    Cc17dStr value(text);
    target->name = value;
}
extern "C" void w3d_cc17d_set_target_name_8027a8a4(Ptr32<Cc17dEditor> self, Ptr32<const char> text)
{
    cc17d_set_name(self->target, text);
    fn_80271518(self, 0);
}


