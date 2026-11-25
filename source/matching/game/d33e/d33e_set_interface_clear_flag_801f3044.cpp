// (Worms 3D GameCube PAL, 0x801f3044).
//
// Stores a reference-counted interface pointer at +36, taking a reference on
// the new object and releasing the old one, clears the top flag bit of the
// word at +32 and returns 0.

struct Iface { virtual void v0(); virtual void add(); virtual void release(); };
struct Ref { Iface *p;
  Ref &operator=(Iface *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; } };
struct HolderB { char pad[32]; unsigned flag : 1; unsigned rest : 31; Ref object; };
extern "C" int w3d_d33e_set_interface_clear_flag_801f3044(HolderB *self, Iface *object) {
  self->object = object;
  do { self->flag = 0; return 0; } while (0);
}
