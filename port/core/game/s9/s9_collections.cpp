#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9_collections.c"
/* Typed views of observed pointer collections and record bytes. */
typedef struct S9KeyedItem { Ptr32<void> unknown; int key; } S9KeyedItem;
typedef struct S9PointerRange { Ptr32<Ptr32<S9KeyedItem>> begin; Ptr32<Ptr32<S9KeyedItem>> end; } S9PointerRange;
int s9_remove_by_key_801625dc(Ptr32<S9PointerRange> items, Ptr32<const S9KeyedItem> key)
{
    Ptr32<Ptr32<S9KeyedItem>> end = items->end;
    Ptr32<Ptr32<S9KeyedItem>> entry = items->begin;
    if (entry == end) goto absent;
search:
    if ((*entry)->key != key->key) goto next;
    *entry = items->end[-1];
    items->end--;
    return 0;
next:
    entry++;
    if (entry != end) goto search;
absent:
    return 0x80004005;
}
typedef struct S9ByteRecord { char unknown[24]; unsigned char byte24; unsigned char byte25; } S9ByteRecord;
extern Ptr32<S9ByteRecord> lbl_80456f14[];
int s9_set_record_bytes_8017df5c(int unused, int index, char value25, char value24)
{
    index[lbl_80456f14]->byte25 = value25;
    index[lbl_80456f14]->byte24 = value24;
    return 0;
}
int s9_get_record_bytes_8017df80(int unused, int index, Ptr32<unsigned char> value25, Ptr32<unsigned char> value24)
{
    *value25 = index[lbl_80456f14]->byte25;
    *value24 = index[lbl_80456f14]->byte24;
    return 0;
}
extern int lbl_804b00dc;
extern Ptr32<void> fn_802098fc(Ptr32<void>, int, int);
void s9_forward_global_80166fd0(int unused, int value)
{
    fn_802098fc(&lbl_804b00dc, value, 32);
}
typedef struct S9LookupInner { char unknown[52]; int handle; } S9LookupInner;
typedef struct S9LookupOuter { char unknown[128]; Ptr32<S9LookupInner> inner; } S9LookupOuter;
extern Ptr32<int> fn_801d0858(Ptr32<void> handle, Ptr32<int> found);
int s9_lookup_optional_80174074(Ptr32<S9LookupOuter> object)
{
    int found;
    Ptr32<int> result = fn_801d0858(w3d::G(object->inner->handle), &found);
    return found ? *result : 0;
}

}
