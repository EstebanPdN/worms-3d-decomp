// External receiver prefix only; no construction or allocation extent claimed.
extern "C" void clear_table_80005398(void *);
extern "C" void clear_bucket_8000532c(void *);
extern "C" void finish_node_8034144c();
extern "C" void free_node_80015264(void *);
struct F18cNodePrefix {
    ~F18cNodePrefix() { finish_node_8034144c(); }
    void operator delete(void *p) { free_node_80015264(p); }
};
struct F18cSearchPrefix {
    unsigned char unknown_0000[0x800c];
    F18cNodePrefix *first;
    F18cNodePrefix *second;
    unsigned unknown_8014;
    unsigned state;
    int sentinel;
    unsigned result;
    unsigned char bucket[16];
    unsigned char unknown_8034[20];
    unsigned short low;
    unsigned short high;
    struct Range {
        unsigned begin;
        unsigned end;
        void clear() { end = begin; }
    } range;
};
extern "C" void f18c_search_cleanup_80004394(F18cSearchPrefix *self) {
    clear_table_80005398((char *)self + 4);
    clear_table_80005398((char *)self + 0x4008);
    self->range.clear();
    delete self->first;
    self->first = 0;
    delete self->second;
    self->second = 0;
    self->state = 0;
    self->sentinel = -1;
    clear_bucket_8000532c(self->bucket);
    self->result = 0;
    self->low = 0;
    self->high = 0x7fff;
}
