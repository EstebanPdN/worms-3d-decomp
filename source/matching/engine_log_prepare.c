/* Preserve LF conversion, existing CRLF and the original temporary ownership. */
#ifdef __cplusplus
extern "C" {
#endif
#include "engine_log.h"

/* Original table 0x80403f54 and strings 0x803d912c..0x803d9177.
 * These are compiler-owned candidate data, not pointers into the game image.
 */
const char *w3d_log_prefixes[10] = {
    "\033[0;30m", "\033[1;31m", "\033[1;32m", "\033[1;33m",
    "\033[1;34m", "\033[1;35m", "\033[1;36m", "\033[1;37m",
    "\033[0;37m", "\033[m"
};

void w3d_log_prepare_text(EngineString *output, const char *text, int style)
{
    w3d_string_append(output, w3d_log_prefixes[style]);
    if (text != 0) {
        const char *newline = strchr(text, '\n');
        if (newline == 0) {
            w3d_string_append(output, text);
        } else {
            const char *line = text;
            newline = strchr(line, '\n');
            while (newline != 0) {
                if (newline == line) {
                    w3d_string_append(output, "\r\n");
                    ++line;
                    newline = strchr(line, '\n');
                } else if (newline[-1] == '\r') {
                    newline = strchr(newline + 1, '\n');
                } else {
                    EngineString fragment, joined, value;
                    w3d_string_default(&fragment);
                    w3d_string_assign_range(&fragment, line, (int)(newline - line));
                    line = newline + 1;
                    w3d_string_base_init(&joined);
                    joined.data = fragment.data;
                    ++w3d_string_header(&joined)->references;
                    w3d_string_append(&joined, "\r\n");
                    w3d_string_base_init(&value);
                    value.data = joined.data;
                    ++w3d_string_header(&value)->references;
                    w3d_string_base_finish(&joined);
                    w3d_string_release(&joined);
                    w3d_string_append(output, value.data);
                    w3d_string_base_finish(&value);
                    w3d_string_release(&value);
                    newline = strchr(line, '\n');
                    w3d_string_base_finish(&fragment);
                    w3d_string_release(&fragment);
                }
            }
            w3d_string_append(output, line);
        }
        w3d_string_append(output, w3d_log_prefixes[9]);
    }
}
#ifdef __cplusplus
}
#endif
