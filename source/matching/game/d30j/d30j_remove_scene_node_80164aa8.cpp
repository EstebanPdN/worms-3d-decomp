// Remove a scene node by handle: recursively remove children, append the actor
// to the tree's interface list, release it, unlink the node from its parent,
// push it on the free list of its kind, bump the generation and post message 66
// to the actor. GWMP8P rev0 0x80164aa8.
#include "d30j_scene_tree.h"
extern "C" void d30j_remove_scene_node_80164aa8(Scene *self, int id) { self->tree->remove(id); }
