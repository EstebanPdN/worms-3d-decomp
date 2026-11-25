extern "C" void clear_table_80005398(void *);
extern "C" void clear_bucket_8000532c(void *);
extern "C" void finish_node_8034144c();
extern "C" void free_node_80015264(void *);
struct Node { ~Node() { finish_node_8034144c(); } void operator delete(void *p) { free_node_80015264(p); } };
struct Tail {
    unsigned char pad[0x800c]; Node *first,*second; unsigned unknown, state; int sentinel; unsigned result;
    unsigned char bucket[16], gap[20]; unsigned short low,high; unsigned begin,end;
    void clear_range() { end=begin; }
    void reset() {
        clear_range(); delete first; first=0; delete second; second=0;
        state=0; sentinel=-1; clear_bucket_8000532c(bucket); result=0; low=0; high=0x7fff;
    }
};
extern "C" void tterra_z36_path_80004394(void *p) {
    clear_table_80005398((char *)p+4); clear_table_80005398((char *)p+0x4008);
    ((Tail *)p)->reset();
}
