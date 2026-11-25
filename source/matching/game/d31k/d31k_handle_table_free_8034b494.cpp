// GWMP8P rev0 0x8034b494. Frees a handle table entry: looks the handle up by
// its slot and generation, frees its children first, picks the free list
// from the object's type kind (10, 11, others), queues the object for
// release, unlinks the entry from its parent under the scene lock, pushes it
// on the free list, bumps the generation and posts message 66 to the object.
// Names are inferred from use.
enum Kind { K0, K9 = 9, K10, K11, K15 = 15 };
struct Type { char u[32]; unsigned pad : 12; Kind kind : 4; unsigned low : 16; };
struct Obj;
struct Msg { short id; void *type; };
struct ObjVt { char u0[16]; void (*rel)(Obj *); Type *(*type)(Obj *); char u24[12]; void (*post)(Obj *, Msg *); };
struct Obj { ObjVt *vt; };
struct Node { char u0[6]; unsigned short child; unsigned short used; unsigned short next; Obj *obj; unsigned short parent; char u18[2]; int id; char u24[12]; };
struct Table { Node *nodes; int u4; unsigned short lists[3]; };
extern "C" int lbl_804b1890;
extern "C" void *lbl_804b1754;
extern "C" void fn_8034b9bc(Table *, Obj *);
extern "C" Msg *fn_801613f0(void *, int);
extern char lbl_8040db38[];
struct Lock {
 int held;
 Lock() : held(1) { lbl_804b1890--; }
 void Unlock() { held = 0; lbl_804b1890++; }
 ~Lock() { if (held) lbl_804b1890++; }
};
inline Node *Find(Table *t, int id) {
 if (id == -1) return 0;
 Node *c = &t->nodes[id & 0xfff];
 if (c->id == id) return c;
 return 0;
}
extern "C" void w3d_d31k_handle_table_free_8034b494(Table *t, int id) {
 Node *n = Find(t, id);
 if (n == 0) return;
 while (n->child) w3d_d31k_handle_table_free_8034b494(t, t->nodes[n->child].id);
 Obj *o = n->obj;
 int k;
 switch (o->vt->type(o)->kind) {
 case 10: k = 0; break;
 case 11: k = 1; break;
 case 9: k = 2; break;
 default: k = 2; break;
 }
 fn_8034b9bc(t, o);
 if (n->obj) n->obj->vt->rel(n->obj);
 n->obj = 0;
 Lock lock;
 unsigned idx = id & 0xfff;
 Node *p = &t->nodes[n->parent];
 if (p->child == idx) p->child = n->next;
 else {
  unsigned i = p->child;
  while (t->nodes[i].next != idx) i = t->nodes[i].next;
  t->nodes[i].next = n->next;
 }
 n->next = t->lists[k];
 int nid = n->id; t->lists[k] = nid & 0xfff;
 n->used = 1;
 n->id = (n->id + 4096) & 0x7fffffff;
 lock.Unlock();
 ObjVt *vt = o->vt;
 Msg *m = fn_801613f0(lbl_804b1754, 8);
 m->id = 66;
 m->type = lbl_8040db38;
 vt->post(o, m);
}
