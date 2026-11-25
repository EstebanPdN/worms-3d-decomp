/* SendMessage candidate source and observed external interfaces.
 * Exact-byte comparison and controlled behavioral proof are separate results.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "lua.h"
typedef unsigned short MessageId;
typedef struct ScriptService {
    unsigned char unknown_00[0x44];
    lua_State *state;
} ScriptService;
typedef struct EngineString { char *data; } EngineString;
typedef struct EmptyMessage {
    MessageId id;
    unsigned short unknown_02;
    const void *vtable;
} EmptyMessage;
extern EngineString *w3d_string_from_text(EngineString *, const char *);
extern EngineString *w3d_string_default(EngineString *);
extern EngineString *w3d_string_format(EngineString *, const char *, ...);
extern void w3d_string_base_finish(EngineString *);
extern void w3d_string_release(EngineString *);
extern void w3d_script_report_error(ScriptService *, const char *);
extern int w3d_message_find_id(const char *, MessageId *);
extern void *w3d_message_storage;
extern EmptyMessage *w3d_message_allocate(void *, unsigned int);
extern unsigned char w3d_empty_message_vtable[];
extern int w3d_message_post_current(void *);

int w3d_script_send_message(ScriptService *service)
{
    int arguments = lua_gettop(service->state);
    if (arguments != 1) {
        w3d_script_report_error(service,
            "Incorrect number of arguments to function 'SendMessage'");
        lua_settop(service->state, ~arguments);
    } else if (!lua_isstring(service->state, -1)) {
        w3d_script_report_error(service,
            "Invalid argument to function 'SendMessage'");
        lua_settop(service->state, -2);
    } else {
        EngineString name;
        MessageId id;
        w3d_string_from_text(&name, lua_tostring(service->state, -1));
        if (w3d_message_find_id(name.data, &id) >= 0) {
            EmptyMessage *message = w3d_message_allocate(w3d_message_storage,
                sizeof(EmptyMessage));
            message->vtable = w3d_empty_message_vtable;
            message->id = id;
            w3d_message_post_current(message);
            lua_settop(service->state, -2);
        } else {
            EngineString error;
            w3d_string_default(&error);
            w3d_string_format(&error, "%s : Message name not registered", name.data);
            w3d_script_report_error(service, error.data);
            lua_settop(service->state, -2);
            w3d_string_base_finish(&error);
            w3d_string_release(&error);
        }
        w3d_string_base_finish(&name);
        w3d_string_release(&name);
    }
    return 0;
}
#ifdef __cplusplus
}
#endif
