#include "w3d_ptr.h"
#line 1 "k7a_clip_frames_8002f764.cpp"
struct K7aString;
extern "C" Ptr32<void> w3d_string_from_text(Ptr32<K7aString> string, Ptr32<const char> text);
extern "C" void w3d_string_base_finish(Ptr32<K7aString> string);
extern "C" void w3d_string_release(Ptr32<K7aString> string);
struct K7aString {
    Ptr32<char> text;
    int unused;
    K7aString() {}
    ~K7aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" Ptr32<const char> w3d_clip_library_name_804aa894;
extern "C" const float w3d_f32_80372f38[];
extern "C" Ptr32<void> w3d_runtime_service_lookup(Ptr32<K7aString> name);
extern "C" Ptr32<void> w3d_empty_80341348(Ptr32<void> service);
extern "C" int w3d_clip_length_8017fc90(Ptr32<void> service, int clip, Ptr32<float> length);

extern "C" int w3d_k7a_clip_frames_8002f764(Ptr32<void> unused, Ptr32<int> clip)
{
    Ptr32<void> service;
    {
        K7aString name;
        w3d_string_from_text(&name, w3d_clip_library_name_804aa894);
        service = w3d_runtime_service_lookup(&name);
    }
    service = w3d_empty_80341348(service);
    float length;
    w3d_clip_length_8017fc90(service, *clip, &length);
    return (int)(length * w3d_f32_80372f38[0]);
}


