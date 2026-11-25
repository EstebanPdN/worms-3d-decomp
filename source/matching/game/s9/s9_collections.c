/* Typed views of observed pointer collections and record bytes. */
typedef struct S9KeyedItem { void *unknown; int key; } S9KeyedItem;
typedef struct S9PointerRange { S9KeyedItem **begin; S9KeyedItem **end; } S9PointerRange;
int s9_remove_by_key_801625dc(S9PointerRange *items, const S9KeyedItem *key)
{
    S9KeyedItem **end = items->end;
    S9KeyedItem **entry = items->begin;
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
extern S9ByteRecord *lbl_80456f14[];
int s9_set_record_bytes_8017df5c(int unused, int index, char value25, char value24)
{
    index[lbl_80456f14]->byte25 = value25;
    index[lbl_80456f14]->byte24 = value24;
    return 0;
}
int s9_get_record_bytes_8017df80(int unused, int index, unsigned char *value25, unsigned char *value24)
{
    *value25 = index[lbl_80456f14]->byte25;
    *value24 = index[lbl_80456f14]->byte24;
    return 0;
}
extern int lbl_804b00dc;
extern void * fn_802098fc(void *, int, int);
void s9_forward_global_80166fd0(int unused, int value)
{
    fn_802098fc(&lbl_804b00dc, value, 32);
}
typedef struct S9LookupInner { char unknown[52]; int handle; } S9LookupInner;
typedef struct S9LookupOuter { char unknown[128]; S9LookupInner *inner; } S9LookupOuter;
extern int *fn_801d0858(void *handle, int *found);
int s9_lookup_optional_80174074(S9LookupOuter *object)
{
    int found;
    int *result = fn_801d0858(object->inner->handle, &found);
    return found ? *result : 0;
}
