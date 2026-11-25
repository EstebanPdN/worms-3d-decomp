#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "d30j_destroy_pool_manager_8017bf40.cpp"
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
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_handle_storage_release(Ptr32<void>);
void w3d_actor_node_destroy(Ptr32<void>, int);
void w3d_actor_member_delete_backend(Ptr32<void>);
}
struct Str { Ptr32<char> p; ~Str() { w3d_string_base_finish(this); w3d_string_release(this); } };
struct Pair { Str s; int v; };
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
struct Ref { Ptr32<Iface> p; ~Ref() { if (p) p->release(); } void set(Ptr32<Iface> q) { if (p) p->release(); p = q; } };
struct Vec { Ptr32<int> start; Ptr32<int> f; Ptr32<int> e; int x; ~Vec() { if (start) w3d_handle_storage_release(start); } };
struct Item : Iface { char u[16] __attribute__((aligned(__alignof__(Iface)))); int key; };
struct Reg : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN3Reg2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN3Reg2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN3Reg2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN3Reg2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN3Reg2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN3Reg2a8Ev")); void w3d_r_drop(int) __asm__(W3D_SYM("_ZN3Reg4dropEi"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void drop(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this), w3d_a0); } };
struct RegRef { Ptr32<Reg> p; ~RegRef() { if (p) p->release(); } };
extern Ref lbl_80456f14[];
extern int lbl_804ab5fc;
struct Tag { char u[8]; ~Tag() { w3d_actor_node_destroy(this, 0); } };
struct Base : Iface { Tag tag __attribute__((aligned(__alignof__(Iface)))); char pad[12]; ~Base();  __attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this), w3d_in); } };
inline Base::~Base() { W3D_SET_VPTR(this->Iface::w3d_vptr_Iface, w3d_vt___vt_4Base, "__vt_4Base"); }
struct D30jPoolManager : Base {
  Ref pool[1920] __attribute__((aligned(__alignof__(Base))));
  Pair names[256];
  int pad2;
  Vec a, b, c;
  char gap[8];
  RegRef reg_;
  Ref extra;
  Str s0, s1;
  ~D30jPoolManager();
  void operator delete(void *p) { w3d_actor_member_delete_backend(p); }
 void w3d_dt_ic(int w3d_in) __asm__(W3D_SYM("_._15D30jPoolManager")); };
extern "C" int d29j_shut_down_pools_8017c26c(Ptr32<D30jPoolManager>);
D30jPoolManager::~D30jPoolManager() { W3D_SET_VPTR(this->Base::w3d_vptr_Iface, w3d_vt___vt_15D30jPoolManager, "__vt_15D30jPoolManager"); 
  w3d_auto_80170b10();
  w3d_auto_8017f524();
  w3d_auto_80174520();
  w3d_auto_8018774c();
  w3d_pset_pool_size();
  w3d_auto_8018a7e4();
  w3d_null_pool_size();
  d29j_shut_down_pools_8017c26c(this);
  for (unsigned int i = 0; i <= 63; i++) {
    reg_.p->drop(((Ptr32<Item>)lbl_80456f14[i].p)->key);
    lbl_80456f14[i].set(0);
  }
  lbl_804ab5fc = 0;
  // Port (v29): los huecos están en la tabla nativa; el original los soltaba al destruir el miembro pool[1920].
  { Ref *slots = (Ref *)w3d_restab_slots(); for (unsigned i = 0; i < w3d_restab_cap(); i++) slots[i].set(0); }
}

void D30jPoolManager::w3d_dt_ic(int w3d_in) { this->~D30jPoolManager(); if (w3d_in & 1) operator delete(this); }
