/* Shared pool allocation, ownership transfer and initialization sequence. */
typedef void (*S9PoolRefMethod)(void *);
typedef int (*S9PoolInitMethod)(void *, void *, int);
#define FIELD(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned short lbl_804ab644;
extern unsigned short *lbl_804ab640;
extern char *lbl_804ab634;
extern int lbl_804a89d8[];
extern int fn_80190438(void *, void *, int);
int s9_pool_acquire_80182a24(void *source, void **out, int priority)
{
    unsigned short available = lbl_804ab644;
    int index;
    int offset;
    char *base;
    void *entry;
    int result;
    if (!available) return 0x80004005;
    if (priority == 255) priority = FIELD(source, unsigned char, 25);
    index = lbl_804ab640[(unsigned short)(available - 1)];
    base = lbl_804ab634;
    lbl_804ab644 = available - 1;
    offset = index * 176;
    entry = (void *)(offset + (int)base);
    if (entry) FIELD(FIELD(entry,void *,0), S9PoolRefMethod,12)(entry);
    if (*out) FIELD(FIELD(*out,void *,0), S9PoolRefMethod,16)(*out);
    *out = entry;
    result = FIELD(FIELD((void *)(offset + (int)base),void *,0), S9PoolInitMethod,40)(entry,source,priority);
    if (result < 0) return result;
    lbl_804a89d8[FIELD(source, unsigned char,24)]++;
    return fn_80190438(source,out,255);
}
