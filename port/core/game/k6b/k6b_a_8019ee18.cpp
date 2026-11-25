#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_8019ee18.c"
typedef struct lua_State lua_State;
struct K6bIface { Ptr32<Ptr32<void>> vtable; };
struct K6bMessageType {
    char head[4];
    unsigned short offset;
};
struct K6bMessageTypeRef { Ptr32<struct K6bMessageType> type; };
struct K6bIfaceArray {
    char head[24];
    unsigned int count;
    char gap[4];
    Ptr32<struct K6bIface> items[1];
};
extern Ptr32<struct K6bMessageTypeRef> lbl_804ab728;
extern Ptr32<void> lua_touserdata(Ptr32<lua_State> L, int index);
extern float w3d_s21_check_number_802dd10c(Ptr32<lua_State> L, int index);
extern Ptr32<void> lua_newuserdata(Ptr32<lua_State> L, unsigned int size);
extern void lua_pushvalue(Ptr32<lua_State> L, int index);
extern int lua_setmetatable(Ptr32<lua_State> L, int index);
int w3d_k6b_lua_iface_array_get_8019ee18(Ptr32<lua_State> L)
{
    Ptr32<char> object = *(Ptr32<Ptr32<char>>)lua_touserdata(L, 1);
    unsigned int index = (int)w3d_s21_check_number_802dd10c(L, 2);
    Ptr32<struct K6bIfaceArray> array = *(Ptr32<Ptr32<struct K6bIfaceArray>>)(object + lbl_804ab728->type->offset);
    Ptr32<Ptr32<struct K6bIface>> items = array->items;
    if (index < array->count) {
        Ptr32<Ptr32<struct K6bIface>> result = (Ptr32<Ptr32<struct K6bIface>>)lua_newuserdata(L, 8);
        Ptr32<struct K6bIface> item;
        lua_pushvalue(L, -10002);
        lua_setmetatable(L, -2);
        item = items[index];
        *result = item;
        ((Ptr32<void (Ptr32<struct K6bIface>)>)item->vtable[3])(item);
        return 1;
    }
    return 0;
}
// desc: w3d_k6b_lua_iface_array_get_8019ee18: Appears to be a Lua binding returning element n of an interface array field of a userdata object as a new retained userdata with the registry metatable.

}
