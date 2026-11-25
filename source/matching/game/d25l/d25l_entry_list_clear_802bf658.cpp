// GWMP8P rev0 0x802bf658. Empties a vector of 24-byte records at +80,
// erasing from the front. The record layout (held object, then float and int
// fields) is read from the copy loop; F and P are partial views whose user
// assignment reproduces the loop size.
struct Obj;
struct ObjVt { void *s0[3]; void (*retain)(Obj *); void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Held {
 Obj *value;
 ~Held() { if (value) value->vt->release(value); }
 Held &operator=(const Held &o) { if (o.value) o.value->vt->retain(o.value); if (value) value->vt->release(value); value = o.value; return *this; }
 void clear(Obj *p) { if (value) value->vt->release(value); value = p; }
};
struct F { float v; F &operator=(const F &o) { v = o.v; return *this; } }; struct P { F x, y; }; struct Entry { Held h; P a; int c; P d; };
inline Entry *copy(const Entry *first, const Entry *last, Entry *result) { for (int n = last - first; n > 0; --n) { *result = *first; ++first; ++result; } return result; }
struct Vec {
 Entry *start, *finish;
 Entry *begin() { return start; }
 Entry *end() { return finish; }
 Entry *erase(Entry *pos)
 {
  if (pos + 1 != finish) copy(pos + 1, finish, pos);
  --finish;
  finish->~Entry();
  return pos;
 }
};
struct S { char pad[80]; Vec v; };
extern "C" void d25l_entry_list_clear_802bf658(S *self)
{
 Entry *it = self->v.begin();
 while (it != self->v.end()) {
  it->h.clear(0);
  it = self->v.erase(it);
 }
}
