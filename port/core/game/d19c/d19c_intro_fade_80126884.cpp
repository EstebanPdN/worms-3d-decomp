#include "w3d_ptr.h"
#line 1 "d19c_intro_fade_80126884.cpp"
// d19c: 0x80126884 (572 bytes). Intro fade-in: enter scope 3, load the
// "Intro.Musy" logo node into +128 (position (0, -134, 0), scale (64, 64, 0))
// and the "Intro.License" node into +124 (position (0, 25, 0), scale
// (240, 34, 0)), mark the intro as fading, then over 40 updates raise a grey
// level by 6.375 per step, apply it as an opaque colour to both meshes and run
// the intro's update; finally mark it faded.
// Built with -mfast-cast (the float to byte conversions use psq_st) and
// -mps-float (two FPRs are saved; the flag reserves the 8 bytes below the
// register save area seen in the original frame). The colour is passed to the
// mesh calls by its own address, so the constructor's pointer is not kept in
// a second saved register. The alpha argument 255.0f is folded to a constant
// byte; the 255.0f that follows this unit's literals belongs to 0x80126ac0.
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
struct d19c_Vec3 { float x, y, z; };
struct d19c_Rgba {
    char r, g, b, a;
    d19c_Rgba(char red, char green, char blue, char alpha) { r = red; g = green; b = blue; a = alpha; }
    void set(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) { r = red; g = green; b = blue; a = alpha; }
};
struct d19c_Node;
struct d19c_NodeVtable {
    Ptr32<void> unknown00[19];
    Ptr32<int (Ptr32<d19c_Node>, Ptr32<const d19c_Vec3>, int)> set_position;   // +76
    Ptr32<void> unknown80;
    Ptr32<int (Ptr32<d19c_Node>, Ptr32<const d19c_Vec3>, int)> set_scale;      // +84
};
struct d19c_Node { Ptr32<d19c_NodeVtable> vtable; };
struct d19c_Intro;
struct d19c_IntroVtable {
    Ptr32<void> unknown00[16];
    Ptr32<void (Ptr32<d19c_Intro>, int)> update;   // +64
};
struct d19c_Intro {
    Ptr32<d19c_IntroVtable> vtable;
    unsigned char unknown004[72];
    unsigned int unknown76:28; unsigned int faded:1; unsigned int fading:1; unsigned int flag1:1; unsigned int flag0:1;
    unsigned char unknown080[44];
    Ptr32<d19c_Node> license;                  // +124
    Ptr32<d19c_Node> logo;                     // +128
};
extern "C" int d19c_handle_load_8015adf4(Ptr32<const d19c_String_8020bb54>, Ptr32<Ptr32<d19c_Node>>, unsigned char);
extern "C" void d19c_scope_enter_8015aee8(unsigned char);
extern "C" Ptr32<d19c_Node> d19c_as_mesh_8034357c(Ptr32<d19c_Node>);
extern "C" int d19c_mesh_set_colour_80173df0(Ptr32<d19c_Node>, Ptr32<const d19c_Rgba>);

extern "C" void d19c_intro_fade_80126884(Ptr32<d19c_Intro> self) {
    d19c_scope_enter_8015aee8(3);
    d19c_Rgba colour(0, 0, 0, -1);
    d19c_Vec3 logo_scale;
    Ptr32<d19c_Vec3> ls = &logo_scale;
    logo_scale.x = 64.0f;
    ls->y = 64.0f;
    ls->z = 0.0f;
    d19c_Vec3 logo_position;
    Ptr32<d19c_Vec3> lp = &logo_position;
    logo_position.x = 0.0f;
    lp->y = -134.0f;
    lp->z = 0.0f;
    {
        d19c_String_8020bb54 name("Intro.Musy");
        d19c_handle_load_8015adf4(&name, &self->logo, 255);
    }
    self->logo->vtable->set_position(self->logo, lp, 0);
    self->logo->vtable->set_scale(self->logo, ls, 0);
    d19c_Vec3 license_scale;
    Ptr32<d19c_Vec3> cs = &license_scale;
    license_scale.x = 240.0f;
    cs->y = 34.0f;
    cs->z = 0.0f;
    d19c_Vec3 license_position;
    Ptr32<d19c_Vec3> cp = &license_position;
    license_position.x = 0.0f;
    cp->y = 25.0f;
    cp->z = 0.0f;
    {
        d19c_String_8020bb54 name("Intro.License");
        d19c_handle_load_8015adf4(&name, &self->license, 255);
    }
    self->license->vtable->set_position(self->license, cp, 0);
    self->license->vtable->set_scale(self->license, cs, 0);
    self->fading = 1;
    self->faded = 0;
    float alpha = 0.0f;
    for (unsigned i = 0; i < 40; i++) {
        alpha += 6.375f;
        colour.set(alpha, alpha, alpha, 255.0f);
        d19c_mesh_set_colour_80173df0(d19c_as_mesh_8034357c(self->license), &colour);
        d19c_mesh_set_colour_80173df0(d19c_as_mesh_8034357c(self->logo), &colour);
        self->vtable->update(self, 0);
    }
    self->faded = 1;
    self->fading = 0;
}


