#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_8019ed40.c"
typedef struct lua_State lua_State;
struct K6bIface { Ptr32<Ptr32<void>> vtable; };
struct K6bMessageType {
    char head[4];
    unsigned short offset;
    unsigned char channel;
    char pad7;
    Ptr32<void> element_type;
};
struct K6bMessageTypeRef { Ptr32<struct K6bMessageType> type; };
extern Ptr32<struct K6bMessageTypeRef> lbl_804ab728;
extern Ptr32<void> lua_touserdata(Ptr32<lua_State> L, int index);
extern int lua_isuserdata(Ptr32<lua_State> L, int index);
extern int lua_type(Ptr32<lua_State> L, int index);
extern void lua_pushvalue(Ptr32<lua_State> L, int index);
extern float w3d_s21_check_number_802dd10c(Ptr32<lua_State> L, int index);
extern int w3d_auto_801fffc8(Ptr32<void> type);
extern void w3d_k5b_iface_array_field_set_801ef2ec(Ptr32<char> object, int offset, int unused, Ptr32<struct K6bIface> item, unsigned int index);
extern int fn_8019e96c(Ptr32<lua_State> L, Ptr32<char> object, Ptr32<struct K6bMessageTypeRef> ref);
int w3d_k6b_lua_iface_array_set_8019ed40(Ptr32<lua_State> L)
{
    Ptr32<char> object = *(Ptr32<Ptr32<char>>)lua_touserdata(L, 1);
    if (lua_isuserdata(L, 2)) {
        Ptr32<struct K6bMessageTypeRef> ref = lbl_804ab728;
        if (w3d_auto_801fffc8(ref->type->element_type) == 24) {
            Ptr32<struct K6bIface> item = *(Ptr32<Ptr32<struct K6bIface>>)lua_touserdata(L, 3);
            int index = (int)w3d_s21_check_number_802dd10c(L, 2);
            w3d_k5b_iface_array_field_set_801ef2ec(object, ref->type->offset, ref->type->channel, item, index);
        }
    } else if (lua_type(L, 2) == 5) {
        lua_pushvalue(L, 2);
        fn_8019e96c(L, object, lbl_804ab728);
    }
    return 0;
}
// desc: w3d_k6b_lua_iface_array_set_8019ed40: Appears to be a Lua binding storing a userdata interface at index n of an array field, or forwarding a table argument to 0x8019e96c.

}
