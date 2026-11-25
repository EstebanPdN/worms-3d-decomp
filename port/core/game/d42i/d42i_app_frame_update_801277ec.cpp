#include "w3d_ptr.h"
#line 1 "d42i_app_frame_update_801277ec.cpp"
// d42i: 0x801277ec. Application frame update. Once, publishes the game
// version text into a setting. Logs Update and, when the flag holds, runs
// enter, runtime reset and mode start, leaving when the pause setting is 0.
// Runs the base update and pending send, inverts the camera matrix keeping
// only its height, and applies it to the renderer. Clears the dirty byte.
struct app_Vec3 { float x, y, z; };
struct app_Matrix {
    float m[3][4];
    float t[3];
    float w;
};
struct app_Key {
    Ptr32<const char> name;
    template <class W3dU> app_Key(Ptr32<W3dU> w3d_p) : app_Key((const char *)w3d_p.get()) {}
 app_Key(const char *n) { name = n; }
};
struct app_Camera;
struct app_CameraVtable {
    Ptr32<void> unknown00[6];
    Ptr32<Ptr32<app_Matrix> (Ptr32<app_Camera>)> matrix;   // +24
    Ptr32<void> unknown1c[2];
    Ptr32<Ptr32<void> (Ptr32<app_Camera>)> view;            // +36
};
struct app_Camera { Ptr32<app_CameraVtable> vtable; };
struct app_Renderer;
struct app_RendererVtable {
    Ptr32<void> unknown00[7];
    Ptr32<void (Ptr32<app_Renderer>, Ptr32<app_Matrix>)> set_matrix;  // +28
    Ptr32<void> unknown20[2];
    Ptr32<void (Ptr32<app_Renderer>, Ptr32<void>)> set_view;           // +40
};
struct app_Renderer { Ptr32<app_RendererVtable> vtable; };
struct app_App {
    unsigned char unknown00[48];
    Ptr32<app_Camera> camera;                 // +48
    unsigned char unknown34[88];
    Ptr32<app_Renderer> renderer;             // +140
};
extern "C" int app_text_format_803434d4(Ptr32<char>, Ptr32<const char>, ...);
extern "C" int app_setting_write_800fc110(const app_Key &, Ptr32<const char>, int, int);
extern "C" void app_log_80207ca4(Ptr32<const char>);
extern "C" int app_setting_read_800fc1f0(Ptr32<app_Key>, Ptr32<int>);
extern "C" int app_paused_8006ee18(void);
extern "C" void app_enter_80129878(Ptr32<app_App>);
extern "C" void app_reset_8015cbe0(Ptr32<app_App>, int);
extern "C" int app_mode_start_8006af38(Ptr32<void>);
extern "C" void app_leave_801298cc(Ptr32<app_App>);
extern "C" void app_update_8015caec(Ptr32<app_App>, Ptr32<void>);
extern "C" void app_send_range_800336d0(Ptr32<void>);
extern "C" Ptr32<app_Matrix> app_invert_801f69ec(Ptr32<app_Matrix>, Ptr32<app_Matrix>);
extern int app_published_804ab09c;
extern int app_version_804af594;
extern Ptr32<void> app_mode_804aaabc;
extern Ptr32<void> app_pending_804aa8c8;
extern unsigned char app_dirty_804ab3e8;
extern const char app_version_format_8039bcdc[], app_version_name_8039bce4[], app_update_8039bcf8[], app_paused_name_8039bd04[];
extern const float app_zero_8039bd58[];

extern "C" void d42i_app_frame_update_801277ec(Ptr32<app_App> self, Ptr32<void> frame) {
    if (!app_published_804ab09c) {
        char text[128];
        Ptr32<char> t = text;
        app_text_format_803434d4(t, app_version_format_8039bcdc, app_version_804af594);
        app_setting_write_800fc110(app_Key(app_version_name_8039bce4), t, 12, 1);
        app_published_804ab09c = 1;
    }
    app_log_80207ca4(app_update_8039bcf8);
    int paused;
    app_Key key(app_paused_name_8039bd04);
    app_setting_read_800fc1f0(&key, &paused);
    if (app_paused_8006ee18()) {
        app_enter_80129878(self);
        app_reset_8015cbe0(self, 0);
        app_mode_start_8006af38(app_mode_804aaabc);
        if (!paused)
            app_leave_801298cc(self);
    }
    app_update_8015caec(self, frame);
    if (app_pending_804aa8c8)
        app_send_range_800336d0(app_pending_804aa8c8);
    app_Vec3 height;
    Ptr32<app_Vec3> area = &height;
    app_Matrix inverse;
    app_Matrix copy;
    Ptr32<app_Matrix> source = &inverse;
    copy = *self->camera->vtable->matrix(self->camera);
    Ptr32<app_Matrix> result = &copy;
    app_invert_801f69ec(source, result);
    height.x = inverse.t[0];
    area->y = inverse.t[1];
    area->z = inverse.t[2];
    float zero = app_zero_8039bd58[0];
    height.x = zero;
    height.z = zero;
    inverse.t[0] = zero;
    inverse.t[1] = area->y;
    inverse.t[2] = area->z;
    app_invert_801f69ec(result, source);
    self->renderer->vtable->set_view(self->renderer, self->camera->vtable->view(self->camera));
    self->renderer->vtable->set_matrix(self->renderer, result);
    app_dirty_804ab3e8 = 0;
}


