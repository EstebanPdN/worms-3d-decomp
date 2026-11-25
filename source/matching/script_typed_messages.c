/* Reconstructed typed Lua message workers; behavior validation is separate
 * from exact-byte recovery. Structures expose the observed target prefixes.
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
typedef struct ScalarMessage {
    MessageId id;
    unsigned short unknown_02;
    const void *vtable;
    union { float number; int integer; const char *text; } payload;
} ScalarMessage;
extern EngineString *w3d_string_from_text(EngineString *, const char *);
extern EngineString *w3d_string_default(EngineString *);
extern EngineString *w3d_string_format(EngineString *, const char *, ...);
extern void w3d_string_base_finish(EngineString *);
extern void w3d_string_release(EngineString *);
extern void w3d_script_report_error(ScriptService *, const char *);
extern int w3d_message_find_id(const char *, MessageId *);
extern void *w3d_message_storage;
extern void *w3d_message_allocate(void *, unsigned int);
extern ScalarMessage *w3d_message_float_init(ScalarMessage *, MessageId, float);
extern ScalarMessage *w3d_message_int_init(ScalarMessage *, MessageId, int);
extern ScalarMessage *w3d_message_string_init(ScalarMessage *, MessageId, const char *);
extern int w3d_message_post_current(void *);

int w3d_script_send_float_message(ScriptService *service)
{
    int arguments = lua_gettop(service->state);
    if (arguments != 2) {
        w3d_script_report_error(service,
            "Incorrect number of arguments to function 'SendFloatMessage'");
        lua_settop(service->state, ~arguments);
    } else if (!lua_isstring(service->state, -2) ||
               !lua_isnumber(service->state, -1)) {
        w3d_script_report_error(service,
            "Invalid argument to function 'SendFloatMessage'");
        lua_settop(service->state, -3);
    } else {
        EngineString name;
        MessageId id;
        w3d_string_from_text(&name, lua_tostring(service->state, -2));
        if (w3d_message_find_id(name.data, &id) >= 0) {
            ScalarMessage *message = (ScalarMessage *)w3d_message_allocate(
                w3d_message_storage, sizeof(ScalarMessage));
            float value = lua_tonumber(service->state, -1);
            w3d_message_post_current(w3d_message_float_init(message, id, value));
            lua_settop(service->state, -3);
        } else {
            EngineString error;
            w3d_string_default(&error);
            w3d_string_format(&error, "%s : Message name not registered", name.data);
            w3d_script_report_error(service, error.data);
            lua_settop(service->state, -3);
            w3d_string_base_finish(&error);
            w3d_string_release(&error);
        }
        w3d_string_base_finish(&name);
        w3d_string_release(&name);
    }
    return 0;
}

int w3d_script_send_int_message(ScriptService *service)
{
    int arguments = lua_gettop(service->state);
    if (arguments != 2) {
        w3d_script_report_error(service,
            "Incorrect number of arguments to function 'SendIntMessage'");
        /* Native wrong-count path uses a fixed index, not ~arguments. */
        lua_settop(service->state, -3);
    } else if (!lua_isstring(service->state, -2) ||
               !lua_isnumber(service->state, -1)) {
        w3d_script_report_error(service,
            "Invalid argument to function 'SendIntMessage'");
        lua_settop(service->state, -3);
    } else {
        EngineString name;
        MessageId id;
        w3d_string_from_text(&name, lua_tostring(service->state, -2));
        if (w3d_message_find_id(name.data, &id) >= 0) {
            ScalarMessage *message = (ScalarMessage *)w3d_message_allocate(
                w3d_message_storage, sizeof(ScalarMessage));
            int value = (int)lua_tonumber(service->state, -1);
            w3d_message_post_current(w3d_message_int_init(message, id, value));
            lua_settop(service->state, -3);
        } else {
            EngineString error;
            w3d_string_default(&error);
            w3d_string_format(&error, "%s : Message name not registered", name.data);
            w3d_script_report_error(service, error.data);
            lua_settop(service->state, -3);
            w3d_string_base_finish(&error);
            w3d_string_release(&error);
        }
        w3d_string_base_finish(&name);
        w3d_string_release(&name);
    }
    return 0;
}

int w3d_script_send_string_message(ScriptService *service)
{
    int arguments = lua_gettop(service->state);
    if (arguments != 2) {
        w3d_script_report_error(service,
            "Incorrect number of arguments to function 'SendStringMessage'");
        lua_settop(service->state, ~arguments);
    } else if (!lua_isstring(service->state, -2) ||
               !lua_isstring(service->state, -1)) {
        w3d_script_report_error(service,
            "Invalid argument to function 'SendStringMessage'");
        lua_settop(service->state, -3);
    } else {
        EngineString name;
        MessageId id;
        w3d_string_from_text(&name, lua_tostring(service->state, -2));
        if (w3d_message_find_id(name.data, &id) >= 0) {
            ScalarMessage *message = (ScalarMessage *)w3d_message_allocate(
                w3d_message_storage, sizeof(ScalarMessage));
            const char *value = lua_tostring(service->state, -1);
            w3d_message_post_current(w3d_message_string_init(message, id, value));
            lua_settop(service->state, -3);
        } else {
            EngineString error;
            w3d_string_default(&error);
            w3d_string_format(&error, "%s : Message name not registered", name.data);
            w3d_script_report_error(service, error.data);
            lua_settop(service->state, -3);
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
