// d24i: 0x80103090 (416 bytes). Lua binding: expects one string argument naming
// a setting, looks up its value handle (0x800fc1b0), requires value kind 5
// (virtual +24), pops the argument and passes the resolved item (0x801797b4) to
// the object at +64 through its virtual +32. Every failure reports through
// 0x801022ec with its message, pops the argument and returns 0; success returns 1.
struct lua_State;
extern "C" int lua_gettop(lua_State *);
extern "C" int lua_isstring(lua_State *, int);
extern "C" const char *lua_tostring(lua_State *, int);
extern "C" void lua_settop(lua_State *, int);
struct d24i_String {
 d24i_String(const d24i_String &);
    char *text;
    d24i_String(const char *);
    ~d24i_String();
};
extern "C" void d24i_string_finish_8020c5c4(d24i_String *);
extern "C" void d24i_string_release_80341588(d24i_String *);
inline d24i_String::~d24i_String() {
    d24i_string_finish_8020c5c4(this);
    d24i_string_release_80341588(this);
}
struct d24i_Key { const char *name; };
struct d24i_Value;
struct d24i_ValueVtable {
    void *unknown00[4];
    void (*release)(d24i_Value *);       // +16
    void *unknown14;
    int (*kind)(d24i_Value *);           // +24
};
struct d24i_Value { d24i_ValueVtable *vtable; };
struct d24i_Handle {
 d24i_Handle(const d24i_Handle &);
    d24i_Value *value;
    // One word with a user copy constructor: the key follows this object 8 bytes
    // later on the stack in the original (0x80103090: handle +16, key +24), while keys alone are 4 apart.
    d24i_Handle() { value = 0; }
    ~d24i_Handle() { if (value) value->vtable->release(value); }
};
struct d24i_Item;
struct d24i_Target;
struct d24i_TargetVtable {
    void *unknown00[8];
    void (*set)(d24i_Target *, d24i_Item *);   // +32
};
struct d24i_Target { d24i_TargetVtable *vtable; };
struct d24i_Binding {
    unsigned char unknown00[64];
    d24i_Target *target;                 // +64
    lua_State *lua;                      // +68
};
extern "C" int d24i_setting_lookup_800fc1b0(d24i_Key *, d24i_Handle *);
extern "C" void d24i_script_error_801022ec(d24i_Binding *, const char *);
extern "C" void *d24i_as_item_80341584(d24i_Value *);
extern "C" d24i_Item *d24i_item_801797b4(void *);
static inline int d24i_find(const d24i_String &name, d24i_Handle &out) {
    d24i_Key key;
    key.name = name.text;
    return d24i_setting_lookup_800fc1b0(&key, &out);
}
extern const char d24i_error_count_8039911c[], d24i_error_type_80399158[], d24i_error_name_80399188[], d24i_error_kind_803991b8[];

extern "C" int d24i_lua_set_item_80103090(d24i_Binding *self) {
    if (lua_gettop(self->lua) != 1) {
        d24i_script_error_801022ec(self, d24i_error_count_8039911c);
        lua_settop(self->lua, -2);
        return 0;
    }
    if (!lua_isstring(self->lua, -1)) {
        d24i_script_error_801022ec(self, d24i_error_type_80399158);
        lua_settop(self->lua, -2);
        return 0;
    }
    d24i_String name(lua_tostring(self->lua, -1));
    d24i_Handle handle;
    if (d24i_find(name, handle) < 0) {
        d24i_script_error_801022ec(self, d24i_error_name_80399188);
        lua_settop(self->lua, -2);
        return 0;
    }
    if (handle.value->vtable->kind(handle.value) != 5) {
        d24i_script_error_801022ec(self, d24i_error_kind_803991b8);
        lua_settop(self->lua, -2);
        return 0;
    }
    d24i_Item *item = d24i_item_801797b4(d24i_as_item_80341584(handle.value));
    lua_settop(self->lua, -2);
    self->target->vtable->set(self->target, item);
    return 1;
}
