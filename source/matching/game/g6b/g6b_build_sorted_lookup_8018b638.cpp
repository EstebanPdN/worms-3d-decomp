typedef unsigned int Word;
typedef unsigned short Half;
struct LookupEntry { Half value, key, index; };
struct HeaderView { char unknown00[24]; Word count; };
struct PageView { char unknown00[40]; HeaderView *values; };
struct LookupData { char unknown00[28]; void *pages; Word unknown20; HeaderView *keys; };
struct LookupView { char unknown00[36]; LookupData *data; char unknown28[28]; LookupEntry *entries; Word count; };
extern "C" void fn_801fe240(void *);
extern "C" void *fn_801fe220(Word);
extern "C" int fn_8018b628(const void *,const void *);
extern "C" void fn_802ede44(void *,Word,Word,int (*)(const void *,const void *));
extern "C" int g6b_build_sorted_lookup_8018b638(LookupView *self) {
    if (self->entries) fn_801fe240(self->entries);
    HeaderView *keys = self->data->keys;
    self->count = keys->count - 1;
    self->entries = (LookupEntry *)fn_801fe220(self->count * sizeof(LookupEntry));
    Word index = 0;
    PageView **pages = (PageView **)((char *)self->data->pages+32);
    Half *key = (Half *)((char *)keys+34);
    Word offset = 0;
    while (index < self->count) {
        Half code = *key++;
        ++index;
        PageView *page = *(PageView **)((char *)pages+(code>>6 & 0x3fc));
        HeaderView *values = page->values;
        Half value = *(Half *)((code & 255)*2 + (char *)values+32);
        ((LookupEntry *)((char *)self->entries+offset))->key = code;
        ((LookupEntry *)((char *)self->entries+offset))->value = value;
        ((LookupEntry *)((char *)self->entries+offset))->index = index;
        offset += sizeof(LookupEntry);
    }
    fn_802ede44(self->entries,self->count,sizeof(LookupEntry),fn_8018b628);
    return 0;
}
