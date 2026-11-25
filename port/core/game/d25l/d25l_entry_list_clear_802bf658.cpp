#include "w3d_ptr.h"
#line 1 "d25l_entry_list_clear_802bf658.cpp"
// GWMP8P rev0 0x802bf658. Empties a vector of 24-byte records at +80,
// erasing from the front. The record layout (held object, then float and int
// fields) is read from the copy loop; F and P are partial views whose user
// assignment reproduces the loop size.
struct Obj;
struct ObjVt { Ptr32<void> s0[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Held {
 Ptr32<Obj> value;
 ~Held() { if (value) value->vt->release(value); }
 Held &operator=(const Held &o) { if (o.value) o.value->vt->retain(o.value); if (value) value->vt->release(value); value = o.value; return *this; }
 void clear(Ptr32<Obj> p) { if (value) value->vt->release(value); value = p; }
};
struct F { float v; F &operator=(const F &o) { v = o.v; return *this; } }; struct P { F x, y; }; struct Entry { Held h; P a; int c; P d; };
inline Ptr32<Entry> copy(Ptr32<const Entry> first, Ptr32<const Entry> last, Ptr32<Entry> result) { for (int n = last - first; n > 0; --n) { *result = *first; ++first; ++result; } return result; }
struct Vec {
 Ptr32<Entry> start; Ptr32<Entry> finish;
 Ptr32<Entry> begin() { return start; }
 Ptr32<Entry> end() { return finish; }
 Ptr32<Entry> erase(Ptr32<Entry> pos)
 {
  if (pos + 1 != finish) copy(pos + 1, finish, pos);
  --finish;
  finish->~Entry();
  return pos;
 }
};
struct S { char pad[80]; Vec v; };
extern "C" void d25l_entry_list_clear_802bf658(Ptr32<S> self)
{
 Ptr32<Entry> it = self->v.begin();
 while (it != self->v.end()) {
  it->h.clear(0);
  it = self->v.erase(it);
 }
}


