#include "w3d_ptr.h"
#line 1 "d19b_update_eye_tracking_80097cbc.cpp"
// Eye-tracking animation update for a character with an "Eye" mesh.
// Partial views: only the observed owner offsets are named; the mesh type is
// opaque and the owner's full class identity and size are unknown.
// Built with the original paired-single float switch (-mps-float), which
// reserves the frame bytes that pair the two saved FPRs.
struct d19b_EyeMesh;
struct d19b_EyeOwner {
    unsigned char unknown00[28];
    Ptr32<void> model;
    unsigned char unknown20[4];
    int clip;
    unsigned char unknown28[24];
    int tracking;
};
extern "C" {
Ptr32<d19b_EyeMesh> w3d_mesh_instance_80343584(Ptr32<void>);
float w3d_eye_track_scale_80097e7c(Ptr32<d19b_EyeOwner>, float);
int w3d_mesh_fade_track_80181814(Ptr32<d19b_EyeMesh>, Ptr32<const char>, float, float);
int w3d_mesh_instance_control_801817e0(Ptr32<d19b_EyeMesh>, int);
int w3d_transition_state_80181ccc(Ptr32<d19b_EyeMesh>, int);
int w3d_transition_play_80181640(Ptr32<d19b_EyeMesh>, Ptr32<const char>, Ptr32<int>, float, float, float, int);
extern Ptr32<const char> eye_horizontal_track_804aabac;
extern Ptr32<const char> eye_vertical_track_804aabb0;
extern Ptr32<const char> eye_reset_clip_804aabb4;
extern const char eye_main_clip_8037f660[];
extern float zero_8037f704[];
extern float one_8037f708[];
extern float minus_one_8037f70c[];
}

extern "C" void d19b_update_eye_tracking_80097cbc(Ptr32<d19b_EyeOwner> self, int tracking,
                                                  float horizontal, float vertical)
{
    Ptr32<d19b_EyeMesh> mesh = w3d_mesh_instance_80343584(self->model);
    if (tracking == 0) {
        if (self->tracking != 0) {
            /* Stop tracking: fade both axes back to rest, then play the reset clip. */
            Ptr32<const char> h = eye_horizontal_track_804aabac;
            float hv = w3d_eye_track_scale_80097e7c(self, zero_8037f704[0]);
            w3d_mesh_fade_track_80181814(mesh, h, hv, zero_8037f704[0]);
            Ptr32<const char> v = eye_vertical_track_804aabb0;
            float vv = w3d_eye_track_scale_80097e7c(self, zero_8037f704[0]);
            w3d_mesh_fade_track_80181814(mesh, v, vv, zero_8037f704[0]);
            w3d_mesh_instance_control_801817e0(mesh, -1);
            w3d_transition_play_80181640(mesh, eye_reset_clip_804aabb4, &self->clip,
                                         one_8037f708[0], minus_one_8037f70c[0], zero_8037f704[0], 0);
        } else if (w3d_transition_state_80181ccc(mesh, self->clip)) {
            /* Idle: restart the main eye clip once the previous one is done. */
            w3d_transition_play_80181640(mesh, eye_main_clip_8037f660, &self->clip,
                                         one_8037f708[0], zero_8037f704[0], zero_8037f704[0], 0);
        }
    } else {
        if (self->tracking == 0) {
            /* Start tracking from the reset pose. */
            w3d_mesh_instance_control_801817e0(mesh, -1);
            w3d_transition_play_80181640(mesh, eye_reset_clip_804aabb4, &self->clip,
                                         one_8037f708[0], minus_one_8037f70c[0], zero_8037f704[0], 0);
        } else if (w3d_transition_state_80181ccc(mesh, self->clip)) {
            /* Follow the requested horizontal/vertical look direction. */
            Ptr32<const char> h = eye_horizontal_track_804aabac;
            float hv = w3d_eye_track_scale_80097e7c(self, horizontal);
            w3d_mesh_fade_track_80181814(mesh, h, hv, one_8037f708[0]);
            Ptr32<const char> v = eye_vertical_track_804aabb0;
            float vv = w3d_eye_track_scale_80097e7c(self, vertical);
            w3d_mesh_fade_track_80181814(mesh, v, vv, one_8037f708[0]);
        }
    }
    self->tracking = tracking;
}


