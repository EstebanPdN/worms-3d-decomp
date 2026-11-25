#include "w3d_ptr.h"
#line 1 "cx7a_tree_descendant_count_800bb4e4.cpp"

// +0x2c points to a variable-size children block. Count at +0x18,
// inline child pointers at +0x20. Returns all descendants, excluding self.
struct Cx7aNode;
struct Cx7aChildren { unsigned char unknown[0x18];unsigned int count;unsigned int spare;Ptr32<Cx7aNode> children[1]; };
struct Cx7aNode { unsigned char unknown[0x2c];Ptr32<Cx7aChildren> children; };
extern "C" unsigned int w3d_cx7a_tree_descendant_count_800bb4e4(Ptr32<Cx7aNode> self) { unsigned int index=0;unsigned int count=self->children->count;Ptr32<Ptr32<Cx7aNode>> next=self->children->children;unsigned int total=count;if(index<count) { Ptr32<Ptr32<Cx7aNode>> cursor=next;do { Ptr32<Cx7aNode> child=*cursor;++index;++cursor;total+=w3d_cx7a_tree_descendant_count_800bb4e4(child); } while(index<count); } return total; }


