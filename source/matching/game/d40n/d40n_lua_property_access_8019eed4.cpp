// GWMP8P rev0 0x8019eed4. Lua metamethod for object properties, shared by
// index and newindex: resolves the name on the object's class, handles
// Add/Set/Remove/Insert/Get prefixes with closures, and reads or writes the
// property by its kind through real pointers to member functions or a text
// stream. Names inferred. The first two strings are extern views because the
// unit's pool would otherwise start 4 bytes past an 8-byte boundary.
struct lua_State { char p0[88]; struct LG *g; };
extern "C" {
int lua_isstring(lua_State *, int);
void *lua_touserdata(lua_State *, int);
const char *luaL_checklstring(lua_State *, int, unsigned int *);
void lua_pushcclosure(lua_State *, int (*)(lua_State *), int);
int lua_type(lua_State *, int);
int lua_toboolean(lua_State *, int);
int lua_isuserdata(lua_State *, int);
int lua_getmetatable(lua_State *, int);
int lua_equal(lua_State *, int, int);
void lua_settop(lua_State *, int);
void lua_pushvalue(lua_State *, int);
int lua_isnumber(lua_State *, int);
float lua_tonumber(lua_State *, int);
void lua_pushboolean(lua_State *, int);
void lua_pushnumber(lua_State *, float);
void lua_pushstring(lua_State *, const char *);
void lua_concat(lua_State *, int);
int lua_error(lua_State *);
int strncmp(const char *, const char *, unsigned int);
int w3d_format_into_80347a10(char *, const char *, ...);
int w3d_format_into_80351df8(char *, const char *, ...);
int w3d_auto_801fffc8(int);
int w3d_s21_kind_is_t_801fff60(int);
int fn_8019e7e8(lua_State *);
int fn_8019ed40(lua_State *);
int fn_8019e8d0(lua_State *);
int fn_8019e848(lua_State *);
int fn_8019ee18(lua_State *);
}
extern "C" void * w3d_string_default(void *);
extern "C" void w3d_string_base_finish(void *);
extern "C" void w3d_string_release(void *);
struct Text {
  char *p;
  Text() {}
  Text(const Text &);
  ~Text() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" void w3d_tagged_construct_8020d318(void *, Text *);
extern "C" void w3d_dtor_node_8020d36c(void *, int);
extern "C" unsigned short w3d_registry_retain_8020d2b8(void *);
struct Reader;
struct ReaderTable { void *s0[3]; void (*retain)(Reader *); void (*release)(Reader *); };
struct Reader {
  ReaderTable *vt;
  unsigned words[6];
  Reader(Text &t) { w3d_tagged_construct_8020d318(this, &t); }
  ~Reader() { w3d_dtor_node_8020d36c(this, 2); }
};
struct Descriptor {
  Reader *p;
  unsigned kind : 7;
  unsigned flag : 1;
  unsigned char tag;
  unsigned format : 5;
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
typedef void (Obj::*Fn)();
struct Obj { virtual void a0(); virtual void a1(); virtual void a2(); virtual struct Cls *cls(); };
struct Cls;
extern "C" struct Prop *w3d_d29e_find_by_name_801e9e84(Cls *, const char *);
struct Info { char p0[7]; unsigned char flags; int kind; };
struct PropBase { Info *info; };
struct PropMid : PropBase {
  virtual void a0(); virtual void a1(); virtual void a2();
  virtual void get(Descriptor *, Obj *);
  virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual void set(const char *, Obj *);
};
union Getter { Fn f; int (Obj::*i)(void); unsigned int (Obj::*u)(void); unsigned short (Obj::*us)(void); short (Obj::*s)(void); unsigned char (Obj::*uc)(void); signed char (Obj::*sc)(void); float (Obj::*fl)(void); const char **(Obj::*str)(void); void *(Obj::*ptr)(void); };
union Setter { Fn f; void (Obj::*o)(Obj *); };
struct Prop : PropMid { int p8; Getter getter; Setter setter; };
struct Sink { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void push(void *); };
struct LG { char p0[36]; Sink *sink; };
extern "C" int fn_8019e96c(lua_State *, Obj *, Prop *);
extern Prop *lbl_804ab728;
inline void push_field2(lua_State *L, Prop *p, Obj *obj, unsigned char g) {
  Text text;
  Text *pt = &text;
  w3d_string_default(pt);
  Stream st(*pt, g);
  Descriptor *pd = &st.desc;
  p->get(pd, obj);
  lua_pushstring(L, pt->p);
}
inline void push_field(lua_State *L, Prop *p, Obj *obj) {
  Text text;
  Text *pt = &text;
  w3d_string_default(pt);
  Stream st(*pt);
  Descriptor *pd = &st.desc;
  p->get(pd, obj);
  lua_pushstring(L, pt->p);
}
extern const char str_append_803a999c[], str_set_803a99a4[];
extern "C" int w3d_d40n_lua_property_access_8019eed4(lua_State *L, const char *err, int setting) {
  char buf[256];
  buf[0] = 0;
  const char *name;
  if (!lua_isstring(L, 2)) goto fail;
  {
    Obj *obj = *(Obj **)lua_touserdata(L, 1);
    name = luaL_checklstring(L, 2, 0);
    Cls *c = obj->cls();
    Prop *p = w3d_d29e_find_by_name_801e9e84(c, name);
    if (!p && !setting) {
      {
        int (*fn)(lua_State *) = 0;
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
      const char *value = 0;
      tmp[0] = 0;
      Obj *ref = 0;
      char *t = tmp;
      if (lua_type(L, 3) == 1) {
        value = lua_toboolean(L, 3) ? "true" : "false";
      } else if (lua_isuserdata(L, 3)) {
        t = (char *)lua_touserdata(L, 3);
        lua_getmetatable(L, 3);
        lua_getmetatable(L, 1);
        if (lua_equal(L, -2, -1)) ref = *(Obj **)t;
        lua_settop(L, -3);
      } else if (lua_type(L, 3) == 5) {
        Info *info = p->info;
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
        (obj->*p->setter.o)(ref);
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
        lua_pushboolean(L, (obj->*p->getter.i)());
        break;
      case 8: case 14:
        lua_pushnumber(L, (float)(obj->*p->getter.u)());
        break;
      case 7: case 13:
        lua_pushnumber(L, (float)(obj->*p->getter.i)());
        break;
      case 6:
        lua_pushnumber(L, (float)(obj->*p->getter.us)());
        break;
      case 5:
        lua_pushnumber(L, (float)(obj->*p->getter.s)());
        break;
      case 4:
        lua_pushnumber(L, (float)(obj->*p->getter.uc)());
        break;
      case 3:
        lua_pushnumber(L, (float)(obj->*p->getter.sc)());
        break;
      case 11:
        lua_pushnumber(L, (obj->*p->getter.fl)());
        break;
      case 15:
        lua_pushstring(L, *(obj->*p->getter.str)());
        break;
      case 24: {
        Sink *s = L->g->sink;
        s->push((obj->*p->getter.ptr)());
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
  w3d_format_into_80351df8(buf, "Unknown field: %s", name);
  err = buf;
  fail:
  lua_settop(L, 2);
  lua_pushstring(L, err);
  lua_concat(L, 2);
  lua_error(L);
  return 0;
}
