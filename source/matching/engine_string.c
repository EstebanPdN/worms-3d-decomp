/* Observed reference-counted byte-string representation and lifecycle.
 * Heap implementations and formatting remain dependencies.
 */
#ifdef __cplusplus
extern "C" {
#endif
typedef unsigned short StringWord;
typedef unsigned int StringSize;
typedef struct StringHeader {
    StringWord references;
    StringWord length;
    StringWord capacity;
} StringHeader;
typedef struct EngineString { char *data; } EngineString;
/* Same observed one-pointer heap wrapper as lua_platform.c. A complete
 * declaration is needed for the original small-data address generation.
 */
typedef struct W3dHeapCore W3dHeapCore;
typedef struct W3dHeap { W3dHeapCore *core; } W3dHeap;
extern W3dHeap w3d_string_heap;
extern StringHeader w3d_string_empty_header;
extern int w3d_string_skip_base_ctor;
extern void *w3d_heap_allocate(W3dHeap *, unsigned long);
extern void w3d_heap_release(W3dHeap *, void *);
extern StringSize strlen(const char *);
/* The observed copy call explicitly clears CR1 as a variadic call. */
extern void *w3d_string_copy_bytes(void *, ...);
typedef struct W3dSharedString W3dSharedString;
/* Opaque shared object, observed through its string prefix. Its ordinary
 * address references must not be replaced with small-data addressing.
 */
extern W3dSharedString w3d_string_shared_empty;

void w3d_string_base_init(EngineString *string) { (void)string; }
void w3d_string_base_finish(EngineString *string) { (void)string; }

char *w3d_string_header_data(StringHeader *header)
{
    return (char *)(header + 1);
}

StringHeader *w3d_string_header(EngineString *string)
{
    return (StringHeader *)(string->data - 6);
}

void w3d_string_release_header(StringHeader *header)
{
    w3d_heap_release(&w3d_string_heap, header);
}

StringHeader *w3d_string_allocate_header(StringSize capacity)
{
    StringHeader *header = (StringHeader *)w3d_heap_allocate(&w3d_string_heap, capacity + 6);
    header->capacity = (StringWord)capacity;
    header->references = 1;
    return header;
}

StringHeader *w3d_string_allocate(EngineString *string, StringSize capacity)
{
    StringHeader *header = w3d_string_allocate_header(capacity);
    string->data = (char *)(header + 1);
    return header;
}

void w3d_string_release(EngineString *string)
{
    StringHeader *header = (StringHeader *)(string->data - 6);
    if (--header->references == 0) w3d_string_release_header(header);
}

EngineString *w3d_string_default(EngineString *string)
{
    if (w3d_string_skip_base_ctor) w3d_string_skip_base_ctor = 0;
    else w3d_string_base_init(string);
    string->data = w3d_string_header_data(&w3d_string_empty_header);
    ++w3d_string_header(string)->references;
    return string;
}

EngineString *w3d_string_from_text(EngineString *string, const char *text)
{
    w3d_string_base_init(string);
    if (text == 0 || *text == 0) {
        string->data = (char *)(&w3d_string_empty_header + 1);
        ++w3d_string_empty_header.references;
    } else {
        StringSize length = strlen(text);
        StringSize capacity = length + 1;
        StringHeader *header = w3d_string_allocate(string, capacity);
        header->length = (StringWord)length;
        w3d_string_copy_bytes(string->data, text, capacity);
    }
    return string;
}

/* length describes a valid readable input range and permits length+1. */
EngineString *w3d_string_assign_range(EngineString *string, const char *text,
    int length)
{
    StringHeader *header = (StringHeader *)(string->data - 6);
    if (header->references > 1 || length + 1 > (int)header->capacity) {
        if (--header->references == 0) w3d_string_release_header(header);
        header = w3d_string_allocate(string, (StringSize)(length + 1));
    }
    header->length = (StringWord)length;
    w3d_string_copy_bytes(string->data, text, length);
    string->data[length] = 0;
    return string;
}

EngineString *w3d_string_assign_text(EngineString *string, const char *text)
{
    if (text == 0 || *text == 0) {
        EngineString *empty = (EngineString *)&w3d_string_shared_empty;
        StringHeader *old;
        ++((StringHeader *)(empty->data - 6))->references;
        old = (StringHeader *)(string->data - 6);
        if (--old->references == 0) w3d_string_release_header(old);
        string->data = empty->data;
        return string;
    }
    return w3d_string_assign_range(string, text, (int)strlen(text));
}
#ifdef __cplusplus
}
#endif
