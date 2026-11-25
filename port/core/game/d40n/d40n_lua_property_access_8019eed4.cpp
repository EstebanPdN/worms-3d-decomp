#include "w3d_ptr.h"
#line 1 "d40n_lua_property_access_8019eed4.cpp"
// GWMP8P rev0 0x8019eed4. Lua metamethod for object properties, shared by
// index and newindex: resolves the name on the object's class, handles
// Add/Set/Remove/Insert/Get prefixes with closures, and reads or writes the
// property by its kind through real pointers to member functions or a text
// stream. Names inferred. The first two strings are extern views because the
// unit's pool would otherwise start 4 bytes past an 8-byte boundary.
struct lua_State { char p0[88]; Ptr32<struct LG> g; };
extern "C" {
int lua_isstring(Ptr32<lua_State>, int);
Ptr32<void> lua_touserdata(Ptr32<lua_State>, int);
Ptr32<const char> luaL_checklstring(Ptr32<lua_State>, int, Ptr32<unsigned int>);
void lua_pushcclosure(Ptr32<lua_State>, Ptr32<int (Ptr32<lua_State>)>, int);
int lua_type(Ptr32<lua_State>, int);
int lua_toboolean(Ptr32<lua_State>, int);
int lua_isuserdata(Ptr32<lua_State>, int);
int lua_getmetatable(Ptr32<lua_State>, int);
int lua_equal(Ptr32<lua_State>, int, int);
void lua_settop(Ptr32<lua_State>, int);
void lua_pushvalue(Ptr32<lua_State>, int);
int lua_isnumber(Ptr32<lua_State>, int);
float lua_tonumber(Ptr32<lua_State>, int);
void lua_pushboolean(Ptr32<lua_State>, int);
void lua_pushnumber(Ptr32<lua_State>, float);
void lua_pushstring(Ptr32<lua_State>, Ptr32<const char>);
void lua_concat(Ptr32<lua_State>, int);
int lua_error(Ptr32<lua_State>);
int strncmp(Ptr32<const char>, Ptr32<const char>, unsigned int);
int w3d_format_into_80347a10(Ptr32<char>, Ptr32<const char>, ...);
int w3d_format_into_80351df8(Ptr32<char>, Ptr32<const char>, ...);
int w3d_auto_801fffc8(int);
int w3d_s21_kind_is_t_801fff60(int);
int fn_8019e7e8(Ptr32<lua_State>);
int fn_8019ed40(Ptr32<lua_State>);
int fn_8019e8d0(Ptr32<lua_State>);
int fn_8019e848(Ptr32<lua_State>);
int fn_8019ee18(Ptr32<lua_State>);
}
extern "C" Ptr32<void> w3d_string_default(Ptr32<void>);
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
struct Text {
  Ptr32<char> p;
  Text() {}
  Text(const Text &);
  ~Text() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" void w3d_tagged_construct_8020d318(Ptr32<void>, Ptr32<Text>);
extern "C" void w3d_dtor_node_8020d36c(Ptr32<void>, int);
extern "C" unsigned short w3d_registry_retain_8020d2b8(Ptr32<void>);
struct Reader;
struct ReaderTable { Ptr32<void> s0[3]; Ptr32<void (Ptr32<Reader>)> retain; Ptr32<void (Ptr32<Reader>)> release; };
struct Reader {
  Ptr32<ReaderTable> vt;
  unsigned words[6];
  Reader(Text &t) { w3d_tagged_construct_8020d318(this, &t); }
  ~Reader() { w3d_dtor_node_8020d36c(this, 2); }
};
struct Descriptor {
  Ptr32<Reader> p;
  unsigned char flag:1; unsigned char kind:7;
  unsigned char tag;
  unsigned short :11; unsigned short format:5;
  Descriptor(const Descriptor &);
  Descriptor(Reader &r, unsigned char t) {
    p = &r; if (p) p->vt->retain(p);
    kind = 10; flag = 0; tag = t; format = 6;
    w3d_registry_retain_8020d2b8(&r);
  }
  Descriptor(Reader &r) {
    p = &r; if (p) p->vt->retain(p);
    kind = 10; flag = 0; tag = 0; format = 6;
    w3d_registry_retain_8020d2b8(&r);
  }
  ~Descriptor() { if (p) p->vt->release(p); }
};
struct Stream {
  Reader reader;
  Descriptor desc;
  Stream(Text &t) : reader(t), desc(reader) {}
  Stream(Text &t, unsigned char g) : reader(t), desc(reader, g) {}
};
struct Obj;
typedef w3d::Pmf<Obj, void()> Fn;
struct Obj { void w3d_r_a0() __asm__(W3D_SYM("_ZN3Obj2a0Ev")); void w3d_r_a1() __asm__(W3D_SYM("_ZN3Obj2a1Ev")); void w3d_r_a2() __asm__(W3D_SYM("_ZN3Obj2a2Ev")); Ptr32<struct Cls> w3d_r_cls() __asm__(W3D_SYM("_ZN3Obj3clsEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<struct Cls> cls() { return ((Ptr32<struct Cls> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
struct Cls;
extern "C" Ptr32<struct Prop> w3d_d29e_find_by_name_801e9e84(Ptr32<Cls>, Ptr32<const char>);
struct Info { char p0[6]; char w3d_kind; unsigned char flags; int kind; };
struct PropBase { Ptr32<Info> info; };
struct PropMid : PropBase {
  void w3d_r_a0() __asm__(W3D_SYM("_ZN7PropMid2a0Ev")); void w3d_r_a1() __asm__(W3D_SYM("_ZN7PropMid2a1Ev")); void w3d_r_a2() __asm__(W3D_SYM("_ZN7PropMid2a2Ev"));
  void w3d_r_get(Ptr32<Descriptor>, Ptr32<Obj>) __asm__(W3D_SYM("_ZN7PropMid3getEP10DescriptorP3Obj"));
  void w3d_r_a4() __asm__(W3D_SYM("_ZN7PropMid2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN7PropMid2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN7PropMid2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN7PropMid2a7Ev"));
  void w3d_r_set(Ptr32<const char>, Ptr32<Obj>) __asm__(W3D_SYM("_ZN7PropMid3setEPKcP3Obj"));
 __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropMid, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropMid, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropMid, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void get(Ptr32<Descriptor> w3d_a0, Ptr32<Obj> w3d_a1) { ((void (*)(w3d_u32, Ptr32<Descriptor>, Ptr32<Obj>))w3d::vfn(this->w3d_vptr_PropMid, 5))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropMid, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropMid, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropMid, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropMid, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void set(Ptr32<const char> w3d_a0, Ptr32<Obj> w3d_a1) { ((void (*)(w3d_u32, Ptr32<const char>, Ptr32<Obj>))w3d::vfn(this->w3d_vptr_PropMid, 10))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_PropMid __attribute__((aligned(__alignof__(PropBase)))); };
union Getter { Fn f; w3d::Pmf<Obj, int()> i; w3d::Pmf<Obj, unsigned int()> u; w3d::Pmf<Obj, unsigned short()> us; w3d::Pmf<Obj, short()> s; w3d::Pmf<Obj, unsigned char()> uc; w3d::Pmf<Obj, signed char()> sc; w3d::Pmf<Obj, float()> fl; w3d::Pmf<Obj, Ptr32<Ptr32<const char>>()> str; w3d::Pmf<Obj, Ptr32<void>()> ptr; };
union Setter { Fn f; w3d::Pmf<Obj, void(Ptr32<Obj>)> o; };
struct Prop : PropMid { int p8 __attribute__((aligned(__alignof__(PropMid)))); Getter getter; Setter setter; };
struct Sink { void w3d_r_a0() __asm__(W3D_SYM("_ZN4Sink2a0Ev")); void w3d_r_a1() __asm__(W3D_SYM("_ZN4Sink2a1Ev")); void w3d_r_a2() __asm__(W3D_SYM("_ZN4Sink2a2Ev")); void w3d_r_a3() __asm__(W3D_SYM("_ZN4Sink2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN4Sink2a4Ev")); void w3d_r_push(Ptr32<void>) __asm__(W3D_SYM("_ZN4Sink4pushEPv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void push(Ptr32<void> w3d_a0) { ((void (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Sink, 7))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Sink; };
struct LG { char p0[36]; Ptr32<Sink> sink; };
extern "C" int fn_8019e96c(Ptr32<lua_State>, Ptr32<Obj>, Ptr32<Prop>);
extern Ptr32<Prop> lbl_804ab728;
inline void push_field2(Ptr32<lua_State> L, Ptr32<Prop> p, Ptr32<Obj> obj, unsigned char g) {
  Text text;
  Ptr32<Text> pt = &text;
  w3d_string_default(pt);
  Stream st(*pt, g);
  Ptr32<Descriptor> pd = &st.desc;
  p->get(pd, obj);
  lua_pushstring(L, pt->p);
}
inline void push_field(Ptr32<lua_State> L, Ptr32<Prop> p, Ptr32<Obj> obj) {
  Text text;
  Ptr32<Text> pt = &text;
  w3d_string_default(pt);
  Stream st(*pt);
  Ptr32<Descriptor> pd = &st.desc;
  p->get(pd, obj);
  lua_pushstring(L, pt->p);
}
extern const char str_append_803a999c[], str_set_803a99a4[];
extern "C" int w3d_d40n_lua_property_access_8019eed4(Ptr32<lua_State> L, Ptr32<const char> err, int setting) {
  char buf[256];
  buf[0] = 0;
  Ptr32<const char> name;
  if (!lua_isstring(L, 2)) goto fail;
  {
    Ptr32<Obj> obj = *(Ptr32<Ptr32<Obj>>)lua_touserdata(L, 1);
    name = luaL_checklstring(L, 2, 0);
    Ptr32<Cls> c = obj->cls();
    Ptr32<Prop> p = w3d_d29e_find_by_name_801e9e84(c, name);
    if (!p && !setting) {
      {
        Ptr32<int (Ptr32<lua_State>)> fn = 0;
        int skip = 0;
        if (strncmp(name, str_append_803a999c, 6) == 0) { fn = fn_8019e7e8; skip = 6; }
        else if (strncmp(name, str_set_803a99a4, 3) == 0) { fn = fn_8019ed40; skip = 3; }
        else if (strncmp(name, "Remove", 5) == 0) { fn = fn_8019e8d0; skip = 6; }
        else if (strncmp(name, "Insert", 5) == 0) { fn = fn_8019e848; skip = 6; }
        else if (strncmp(name, "Get", 3) == 0) { fn = fn_8019ee18; skip = 3; }
        if (fn) {
          p = w3d_d29e_find_by_name_801e9e84(c, name + skip);
          if (!p) goto unknown;
          if (p->info->flags & 1) {
            lbl_804ab728 = p;
            lua_pushcclosure(L, fn, 1);
            return 1;
          }
        }
      }
    }
    if (!p) goto unknown;
    if (setting) {
      char tmp[64];
      Ptr32<const char> value = 0;
      tmp[0] = 0;
      Ptr32<Obj> ref = 0;
      Ptr32<char> t = tmp;
      if (lua_type(L, 3) == 1) {
        value = lua_toboolean(L, 3) ? w3d::R("true") : w3d::R("false");
      } else if (lua_isuserdata(L, 3)) {
        t = (Ptr32<char>)lua_touserdata(L, 3);
        lua_getmetatable(L, 3);
        lua_getmetatable(L, 1);
        if (lua_equal(L, -2, -1)) ref = *(Ptr32<Ptr32<Obj>>)t;
        lua_settop(L, -3);
      } else if (lua_type(L, 3) == 5) {
        Ptr32<Info> info = p->info;
        if (info->flags & 1) {
          lua_pushvalue(L, 3);
          fn_8019e96c(L, obj, p);
          lua_settop(L, -2);
          return 0;
        }
      } else if (lua_isnumber(L, 3)) {
        w3d_format_into_80347a10(t, "%f", lua_tonumber(L, 3));
        value = t;
      } else {
        value = luaL_checklstring(L, 3, 0);
      }
      if (p->info->flags & 1) goto fail;
      if (w3d_auto_801fffc8(p->info->kind) == 24) {
        (p->setter.o)(obj, ref);
      } else {
        p->set(value, obj);
      }
      return 0;
    }
    if (p->info->flags & 1) goto fail;
    int t = w3d_s21_kind_is_t_801fff60(p->info->kind);
    if (t) {
      switch (w3d_auto_801fffc8(p->info->kind)) {
      case 1:
        lua_pushboolean(L, (p->getter.i)(obj));
        break;
      case 8: case 14:
        lua_pushnumber(L, (float)(p->getter.u)(obj));
        break;
      case 7: case 13:
        lua_pushnumber(L, (float)(p->getter.i)(obj));
        break;
      case 6:
        lua_pushnumber(L, (float)(p->getter.us)(obj));
        break;
      case 5:
        lua_pushnumber(L, (float)(p->getter.s)(obj));
        break;
      case 4:
        lua_pushnumber(L, (float)(p->getter.uc)(obj));
        break;
      case 3:
        lua_pushnumber(L, (float)(p->getter.sc)(obj));
        break;
      case 11:
        lua_pushnumber(L, (p->getter.fl)(obj));
        break;
      case 15:
        lua_pushstring(L, *(p->getter.str)(obj));
        break;
      case 24: {
        Ptr32<Sink> s = L->g->sink;
        s->push((p->getter.ptr)(obj));
        break;
      }
      default:
        push_field(L, p, obj);
        break;
      }
    } else {
      push_field2(L, p, obj, t);
    }
    return 1;
  }
  unknown:
  w3d_format_into_80351df8(buf, "Unknown field: %s", w3d::VA(name));
  err = buf;
  fail:
  lua_settop(L, 2);
  lua_pushstring(L, err);
  lua_concat(L, 2);
  lua_error(L);
  return 0;
}


