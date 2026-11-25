#include "w3d_ptr.h"
#line 1 "d19c_water_init_8012aec0.cpp"
// d19c: 0x8012aec0 (316 bytes). Water ripple initialisation (d16c's draft):
// subscribe to the cached message id, load the "Water.Ripple" mesh into +928,
// reserve 150 indices, place it at the origin rotated by pi/2 about X, and
// give each of the 150 ripples a start time up to 2047 ticks before now.
// Built with -mps-float: the d16c build differed only by an 8-byte frame gap
// below the register save area (the function saves f31 for pi/2 / 0.0f).
// Shared engine string; constructor and release are out of line.
struct d19c_String_8020bb54 {
 d19c_String_8020bb54(const d19c_String_8020bb54 &);
    Ptr32<char> text;
    template <class W3dU> d19c_String_8020bb54(Ptr32<W3dU> w3d_p) : d19c_String_8020bb54((const char *)w3d_p.get()) {}
 d19c_String_8020bb54(const char *);
    ~d19c_String_8020bb54();
};
extern "C" void d19c_string_finish_8020c5c4(Ptr32<d19c_String_8020bb54>);
extern "C" void d19c_string_release_80341588(Ptr32<d19c_String_8020bb54>);
inline d19c_String_8020bb54::~d19c_String_8020bb54() {
    d19c_string_finish_8020c5c4(this);
    d19c_string_release_80341588(this);
}
struct d19c_Vec3 { float x, y, z;
    void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct d19c_MessageId { unsigned short value; d19c_MessageId() {} };
struct d19c_Mesh;
struct d19c_MeshVtable {
    Ptr32<void> unknown00[19];
    Ptr32<void (Ptr32<d19c_Mesh>, Ptr32<d19c_Vec3>, int)> set_position;   // +76
    Ptr32<void (Ptr32<d19c_Mesh>, Ptr32<d19c_Vec3>, int)> set_rotation;   // +80
};
struct d19c_Mesh { Ptr32<d19c_MeshVtable> vtable; };
struct d19c_Clock { unsigned char unknown00[52]; int now; };
struct d19c_Water {
    unsigned char unknown000[328];
    int ripple_start[150];               // +328
    Ptr32<d19c_Mesh> ripple;                   // +928
    unsigned subscription;               // +932
    int unknown3a8;                      // +936
    int unknown3ac;                      // +940
};
extern "C" unsigned short d19c_cached_message_id_8015f5a0(Ptr32<void>, int);
extern "C" int d19c_subscribe_80162024(Ptr32<d19c_Water>, Ptr32<d19c_MessageId>, Ptr32<unsigned int>);
extern "C" int d19c_handle_load_8015adf4(Ptr32<const d19c_String_8020bb54>, Ptr32<Ptr32<d19c_Mesh>>, unsigned char);
extern "C" int d19c_mesh_reserve_indices_8018920c(Ptr32<d19c_Mesh>, int);
extern "C" Ptr32<d19c_Clock> d19c_engine_context_80165254(void);
extern "C" unsigned d19c_random_8015ff5c(Ptr32<d19c_Water>);
extern unsigned int d19c_message_804af608;

extern "C" void d19c_water_init_8012aec0(Ptr32<d19c_Water> self) {
    d19c_Vec3 v;
    self->unknown3ac = 0;
    d19c_MessageId id;
    id.value = d19c_cached_message_id_8015f5a0(&d19c_message_804af608, 1);
    d19c_subscribe_80162024(self, &id, &self->subscription);
    self->unknown3a8 = 0;
    {
        d19c_String_8020bb54 name("Water.Ripple");
        d19c_handle_load_8015adf4(&name, &self->ripple, 255);
    }
    d19c_mesh_reserve_indices_8018920c(self->ripple, 150);
    v.set(0.0f, 0.0f, 0.0f);
    self->ripple->vtable->set_position(self->ripple, &v, 0);
    v.set(1.5707964f, 0.0f, 0.0f);
    self->ripple->vtable->set_rotation(self->ripple, &v, 0);
    int now = d19c_engine_context_80165254()->now;
    for (unsigned i = 0; i <= 149; i++)
        self->ripple_start[i] = now - (d19c_random_8015ff5c(self) & 0x7ff);
}


