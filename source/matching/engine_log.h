#ifndef W3D_REFERENCE_ENGINE_LOG_H
#define W3D_REFERENCE_ENGINE_LOG_H
typedef unsigned int Word;
typedef unsigned short StringWord;
typedef struct StringHeader { StringWord references, length, capacity; } StringHeader;
typedef struct EngineString { char *data; } EngineString;
typedef struct LogChannel LogChannel;
typedef struct LogChannelMethods {
    void *unknown_00[6];
    void (*write)(LogChannel *, const char *, Word, int);
} LogChannelMethods;
struct LogChannel { LogChannelMethods *methods; };
extern int w3d_log_enabled;
extern LogChannel *w3d_log_channels[16];
extern const char *w3d_log_prefixes[10];
extern EngineString *w3d_string_from_text(EngineString *, const char *);
extern EngineString *w3d_string_default(EngineString *);
extern EngineString *w3d_string_append(EngineString *, const char *);
extern EngineString *w3d_string_assign_range(EngineString *, const char *, int);
extern void w3d_string_base_init(EngineString *);
extern void w3d_string_base_finish(EngineString *);
extern void w3d_string_release(EngineString *);
extern StringHeader *w3d_string_header(EngineString *);
extern char *strchr(const char *, int);
void w3d_log_prepare_text(EngineString *, const char *, int);
void w3d_log_channel_write(LogChannel *, const char *, int);
void w3d_log_message(Word, const char *, int);
#endif
