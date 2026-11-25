#include "w3d_ptr.h"
#line 1 "d30j_remove_node_children_80164cec.cpp"
// Remove every child of a scene node by handle, with the node removal inlined.
// GWMP8P rev0 0x80164cec.
#include "d30j_scene_tree.h"
extern "C" void d30j_remove_node_children_80164cec(Ptr32<Scene> self, int id) {
  Ptr32<Tree> t = self->tree;
  Ptr32<Node> n = t->find(id);
  if (n) while (n->child) t->remove(t->nodes[n->child].id);
}


