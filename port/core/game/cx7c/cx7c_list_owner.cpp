#include "w3d_ptr.h"
#line 1 "cx7c_list_owner.cpp"
/* Inferred list owner at 0x8035d5b4. Observed 32-bit ABI:
 * +0 vptr, +4 allocator/unknown word, +8 circular-list sentinel pointer.
 * The 12-byte sentinel stores next/previous at +0/+4; +8 is unobserved.
 * Construction installs the base table, allocates the sentinel, then installs
 * the derived table. The allocator's original fallback is preserved.
 */
struct Cx7cListNode { Ptr32<Cx7cListNode> next; Ptr32<Cx7cListNode> previous; unsigned int unknown_08; };
extern "C" {
Ptr32<void> cx7c_allocate_80212fd4(unsigned int);
Ptr32<void> cx7c_allocation_fallback_803413d8(unsigned int);
extern unsigned char cx7c_base_vtable_80419648[];
extern unsigned char cx7c_derived_vtable_80419628[];
}
struct Cx7cList {
    unsigned int unknown_00;
    Ptr32<Cx7cListNode> sentinel;
    void initialize() {
        sentinel = 0;
        Ptr32<Cx7cListNode> node = (Ptr32<Cx7cListNode>)cx7c_allocate_80212fd4(sizeof(Cx7cListNode));
        if (!node) node = (Ptr32<Cx7cListNode>)cx7c_allocation_fallback_803413d8(sizeof(Cx7cListNode));
        node->next = node;
        node->previous = node;
        sentinel = node;
    }
};
struct Cx7cListOwner { Ptr32<void> vptr; Cx7cList list; };
extern "C" Ptr32<Cx7cListOwner> w3d_cx7c_list_owner_construct_8035d5b4(Ptr32<Cx7cListOwner> self)
{
    volatile char frame_reservation[16];
    self->vptr = cx7c_base_vtable_80419648;
    self->list.initialize();
    self->vptr = cx7c_derived_vtable_80419628;
    return self;
}


