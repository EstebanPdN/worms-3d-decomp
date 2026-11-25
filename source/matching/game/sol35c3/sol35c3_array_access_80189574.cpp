// Partial GC32 array-header and owner layouts observed in original instructions.
typedef unsigned int u32;
typedef unsigned short u16;
struct Header {
    u32 unknown0;
    u16 kind;
    unsigned char unknown6[18];
    u32 count;
    u16 locks;
    u16 unknown30;
};
struct ArrayRef;
extern "C" void *fn_801ef048(ArrayRef *, u32, u32, u32);
struct ArrayRef {
    Header *header;
    u32 size() const { return header->count; }
    void *lock(u32 count, u32 stride, u32 mode) {
        Header *h = header;
        if (h->kind == 1 && count == h->count) {
            ++h->locks;
            return h + 1;
        }
        return fn_801ef048(this, count, stride, mode);
    }
};
struct Resource {
    unsigned char unknown0[88];
    ArrayRef selected;
    unsigned char unknown92[4];
    ArrayRef fallback;
};
struct Link { unsigned char unknown0[48]; Resource *resource; };
struct Owner { unsigned char unknown0[168]; Link *link; };
extern "C" void *sol35c3_array_access_80189574(Owner *self)
{
    Resource *resource = self->link->resource;
    u32 count = resource->selected.size();
    void *data = resource->selected.lock(count, 4, 2);
    if (count == 0) {
        u32 fallbackCount = resource->fallback.size();
        if (fallbackCount == 0)
            return 0;
        data = resource->selected.lock(fallbackCount, 4, 0);
    }
    return data;
}
