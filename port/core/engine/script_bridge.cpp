#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "script_bridge.c"
/* Game-to-Lua callback bridge, reconstructed from GWMP8P revision 0.
 * The service methods declared here remain separate recovery obligations.
 * Names describe observed registration strings; no original name claim.
 */
#include "lua.h"

/* Observed object prefix only; this is not the complete allocation layout. */
typedef struct W3dScriptService {
    unsigned char unknown_00[0x44];
    Ptr32<int> state;
} W3dScriptService;

extern int w3d_script_send_message(Ptr32<W3dScriptService>);
extern int w3d_script_send_float_message(Ptr32<W3dScriptService>);
extern int w3d_script_send_int_message(Ptr32<W3dScriptService>);
extern int w3d_script_send_string_message(Ptr32<W3dScriptService>);
extern int w3d_script_get_data(Ptr32<W3dScriptService>);
extern int w3d_script_set_data(Ptr32<W3dScriptService>);
extern int w3d_script_globals(Ptr32<W3dScriptService>);
extern int w3d_script_start_timer(Ptr32<W3dScriptService>);
extern int w3d_script_cancel_timer(Ptr32<W3dScriptService>);
extern int w3d_script_edit_container(Ptr32<W3dScriptService>);
extern int w3d_script_close_container(Ptr32<W3dScriptService>);
extern int w3d_script_query_container(Ptr32<W3dScriptService>);
extern int w3d_script_copy_container(Ptr32<W3dScriptService>);
extern int w3d_script_print(Ptr32<W3dScriptService>);
extern void w3d_script_report_error(Ptr32<W3dScriptService>, Ptr32<const char>);

int w3d_script_panic(Ptr32<W3dScriptService> service)
{
    w3d_script_report_error(service, lua_tostring(service->state, -1));
    lua_settop(service->state, -2);
    return 0;
}


Ptr32<W3dScriptService> w3d_script_service_from_lua(Ptr32<int> state)
{
    Ptr32<W3dScriptService> service;
    lua_pushstring(state, "_SCRIPTSERVICE");
    lua_gettable(state, LUA_GLOBALSINDEX);
    service = (Ptr32<W3dScriptService>)lua_touserdata(state, -1);
    lua_settop(state, -2);
    return service;
}

int w3d_lua_SendMessage(Ptr32<int> state)
{
    return w3d_script_send_message(w3d_script_service_from_lua(state));
}

int w3d_lua_SendFloatMessage(Ptr32<int> state)
{
    return w3d_script_send_float_message(w3d_script_service_from_lua(state));
}

int w3d_lua_SendIntMessage(Ptr32<int> state)
{
    return w3d_script_send_int_message(w3d_script_service_from_lua(state));
}

int w3d_lua_SendStringMessage(Ptr32<int> state)
{
    return w3d_script_send_string_message(w3d_script_service_from_lua(state));
}

int w3d_lua_GetData(Ptr32<int> state)
{
    return w3d_script_get_data(w3d_script_service_from_lua(state));
}

int w3d_lua_SetData(Ptr32<int> state)
{
    return w3d_script_set_data(w3d_script_service_from_lua(state));
}

int w3d_lua_globals(Ptr32<int> state)
{
    return w3d_script_globals(w3d_script_service_from_lua(state));
}

int w3d_lua_StartTimer(Ptr32<int> state)
{
    return w3d_script_start_timer(w3d_script_service_from_lua(state));
}

int w3d_lua_CancelTimer(Ptr32<int> state)
{
    return w3d_script_cancel_timer(w3d_script_service_from_lua(state));
}

int w3d_lua_EditContainer(Ptr32<int> state)
{
    return w3d_script_edit_container(w3d_script_service_from_lua(state));
}

int w3d_lua_CloseContainer(Ptr32<int> state)
{
    return w3d_script_close_container(w3d_script_service_from_lua(state));
}

int w3d_lua_QueryContainer(Ptr32<int> state)
{
    return w3d_script_query_container(w3d_script_service_from_lua(state));
}

int w3d_lua_CopyContainer(Ptr32<int> state)
{
    return w3d_script_copy_container(w3d_script_service_from_lua(state));
}

int w3d_lua_Print(Ptr32<int> state)
{
    return w3d_script_print(w3d_script_service_from_lua(state));
}

int w3d_lua_panic(Ptr32<int> state)
{
    return w3d_script_panic(w3d_script_service_from_lua(state));
}

}
