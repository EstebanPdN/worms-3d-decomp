/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Shared pool allocation, ownership transfer and initialization sequence. */
typedef void (*S9PoolRefMethod)(void *);
typedef int (*S9PoolInitMethod)(void *, void *, int);
#define FIELD(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned short lbl_804ab644;
extern unsigned short *lbl_804ab640;
extern char *lbl_804ab634;
extern int lbl_804a89d8[];
extern int fn_80190438(void *, void *, int);
extern unsigned short lbl_804ab668;
extern unsigned short *lbl_804ab664;
extern char *lbl_804ab658;
extern unsigned short lbl_804ab690;
extern unsigned short *lbl_804ab68c;
extern char *lbl_804ab680;
extern unsigned short lbl_804b18b8;
extern unsigned short *lbl_804b18b4;
extern char *lbl_804b18b0;

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

int s9_pool_acquire_801849ec(void *source, void **out, int priority)
{
    unsigned short available = lbl_804ab668;
    int index;
    int offset;
    char *base;
    void *entry;
    int result;
    if (!available) return 0x80004005;
    if (priority == 255) priority = FIELD(source, unsigned char, 25);
    index = lbl_804ab664[(unsigned short)(available - 1)];
    base = lbl_804ab658;
    lbl_804ab668 = available - 1;
    offset = index * 172;
    entry = (void *)(offset + (int)base);
    if (entry) FIELD(FIELD(entry,void *,0), S9PoolRefMethod,12)(entry);
    if (*out) FIELD(FIELD(*out,void *,0), S9PoolRefMethod,16)(*out);
    *out = entry;
    result = FIELD(FIELD((void *)(offset + (int)base),void *,0), S9PoolInitMethod,40)(entry,source,priority);
    if (result < 0) return result;
    lbl_804a89d8[FIELD(source, unsigned char,24)]++;
    return fn_80190438(source,out,255);
}

int s9_pool_acquire_80188344(void *source, void **out, int priority)
{
    unsigned short available = lbl_804ab690;
    int index;
    int offset;
    char *base;
    void *entry;
    int result;
    if (!available) return 0x80004005;
    if (priority == 255) priority = FIELD(source, unsigned char, 25);
    index = lbl_804ab68c[(unsigned short)(available - 1)];
    base = lbl_804ab680;
    lbl_804ab690 = available - 1;
    offset = index * 172;
    entry = (void *)(offset + (int)base);
    if (entry) FIELD(FIELD(entry,void *,0), S9PoolRefMethod,12)(entry);
    if (*out) FIELD(FIELD(*out,void *,0), S9PoolRefMethod,16)(*out);
    *out = entry;
    result = FIELD(FIELD((void *)(offset + (int)base),void *,0), S9PoolInitMethod,40)(entry,source,priority);
    if (result < 0) return result;
    lbl_804a89d8[FIELD(source, unsigned char,24)]++;
    return fn_80190438(source,out,255);
}

int s9_pool_acquire_8018afb0(void *source, void **out, int priority)
{
    unsigned short available = lbl_804b18b8;
    int index;
    int offset;
    char *base;
    void *entry;
    int result;
    if (!available) return 0x80004005;
    if (priority == 255) priority = FIELD(source, unsigned char, 25);
    index = lbl_804b18b4[(unsigned short)(available - 1)];
    base = lbl_804b18b0;
    lbl_804b18b8 = available - 1;
    offset = index * 276;
    entry = (void *)(offset + (int)base);
    if (entry) FIELD(FIELD(entry,void *,0), S9PoolRefMethod,12)(entry);
    if (*out) FIELD(FIELD(*out,void *,0), S9PoolRefMethod,16)(*out);
    *out = entry;
    result = FIELD(FIELD((void *)(offset + (int)base),void *,0), S9PoolInitMethod,40)(entry,source,priority);
    if (result < 0) return result;
    lbl_804a89d8[FIELD(source, unsigned char,24)]++;
    return fn_80190438(source,out,255);
}
