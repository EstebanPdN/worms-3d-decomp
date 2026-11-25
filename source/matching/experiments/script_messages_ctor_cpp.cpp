/* Observed SendMessage service and its external string/allocation interfaces.
 * Source subsets are admitted only through the complete reference comparison.
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
typedef struct EngineString EngineString;
typedef struct EmptyMessage {
    MessageId id;
    unsigned short unknown_02;
    const void *vtable;
} EmptyMessage;
extern void w3d_string_from_text(EngineString *, const char *);
extern void w3d_string_default(EngineString *);
extern void w3d_string_format(EngineString *, const char *, ...);
extern void w3d_string_base_finish(EngineString *);
extern void w3d_string_release(EngineString *);
extern void w3d_script_report_error(ScriptService *, const char *);
extern int w3d_message_find_id(const char *, MessageId *);
extern void *w3d_message_storage;
extern EmptyMessage *w3d_message_allocate(void *, unsigned int);
extern unsigned char w3d_empty_message_vtable[];
extern int w3d_message_post_current(void *);
struct EngineString {
    char *data;
    EngineString(const char *text) __asm__("w3d_string_from_text");
    EngineString() __asm__("w3d_string_default");
    ~EngineString() { w3d_string_base_finish(this); w3d_string_release(this); }
};


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
        EngineString name(lua_tostring(service->state, -1));
        MessageId id;
        if (w3d_message_find_id(name.data, &id) >= 0) {
            EmptyMessage *message = w3d_message_allocate(w3d_message_storage, 8);
            message->vtable = w3d_empty_message_vtable;
            message->id = id;
            w3d_message_post_current(message);
            lua_settop(service->state, -2);
        } else {
            EngineString error;
            w3d_string_format(&error, "%s : Message name not registered", name.data);
            w3d_script_report_error(service, error.data);
            lua_settop(service->state, -2);
        }
    }
    return 0;
}
#ifdef __cplusplus
}
#endif
