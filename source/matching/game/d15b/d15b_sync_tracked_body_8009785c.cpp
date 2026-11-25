// Partial views of a tracking controller that follows a looked-up body.
// Only observed offsets are named; full class identities and sizes unknown.
struct d15b_Vec3 {
    float x, y, z;
    d15b_Vec3(const d15b_Vec3 &q) { float a = q.x, c = q.z, b = q.y; x = a; z = c; y = b; }
};
struct d15b_Target;
struct d15b_TargetTable {
    unsigned char unknown00[76];
    void (*set_position)(d15b_Target *, d15b_Vec3 *, int);
    void (*set_orientation)(d15b_Target *, void *, int);
};
struct d15b_Target { d15b_TargetTable *vtable; };
struct d15b_Body { unsigned char unknown00[120]; unsigned char orientation[1]; };
struct d15b_Tracker {
    unsigned char unknown00[28];
    d15b_Target *target;
    int body_handle;
    unsigned char unknown24[4];
    unsigned char mode;
    unsigned char unknown29[27];
    void *members;
};
extern "C" void *w3d_s20_lookup_handle_object_80164fc8(int);
extern "C" void w3d_auto_8015fd1c(d15b_Tracker *);
extern "C" const d15b_Vec3 *w3d_member_8003e304(d15b_Body *);
extern "C" float w3d_getf_8003e30c(d15b_Body *);
extern "C" int w3d_handle_member_query_801265ec(void *, const d15b_Vec3 *);
extern "C" int w3d_get_80098370(d15b_Body *);
extern "C" float w3d_getf_80098380(d15b_Body *);
extern "C" float w3d_getf_80098378(d15b_Body *);
extern "C" void w3d_tracker_apply_80097cbc(d15b_Tracker *, int, float, float);

extern "C" int d15b_sync_tracked_body_8009785c(d15b_Tracker *self) {
    d15b_Body *body = (d15b_Body *)w3d_s20_lookup_handle_object_80164fc8(self->body_handle);
    if (body == 0) {
        self->body_handle = 0;
        w3d_auto_8015fd1c(self);
    } else {
        d15b_Vec3 position(*w3d_member_8003e304(body));
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
