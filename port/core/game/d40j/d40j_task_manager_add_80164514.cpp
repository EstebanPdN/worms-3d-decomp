#include "w3d_ptr.h"
#line 1 "d40j_task_manager_add_80164514.cpp"
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
extern "C" void w3d_push_heap_8034a400(Ptr32<Timer> first, Ptr32<Timer> last, Later comp);
enum Kind { K9 = 9, K10 = 10, K11 = 11 };
struct TypeInfo { char q[20]; Ptr32<TypeInfo> parent; char r[8]; unsigned int lo:16; unsigned int kind:4; unsigned int hi:12;
  bool Is(Ptr32<const TypeInfo> t) const { Ptr32<const TypeInfo> x = this; while (x != t) { if (x == x->parent) return false; x = x->parent; } return true; }
};
struct Task { void w3d_r_v0() __asm__(W3D_SYM("_ZN4Task2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN4Task6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN4Task7ReleaseEv")); Ptr32<TypeInfo> w3d_r_Type() __asm__(W3D_SYM("_ZN4Task4TypeEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Task, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Task, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Task, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<TypeInfo> Type() { return ((Ptr32<TypeInfo> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Task, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Task; };
struct Slot { int Index() { return id & 0xfff; } int w0; unsigned short a, firstChild, c, next; Ptr32<Task> task; unsigned short parent, e; unsigned id; char s[12];
};
typedef std::vector<unsigned> Active;
struct Mgr;
struct Group { Ptr32<Queue> queue; Ptr32<Active> active; Ptr32<Mgr> table; };
struct Mgr { Ptr32<Slot> slots; int base; unsigned short head[3]; char q[22]; int last; Group g[3];
  Ptr32<Slot> Get(unsigned id) { if (id == 0xffffffff) return 0; Ptr32<Slot> s = slots + (id & 0xfff); if (s->id == id) return s; return 0; }
};
struct Engine { char q[60]; int mode; };
extern "C" Ptr32<Engine> engine_context_80165254();
extern "C" Ptr32<char> type_name_801ffea8(Ptr32<TypeInfo>);
extern "C" void start_task_8034b418(Ptr32<Mgr>, Ptr32<Slot>, int);
extern TypeInfo type_803617d0, type_80361860, type_803618f0;
struct Self { char q[28]; Ptr32<Mgr> mgr; };
static inline unsigned Add(Ptr32<Mgr> m, Ptr32<Task> t, unsigned parentId) {
  Ptr32<Slot> parent = m->Get(parentId);
  engine_context_80165254();
  type_name_801ffea8(t->Type());
  unsigned pool;
  switch ((Kind)t->Type()->kind) {
    case K9: pool = 2; break;
    case K10: pool = 0; break;
    case K11: pool = 1; break;
    default: pool = 2; break;
  }
  Ptr32<Slot> s = m->slots + m->head[pool];
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
    Ptr32<Queue> q = m->g[pool].queue;
    q->c.push_back(Timer(s->id, m->last));
    w3d_push_heap_8034a400(q->c.begin(), q->c.end(), q->comp);
  } else {
    Ptr32<Active> v = m->g[pool].active;
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
extern "C" unsigned w3d_d40j_task_manager_add_80164514(Ptr32<Self> self, Ptr32<Task> t, unsigned parentId) { return Add(self->mgr, t, parentId); }


