#include "w3d_ptr.h"
#line 1 "tsonnet_c26_static_node_8020b208.cpp"
inline void *operator new(__SIZE_TYPE__, void *p) { return p; }
struct TaggedLink {
 Ptr32<void> target;
 unsigned int kind:8; unsigned int pointer:24;
 TaggedLink(unsigned char tag) { kind = tag; pointer = 0; }
};
struct Node { Ptr32<Ptr32<void>> vtable; TaggedLink link; Node(); };
extern "C" Ptr32<void> lbl_80419470[];
extern "C" Node lbl_804632e8[];
extern "C" int lbl_804b0690;
extern "C" int atexit(Ptr32<void (void)>);
extern "C" void fn_8020b1cc();
inline Node::Node() : link(2) { vtable = lbl_80419470; }
extern "C" Ptr32<Node> tsonnet_c26_static_node_8020b208() {
 if (lbl_804b0690 == 0) {
  Ptr32<Node> n = lbl_804632e8;
  lbl_804b0690 = 1;
  new (n) Node;
  atexit(fn_8020b1cc);
 }
 return lbl_804632e8;
}


