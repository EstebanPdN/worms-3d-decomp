/* Register-level reconstruction. Valid records have count <= 7 and do not
 * overlap input bytes. Names and table ownership are provisional. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 value, pad; u16 a,b,c; const u8 *key; } Entry;
typedef struct { u8 prefix[0x52]; u8 count; u8 reserved[5]; Entry entries[7]; u8 tail[16]; } Record;
typedef char tterra_cw46_entry_size[(sizeof(Entry)==12)?1:-1];
typedef char tterra_cw46_record_size[(sizeof(Record)==188)?1:-1];
extern Record tterra_cw46_table_804a7df8[];
static u16 expand(u8 x) { return ((u16)x << 8) | ((u16)x << 1); }
u32 tterra_cw46_add_record(Record *r, const u8 *p) {
    Entry *e;
    if (r->count >= 7) return 0;
    e = &r->entries[r->count];
    e->value = p[3]; e->a = expand(p[0]); e->b = expand(p[1]); e->c = expand(p[2]); e->key = p;
    ++r->count; return 1;
}
u32 tterra_cw46_remove_record(Record *r, const u8 *p) {
    u32 i, j;
    for (i = 0; i < r->count; ++i) if (r->entries[i].key == p) {
        for (j = i; j + 1 < r->count; ++j) r->entries[j] = r->entries[j+1];
        --r->count; return 1;
    }
    return 0;
}
u32 tterra_cw46_add(u32 i, const u8 *p) { return tterra_cw46_add_record(&tterra_cw46_table_804a7df8[i & 255], p); }
u32 tterra_cw46_remove(u32 i, const u8 *p) { return tterra_cw46_remove_record(&tterra_cw46_table_804a7df8[i & 255], p); }
/* Higher forwarding entries; provisional register-level signatures. */
u32 tterra_cw46_outer_add(u32 i, const u8 *p) { return tterra_cw46_add(i, p); }
u32 tterra_cw46_outer_remove(u32 i, const u8 *p) { return tterra_cw46_remove(i, p); }
/* One relationship iteration from 80331718..803318b0. Offsets are observed;
 * callers must supply live endpoints and a valid retained object. */
typedef struct { u8 pad[28]; u8 index; } Endpoint;
typedef struct Node {
    struct Node *next; u8 pad0[16]; float gain; u8 pad1[4];
    u8 value, saved_index; u8 pad2[2]; Endpoint *a, *b;
    u32 flags; u8 pad3[8]; u8 data[4];
} Node;
typedef char node_size_check[(sizeof(Node)==56)?1:-1];
void tterra_cw46_step(Node *n) {
    u8 a=n->a->index, b=n->b->index;
    if (!(n->flags & 0x80000000u)) {
        if (a==255 || b==255) return;
        n->data[0]=(u8)(int)(127.0f*n->gain);
        n->data[1]=(u8)(int)((float)n->value*n->gain);
        n->data[2]=0;
        if (n->flags & 1) { n->data[3]=b; tterra_cw46_outer_add(a,n->data); }
        else { n->data[3]=a; tterra_cw46_outer_add(b,n->data); }
        n->flags |= 0x80000000u;
    } else if (a==255 || b==255) {
        if ((a!=255 && a==n->saved_index) || (b!=255 && b==n->saved_index))
            tterra_cw46_outer_remove(n->saved_index,n->data);
        n->flags &= 0x7fffffffu;
    } else {
        n->data[0]=(u8)(int)(127.0f*n->gain);
        n->data[1]=(u8)(int)((float)n->value*n->gain);
        n->data[2]=0;
    }
}

/* Bounded traversal corresponding to 80331710..803318bc. */
void tterra_cw46_walk(Node *head) {
    while (head) { tterra_cw46_step(head); head = head->next; }
}
