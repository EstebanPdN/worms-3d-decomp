#include "w3d_ptr.h"
#line 1 "k7b_a_801a4278.cpp"
struct K7bVec3 {
    float x, y, z;
    void set(float nx, float ny, float nz) { x = nx; y = ny; z = nz; }
    K7bVec3 &operator=(const K7bVec3 &o) { set(o.x, o.y, o.z); return *this; }
};
struct K7bStateBits { char pad[4]; unsigned char flags; char w3d_tag_rest[3]; void clear_dirty() { flags &= ~2; } };
struct K7bNode;
extern "C" void fn_801a3eb0(Ptr32<void> target, int value, Ptr32<K7bNode> node);
extern "C" void w3d_auto_801f6448(Ptr32<K7bNode> node, float x, float y, float z);
inline void k7b_node_set_position(Ptr32<K7bNode> node, const K7bVec3 &p) { w3d_auto_801f6448(node, p.x, p.y, p.z); }
struct K7bPlacement {
    char pad00[4];
    K7bStateBits state;
    char pad0c[8];
    char node[36];
    K7bVec3 current;
    char pad44[4];
    K7bVec3 position;
    char target[12];
    K7bVec3 home;
    int value;
};
extern "C" void w3d_k7b_placement_reset_801a4278(Ptr32<K7bPlacement> self)
{
    self->state.clear_dirty();
    fn_801a3eb0(self->target, self->value, (Ptr32<K7bNode>)self->node);
    k7b_node_set_position((Ptr32<K7bNode>)self->node, self->position);
    self->current = self->home;
}


