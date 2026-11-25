inline void *operator new(unsigned int, void *place) { return place; }
enum Kind { KNone = -1, K9 = 9, K10 = 10, K11 = 11 };
struct Info { char p0[32]; unsigned : 12; unsigned kind : 4; unsigned : 16; };
struct Msg { short id; void *type; Msg(short i, void *t) { id = i; type = t; } };
struct ActorVt;
struct Obj { ActorVt *vt; };
struct ActorVt { char p[16]; void (*release)(Obj *); Info *(*info)(Obj *); char q[12]; void (*post)(Obj *, Msg *); };
struct Ref { Obj *p; void set(Obj *q) { if (p) p->vt->release(p); p = q; } };
struct Node { char p0[6]; unsigned short child; unsigned short state; unsigned short next; Ref actor; unsigned short parent; char p12[2]; int id; char p18[12]; int index() { return id & 0xfff; } };
extern int lbl_804b1890;
extern void *lbl_804b1754;
extern char lbl_8040db38[];
struct Lock {
  int held;
  Lock() { held = 1; lbl_804b1890--; }
  void release() { lbl_804b1890++; held = 0; }
  ~Lock() { if (held) lbl_804b1890++; }
};
struct Tree;
extern "C" void fn_8034b494(Tree *, int);
extern "C" void w3d_cx9c_append_interface_8034b9bc(Tree *, Obj *);
extern "C" void *tsonnet_b33_arena_801613f0(void *, int);
struct Tree {
  Node *nodes; int p4; unsigned short free_[3];
  Node *find(int id) {
    if (id == -1) return 0;
    Node *p = &nodes[id & 0xfff];
    if (p->id == id) return p;
    return 0;
  }
  void remove(int id) {
    Node *n = find(id);
    if (n == 0) return;
    while (n->child) fn_8034b494(this, nodes[n->child].id);
    Obj *a = n->actor.p;
    int kind;
    switch ((Kind)a->vt->info(a)->kind) {
      case K9: kind = 2; break;
      case K10: kind = 0; break;
      case K11: kind = 1; break;
      default: kind = 2; break;
    }
    w3d_cx9c_append_interface_8034b9bc(this, a);
    n->actor.set(0);
    {
      Lock lock;
      int idx = id & 0xfff;
      Node *parent = &nodes[n->parent];
      if (parent->child == idx) parent->child = n->next;
      else {
        int k = parent->child;
        while (nodes[k].next != idx) k = nodes[k].next;
        nodes[k].next = n->next;
      }
      n->next = free_[kind];
      free_[kind] = n->index();
      n->state = 1;
      n->id = (n->id + 0x1000) & 0x7fffffff;
      lock.release();
      ActorVt *vt = a->vt;
      vt->post(a, new (tsonnet_b33_arena_801613f0(lbl_804b1754, 8)) Msg(66, lbl_8040db38));
    }
  }
};
struct Scene { char p0[28]; Tree *tree; };
