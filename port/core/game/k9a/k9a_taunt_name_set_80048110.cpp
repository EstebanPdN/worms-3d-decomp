#include "w3d_ptr.h"
#line 1 "k9a_taunt_name_set_80048110.cpp"
// Appears to pick a "Taunt<n>" name (the object's index modulo 13, plus one), reads the
// property it names and hands the resulting text to the name setter.
extern "C" Ptr32<void> w3d_string_default(Ptr32<void> string);
extern "C" void w3d_string_base_finish(Ptr32<void> string);
extern "C" void w3d_string_release(Ptr32<void> string);
extern "C" Ptr32<void> w3d_string_from_text(Ptr32<void> string, Ptr32<const char> text);
extern "C" int w3d_string_format(Ptr32<void> string, Ptr32<const char> format, ...);
struct K9aString
{
    Ptr32<char> text;
    unsigned int storage;
    K9aString() {}
    template <class W3dU> K9aString(Ptr32<W3dU> w3d_p) : K9aString((const char *)w3d_p.get()) {}
 K9aString(const char *t) { w3d_string_from_text(this, t); }
    ~K9aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K9aObject;
extern "C" unsigned int w3d_auto_8015ff5c(Ptr32<K9aObject> self);
extern "C" int w3d_auto_800fc2b0(Ptr32<Ptr32<const char>> key, Ptr32<Ptr32<const char>> value);
struct K9aRaw { Ptr32<char> text; unsigned int storage; K9aRaw() {} ~K9aRaw() {} };
extern "C" void w3d_fn_80043134(Ptr32<K9aObject> self, Ptr32<K9aRaw> name, int flag);
extern char w3d_str_803763c0[];
extern "C" void w3d_k9a_taunt_name_set_80048110(Ptr32<K9aObject> self)
{
    K9aString name;
    K9aRaw temp;
    Ptr32<const char> value = 0;
    w3d_string_default(&name);
    unsigned int n = w3d_auto_8015ff5c(self);
    w3d_string_format(&name, w3d_str_803763c0, n % 13 + 1);
    Ptr32<const char> key = name.text;
    w3d_auto_800fc2b0(&key, &value);
    w3d_string_from_text(&temp, value);
    w3d_fn_80043134(self, &temp, 0);
}


