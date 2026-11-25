inline void *operator new(unsigned int, void *p) { return p; }
struct TaggedLink {
 void *target;
 unsigned int pointer : 24;
 unsigned int kind : 8;
 TaggedLink(unsigned char tag) { kind = tag; pointer = 0; }
};
struct Node { void **vtable; TaggedLink link; Node(); };
extern "C" void *lbl_80419470[];
extern "C" Node lbl_804632e8[];
extern "C" int lbl_804b0690;
extern "C" int atexit(void (*)());
extern "C" void fn_8020b1cc();
inline Node::Node() : link(2) { vtable = lbl_80419470; }
extern "C" Node *tsonnet_c26_static_node_8020b208() {
 if (lbl_804b0690 == 0) {
  Node *n = lbl_804632e8;
  lbl_804b0690 = 1;
  new (n) Node;
  atexit(fn_8020b1cc);
 }
 return lbl_804632e8;
}
