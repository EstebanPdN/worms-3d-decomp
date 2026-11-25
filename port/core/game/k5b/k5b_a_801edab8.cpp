#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801edab8.c"
struct K5bShared { Ptr32<Ptr32<void>> vtable; };
extern Ptr32<struct K5bShared> lbl_804b05a8;
extern Ptr32<struct K5bShared> lbl_804b05ac;
extern Ptr32<struct K5bShared> lbl_804b05b0;
extern Ptr32<struct K5bShared> lbl_804b05b4;
extern Ptr32<void> lbl_804176d0[];
extern Ptr32<void> lbl_80417670[];
extern Ptr32<void> lbl_804176a0[];
extern Ptr32<void> w3d_aligned_allocate(unsigned int size, unsigned int alignment);
extern Ptr32<struct K5bShared> w3d_tagged_construct_801ee1e4(Ptr32<struct K5bShared> self);
static inline void k5b_retain(Ptr32<struct K5bShared> object)
{
    ((Ptr32<void (Ptr32<struct K5bShared>)>)object->vtable[3])(object);
}
int w3d_k5b_shared_defaults_create_801edab8(void)
{
    Ptr32<struct K5bShared> first;
    Ptr32<struct K5bShared> second;
    Ptr32<struct K5bShared> third;
    lbl_804b05a8 = w3d_aligned_allocate(32, 32);
    lbl_804b05ac = w3d_aligned_allocate(32, 32);
    lbl_804b05b0 = w3d_aligned_allocate(32, 32);
    lbl_804b05b4 = w3d_aligned_allocate(32, 32);
    lbl_804b05a8 = w3d_tagged_construct_801ee1e4(lbl_804b05a8);
    first = lbl_804b05ac;
    w3d_tagged_construct_801ee1e4(first);
    first->vtable = lbl_804176d0;
    lbl_804b05ac = first;
    second = lbl_804b05b0;
    w3d_tagged_construct_801ee1e4(second);
    second->vtable = lbl_80417670;
    lbl_804b05b0 = second;
    third = lbl_804b05b4;
    w3d_tagged_construct_801ee1e4(third);
    third->vtable = lbl_804176a0;
    lbl_804b05b4 = third;
    k5b_retain(lbl_804b05a8);
    k5b_retain(lbl_804b05ac);
    k5b_retain(lbl_804b05b0);
    k5b_retain(lbl_804b05b4);
    return 0;
}
// desc: w3d_k5b_shared_defaults_create_801edab8: Appears to allocate and construct the four shared default objects at 0x804b05a8..0x804b05b4 (three with derived vtables) and retain each once.

}
