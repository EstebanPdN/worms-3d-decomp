#include "w3d_ptr.h"
#line 1 "d20e_box_properties_801c4930.cpp"
// Box property registration (Worms 3D GameCube PAL, 0x801c4930).
//
// Creates the Min and Max vector bindings (0x801f0504) and resets both to
// the constant at 0x803acb38 (0.0f) in all components, registers the XSize,
// YSize and ZSize member bindings (0x801ebf38), registers the "Data"
// property through 0x801efec4 with a function-local static descriptor
// (size 44, element type 5, type 9, type object 0x8045ed7c), calls the
// refresh routine 0x801e8d9c and returns 0. Names are read from the
// descriptors' name pointers in the original data.
//
// The static descriptor is a function-local static (guard and object are
// this function's .sbss/.bss statics, at 0x804b04d4 and 0x8045d610 in the
// original) initialized from a zero-filled local: the original builds the
// value in a stack temporary (memset, field stores) inside the guard and
// copies it into the static, and computes the static's address before the
// guard test. Written as a GNU statement expression, the form a property
// registration macro would expand to. Vectors follow the d18e recipe (first
// via inline constructor and assignment, second filled through a pointer and
// copied with an inline set(const D20eVec3 &)). Built with -mps-float (one
// saved FPR in a non-leaf function).
extern "C" Ptr32<void> memset(...);

// 20-byte property descriptor registered by 0x801efec4.
struct D20ePropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> typeObject;
    int unknown12;
    int unknown16;
};

struct D20eVec3 {
    float x, y, z;
    D20eVec3() {}
    D20eVec3(float a, float b, float c) { x = a; y = b; z = c; }
};

struct D20eVectorBinding {
    unsigned header[2];
    D20eVec3 value;
    void set(const D20eVec3 &v) { value = v; }
};

struct D20eDescriptor;
extern "C" Ptr32<D20eVectorBinding> fn_801f0504(Ptr32<void> owner, Ptr32<const D20eDescriptor> descriptor);
extern "C" Ptr32<void> fn_801ebf38(Ptr32<void> owner, Ptr32<const D20eDescriptor> descriptor);
extern "C" Ptr32<void> fn_801efec4(Ptr32<void> owner, Ptr32<D20ePropertyInfo> info);
extern "C" void fn_801e8d9c(Ptr32<void> owner);
extern char lbl_803aca0c[];        // "Data"
extern char lbl_8045ed7c[];        // property type object
extern "C" const D20eDescriptor k_803aca60;   // Min
extern "C" const D20eDescriptor k_803aca84;   // Max
extern "C" const D20eDescriptor k_803acab0;   // XSize
extern "C" const D20eDescriptor k_803acae0;   // YSize
extern "C" const D20eDescriptor k_803acb10;   // ZSize
extern "C" const float value_803acb38[];      // 0.0f

extern "C" int w3d_d20e_register_box_properties_801c4930(Ptr32<void> self)
{
    Ptr32<D20eVectorBinding> min = fn_801f0504(self, &k_803aca60);
    float zero = value_803acb38[0];
    D20eVec3 a(zero, zero, zero);
    min->value = a;
    Ptr32<D20eVectorBinding> max = fn_801f0504(self, &k_803aca84);
    D20eVec3 b;
    Ptr32<D20eVec3> q = &b;
    q->x = zero;
    q->y = zero;
    q->z = zero;
    max->set(b);
    fn_801ebf38(self, &k_803acab0);
    fn_801ebf38(self, &k_803acae0);
    fn_801ebf38(self, &k_803acb10);
    static D20ePropertyInfo info = ({
        D20ePropertyInfo t;
        memset(w3d::VA(&t), 0, sizeof(t));
        t.name = lbl_803aca0c;
        t.size = 44;
        t.elementType = 5;
        t.type = 9;
        t.typeObject = lbl_8045ed7c;
        t;
    });
    fn_801efec4(self, &info);
    fn_801e8d9c(self);
    return 0;
}


