// Attach a binding to its host and create the two Lua metatable pairs: index and
// newindex closures for the getter and setter tables, plus the global
// XomCreateInstance closure. GWMP8P rev0 0x8019fa44.
struct lua_State;
typedef int (*lua_CFunction)(lua_State *);
extern "C" {
int lua_gettop(lua_State *);
void lua_settop(lua_State *, int);
void lua_pushvalue(lua_State *, int);
void lua_pushstring(lua_State *, const char *);
void lua_pushcclosure(lua_State *, lua_CFunction, int);
void lua_settable(lua_State *, int);
int luaL_ref(lua_State *, int);
int w3d_auto_801a0304(lua_State *);
void w3d_auto_801a03f0(lua_State *, void *, int);
void w3d_auto_801a0448(lua_State *, const char *, int, int);
int fn_8019f838(lua_State *);
int fn_8019f8f0(lua_State *);
int fn_8019f8a0(lua_State *);
int fn_8019e710(lua_State *);
}
extern int lbl_804b1950;
extern const char lbl_803a9a94[];
extern const char lbl_803a9a5c[];
extern const char lbl_803a9a64[];
extern const char lbl_803a9a70[];
struct Ref { virtual void a0(); virtual void add(); virtual void release(); };
struct Host : Ref { char p[32]; Ref *binding; virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual lua_State *state(); };
struct Bind : Ref { char p0[16]; Host *host; int get; int set; };
extern "C" int d30j_bind_lua_tables_8019fa44(Bind *self, Host *host) {
  self->host = host;
  if (self) self->add();
  if (host->binding) host->binding->release();
  host->binding = self;
  lua_State *L = host->state();
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
