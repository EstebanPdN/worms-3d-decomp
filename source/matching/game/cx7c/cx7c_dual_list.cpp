/* Inferred composite of two list owners at 0x80357568. Each 12-byte
 * subobject has vptr +0 and sentinel +8. Tables show successive base and
 * derived identities; no original class names are claimed.
 */
struct Cx7cDualNode { Cx7cDualNode *next,*previous; unsigned int unused_08; };
extern "C" {
void *cx7c_allocate_80212fd4(unsigned int);
void *cx7c_allocation_fallback_803413d8(unsigned int);
extern unsigned char cx7c_vtable_80417280[],cx7c_vtable_80417260[];
extern unsigned char cx7c_vtable_80417240[],cx7c_vtable_80417220[];
}
struct Cx7cDualList {
    unsigned int unknown_00;
    Cx7cDualNode *sentinel;
    void initialize(Cx7cDualNode *zero) {
        sentinel=zero;
        Cx7cDualNode *node=(Cx7cDualNode*)cx7c_allocate_80212fd4(12);
        if (!node) node=(Cx7cDualNode*)cx7c_allocation_fallback_803413d8(12);
        node->next=node;node->previous=node;sentinel=node;
    }
};
struct Cx7cDualPart {void *vptr; Cx7cDualList list;};
struct Cx7cDualOwner {Cx7cDualPart first,second;};
extern "C" Cx7cDualOwner *w3d_cx7c_dual_list_construct_80357568(Cx7cDualOwner *self)
{
    volatile char frame_reservation[32];
    self->first.vptr=cx7c_vtable_80417280;
    self->first.list.initialize(0);
    self->first.vptr=cx7c_vtable_80417260;
    self->second.vptr=cx7c_vtable_80417240;
    self->second.list.initialize(0);
    self->second.vptr=cx7c_vtable_80417220;
    return self;
}
