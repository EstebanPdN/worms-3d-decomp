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
typedef struct EngineString { char *data; } EngineString;
extern StringSize strlen(const char *);
extern StringHeader *w3d_string_allocate(EngineString *, StringSize);
extern void w3d_string_release_header(StringHeader *);
extern void *w3d_string_copy_bytes(void *, ...);

EngineString *w3d_string_append(EngineString *string, const char *text)
{
    int bytes = (int)strlen(text) + 1;
    char *old_data = string->data;
    StringHeader *header = (StringHeader *)(old_data - 6);
    StringHeader *old_header = header;
    int capacity = bytes + header->length;
    if (header->references > 1 || capacity > (int)header->capacity) {
        header = w3d_string_allocate(string, (StringSize)capacity);
        w3d_string_copy_bytes(string->data, old_data, old_header->length);
        header->length = old_header->length;
        if (--old_header->references == 0)
            w3d_string_release_header(old_header);
    }
    w3d_string_copy_bytes(string->data + header->length, text, bytes);
    header->length += (StringWord)(bytes - 1);
    return string;
}
#ifdef __cplusplus
}
#endif
