#include "w3d_ptr.h"
#line 1 "d11c_seek_target_80021bb4_v0.cpp"
// d11c: 0x80021bb4 (172 bytes), raise the "AIStrike.SeekTarget" property and
// switch the global camera to its "Blimp" mode unless that mode is current.
// Observed in the original DOL: the property key literal 0x8036c15c
// "AIStrike.SeekTarget" is written with 1 through 0x800fc43c; the camera
// object is the r13 word 0x804aa8c8; its current mode is modes[current]
// (+316 array indexed by +312) and the mode name is that record's +60 word.
// A temporary engine string built from the original literal 0x8036c0fc
// "Blimp" (0x8020bb54) is compared with strcmp and destroyed (0x8020c5c4 then
// 0x80341588) before 0x80035714 receives the camera, the same literal and the
// float 0x8036c170 (decoded from the DOL as 0.0f). No register argument is
// read. All names and views are inferred; unknown words are partial views.
struct d11c_CameraMode {
    unsigned char unknown00[60];
    Ptr32<const char> name;                    // +60
};
struct d11c_Camera {
    unsigned char unknown00[312];
    int current;                         // +312
    Ptr32<Ptr32<d11c_CameraMode>> modes;             // +316
};
extern "C" {
void d11c_string_base_finish_8020c5c4(Ptr32<void>);
void d11c_string_release_80341588(Ptr32<void>);
int d11c_property_write_800fc43c(Ptr32<Ptr32<const char>> name, int value);
int strcmp(Ptr32<const char> a, Ptr32<const char> b);
int d11c_camera_set_mode_80035714(Ptr32<d11c_Camera> camera, Ptr32<const char> name, float blend);
extern Ptr32<d11c_Camera> d11c_camera_804aa8c8;
extern char d11c_seek_target_8036c15c[];
extern char d11c_blimp_8036c0fc[];
extern const float d11c_f32_8036c170[];
}
struct d11c_String_8020bb54 {
 d11c_String_8020bb54(const d11c_String_8020bb54 &);
    Ptr32<const char> text;
    template <class W3dU> d11c_String_8020bb54(Ptr32<W3dU> w3d_p) : d11c_String_8020bb54((const char *)w3d_p.get()) {}
 d11c_String_8020bb54(const char *s);
    ~d11c_String_8020bb54() { d11c_string_base_finish_8020c5c4(this); d11c_string_release_80341588(this); }
};
static inline int d11c_name_differs(Ptr32<d11c_CameraMode> mode, const d11c_String_8020bb54 &name) {
    return strcmp(mode->name, name.text) != 0;
}
extern "C" void d11c_seek_target_80021bb4() {
    Ptr32<const char> flag = d11c_seek_target_8036c15c;
    d11c_property_write_800fc43c(&flag, 1);
    Ptr32<d11c_Camera> camera = d11c_camera_804aa8c8;
    Ptr32<d11c_CameraMode> mode = *(Ptr32<Ptr32<d11c_CameraMode>>)((Ptr32<char>)camera->modes + (camera->current << 2));
    int differs;
    {
        d11c_String_8020bb54 text(d11c_blimp_8036c0fc);
        differs = d11c_name_differs(mode, text);
    }
    if (differs)
        d11c_camera_set_mode_80035714(camera, d11c_blimp_8036c0fc, d11c_f32_8036c170[0]);
}


