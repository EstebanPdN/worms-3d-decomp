#include "w3d_ptr.h"
#line 1 "k8c_log_format_802cc2d8.cpp"
struct K8cLogger;
struct K8cString;
extern "C" {
Ptr32<void> fn_803426b8(Ptr32<K8cString> str);
void fn_8020c5c4(Ptr32<K8cString> str);
void fn_80341588(Ptr32<K8cString> str);
void fn_8020c510(Ptr32<K8cString> str, Ptr32<const char> format, ...);
void fn_802cc0ac(Ptr32<K8cLogger> self, Ptr32<const char> text, int arg);
extern const char w3d_str_803d9450[];
extern const char w3d_str_803d9454[];
}
struct K8cString {
    Ptr32<const char> data;
    K8cString() {}
    ~K8cString() { fn_8020c5c4(this); fn_80341588(this); }
};
extern "C" void w3d_k8c_log_float_802cc2d8(Ptr32<K8cLogger> self, int arg, float value)
{
    K8cString text;
    fn_803426b8(&text);
    fn_8020c510(&text, w3d_str_803d9450, value);
    fn_802cc0ac(self, text.data, arg);
}
struct K8cVec3 { float x, y, z; };
extern "C" void w3d_k8c_log_vec3_802cc354(Ptr32<K8cLogger> self, Ptr32<const K8cVec3> v, int arg)
{
    K8cString text;
    fn_803426b8(&text);
    fn_8020c510(&text, w3d_str_803d9454, v->x, v->y, v->z);
    fn_802cc0ac(self, text.data, arg);
}


