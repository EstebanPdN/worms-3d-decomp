// Partial intrusive-node view. Both original list heads and name accessors
// remain external; search order and exact strcmp-zero behavior are preserved.
struct cc39b_NamedNode { unsigned int opaque;cc39b_NamedNode *next; };
extern "C" cc39b_NamedNode *cc39b_active_head_8020ff3c();
extern "C" cc39b_NamedNode *cc39b_pending_head_8020ff34();
extern "C" const char *cc39b_node_name_801ffea8(cc39b_NamedNode *);
extern "C" int cc39b_compare_802ef234(const char *,const char *);
extern "C" cc39b_NamedNode *cc39b_find_named_8021048c(const char *name,int active_only) {
 cc39b_NamedNode *node=cc39b_active_head_8020ff3c();
 for(;node;node=node->next) if(cc39b_compare_802ef234(cc39b_node_name_801ffea8(node),name)==0) break;
 if(!active_only && !node) {
  for(node=cc39b_pending_head_8020ff34();node;node=node->next)
   if(cc39b_compare_802ef234(cc39b_node_name_801ffea8(node),name)==0) break;
 }
 return node;
}
