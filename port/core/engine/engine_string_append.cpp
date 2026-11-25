#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "engine_string_append.c"
/* Reference target byte-string append, retaining copy-on-write ownership.
 * Valid inputs have readable NUL-terminated text and representable sizes.
 */
#ifdef __cplusplus
extern "C" {
#endif
typedef unsigned short StringWord;
typedef unsigned int StringSize;
typedef struct StringHeader {
    StringWord references, length, capacity;
} StringHeader;
typedef struct EngineString { Ptr32<char> data; } EngineString;
extern StringSize strlen(Ptr32<const char>);
extern Ptr32<StringHeader> w3d_string_allocate(Ptr32<EngineString>, StringSize);
extern void w3d_string_release_header(Ptr32<StringHeader>);
extern Ptr32<void> w3d_string_copy_bytes(Ptr32<void>, ...);

Ptr32<EngineString> w3d_string_append(Ptr32<EngineString> string, Ptr32<const char> text)
{
    int bytes = (int)strlen(text) + 1;
    Ptr32<char> old_data = string->data;
    Ptr32<StringHeader> header = (Ptr32<StringHeader>)(old_data - 6);
    Ptr32<StringHeader> old_header = header;
    int capacity = bytes + header->length;
    if (header->references > 1 || capacity > (int)header->capacity) {
        header = w3d_string_allocate(string, (StringSize)capacity);
        w3d_string_copy_bytes(string->data, w3d::VA(old_data), old_header->length);
        header->length = old_header->length;
        if (--old_header->references == 0)
            w3d_string_release_header(old_header);
    }
    w3d_string_copy_bytes(string->data + header->length, w3d::VA(text), bytes);
    header->length += (StringWord)(bytes - 1);
    return string;
}
#ifdef __cplusplus
}
#endif

}
