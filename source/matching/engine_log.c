/* Observed channel dispatch prefixes, not complete recovered engine classes. */
#ifdef __cplusplus
extern "C" {
#endif
#include "engine_log.h"

void w3d_log_message(Word channel, const char *text, int style)
{
    if (w3d_log_enabled && channel < 16 && w3d_log_channels[channel] != 0) {
        EngineString line;
        w3d_string_from_text(&line, text);
        w3d_string_append(&line, "\r\n");
        w3d_log_channel_write(w3d_log_channels[channel], line.data, style);
        w3d_string_base_finish(&line);
        w3d_string_release(&line);
    }
}
#ifdef __cplusplus
}
#endif
