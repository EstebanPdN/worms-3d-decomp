struct K8cLogger;
struct K8cString;
extern "C" {
void *fn_803426b8(K8cString *str);
void fn_8020c5c4(K8cString *str);
void fn_80341588(K8cString *str);
void fn_8020c510(K8cString *str, const char *format, ...);
void fn_802cc0ac(K8cLogger *self, const char *text, int arg);
extern const char w3d_str_803d9450[];
extern const char w3d_str_803d9454[];
}
struct K8cString {
    const char *data;
    K8cString() {}
    ~K8cString() { fn_8020c5c4(this); fn_80341588(this); }
};
extern "C" void w3d_k8c_log_float_802cc2d8(K8cLogger *self, int arg, float value)
{
    K8cString text;
    fn_803426b8(&text);
    fn_8020c510(&text, w3d_str_803d9450, value);
    fn_802cc0ac(self, text.data, arg);
}
struct K8cVec3 { float x, y, z; };
extern "C" void w3d_k8c_log_vec3_802cc354(K8cLogger *self, const K8cVec3 *v, int arg)
{
    K8cString text;
    fn_803426b8(&text);
    fn_8020c510(&text, w3d_str_803d9454, v->x, v->y, v->z);
    fn_802cc0ac(self, text.data, arg);
}
