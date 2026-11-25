struct K7aString;
extern "C" void * w3d_string_from_text(K7aString *string, const char *text);
extern "C" void w3d_string_base_finish(K7aString *string);
extern "C" void w3d_string_release(K7aString *string);
struct K7aString {
    char *text;
    int unused;
    K7aString() {}
    ~K7aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" const char *w3d_clip_library_name_804aa894;
extern "C" const float w3d_f32_80372f38[];
extern "C" void *w3d_runtime_service_lookup(K7aString *name);
extern "C" void *w3d_empty_80341348(void *service);
extern "C" int w3d_clip_length_8017fc90(void *service, int clip, float *length);

extern "C" int w3d_k7a_clip_frames_8002f764(void *unused, int *clip)
{
    void *service;
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
