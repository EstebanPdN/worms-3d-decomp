// GWMP8P rev0 0x8021020c. Sends a value to every registered handler (first
// or second virtual by mode), then to every listener in the manager's node
// list. Names are inferred from use.
struct Item;
struct ItemVt { void *u[3]; void (*on)(Item *, int); };
struct Item { ItemVt *vt; };
struct Node { Node *next; Node *prev; Item *val; };
struct It {
 Node *n;
 It() {}
 It(Node *x) : n(x) {}
 It(const It &o) : n(o.n) {}
 It &operator=(const It &o) { n = o.n; return *this; }
 int operator!=(const It &o) const { return n != o.n; }
 int operator!=(Node *o) const { return n != o; }
};
struct NodeList { int u0; Node *head; It begin() const { return It(head->next); } It end() const { return It(head); } };
struct Mgr;
struct MgrVt { void *u[3]; void (*retain)(Mgr *); void (*release)(Mgr *); };
struct Mgr { MgrVt *vt; NodeList list; };
struct MgrRef {
 Mgr *p;
 MgrRef(Mgr *m) : p(m) { p->vt->retain(p); }
 MgrRef(const MgrRef &);
 ~MgrRef() { p->vt->release(p); }
};
struct Handler;
struct HandlerVt { void *u[5]; void (*a)(Handler *, int); void (*b)(Handler *, int); };
struct Handler { HandlerVt *vt; };
struct Handlers { unsigned size; int u4; Handler **data; };
extern Handlers lbl_80463be0[];
extern "C" Mgr *fn_80210610();
extern "C" void w3d_d30k_handler_notify_8021020c(int mode, int arg) {
 Handlers *h = lbl_80463be0;
 Handler **p = h->data, **z = p + h->size;
 for (; p != z; p++) {
  switch (mode) {
   case 0: (*p)->vt->a(*p, arg); break;
   case 1: (*p)->vt->b(*p, arg); break;
  }
 }
 Mgr *raw = fn_80210610();
 MgrRef m(raw);
 NodeList *l = &raw->list;
  It e(l->begin());
 It it(e);
 Node *en = l->head;
 e.n = en;
 while (it != en) {
  Item *v = it.n->val;
  Node *next = it.n->next;
  v->vt->on(v, arg);
  it.n = next;
 }
}
