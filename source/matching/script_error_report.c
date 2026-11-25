#ifdef __cplusplus
extern "C" {
#endif
#include "script_errors.h"

void w3d_script_report_error(ScriptService *service, const char *error)
{
    EngineString message;
    w3d_string_default(&message);
    w3d_string_format(&message, "%s\nscript execution terminated", error);
    w3d_script_log(service, message.data, 1);
    w3d_script_output_hook(service, message.data);
    {
        StringMessage *failure = (StringMessage *)w3d_message_allocate(
            w3d_message_storage, sizeof(StringMessage));
        MessageId id = (MessageId)w3d_cached_message_id(&w3d_script_failure_message, 1);
        w3d_message_post_current(w3d_message_string_init(failure, id,
            "FAIL: Script execution terminated"));
    }
    w3d_script_set_run_state(service, 2);
    if (service->state != 0) {
        lua_Debug frame;
        int level;
        for (level = 0; lua_getstack(service->state, level, &frame); ++level) {
            lua_getinfo(service->state, "lS", &frame);
            if (frame.currentline != -1) {
                EngineString context;
                w3d_string_default(&context);
                w3d_script_source_line(service, frame.source, frame.currentline - 1,
                    service->source_context);
                w3d_string_format(&context, "error in %s at line %d: %s",
                    frame.source, frame.currentline, service->source_context);
                w3d_script_log(service, context.data, 1);
                w3d_script_output_hook(service, context.data);
                w3d_string_base_finish(&context);
                w3d_string_release(&context);
                break;
            }
        }
    }
    w3d_string_base_finish(&message);
    w3d_string_release(&message);
}
#ifdef __cplusplus
}
#endif
