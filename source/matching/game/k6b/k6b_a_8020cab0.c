struct K6bPair { int first; int second; };
struct K6bHashTable {
    unsigned short *buckets;
    unsigned int mask;
    unsigned int count;
    struct K6bPair entries;
    struct K6bPair spare;
};
extern unsigned int w3d_s21_power_of_two_b_8020ca70(unsigned int value);
extern void *w3d_heap_allocate_entry_b(unsigned int size);
extern void *memset(void *target, int value, unsigned int size);
extern void fn_8035c9f8(struct K6bPair *list, int size);
static inline void k6b_pair_clear_second(struct K6bPair *pair, int zero)
{
    pair->second = zero;
}
struct K6bHashTable *w3d_k6b_hash_table_construct_8020cab0(struct K6bHashTable *self, unsigned int capacity)
{
    int zero = 0;
    struct K6bPair *entries = &self->entries;
    unsigned int count;
    volatile char pad[8];
    self->entries.first = zero;
    k6b_pair_clear_second(entries, zero);
    k6b_pair_clear_second(&self->spare, zero);
    count = w3d_s21_power_of_two_b_8020ca70(capacity);
    self->count = count;
    self->mask = count - 1;
    self->buckets = (unsigned short *)w3d_heap_allocate_entry_b(count * 2);
    memset(self->buckets, 0, self->count * 2);
    fn_8035c9f8(entries, 8);
    return self;
}
// desc: w3d_k6b_hash_table_construct_8020cab0: Appears to construct a table: clear +12/+16/+24, round the capacity to a power of two, store count and mask, allocate and zero 2-byte buckets and reserve 8 entries.
