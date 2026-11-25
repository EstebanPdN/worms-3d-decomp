#ifdef __cplusplus
extern "C" {
#endif
#include "script_errors.h"

void w3d_script_log(ScriptService *service, const char *text, int urgent)
{
    w3d_log_message(w3d_script_log_channel, text, urgent);
    service->output_seen = 1;
}

void w3d_script_output_hook(ScriptService *service, const char *text)
{
    (void)service; (void)text;
}

void w3d_script_set_run_state(ScriptService *service, int state)
{
    service->run_state = state;
}

void w3d_cached_message_base_init(CachedMessageName *message)
{
    (void)message;
}

CachedMessageName *w3d_cached_message_name_init(CachedMessageName *message,
    const char *name)
{
    message->name = name;
    message->value.word &= ~0x8000u;
    w3d_cached_message_base_init(message);
    return message;
}

Word w3d_cached_message_id(CachedMessageName *message, int force)
{
    if ((message->value.word & 0x8000) == 0) {
        MessageId id;
        if (w3d_message_find_id(message->name, &id) < 0 && force == 0)
            return 0xffff;
        message->value.half[0] = id;
        message->value.word |= 0x8000;
    }
    return message->value.half[0];
}

const char *w3d_source_line_data(SourceLine *line)
{
    return line->data;
}

Word w3d_source_line_size(SourceLine *line)
{
    return line->size;
}

int w3d_source_line_at(SourceDocument *document, Word index, SourceLine **line)
{
    if (index >= (Word)(document->end - document->begin))
        return (int)0x80004005u;
    *line = document->begin[index];
    return 0;
}

int w3d_script_find_source(ScriptService *service, const char *name,
    SourceDocument **document)
{
    Word index;
    *document = 0;
    for (index = 0; index < (Word)(service->sources_end - service->sources_begin); ++index) {
        EngineString candidate;
        int comparison;
        *document = service->sources_begin[index];
        w3d_source_document_name(&candidate, *document);
        comparison = strcmp(candidate.data, name);
        w3d_string_base_finish(&candidate);
        w3d_string_release(&candidate);
        if (comparison == 0) return 1;
    }
    *document = 0;
    return 0;
}

int w3d_script_source_line(ScriptService *service, const char *name,
    int index, char *destination)
{
    SourceDocument *document = 0;
    SourceLine *line;
    int result;
    w3d_script_find_source(service, name, &document);
    if (document == 0) {
        strcpy(destination, "<source unavailable>");
        return 0;
    }
    result = w3d_source_line_at(document, (Word)index, &line);
    if (result >= 0) {
        Word size = w3d_source_line_size(line);
        if (size > 255) size = 255;
        memcpy(destination, w3d_source_line_data(line), size);
        destination[size] = '\0';
        result = 0;
    }
    return result;
}

EngineString *w3d_source_document_name(EngineString *name, SourceDocument *document)
{
    w3d_string_base_init(name);
    name->data = document->name.data;
    ++w3d_string_header(name)->references;
    return name;
}

#ifdef __cplusplus
}
#endif
