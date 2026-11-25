// Destructor of the object pool manager: shut down every pool, drop the sixty-
// four global type references from the registry, clear the singleton, then
// destroy the members in reverse order. GWMP8P rev0 0x8017bf40.
#pragma interface
extern "C" {
int w3d_auto_80170b10();
int w3d_auto_8017f524();
int w3d_auto_80174520();
int w3d_auto_8018774c();
int w3d_pset_pool_size();
int w3d_auto_8018a7e4();
int w3d_null_pool_size();
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_handle_storage_release(void *);
void w3d_actor_node_destroy(void *, int);
void w3d_actor_member_delete_backend(void *);
}
struct Str { char *p; ~Str() { w3d_string_base_finish(this); w3d_string_release(this); } };
struct Pair { Str s; int v; };
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
struct Ref { Iface *p; ~Ref() { if (p) p->release(); } void set(Iface *q) { if (p) p->release(); p = q; } };
struct Vec { int *start; int *f; int *e; int x; ~Vec() { if (start) w3d_handle_storage_release(start); } };
struct Item : Iface { char u[16]; int key; };
struct Reg : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void drop(int); };
struct RegRef { Reg *p; ~RegRef() { if (p) p->release(); } };
extern Ref lbl_80456f14[];
extern int lbl_804ab5fc;
struct Tag { char u[8]; ~Tag() { w3d_actor_node_destroy(this, 0); } };
struct Base : Iface { Tag tag; char pad[12]; virtual ~Base(); };
inline Base::~Base() {}
struct D30jPoolManager : Base {
  Ref pool[1920];
  Pair names[256];
  int pad2;
  Vec a, b, c;
  char gap[8];
  RegRef reg_;
  Ref extra;
  Str s0, s1;
  virtual ~D30jPoolManager();
  void operator delete(void *p) { w3d_actor_member_delete_backend(p); }
};
extern "C" int d29j_shut_down_pools_8017c26c(D30jPoolManager *);
D30jPoolManager::~D30jPoolManager() {
  w3d_auto_80170b10();
  w3d_auto_8017f524();
  w3d_auto_80174520();
  w3d_auto_8018774c();
  w3d_pset_pool_size();
  w3d_auto_8018a7e4();
  w3d_null_pool_size();
  d29j_shut_down_pools_8017c26c(this);
  for (unsigned int i = 0; i <= 63; i++) {
    reg_.p->drop(((Item *)lbl_80456f14[i].p)->key);
    lbl_80456f14[i].set(0);
  }
  lbl_804ab5fc = 0;
}
