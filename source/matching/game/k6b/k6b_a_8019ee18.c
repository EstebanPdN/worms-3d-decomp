typedef struct lua_State lua_State;
struct K6bIface { void **vtable; };
struct K6bMessageType {
    char head[4];
    unsigned short offset;
};
struct K6bMessageTypeRef { struct K6bMessageType *type; };
struct K6bIfaceArray {
    char head[24];
    unsigned int count;
    char gap[4];
    struct K6bIface *items[1];
};
extern struct K6bMessageTypeRef *lbl_804ab728;
extern void *lua_touserdata(lua_State *L, int index);
extern float w3d_s21_check_number_802dd10c(lua_State *L, int index);
extern void *lua_newuserdata(lua_State *L, unsigned int size);
extern void lua_pushvalue(lua_State *L, int index);
extern int lua_setmetatable(lua_State *L, int index);
int w3d_k6b_lua_iface_array_get_8019ee18(lua_State *L)
{
    char *object = *(char **)lua_touserdata(L, 1);
    unsigned int index = (int)w3d_s21_check_number_802dd10c(L, 2);
    struct K6bIfaceArray *array = *(struct K6bIfaceArray **)(object + lbl_804ab728->type->offset);
    struct K6bIface **items = array->items;
    if (index < array->count) {
        struct K6bIface **result = (struct K6bIface **)lua_newuserdata(L, 8);
        struct K6bIface *item;
        lua_pushvalue(L, -10002);
        lua_setmetatable(L, -2);
        item = items[index];
        *result = item;
        ((void (*)(struct K6bIface *))item->vtable[3])(item);
        return 1;
    }
    return 0;
}
// desc: w3d_k6b_lua_iface_array_get_8019ee18: Appears to be a Lua binding returning element n of an interface array field of a userdata object as a new retained userdata with the registry metatable.
