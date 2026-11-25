// Task manager (Worms 3D GameCube PAL, 0x80164514): takes a free slot from the
// pool chosen by the task type's kind, resets it, links it under the parent
// handle, stores a reference to the task, and adds its id to the pool's timer
// queue or active list. It then runs the task's start hook at a mode chosen by
// task type and restores the engine's mode. Returns the new slot's id. Names are inferred.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct Timer {
  unsigned id; int when;
  Timer(unsigned i, int w) : id(i), when(w) {}
};
struct Later { unsigned char unused; };
struct Queue { std::vector<Timer> c; Later comp; };
extern "C" void w3d_push_heap_8034a400(Timer *first, Timer *last, Later comp);
enum Kind { K9 = 9, K10 = 10, K11 = 11 };
struct TypeInfo { char q[20]; TypeInfo *parent; char r[8]; unsigned hi : 12; unsigned kind : 4; unsigned lo : 16;
  bool Is(const TypeInfo *t) const { const TypeInfo *x = this; while (x != t) { if (x == x->parent) return false; x = x->parent; } return true; }
};
struct Task { virtual void v0(); virtual void AddRef(); virtual void Release(); virtual TypeInfo *Type(); };
struct Slot { int Index() { return id & 0xfff; } int w0; unsigned short a, firstChild, c, next; Task *task; unsigned short parent, e; unsigned id; char s[12];
};
typedef std::vector<unsigned> Active;
struct Mgr;
struct Group { Queue *queue; Active *active; Mgr *table; };
struct Mgr { Slot *slots; int base; unsigned short head[3]; char q[22]; int last; Group g[3];
  Slot *Get(unsigned id) { if (id == 0xffffffff) return 0; Slot *s = slots + (id & 0xfff); if (s->id == id) return s; return 0; }
};
struct Engine { char q[60]; int mode; };
extern "C" Engine *engine_context_80165254();
extern "C" char *type_name_801ffea8(TypeInfo *);
extern "C" void start_task_8034b418(Mgr *, Slot *, int);
extern TypeInfo type_803617d0, type_80361860, type_803618f0;
struct Self { char q[28]; Mgr *mgr; };
static inline unsigned Add(Mgr *m, Task *t, unsigned parentId) {
  Slot *parent = m->Get(parentId);
  engine_context_80165254();
  type_name_801ffea8(t->Type());
  unsigned pool;
  switch ((Kind)t->Type()->kind) {
    case K9: pool = 2; break;
    case K10: pool = 0; break;
    case K11: pool = 1; break;
    default: pool = 2; break;
  }
  Slot *s = m->slots + m->head[pool];
  m->head[pool] = s->next;
  s->w0 = 0; s->a = 0; s->firstChild = 0; s->c = 0; s->next = 0;
  if (s->task) s->task->Release();
  s->task = 0; s->parent = 0; s->e = 0;
  unsigned short old = parent->firstChild;
  s->next = old;
  parent->firstChild = s->Index();
  if (t) t->AddRef();
  if (s->task) s->task->Release();
  s->task = t;
  s->parent = parentId & 0xfff;
  if (pool < 2) {
    Queue *q = m->g[pool].queue;
    q->c.push_back(Timer(s->id, m->last));
    w3d_push_heap_8034a400(q->c.begin(), q->c.end(), q->comp);
  } else {
    Active *v = m->g[pool].active;
    unsigned id;
    id = s->id;
    v->push_back(id);
  }
  int saved = engine_context_80165254()->mode;
  int mode;
  if (t->Type()->Is(&type_803617d0)) mode = 4;
  else if (t->Type()->Is(&type_80361860)) mode = 3;
  else if (t->Type()->Is(&type_803618f0)) mode = 5;
  else goto skip;
  engine_context_80165254()->mode = mode;
skip:
  start_task_8034b418(m, s, 0);
  engine_context_80165254()->mode = saved;
  return s->id;
}
extern "C" unsigned w3d_d40j_task_manager_add_80164514(Self *self, Task *t, unsigned parentId) { return Add(self->mgr, t, parentId); }
