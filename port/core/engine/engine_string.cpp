#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "engine_string.c"
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
typedef struct EngineString { Ptr32<char> data; } EngineString;
/* Same observed one-pointer heap wrapper as lua_platform.c. A complete
 * declaration is needed for the original small-data address generation.
 */
typedef struct W3dHeapCore W3dHeapCore;
typedef struct W3dHeap { Ptr32<W3dHeapCore> core; } W3dHeap;
extern W3dHeap w3d_string_heap;
extern StringHeader w3d_string_empty_header;
extern int w3d_string_skip_base_ctor;
extern Ptr32<void> w3d_heap_allocate(Ptr32<W3dHeap>, unsigned int);
extern void w3d_heap_release(Ptr32<W3dHeap>, Ptr32<void>);
extern StringSize strlen(Ptr32<const char>);
/* The observed copy call explicitly clears CR1 as a variadic call. */
extern Ptr32<void> w3d_string_copy_bytes(Ptr32<void>, ...);
typedef struct W3dSharedString W3dSharedString;
/* Opaque shared object, observed through its string prefix. Its ordinary
 * address references must not be replaced with small-data addressing.
 */
extern W3dSharedString w3d_string_shared_empty;

void w3d_string_base_init(Ptr32<EngineString> string) { (void)string; }
void w3d_string_base_finish(Ptr32<EngineString> string) { (void)string; }

Ptr32<char> w3d_string_header_data(Ptr32<StringHeader> header)
{
    return (Ptr32<char>)(header + 1);
}

Ptr32<StringHeader> w3d_string_header(Ptr32<EngineString> string)
{
    return (Ptr32<StringHeader>)(string->data - 6);
}

void w3d_string_release_header(Ptr32<StringHeader> header)
{
    w3d_heap_release(&w3d_string_heap, header);
}

Ptr32<StringHeader> w3d_string_allocate_header(StringSize capacity)
{
    Ptr32<StringHeader> header = (Ptr32<StringHeader>)w3d_heap_allocate(&w3d_string_heap, capacity + 6);
    header->capacity = (StringWord)capacity;
    header->references = 1;
    return header;
}

Ptr32<StringHeader> w3d_string_allocate(Ptr32<EngineString> string, StringSize capacity)
{
    Ptr32<StringHeader> header = w3d_string_allocate_header(capacity);
    string->data = (Ptr32<char>)(header + 1);
    return header;
}

void w3d_string_release(Ptr32<EngineString> string)
{
    Ptr32<StringHeader> header = (Ptr32<StringHeader>)(string->data - 6);
    if (--header->references == 0) w3d_string_release_header(header);
}

Ptr32<EngineString> w3d_string_default(Ptr32<EngineString> string)
{
    if (w3d_string_skip_base_ctor) w3d_string_skip_base_ctor = 0;
    else w3d_string_base_init(string);
    string->data = w3d_string_header_data(&w3d_string_empty_header);
    ++w3d_string_header(string)->references;
    return string;
}

Ptr32<EngineString> w3d_string_from_text(Ptr32<EngineString> string, Ptr32<const char> text)
{
    w3d_string_base_init(string);
    if (text == 0 || *text == 0) {
        string->data = (Ptr32<char>)(&w3d_string_empty_header + 1);
        ++w3d_string_empty_header.references;
    } else {
        StringSize length = strlen(text);
        StringSize capacity = length + 1;
        Ptr32<StringHeader> header = w3d_string_allocate(string, capacity);
        header->length = (StringWord)length;
        w3d_string_copy_bytes(string->data, w3d::VA(text), capacity);
    }
    return string;
}

/* length describes a valid readable input range and permits length+1. */
Ptr32<EngineString> w3d_string_assign_range(Ptr32<EngineString> string, Ptr32<const char> text,
    int length)
{
    Ptr32<StringHeader> header = (Ptr32<StringHeader>)(string->data - 6);
    if (header->references > 1 || length + 1 > (int)header->capacity) {
        if (--header->references == 0) w3d_string_release_header(header);
        header = w3d_string_allocate(string, (StringSize)(length + 1));
    }
    header->length = (StringWord)length;
    w3d_string_copy_bytes(string->data, w3d::VA(text), length);
    string->data[length] = 0;
    return string;
}

Ptr32<EngineString> w3d_string_assign_text(Ptr32<EngineString> string, Ptr32<const char> text)
{
    if (text == 0 || *text == 0) {
        Ptr32<EngineString> empty = (Ptr32<EngineString>)&w3d_string_shared_empty;
        Ptr32<StringHeader> old;
        ++((Ptr32<StringHeader>)(empty->data - 6))->references;
        old = (Ptr32<StringHeader>)(string->data - 6);
        if (--old->references == 0) w3d_string_release_header(old);
        string->data = empty->data;
        return string;
    }
    return w3d_string_assign_range(string, text, (int)strlen(text));
}
#ifdef __cplusplus
}
#endif

}
