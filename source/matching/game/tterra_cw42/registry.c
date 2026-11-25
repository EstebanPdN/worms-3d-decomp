/* Register-level reconstruction. Valid records have count <= 7 and do not
 * overlap input bytes. Names and table ownership are provisional. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 value, pad; u16 a,b,c; const u8 *key; } Entry;
typedef struct { u8 prefix[0x52]; u8 count; u8 reserved[5]; Entry entries[7]; u8 tail[16]; } Record;
typedef char tterra_cw42_entry_size[(sizeof(Entry)==12)?1:-1];
typedef char tterra_cw42_record_size[(sizeof(Record)==188)?1:-1];
extern Record tterra_cw42_table_804a7df8[];
static u16 expand(u8 x) { return ((u16)x << 8) | ((u16)x << 1); }
u32 tterra_cw42_add_record(Record *r, const u8 *p) {
    Entry *e;
    if (r->count >= 7) return 0;
    e = &r->entries[r->count];
    e->value = p[3]; e->a = expand(p[0]); e->b = expand(p[1]); e->c = expand(p[2]); e->key = p;
    ++r->count; return 1;
}
u32 tterra_cw42_remove_record(Record *r, const u8 *p) {
    u32 i, j;
    for (i = 0; i < r->count; ++i) if (r->entries[i].key == p) {
        for (j = i; j + 1 < r->count; ++j) r->entries[j] = r->entries[j+1];
        --r->count; return 1;
    }
    return 0;
}
u32 tterra_cw42_add(u32 i, const u8 *p) { return tterra_cw42_add_record(&tterra_cw42_table_804a7df8[i & 255], p); }
u32 tterra_cw42_remove(u32 i, const u8 *p) { return tterra_cw42_remove_record(&tterra_cw42_table_804a7df8[i & 255], p); }
