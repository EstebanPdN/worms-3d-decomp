#ifndef W3D_REFERENCE_SCRIPT_ERRORS_H
#define W3D_REFERENCE_SCRIPT_ERRORS_H
#include "lua.h"
#include <string.h>
typedef unsigned int Word;
typedef unsigned short MessageId;
typedef struct EngineString { Ptr32<char> data; } EngineString;
typedef struct SourceLine {
    unsigned char unknown_00[8];
    Ptr32<const char> data;
    Word size;
} SourceLine;
typedef struct SourceDocument {
    unsigned char unknown_00[4];
    Ptr32<Ptr32<SourceLine>> begin;
    Ptr32<Ptr32<SourceLine>> end;
    unsigned char unknown_0c[12];
    EngineString name;
} SourceDocument;
typedef struct ScriptService {
    unsigned char unknown_00[0x1c];
    Ptr32<Ptr32<SourceDocument>> sources_begin;
    Ptr32<Ptr32<SourceDocument>> sources_end;
    unsigned char unknown_24[0x20];
    Ptr32<int> state;
    int run_state;
    char source_context[256];
    unsigned char unknown_14c[0x24];
    int output_seen;
} ScriptService;
typedef struct CachedMessageName {
    union { Word word; MessageId half[2]; } value;
    Ptr32<const char> name;
} CachedMessageName;
typedef struct StringMessage {
    MessageId id;
    MessageId unknown_02;
    Ptr32<const void> vtable;
    Ptr32<const char> value;
} StringMessage;

extern Word w3d_script_log_channel;
extern CachedMessageName w3d_script_failure_message;
extern Ptr32<void> w3d_message_storage;
extern void w3d_log_message(Word, Ptr32<const char>, int);
extern Ptr32<EngineString> w3d_string_default(Ptr32<EngineString>);
extern Ptr32<EngineString> w3d_string_format(Ptr32<EngineString>, Ptr32<const char>, ...);
extern void w3d_string_base_finish(Ptr32<EngineString>);
extern void w3d_string_release(Ptr32<EngineString>);
extern int w3d_message_find_id(Ptr32<const char>, Ptr32<MessageId>);
extern Ptr32<void> w3d_message_allocate(Ptr32<void>, unsigned int);
extern Ptr32<StringMessage> w3d_message_string_init(Ptr32<StringMessage>, MessageId, Ptr32<const char>);
extern int w3d_message_post_current(Ptr32<void>);
extern Ptr32<EngineString> w3d_source_document_name(Ptr32<EngineString>, Ptr32<SourceDocument>);
void w3d_cached_message_base_init(Ptr32<CachedMessageName>);
Ptr32<CachedMessageName> w3d_cached_message_name_init(Ptr32<CachedMessageName>, Ptr32<const char>);
extern void w3d_string_base_init(Ptr32<EngineString>);
typedef struct StringHeader { MessageId references, length, capacity; } StringHeader;
extern Ptr32<StringHeader> w3d_string_header(Ptr32<EngineString>);
void w3d_script_log(Ptr32<ScriptService>, Ptr32<const char>, int);
void w3d_script_output_hook(Ptr32<ScriptService>, Ptr32<const char>);
void w3d_script_set_run_state(Ptr32<ScriptService>, int);
Word w3d_cached_message_id(Ptr32<CachedMessageName>, int);
int w3d_script_source_line(Ptr32<ScriptService>, Ptr32<const char>, int, Ptr32<char>);

#endif
