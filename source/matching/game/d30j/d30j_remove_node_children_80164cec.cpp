// Remove every child of a scene node by handle, with the node removal inlined.
// GWMP8P rev0 0x80164cec.
#include "d30j_scene_tree.h"
extern "C" void d30j_remove_node_children_80164cec(Scene *self, int id) {
  Tree *t = self->tree;
  Node *n = t->find(id);
  if (n) while (n->child) t->remove(t->nodes[n->child].id);
}
