#ifndef W3D_REFERENCE_SCRIPT_ERRORS_H
#define W3D_REFERENCE_SCRIPT_ERRORS_H
#include "lua.h"
#include <string.h>
typedef unsigned int Word;
typedef unsigned short MessageId;
typedef struct EngineString { char *data; } EngineString;
typedef struct SourceLine {
    unsigned char unknown_00[8];
    const char *data;
    Word size;
} SourceLine;
typedef struct SourceDocument {
    unsigned char unknown_00[4];
    SourceLine **begin;
    SourceLine **end;
    unsigned char unknown_0c[12];
    EngineString name;
} SourceDocument;
typedef struct ScriptService {
    unsigned char unknown_00[0x1c];
    SourceDocument **sources_begin;
    SourceDocument **sources_end;
    unsigned char unknown_24[0x20];
    lua_State *state;
    int run_state;
    char source_context[256];
    unsigned char unknown_14c[0x24];
    int output_seen;
} ScriptService;
typedef struct CachedMessageName {
    union { Word word; MessageId half[2]; } value;
    const char *name;
} CachedMessageName;
typedef struct StringMessage {
    MessageId id;
    MessageId unknown_02;
    const void *vtable;
    const char *value;
} StringMessage;

extern Word w3d_script_log_channel;
extern CachedMessageName w3d_script_failure_message;
extern void *w3d_message_storage;
extern void w3d_log_message(Word, const char *, int);
extern EngineString *w3d_string_default(EngineString *);
extern EngineString *w3d_string_format(EngineString *, const char *, ...);
extern void w3d_string_base_finish(EngineString *);
extern void w3d_string_release(EngineString *);
extern int w3d_message_find_id(const char *, MessageId *);
extern void *w3d_message_allocate(void *, unsigned int);
extern StringMessage *w3d_message_string_init(StringMessage *, MessageId, const char *);
extern int w3d_message_post_current(void *);
extern EngineString *w3d_source_document_name(EngineString *, SourceDocument *);
void w3d_cached_message_base_init(CachedMessageName *);
CachedMessageName *w3d_cached_message_name_init(CachedMessageName *, const char *);
extern void w3d_string_base_init(EngineString *);
typedef struct StringHeader { MessageId references, length, capacity; } StringHeader;
extern StringHeader *w3d_string_header(EngineString *);
void w3d_script_log(ScriptService *, const char *, int);
void w3d_script_output_hook(ScriptService *, const char *);
void w3d_script_set_run_state(ScriptService *, int);
Word w3d_cached_message_id(CachedMessageName *, int);
int w3d_script_source_line(ScriptService *, const char *, int, char *);

#endif
