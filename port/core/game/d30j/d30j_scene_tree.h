inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
enum Kind { KNone = -1, K9 = 9, K10 = 10, K11 = 11 };
struct Info { char p0[32]; unsigned int :16; unsigned int kind:4; unsigned int :12; };
struct Msg { short id; Ptr32<void> type; Msg(short i, Ptr32<void> t) { id = i; type = t; } };
struct ActorVt;
struct Obj { Ptr32<ActorVt> vt; };
struct ActorVt { char p[16]; Ptr32<void (Ptr32<Obj>)> release; Ptr32<Ptr32<Info> (Ptr32<Obj>)> info; char q[12]; Ptr32<void (Ptr32<Obj>, Ptr32<Msg>)> post; };
struct Ref { Ptr32<Obj> p; void set(Ptr32<Obj> q) { if (p) p->vt->release(p); p = q; } };
struct Node { char p0[6]; unsigned short child; unsigned short state; unsigned short next; Ref actor; unsigned short parent; char p12[2]; int id; char p18[12]; int index() { return id & 0xfff; } };
extern int lbl_804b1890;
extern Ptr32<void> lbl_804b1754;
extern char lbl_8040db38[];
struct Lock {
  int held;
  Lock() { held = 1; lbl_804b1890--; }
  void release() { lbl_804b1890++; held = 0; }
  ~Lock() { if (held) lbl_804b1890++; }
};
struct Tree;
extern "C" void fn_8034b494(Ptr32<Tree>, int);
extern "C" void w3d_cx9c_append_interface_8034b9bc(Ptr32<Tree>, Ptr32<Obj>);
extern "C" Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
struct Tree {
  Ptr32<Node> nodes; int p4; unsigned short free_[3];
  Ptr32<Node> find(int id) {
    if (id == -1) return 0;
    Ptr32<Node> p = &nodes[id & 0xfff];
    if (p->id == id) return p;
    return 0;
  }
  void remove(int id) {
    Ptr32<Node> n = find(id);
    if (n == 0) return;
    while (n->child) fn_8034b494(this, nodes[n->child].id);
    Ptr32<Obj> a = n->actor.p;
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
      Ptr32<Node> parent = &nodes[n->parent];
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
      Ptr32<ActorVt> vt = a->vt;
      vt->post(a, new (tsonnet_b33_arena_801613f0(lbl_804b1754, 8)) Msg(66, lbl_8040db38));
    }
  }
};
struct Scene { char p0[28]; Ptr32<Tree> tree; };
