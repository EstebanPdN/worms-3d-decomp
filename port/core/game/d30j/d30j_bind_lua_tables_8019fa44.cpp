#include "w3d_ptr.h"
#line 1 "d30j_bind_lua_tables_8019fa44.cpp"
// Attach a binding to its host and create the two Lua metatable pairs: index and
// newindex closures for the getter and setter tables, plus the global
// XomCreateInstance closure. GWMP8P rev0 0x8019fa44.
struct lua_State;
typedef Ptr32<int (Ptr32<lua_State>)> lua_CFunction;
extern "C" {
int lua_gettop(Ptr32<lua_State>);
void lua_settop(Ptr32<lua_State>, int);
void lua_pushvalue(Ptr32<lua_State>, int);
void lua_pushstring(Ptr32<lua_State>, Ptr32<const char>);
void lua_pushcclosure(Ptr32<lua_State>, lua_CFunction, int);
void lua_settable(Ptr32<lua_State>, int);
int luaL_ref(Ptr32<lua_State>, int);
int w3d_auto_801a0304(Ptr32<lua_State>);
void w3d_auto_801a03f0(Ptr32<lua_State>, Ptr32<void>, int);
void w3d_auto_801a0448(Ptr32<lua_State>, Ptr32<const char>, int, int);
int fn_8019f838(Ptr32<lua_State>);
int fn_8019f8f0(Ptr32<lua_State>);
int fn_8019f8a0(Ptr32<lua_State>);
int fn_8019e710(Ptr32<lua_State>);
}
extern int lbl_804b1950;
extern const char lbl_803a9a94[];
extern const char lbl_803a9a5c[];
extern const char lbl_803a9a64[];
extern const char lbl_803a9a70[];
struct Ref { void w3d_r_a0() __asm__(W3D_SYM("_ZN3Ref2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN3Ref3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN3Ref7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ref, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ref, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ref, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Ref; };
struct Host : Ref { char p[32] __attribute__((aligned(__alignof__(Ref)))); Ptr32<Ref> binding; void w3d_r_a3() __asm__(W3D_SYM("_ZN4Host2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN4Host2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN4Host2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN4Host2a6Ev")); Ptr32<lua_State> w3d_r_state() __asm__(W3D_SYM("_ZN4Host5stateEv"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ref, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ref, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ref, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ref, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<lua_State> state() { return ((Ptr32<lua_State> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ref, 9))(w3d::h2g(this)); } };
struct Bind : Ref { char p0[16] __attribute__((aligned(__alignof__(Ref)))); Ptr32<Host> host; int get; int set; };
extern "C" int d30j_bind_lua_tables_8019fa44(Ptr32<Bind> self, Ptr32<Host> host) {
  self->host = host;
  if (self) self->add();
  if (host->binding) host->binding->release();
  host->binding = self;
  Ptr32<lua_State> L = host->state();
  lua_gettop(L);
  {
    int t = w3d_auto_801a0304(L);
    w3d_auto_801a03f0(L, &lbl_804b1950, 1);
    lua_pushvalue(L, t);
    self->set = luaL_ref(L, -10000);
    int a = w3d_auto_801a0304(L);
    w3d_auto_801a0448(L, lbl_803a9a94, 2, t);
    int b = w3d_auto_801a0304(L);
    lua_pushstring(L, lbl_803a9a5c);
    lua_pushvalue(L, a);
    lua_pushcclosure(L, fn_8019f838, 1);
    lua_settable(L, t);
    lua_pushstring(L, lbl_803a9a64);
    lua_pushvalue(L, b);
    lua_pushcclosure(L, fn_8019f8f0, 1);
    lua_settable(L, t);
    lua_settop(L, -4);
  }
  {
    int t = w3d_auto_801a0304(L);
    w3d_auto_801a03f0(L, &lbl_804b1950, 1);
    lua_pushvalue(L, t);
    self->get = luaL_ref(L, -10000);
    int a = w3d_auto_801a0304(L);
    w3d_auto_801a0448(L, lbl_803a9a94, 2, t);
    int b = w3d_auto_801a0304(L);
    lua_pushstring(L, lbl_803a9a5c);
    lua_pushvalue(L, a);
    lua_pushcclosure(L, fn_8019f838, 1);
    lua_settable(L, t);
    lua_pushstring(L, lbl_803a9a64);
    lua_pushvalue(L, b);
    lua_pushcclosure(L, fn_8019f8a0, 1);
    lua_settable(L, t);
    lua_pushstring(L, lbl_803a9a70);
    lua_pushvalue(L, t);
    lua_pushcclosure(L, fn_8019e710, 1);
    lua_settable(L, -10001);
    lua_settop(L, -4);
  }
  lua_gettop(L);
  return 0;
}


