/* Game-to-Lua callback bridge, reconstructed from GWMP8P revision 0.
 * The service methods declared here remain separate recovery obligations.
 * Names describe observed registration strings; no original name claim.
 */
#include "lua.h"

/* Observed object prefix only; this is not the complete allocation layout. */
typedef struct W3dScriptService {
    unsigned char unknown_00[0x44];
    lua_State *state;
} W3dScriptService;

extern int w3d_script_send_message(W3dScriptService *);
extern int w3d_script_send_float_message(W3dScriptService *);
extern int w3d_script_send_int_message(W3dScriptService *);
extern int w3d_script_send_string_message(W3dScriptService *);
extern int w3d_script_get_data(W3dScriptService *);
extern int w3d_script_set_data(W3dScriptService *);
extern int w3d_script_globals(W3dScriptService *);
extern int w3d_script_start_timer(W3dScriptService *);
extern int w3d_script_cancel_timer(W3dScriptService *);
extern int w3d_script_edit_container(W3dScriptService *);
extern int w3d_script_close_container(W3dScriptService *);
extern int w3d_script_query_container(W3dScriptService *);
extern int w3d_script_copy_container(W3dScriptService *);
extern int w3d_script_print(W3dScriptService *);
extern void w3d_script_report_error(W3dScriptService *, const char *);

int w3d_script_panic(W3dScriptService *service)
{
    w3d_script_report_error(service, lua_tostring(service->state, -1));
    lua_settop(service->state, -2);
    return 0;
}


W3dScriptService *w3d_script_service_from_lua(lua_State *state)
{
    W3dScriptService *service;
    lua_pushstring(state, "_SCRIPTSERVICE");
    lua_gettable(state, LUA_GLOBALSINDEX);
    service = (W3dScriptService *)lua_touserdata(state, -1);
    lua_settop(state, -2);
    return service;
}

int w3d_lua_SendMessage(lua_State *state)
{
    return w3d_script_send_message(w3d_script_service_from_lua(state));
}

int w3d_lua_SendFloatMessage(lua_State *state)
{
    return w3d_script_send_float_message(w3d_script_service_from_lua(state));
}

int w3d_lua_SendIntMessage(lua_State *state)
{
    return w3d_script_send_int_message(w3d_script_service_from_lua(state));
}

int w3d_lua_SendStringMessage(lua_State *state)
{
    return w3d_script_send_string_message(w3d_script_service_from_lua(state));
}

int w3d_lua_GetData(lua_State *state)
{
    return w3d_script_get_data(w3d_script_service_from_lua(state));
}

int w3d_lua_SetData(lua_State *state)
{
    return w3d_script_set_data(w3d_script_service_from_lua(state));
}

int w3d_lua_globals(lua_State *state)
{
    return w3d_script_globals(w3d_script_service_from_lua(state));
}

int w3d_lua_StartTimer(lua_State *state)
{
    return w3d_script_start_timer(w3d_script_service_from_lua(state));
}

int w3d_lua_CancelTimer(lua_State *state)
{
    return w3d_script_cancel_timer(w3d_script_service_from_lua(state));
}

int w3d_lua_EditContainer(lua_State *state)
{
    return w3d_script_edit_container(w3d_script_service_from_lua(state));
}

int w3d_lua_CloseContainer(lua_State *state)
{
    return w3d_script_close_container(w3d_script_service_from_lua(state));
}

int w3d_lua_QueryContainer(lua_State *state)
{
    return w3d_script_query_container(w3d_script_service_from_lua(state));
}

int w3d_lua_CopyContainer(lua_State *state)
{
    return w3d_script_copy_container(w3d_script_service_from_lua(state));
}

int w3d_lua_Print(lua_State *state)
{
    return w3d_script_print(w3d_script_service_from_lua(state));
}

int w3d_lua_panic(lua_State *state)
{
    return w3d_script_panic(w3d_script_service_from_lua(state));
}
