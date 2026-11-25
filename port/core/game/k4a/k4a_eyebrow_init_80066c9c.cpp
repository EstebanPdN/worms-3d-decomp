#include "w3d_ptr.h"
#line 1 "k4a_eyebrow_init_80066c9c.cpp"
struct K4aString;
extern "C" Ptr32<void> w3d_string_from_text(Ptr32<K4aString> string, Ptr32<const char> text);
extern "C" void w3d_string_base_finish(Ptr32<K4aString> string);
extern "C" void w3d_string_release(Ptr32<K4aString> string);
struct K4aString {
    Ptr32<char> text;
    int unused;
    K4aString() {}
    ~K4aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K4aWords3 { int a, b, c; };
struct K4aEyebrow { char pad0[32]; unsigned int handle; K4aWords3 origin; };
extern "C" char w3d_str_8037a070[];
extern "C" K4aWords3 w3d_origin_8045e788;
extern "C" Ptr32<void> w3d_handle_set_name(Ptr32<K4aString> name, Ptr32<void> handle, unsigned int flags);

extern "C" void k4a_eyebrow_init_80066c9c(Ptr32<K4aEyebrow> self)
{
    {
        K4aString name;
        w3d_string_from_text(&name, w3d_str_8037a070);
        w3d_handle_set_name(&name, &self->handle, 255);
    }
    self->origin = w3d_origin_8045e788;
}


