#include "w3d_ptr.h"
#line 1 "d30k_handler_notify_8021020c.cpp"
// GWMP8P rev0 0x8021020c. Sends a value to every registered handler (first
// or second virtual by mode), then to every listener in the manager's node
// list. Names are inferred from use.
struct Item;
struct ItemVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Item>, int)> on; };
struct Item { Ptr32<ItemVt> vt; };
struct Node { Ptr32<Node> next; Ptr32<Node> prev; Ptr32<Item> val; };
struct It {
 Ptr32<Node> n;
 It() {}
 template <class W3dU> It(Ptr32<W3dU> w3d_p) : It((Node *)w3d_p.get()) {}
 It(Node *x) : n(x) {}
 It(const It &o) : n(o.n) {}
 It &operator=(const It &o) { n = o.n; return *this; }
 int operator!=(const It &o) const { return n != o.n; }
 int operator!=(Node *o) const { return n != o; }
};
struct NodeList { int u0; Ptr32<Node> head; It begin() const { return It(head->next); } It end() const { return It(head); } };
struct Mgr;
struct MgrVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Mgr>)> retain; Ptr32<void (Ptr32<Mgr>)> release; };
struct Mgr { Ptr32<MgrVt> vt; NodeList list; };
struct MgrRef {
 Ptr32<Mgr> p;
 template <class W3dU> MgrRef(Ptr32<W3dU> w3d_p) : MgrRef((Mgr *)w3d_p.get()) {}
 MgrRef(Mgr *m) : p(m) { p->vt->retain(p); }
 MgrRef(const MgrRef &);
 ~MgrRef() { p->vt->release(p); }
};
struct Handler;
struct HandlerVt { Ptr32<void> u[5]; Ptr32<void (Ptr32<Handler>, int)> a; Ptr32<void (Ptr32<Handler>, int)> b; };
struct Handler { Ptr32<HandlerVt> vt; };
struct Handlers { unsigned size; int u4; Ptr32<Ptr32<Handler>> data; };
extern Handlers lbl_80463be0[];
extern "C" Ptr32<Mgr> fn_80210610();
extern "C" void w3d_d30k_handler_notify_8021020c(int mode, int arg) {
 Ptr32<Handlers> h = lbl_80463be0;
 Ptr32<Ptr32<Handler>> p = h->data; Ptr32<Ptr32<Handler>> z = p + h->size;
 for (; p != z; p++) {
  switch (mode) {
   case 0: (*p)->vt->a(*p, arg); break;
   case 1: (*p)->vt->b(*p, arg); break;
  }
 }
 Ptr32<Mgr> raw = fn_80210610();
 MgrRef m(raw);
 Ptr32<NodeList> l = &raw->list;
  It e(l->begin());
 It it(e);
 Ptr32<Node> en = l->head;
 e.n = en;
 while (it != (Node *)en) {
  Ptr32<Item> v = it.n->val;
  Ptr32<Node> next = it.n->next;
  v->vt->on(v, arg);
  it.n = next;
 }
}


