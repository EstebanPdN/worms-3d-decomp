/* Observed scalar message prefix. String payloads retain the supplied
 * pointer; these initialization functions do not allocate/copy its text.
 */
#ifdef __cplusplus
extern "C" {
#endif
typedef unsigned short MessageId;
typedef struct ScalarMessage {
    MessageId id;
    unsigned short unknown_02;
    const void *vtable;
    union { float number; int integer; const char *text; } payload;
} ScalarMessage;
extern unsigned char w3d_empty_message_vtable[];

ScalarMessage *w3d_message_float_init(ScalarMessage *message, MessageId id,
    float number)
{
    message->id = id;
    message->vtable = w3d_empty_message_vtable;
    message->payload.number = number;
    return message;
}

ScalarMessage *w3d_message_int_init(ScalarMessage *message, MessageId id,
    int integer)
{
    message->id = id;
    message->vtable = w3d_empty_message_vtable;
    message->payload.integer = integer;
    return message;
}

ScalarMessage *w3d_message_string_init(ScalarMessage *message, MessageId id,
    const char *text)
{
    message->id = id;
    message->vtable = w3d_empty_message_vtable;
    message->payload.text = text;
    return message;
}
#ifdef __cplusplus
}
#endif
