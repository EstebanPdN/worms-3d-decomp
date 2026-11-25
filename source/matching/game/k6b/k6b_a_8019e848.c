typedef struct lua_State lua_State;
struct K6bMessageType {
    char head[4];
    unsigned short id;
    unsigned char channel;
};
struct K6bMessageTypeRef { struct K6bMessageType *type; };
extern struct K6bMessageTypeRef *lbl_804ab728;
extern void *lua_touserdata(lua_State *L, int index);
extern float w3d_s21_check_number_802dd10c(lua_State *L, int index);
extern void fn_801ef200(void *target, unsigned short id, unsigned char channel, void *payload, int value, int flag);
int w3d_k6b_lua_send_message_8019e848(lua_State *L)
{
    void *target = *(void **)lua_touserdata(L, 1);
    int value = (int)w3d_s21_check_number_802dd10c(L, 2);
    int payload = *(int *)lua_touserdata(L, 3);
    struct K6bMessageType *type = lbl_804ab728->type;
    fn_801ef200(target, type->id, type->channel, &payload, value, 1);
    return 0;
}
// desc: w3d_k6b_lua_send_message_8019e848: Appears to be a Lua binding: read a target object, a number and a userdata word and send them with the message type from 0x804ab728 through 0x801ef200.
