// d16c: 0x801247d0 (252 bytes). Lazily load the "TransitionMesh" resource,
// retain it as the transition's mesh (releasing the previous one) and scale it
// by the current progress: xy = progress * 1.125 + (1 - progress), z = 1.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return (GCC 2.95 then loads the string address last).

// Shared engine string; constructor and release are out of line.
struct d16c_String_8020bb54 {
 d16c_String_8020bb54(const d16c_String_8020bb54 &);
    char *text;
    d16c_String_8020bb54(const char *);
    ~d16c_String_8020bb54();
};
extern "C" void d16c_string_finish_8020c5c4(d16c_String_8020bb54 *);
extern "C" void d16c_string_release_80341588(d16c_String_8020bb54 *);
inline d16c_String_8020bb54::~d16c_String_8020bb54() {
    d16c_string_finish_8020c5c4(this);
    d16c_string_release_80341588(this);
}

struct d16c_Vec3 { float x, y, z; };
struct d16c_Mesh;
struct d16c_MeshVtable {
    void *unknown00[3];
    void (*retain)(d16c_Mesh *);                       // +12
    void (*release)(d16c_Mesh *);                      // +16
    void *unknown14[16];
    void (*scale)(d16c_Mesh *, d16c_Vec3 *, int);      // +84
};
struct d16c_Mesh { d16c_MeshVtable *vtable; };

struct d16c_Transition {
    unsigned char unknown00[28];
    unsigned handle;                     // +28
    unsigned unknown20;
    d16c_Mesh *mesh;                     // +36
};
struct d16c_Settings {
    unsigned char unknown00[184];
    float progress;                      // +184
};
extern d16c_Settings *d16c_settings_804b1788;
extern const char d16c_mesh_name_8039b868[];      // "TransitionMesh"
extern const float d16c_one_8039b878[];           // 1.0f
extern const float d16c_scale_8039b87c[];         // 1.125f

extern "C" int d16c_handle_load_8015adf4(const d16c_String_8020bb54 *, unsigned *, unsigned char);
extern "C" d16c_Mesh *d16c_handle_mesh_80343584(unsigned);

extern "C" void d16c_transition_mesh_801247d0(d16c_Transition *self) {
    unsigned *handle = &self->handle;
    if (!*handle) {
        {
            d16c_String_8020bb54 name(d16c_mesh_name_8039b868);
            d16c_handle_load_8015adf4(&name, handle, 34);
        }
        d16c_Mesh *next = d16c_handle_mesh_80343584(self->handle);
        if (next) next->vtable->retain(next);
        if (self->mesh) self->mesh->vtable->release(self->mesh);
        self->mesh = next;
        float s = d16c_settings_804b1788->progress * d16c_scale_8039b87c[0]
                + (d16c_one_8039b878[0] - d16c_settings_804b1788->progress);
        d16c_Vec3 scale;
        d16c_Vec3 *p = &scale;
        scale.x = s;
        scale.y = s;
        p->z = d16c_one_8039b878[0];
        next->vtable->scale(next, p, 0);
    }
}
