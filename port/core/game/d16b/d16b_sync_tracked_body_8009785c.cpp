#include "w3d_ptr.h"
#line 1 "d16b_sync_tracked_body_8009785c.cpp"
// Partial views of a tracking controller that follows a looked-up body.
// Only observed offsets are named; full class identities and sizes unknown.
// Built with the original paired-single float switch (-mps-float), which
// reserves the 8 frame bytes that pair the saved FPR.
struct d16b_Vec3 {
    float x, y, z;
    d16b_Vec3(const d16b_Vec3 &q) { float a = q.x, b = q.y, c = q.z; x = a; y = b; z = c; }
};
struct d16b_Target;
struct d16b_TargetTable {
    unsigned char unknown00[76];
    Ptr32<void (Ptr32<d16b_Target>, Ptr32<d16b_Vec3>, int)> set_position;
    Ptr32<void (Ptr32<d16b_Target>, Ptr32<void>, int)> set_orientation;
};
struct d16b_Target { Ptr32<d16b_TargetTable> vtable; };
struct d16b_Body { unsigned char unknown00[120]; unsigned char orientation[1]; };
struct d16b_Tracker {
    unsigned char unknown00[28];
    Ptr32<d16b_Target> target;
    int body_handle;
    unsigned char unknown24[4];
    unsigned char mode;
    unsigned char unknown29[27];
    Ptr32<void> members;
};
extern "C" Ptr32<void> w3d_s20_lookup_handle_object_80164fc8(int);
extern "C" void w3d_auto_8015fd1c(Ptr32<d16b_Tracker>);
extern "C" Ptr32<const d16b_Vec3> w3d_member_8003e304(Ptr32<d16b_Body>);
extern "C" float w3d_getf_8003e30c(Ptr32<d16b_Body>);
extern "C" int w3d_handle_member_query_801265ec(Ptr32<void>, Ptr32<const d16b_Vec3>);
extern "C" int w3d_get_80098370(Ptr32<d16b_Body>);
extern "C" float w3d_getf_80098380(Ptr32<d16b_Body>);
extern "C" float w3d_getf_80098378(Ptr32<d16b_Body>);
extern "C" void w3d_tracker_apply_80097cbc(Ptr32<d16b_Tracker>, int, float, float);

extern "C" int d16b_sync_tracked_body_8009785c(Ptr32<d16b_Tracker> self) {
    Ptr32<d16b_Body> body = (Ptr32<d16b_Body>)w3d_s20_lookup_handle_object_80164fc8(self->body_handle);
    if (body == 0) {
        self->body_handle = 0;
        w3d_auto_8015fd1c(self);
    } else {
        d16b_Vec3 position(*w3d_member_8003e304(body));
        position.y -= w3d_getf_8003e30c(body);
        self->target->vtable->set_position(self->target, &position, 0);
        self->target->vtable->set_orientation(self->target, body->orientation, 0);
        w3d_handle_member_query_801265ec(self->members, w3d_member_8003e304(body));
        if (self->mode == 2) {
            int kind = w3d_get_80098370(body);
            float first = w3d_getf_80098380(body);
            w3d_tracker_apply_80097cbc(self, kind, first, w3d_getf_80098378(body));
        }
    }
    return 0;
}


