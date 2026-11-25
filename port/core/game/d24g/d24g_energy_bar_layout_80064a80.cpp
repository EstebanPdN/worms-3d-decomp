#include "w3d_ptr.h"
#line 1 "d24g_energy_bar_layout_80064a80.cpp"
/* Worms 3D GameCube PAL 0x80064a80. Lays out the energy bar mesh: converts the +28 object to a mesh, sets three sprites, and writes for each its index, position (x 3.0, 1.5, 3.0 with height from setting +144), its vector (x 3.0, 3.0, 4.5), its offset (0, 0.375, 0.5625 by 0) and its texture pair (0.375, 0.1875, 0.375 by 1.0). Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Mesh;
struct Object;
struct Self { char u0[28]; Ptr32<Object> mesh; char u32[112]; Ptr32<Object> height; };
extern "C" Ptr32<Mesh> as_mesh_8034380c(Ptr32<Object>);
extern "C" int mesh_set_80189450(Ptr32<Mesh>, int);
extern "C" int mesh_alloc_8018920c(Ptr32<Mesh>, int);
extern "C" float value_80178df0(Ptr32<Object>);
extern "C" Ptr32<unsigned char> mesh_a_80189828(Ptr32<Mesh>);
extern "C" Ptr32<Vec2> mesh_b_8018963c(Ptr32<Mesh>);
extern "C" Ptr32<Vec3> mesh_c_80189518(Ptr32<Mesh>);
extern "C" Ptr32<Vec2> mesh_d_80189884(Ptr32<Mesh>);
extern "C" Ptr32<Vec2> mesh_e_801898e0(Ptr32<Mesh>);
extern "C" void w3d_d24g_energy_bar_layout_80064a80(Ptr32<Self> self)
{
    Ptr32<Mesh> m = as_mesh_8034380c(self->mesh);
    mesh_set_80189450(m, 3);
    mesh_alloc_8018920c(m, 3);
    float h = value_80178df0(self->height);
    mesh_a_80189828(m)[0] = 0;
    { Ptr32<Vec2> p = mesh_b_8018963c(m); p[0].x = 3.0f; p[0].y = h; }
    { Ptr32<Vec3> p = mesh_c_80189518(m); p[0].x = 0.0f; p[0].y = 0.0f; p[0].z = 0.0f; }
    { Ptr32<Vec2> p = mesh_d_80189884(m); p[0].x = 0.0f; p[0].y = 0.0f; }
    { Ptr32<Vec2> p = mesh_e_801898e0(m); p[0].x = 0.375f; p[0].y = 1.0f; }
    mesh_a_80189828(m)[1] = 1;
    { Ptr32<Vec2> p = mesh_b_8018963c(m); p[1].x = 1.5f; p[1].y = h; }
    { Ptr32<Vec3> q = mesh_c_80189518(m) + 1; q->x = 3.0f; q->y = 0.0f; q->z = 0.0f; }
    { Ptr32<Vec2> p = mesh_d_80189884(m); p[1].x = 0.375f; p[1].y = 0.0f; }
    { Ptr32<Vec2> p = mesh_e_801898e0(m); p[1].x = 0.1875f; p[1].y = 1.0f; }
    mesh_a_80189828(m)[2] = 2;
    { Ptr32<Vec2> p = mesh_b_8018963c(m); p[2].x = 3.0f; p[2].y = h; }
    { Ptr32<Vec3> q = mesh_c_80189518(m) + 2; q->x = 4.5f; q->y = 0.0f; q->z = 0.0f; }
    { Ptr32<Vec2> p = mesh_d_80189884(m); p[2].x = 0.5625f; p[2].y = 0.0f; }
    { Ptr32<Vec2> p = mesh_e_801898e0(m); p[2].x = 0.375f; p[2].y = 1.0f; }
}


