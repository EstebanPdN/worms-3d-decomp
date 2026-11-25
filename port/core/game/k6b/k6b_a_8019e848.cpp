#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_8019e848.c"
typedef struct lua_State lua_State;
struct K6bMessageType {
    char head[4];
    unsigned short id;
    unsigned char channel;
};
struct K6bMessageTypeRef { Ptr32<struct K6bMessageType> type; };
extern Ptr32<struct K6bMessageTypeRef> lbl_804ab728;
extern Ptr32<void> lua_touserdata(Ptr32<lua_State> L, int index);
extern float w3d_s21_check_number_802dd10c(Ptr32<lua_State> L, int index);
extern void fn_801ef200(Ptr32<void> target, unsigned short id, unsigned char channel, Ptr32<void> payload, int value, int flag);
int w3d_k6b_lua_send_message_8019e848(Ptr32<lua_State> L)
{
    Ptr32<void> target = *(Ptr32<Ptr32<void>>)lua_touserdata(L, 1);
    int value = (int)w3d_s21_check_number_802dd10c(L, 2);
    int payload = *(Ptr32<int>)lua_touserdata(L, 3);
    Ptr32<struct K6bMessageType> type = lbl_804ab728->type;
    fn_801ef200(target, type->id, type->channel, &payload, value, 1);
    return 0;
}
// desc: w3d_k6b_lua_send_message_8019e848: Appears to be a Lua binding: read a target object, a number and a userdata word and send them with the message type from 0x804ab728 through 0x801ef200.

}
