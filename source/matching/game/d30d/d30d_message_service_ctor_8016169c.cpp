// GWMP8P rev0 0x8016169c. Message service constructor: registers itself, reads
// MRS.MaxMessages (default 500) and MRS.MaxInterests (default 4096), allocates the
// message table, the interest pool (20-byte records) and four counted per-id list
// arrays, then sizes the free pool vector at 0x80455244 and fills it with pointers
// into the interest pool. The vector's growth computes capacity from byte counts,
// as observed in the other vectors of this family (0x801f2e60). Names are inferred.
extern void *operator new[](unsigned);
extern "C" {
void *alloc_80212fd4(unsigned);
void free_802134fc(void *);
void *memcpy(void *, const void *, unsigned, ...);
void *memmove(void *, const void *, unsigned);
int read_int_80206920(const char *, unsigned *);
int base_801628b0(void *);
void block_init_801626c8(void *);
}
struct Block {
    void *vt; int u4[4];
    Block();
};
extern char vt_804117f8[];
inline Block::Block() { vt = vt_804117f8; block_init_801626c8(this); }
struct Slot { int a, b, c; Slot() { a = b = c = 0; } ~Slot(); };
static inline const int &maximum(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned &minimum(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
struct Blocks;
extern Blocks blocks_80455244;
struct Blocks {
    unsigned char *begin_, *end_, *cap_;
    Block **pos(unsigned n) { return (Block **)begin_ + n; }
    void erase(Block **first, Block **last) { int n = (char *)last - (char *)first; memcpy(first, last, end_ - (unsigned char *)last); end_ -= n; }
    void insert(Block **at, unsigned cnt, Block *const &value, unsigned size, unsigned usedv) {
        if ((unsigned char *)(at + cnt) > cap_) {
            int room = (Block **)cap_ - at;
            unsigned used = usedv;
            int capb = cap_ - begin_;
            int need = capb + (cnt - room);
            int grow = capb + ((unsigned)capb >> 1);
            unsigned bytes = maximum(need, grow) * 4;
            unsigned char *data = (unsigned char *)alloc_80212fd4(bytes);
            if (begin_) { memcpy(data, begin_, minimum(bytes, used)); free_802134fc(begin_); }
            at = (Block **)data + size;
            begin_ = data; end_ = data + used; cap_ = data + bytes;
        }
        if ((unsigned char *)at == end_) {
            for (unsigned i = 0; i < cnt; i++) ((Block **)end_)[i] = value;
            end_ += cnt * 4;
        } else {
            Block *v = value;
            memmove(at + cnt, at, end_ - (unsigned char *)at);
            end_ += cnt * 4;
            for (unsigned i = 0; i < cnt; i++) *at = v;
        }
    }
    void resize(unsigned n, Block *const &value) {
        unsigned used = end_ - begin_;
        unsigned size = (int)used >> 2;
        if (n < size) erase((Block **)begin_ + n, (Block **)end_);
        else { unsigned cnt = n - size; insert((Block **)end_, cnt, value, size, used); }
    }
};

extern unsigned maxMessages_804ab49c;
extern unsigned maxInterests_804ab498;
extern struct Service *self_804ab4a0;
extern Block **table_804ab4a4;
extern Block *pool_804ab4a8;
extern Slot *s0_804ab4ac, *s1_804ab4b0, *s2_804ab4b4, *s3_804ab4b8;
extern char name1_803a48b0[], name2_803a48c0[], vt_804117c8[];
struct Service { void *vt; Service(); };
extern "C" Service *d30d_message_service_ctor_8016169c(Service *self) {
    base_801628b0(self);
    self->vt = vt_804117c8;
    self_804ab4a0 = self;
    if (read_int_80206920(name1_803a48b0, &maxMessages_804ab49c) < 0) maxMessages_804ab49c = 500;
    if (read_int_80206920(name2_803a48c0, &maxInterests_804ab498) < 0) maxInterests_804ab498 = 4096;
    Block *value;
    Block **pv = &value;
    table_804ab4a4 = new Block *[maxMessages_804ab49c];
    pool_804ab4a8 = new Block[maxInterests_804ab498];
    s0_804ab4ac = new Slot[maxMessages_804ab49c];
    s1_804ab4b0 = new Slot[maxMessages_804ab49c];
    s2_804ab4b4 = new Slot[maxMessages_804ab49c];
    s3_804ab4b8 = new Slot[maxMessages_804ab49c];
    for (unsigned i = 0; i < maxMessages_804ab49c; i++) table_804ab4a4[i] = 0;
    value = 0;
    blocks_80455244.resize(maxInterests_804ab498, *pv);
    for (unsigned j = 0; j < maxInterests_804ab498; j++) *(Block **)(blocks_80455244.begin_ + (j << 2)) = pool_804ab4a8 + j;
    return self;
}
