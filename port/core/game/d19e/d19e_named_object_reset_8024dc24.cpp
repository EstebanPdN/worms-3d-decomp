#include "w3d_ptr.h"
#line 1 "d19e_named_object_reset_8024dc24.cpp"
// Named placed-object property reset (Worms 3D GameCube PAL, 0x8024dc24).
//
// Looks up the object's Name and ResourceName string properties (entry
// helper 0x801ed24c) and resets each to the shared empty string 0x804b06a0
// through a retained temporary copy; then looks up the Position,
// Orientation, VoxelPos and Scale three-float vector properties (binding
// helper 0x801f0210) and stores the constant at 0x803c521c (0.0f) into all
// three components of each, calls the refresh routine 0x801e8d9c and reports
// success. Descriptor names are read from the name pointer at +0 of each
// static descriptor.
//
// String-entry reset: same shape as 0x8022c9bc (temporary copy, inline
// reference-counted assignment, destructor). Vector resets: every vector is
// filled through a pointer and passed to the binding's inline
// set(const D19eObjectVec3 &), the later-vector form of the 0x801bce74
// family. Built with -mps-float. Binding views are partial.

struct D19eObjectString;
extern "C" void w3d_string_base_init(Ptr32<D19eObjectString> string);
extern "C" void w3d_string_base_finish(Ptr32<D19eObjectString> string);
extern "C" void w3d_string_release(Ptr32<D19eObjectString> string);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<D19eObjectString> string);
extern "C" void w3d_string_release_header(Ptr32<void> header);

// Four-byte shared engine string; the 16-bit reference count sits six bytes
// before the text.
struct D19eObjectString {
    Ptr32<char> data;
    D19eObjectString(const D19eObjectString &other)
    {
        w3d_string_base_init(this);
        data = other.data;
        ++*w3d_string_header(this);
    }
    ~D19eObjectString()
    {
        w3d_string_base_finish(this);
        w3d_string_release(this);
    }
    D19eObjectString &operator=(const D19eObjectString &other)
    {
        ++*(Ptr32<unsigned short>)(other.data - 6);
        Ptr32<char> old = data;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        data = other.data;
        return *this;
    }
};

struct D19eObjectTextEntry {
    unsigned prefix[2];
    D19eObjectString value;        // +8
};

struct D19eObjectVec3 {
    float x, y, z;
    D19eObjectVec3() {}
};

struct D19eObjectVecBinding {
    unsigned prefix[2];
    D19eObjectVec3 value;          // +8
    void set(const D19eObjectVec3 &v) { value = v; }
};

struct D19eObjectDescriptor;

extern "C" Ptr32<D19eObjectTextEntry> fn_801ed24c(Ptr32<void> object, Ptr32<const D19eObjectDescriptor> descriptor);
extern "C" Ptr32<D19eObjectVecBinding> fn_801f0210(Ptr32<void> object, Ptr32<const D19eObjectDescriptor> descriptor);
extern "C" void fn_801e8d9c(Ptr32<void> object);

extern D19eObjectString w3d_empty_string_804b06a0[];   // shared empty string

extern "C" const D19eObjectDescriptor key_803c511c;    // "Name"
extern "C" const D19eObjectDescriptor key_803c5150;    // "ResourceName"
extern "C" const D19eObjectDescriptor key_803c5174;    // "Position"
extern "C" const D19eObjectDescriptor key_803c51a4;    // "Orientation"
extern "C" const D19eObjectDescriptor key_803c51d4;    // "VoxelPos"
extern "C" const D19eObjectDescriptor key_803c51f8;    // "Scale"
extern "C" const float value_803c521c[];               // 0.0f

extern "C" int w3d_d19e_reset_named_object_8024dc24(Ptr32<void> object)
{
    {
        Ptr32<D19eObjectTextEntry> name = fn_801ed24c(object, &key_803c511c);
        D19eObjectString text(w3d_empty_string_804b06a0[0]);
        name->value = text;
    }
    {
        Ptr32<D19eObjectTextEntry> resource = fn_801ed24c(object, &key_803c5150);
        D19eObjectString text(w3d_empty_string_804b06a0[0]);
        resource->value = text;
    }
    Ptr32<D19eObjectVecBinding> position = fn_801f0210(object, &key_803c5174);
    float v = value_803c521c[0];
    D19eObjectVec3 a;
    Ptr32<D19eObjectVec3> pa = &a;
    pa->x = v;
    pa->y = v;
    pa->z = v;
    position->set(a);
    Ptr32<D19eObjectVecBinding> orientation = fn_801f0210(object, &key_803c51a4);
    D19eObjectVec3 b;
    Ptr32<D19eObjectVec3> pb = &b;
    pb->x = v;
    pb->y = v;
    pb->z = v;
    orientation->set(b);
    Ptr32<D19eObjectVecBinding> voxel = fn_801f0210(object, &key_803c51d4);
    D19eObjectVec3 c;
    Ptr32<D19eObjectVec3> pc = &c;
    pc->x = v;
    pc->y = v;
    pc->z = v;
    voxel->set(c);
    Ptr32<D19eObjectVecBinding> scale = fn_801f0210(object, &key_803c51f8);
    D19eObjectVec3 d;
    Ptr32<D19eObjectVec3> pd = &d;
    pd->x = v;
    pd->y = v;
    pd->z = v;
    scale->set(d);
    fn_801e8d9c(object);
    return 0;
}

typedef char D19eObjectStringSize[(sizeof(D19eObjectString) == 4) ? 1 : -1];


