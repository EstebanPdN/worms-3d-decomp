// Adds or updates a named member of a property table: an existing entry of kind 5 is checked against the
// requested key and flags and its target replaced or cleared; otherwise a new member is created and bound.
// Field and method names are inferred from the callees.
struct Type;
extern "C" Type *w3d_auto_801fff3c(int);
struct IVal {
  virtual void a0(); virtual void add(); virtual void release(); virtual int id();
};
struct Val : IVal { unsigned short used; };
struct Desc {
  int a; int b;
  Desc(int x) { a = x; b = 58280; }
  ~Desc();
};
extern "C" void w3d_s20_destroy_owned_80178474(Desc *, int);
inline Desc::~Desc() { w3d_s20_destroy_owned_80178474(this, 2); }
struct Prop;
struct Member : Val {
  virtual int kind(); virtual void a5(); virtual void a6(); virtual int key();
  virtual void a8(); virtual void setA(int); virtual void setB(int); virtual void setC(int);
};
extern "C" {
Member *w3d_empty_80341584(Member *);
void w3d_s20_clear_target_80179770(Member *);
Val *w3d_auto_801797b4(Member *);
void w3d_s20_replace_target_801795d4(Member *, Val *);
int cc42a_bind_typed_8017963c(Member *, Type *);
Prop *w3d_auto_80179598(Member *, Desc *);
void f3c_propagate_tag_801ea4c8(Prop *, Val *);
void *w3d_heap_allocate_entry_a(unsigned int);
Member *s9_beam_80179428(void *);
}
struct MRef { Member *p; Member *operator->() { return p; } void set(Member *q) { if (q) q->add(); if (p) p->release(); p = q; } };
struct Loc { unsigned short idx; Loc() {} Loc(const Loc &); };
struct Self { char p0[24]; MRef *table; char p1c[2064]; int freeSlots; };
extern "C" int d24j_find_table_slot_80177eb0(Self *, int, Loc *);
extern int lbl_804ab5b0;
extern "C" int property_table_set_80175c20(Self *self, int key, Val *val, int b, int flags) {
  Loc loc;
  if (d24j_find_table_slot_80177eb0(self, key, &loc) >= 0) {
    if (self->table[loc.idx]->kind() != 5) goto bad;
    {
      Member *m;
      if (flags & 4) b = self->table[loc.idx]->key();
      if (self->table[loc.idx]->key() != b) goto bad;
      if (flags & 1) {
        m = w3d_empty_80341584(self->table[loc.idx].p);
        if (val == 0) { w3d_s20_clear_target_80179770(m); return 0; }
        if (flags) {
          if (w3d_auto_801797b4(m) && w3d_auto_801797b4(m)->id() != val->id()) return 0x80004005;
          w3d_s20_replace_target_801795d4(m, val);
          return 0;
        }
        if (w3d_auto_801797b4(m) == 0) cc42a_bind_typed_8017963c(m, w3d_auto_801fff3c(val->id()));
        if (w3d_auto_801797b4(m)->id() != val->id()) {
        bad:
          return 0x80004005;
        }
        Desc d(flags);
        f3c_propagate_tag_801ea4c8(w3d_auto_80179598(m, &d), val);
        return 0;
      }
    }
    goto bad;
  }
  Member *m = s9_beam_80179428(w3d_heap_allocate_entry_a(20));
  self->table[loc.idx].set(m);
  m->setA(key);
  m->setB(b);
  m->setC(flags);
  self->freeSlots--;
  lbl_804ab5b0++;
  if (val) {
    cc42a_bind_typed_8017963c(m, w3d_auto_801fff3c(val->id()));
    Desc d(0);
    f3c_propagate_tag_801ea4c8(w3d_auto_80179598(m, &d), val);
    if (val->used == 0) { val->add(); val->release(); }
  }
  return 0;
}
