struct R27cNode { void *unused; R27cNode *parent; R27cNode *left; R27cNode *right; unsigned key; void *value; };
struct R27cTree { void *unused; R27cNode *sentinel; };
struct R27cMap { char pad[20]; R27cTree tree; };
struct R27cKeyPart { char pad[8]; unsigned short index; };
extern "C" void *r27c_find_pair_8020e4bc(R27cMap *map, R27cKeyPart *a, R27cKeyPart *b) {
 unsigned key=((unsigned)a->index << 16) | b->index;
 R27cNode *candidate=map->tree.sentinel;
 R27cNode *node=candidate->parent;
 while(node) { if(node->key<key) node=node->right; else {candidate=node; node=node->left;} }
 if(candidate==map->tree.sentinel || key<candidate->key) candidate=map->tree.sentinel;
 return candidate==map->tree.sentinel ? 0 : candidate->value;
}
