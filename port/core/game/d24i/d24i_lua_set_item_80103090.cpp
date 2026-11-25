#include "w3d_ptr.h"
#line 1 "d24i_lua_set_item_80103090.cpp"
// d24i: 0x80103090 (416 bytes). Lua binding: expects one string argument naming
// a setting, looks up its value handle (0x800fc1b0), requires value kind 5
// (virtual +24), pops the argument and passes the resolved item (0x801797b4) to
// the object at +64 through its virtual +32. Every failure reports through
// 0x801022ec with its message, pops the argument and returns 0; success returns 1.
struct lua_State;
extern "C" int lua_gettop(Ptr32<lua_State>);
extern "C" int lua_isstring(Ptr32<lua_State>, int);
extern "C" Ptr32<const char> lua_tostring(Ptr32<lua_State>, int);
extern "C" void lua_settop(Ptr32<lua_State>, int);
struct d24i_String {
 d24i_String(const d24i_String &);
    Ptr32<char> text;
    template <class W3dU> d24i_String(Ptr32<W3dU> w3d_p) : d24i_String((const char *)w3d_p.get()) {}
 d24i_String(const char *);
    ~d24i_String();
};
extern "C" void d24i_string_finish_8020c5c4(Ptr32<d24i_String>);
extern "C" void d24i_string_release_80341588(Ptr32<d24i_String>);
inline d24i_String::~d24i_String() {
    d24i_string_finish_8020c5c4(this);
    d24i_string_release_80341588(this);
}
struct d24i_Key { Ptr32<const char> name; };
struct d24i_Value;
struct d24i_ValueVtable {
    Ptr32<void> unknown00[4];
    Ptr32<void (Ptr32<d24i_Value>)> release;       // +16
    Ptr32<void> unknown14;
    Ptr32<int (Ptr32<d24i_Value>)> kind;           // +24
};
struct d24i_Value { Ptr32<d24i_ValueVtable> vtable; };
struct d24i_Handle {
 d24i_Handle(const d24i_Handle &);
    Ptr32<d24i_Value> value;
    // One word with a user copy constructor: the key follows this object 8 bytes
    // later on the stack in the original (0x80103090: handle +16, key +24), while keys alone are 4 apart.
    d24i_Handle() { value = 0; }
    ~d24i_Handle() { if (value) value->vtable->release(value); }
};
struct d24i_Item;
struct d24i_Target;
struct d24i_TargetVtable {
    Ptr32<void> unknown00[8];
    Ptr32<void (Ptr32<d24i_Target>, Ptr32<d24i_Item>)> set;   // +32
};
struct d24i_Target { Ptr32<d24i_TargetVtable> vtable; };
struct d24i_Binding {
    unsigned char unknown00[64];
    Ptr32<d24i_Target> target;                 // +64
    Ptr32<lua_State> lua;                      // +68
};
extern "C" int d24i_setting_lookup_800fc1b0(Ptr32<d24i_Key>, Ptr32<d24i_Handle>);
extern "C" void d24i_script_error_801022ec(Ptr32<d24i_Binding>, Ptr32<const char>);
extern "C" Ptr32<void> d24i_as_item_80341584(Ptr32<d24i_Value>);
extern "C" Ptr32<d24i_Item> d24i_item_801797b4(Ptr32<void>);
static inline int d24i_find(const d24i_String &name, d24i_Handle &out) {
    d24i_Key key;
    key.name = name.text;
    return d24i_setting_lookup_800fc1b0(&key, &out);
}
extern const char d24i_error_count_8039911c[], d24i_error_type_80399158[], d24i_error_name_80399188[], d24i_error_kind_803991b8[];

extern "C" int d24i_lua_set_item_80103090(Ptr32<d24i_Binding> self) {
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
    Ptr32<d24i_Item> item = d24i_item_801797b4(d24i_as_item_80341584(handle.value));
    lua_settop(self->lua, -2);
    self->target->vtable->set(self->target, item);
    return 1;
}


