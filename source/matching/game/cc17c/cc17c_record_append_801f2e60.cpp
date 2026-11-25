/* Same growth shape as the admitted pointer-vector append 0x8020abe0 (cx10b): byte-addressed
 * storage whose capacity is computed from the used byte count (the original multiplies that count
 * by the element size, kept as observed). Elements are 12-byte records: two words and a 16-bit
 * value (observed stores). Inferred names. */
extern "C" void *allocate_80212fd4(unsigned int);
extern "C" void free_802134fc(void *);
extern "C" void *copy_802eee50(void *, const void *, unsigned int, ...);
static inline const int &maximum(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &minimum(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct Cc17cRecord { int first; int second; short third; };
struct Cc17cRecords {
    unsigned char *begin, *end, *capacity;
    void push(const Cc17cRecord &value) {
        if (end == capacity) {
            unsigned int used = end - begin;
            unsigned int bytes = maximum((int)used + 1, (int)(used + (used >> 1))) * 12;
            unsigned char *data = (unsigned char *)allocate_80212fd4(bytes);
            if (begin) { copy_802eee50(data, begin, minimum(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; capacity = data + bytes;
        }
        *(Cc17cRecord *)end = value; end += 12;
    }
};
/* Observed: flag word at +32, record vector at +40. */
struct Cc17cRecordOwner { unsigned char opaque[32]; unsigned int flags; unsigned char pad36[4]; Cc17cRecords records; };
extern "C" int w3d_cc17c_record_append_801f2e60(Cc17cRecordOwner *self, int first, int second, short third)
{
    Cc17cRecord record;
    record.first = first;
    record.second = second;
    record.third = third;
    self->records.push(record);
    self->flags &= ~0x20000000;
    return 0;
}
