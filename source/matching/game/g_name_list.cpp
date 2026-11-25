/* Bounded list of short names kept as 33-byte records (0x800c4598..0x800c4e18).
 *
 * Names are inferred from behavior; no original symbols survive. Layout:
 *   +0x04 record vector {begin, end, capacity}, +0x10 limit (unsigned count).
 * Each record is a zero-padded 33-character text. Removal shifts the tail
 * down with memcpy (the vector erase shape); reads copy a record into an
 * engine string with w3d_string_assign. 0x80004005 reports an empty list.
 */
#include "g_types2.h"

extern "C" {

typedef struct W3dNameRecord {
    char text[33];
} W3dNameRecord;

typedef struct W3dNameVector {
    W3dNameRecord *begin;
    W3dNameRecord *end;
    W3dNameRecord *capacity;
} W3dNameVector;

typedef struct W3dNameList {
    unsigned char unknown_00[4];
    W3dNameVector names;
    unsigned int limit;
} W3dNameList;

void w3d_handle_storage_release(void *storage);
void w3d_actor_member_delete_backend(void *block);
void *w3d_memcpy_802eee50(void *dest, const void *source, unsigned int size, ...);
W3dGString *w3d_string_assign(W3dGString *string, const char *text);

}

/* Vector member constructor: empty range. */
static inline void w3d_name_vector_init(W3dNameVector *names)
{
    names->capacity = 0;
    names->end = 0;
    names->begin = 0;
}

extern "C" {

W3dNameList *w3d_name_list_init_800c4598(W3dNameList *list)
{
    w3d_name_vector_init(&list->names);
    list->limit = 0;
    return list;
}

void w3d_name_list_destroy_800c45b8(W3dNameList *list, int flags)
{
    if (list->names.begin)
        w3d_handle_storage_release(list->names.begin);
    if (flags & 1)
        w3d_actor_member_delete_backend(list);
}

void w3d_name_list_clear_800c4604(W3dNameList *list)
{
    W3dNameVector *names = &list->names;
    W3dNameRecord *first;
    W3dNameRecord *last;
    int count;
    list->limit = 0;
    first = list->names.begin;
    last = names->end;
    count = last - first;
    w3d_memcpy_802eee50(first, last, (char *)names->end - (char *)last);
    names->end -= count;
}

unsigned int w3d_name_list_count_800c4660(W3dNameList *list)
{
    return list->names.end - list->names.begin;
}

#if 0 /* 0x800c4a7c: the output string and front pointer swap registers (r9/r4); 6 attempts. */
int w3d_name_list_pop_front_800c4a7c(W3dNameList *list, W3dGString *out)
{
    W3dNameVector *names = &list->names;
    int result = 0x80004005;
    if (list->names.begin != names->end) {
        W3dNameRecord *first;
        w3d_string_assign(out, list->names.begin->text);
        first = list->names.begin;
        if (first + 1 != names->end)
            w3d_memcpy_802eee50(first, first + 1, (char *)names->end - (char *)(first + 1));
        names->end--;
        result = 0;
    }
    return result;
}
#endif

int w3d_name_list_pop_back_800c4d38(W3dNameList *list, W3dGString *out)
{
    W3dNameVector *names = &list->names;
    if (list->names.begin == names->end)
        return 0x80004005;
    w3d_string_assign(out, (names->end - 1)->text);
    names->end--;
    return 0;
}

int w3d_name_list_back_800c4d9c(W3dNameList *list, W3dGString *out)
{
    if (list->names.begin == list->names.end)
        return 0x80004005;
    w3d_string_assign(out, (list->names.end - 1)->text);
    return 0;
}

void w3d_name_list_freeze_800c4de8(W3dNameList *list)
{
    list->limit = w3d_name_list_count_800c4660(list);
}

void w3d_name_list_trim_800c4e18(W3dNameList *list)
{
    if (list->limit <= w3d_name_list_count_800c4660(list)) {
        W3dNameVector *names = &list->names;
        while (w3d_name_list_count_800c4660(list) > list->limit)
            names->end--;
    }
}

}
