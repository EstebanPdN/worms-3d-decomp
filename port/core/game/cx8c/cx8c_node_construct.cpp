#include "w3d_ptr.h"
#line 1 "cx8c_node_construct.cpp"
/* Layout offsets and call addresses observed in the original. Names and object roles are inferred. */
struct Cx8cNode {Ptr32<void> vtable;unsigned int unknown[2];Ptr32<void> member_vtable;};
extern "C" {extern char cx8c_vtable_80419598[],cx8c_vtable_80411ad8[];void cx8c_node_init_8020fc60(Ptr32<Cx8cNode>, Ptr32<void>);}
extern "C" void w3d_cx8c_node_construct_8034baf8(Ptr32<Cx8cNode> self, Ptr32<void> arg_r4) {self->member_vtable=cx8c_vtable_80419598;self->vtable=cx8c_vtable_80411ad8;cx8c_node_init_8020fc60(self, arg_r4);}


