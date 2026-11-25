#ifdef __cplusplus
extern "C" {
#endif
#include "engine_log.h"

void w3d_log_channel_write(LogChannel *channel, const char *text, int style)
{
    if (w3d_log_enabled && channel != 0) {
        EngineString prepared;
        w3d_string_default(&prepared);
        w3d_log_prepare_text(&prepared, text, style);
        channel->methods->write(channel, prepared.data,
            ((StringWord *)prepared.data)[-2], 0);
        w3d_string_base_finish(&prepared);
        w3d_string_release(&prepared);
    }
}
#ifdef __cplusplus
}
#endif
