// GWMP8P rev0 0x8003671c. Returns the first pool item that is not in use, or
// creates and appends a new one.
extern "C" unsigned char *w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(void *);
extern "C" void *memcpy(void *, const void *, ...);
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned int &smaller(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct Item { char unknown00[16]; Item(); };
extern "C" int w3d_auto_80036c8c(Item *);
struct Storage {
    unsigned char *begin, *end, *capacity;
    unsigned int size() const { return (unsigned int)(end - begin) >> 2; }
    int count() const { return (Item **)end - (Item **)begin; }
    Item *&operator[](unsigned int i) { return ((Item **)begin)[i]; }
    void push(Item *const &value) {
        if (end == capacity) {
            unsigned int used = end - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned int allocated = larger(next, grown) * 4;
            unsigned char *fresh = w3d_handle_storage_allocate(allocated);
            if (begin) {
                memcpy(fresh, begin, smaller(allocated, used));
                w3d_handle_storage_release(begin);
            }
            begin = fresh; end = fresh + used; capacity = fresh + allocated;
        }
        *(Item **)end = value;
        end += 4;
    }
};
struct Pool { int unknown0; Storage items; };
extern "C" Item *w3d_d46a_pool_find_or_create_8003671c(Pool *self)
{
    Item *found = 0;
    unsigned int i = 0;
    if (i < self->items.size()) {
        do {
            if (!w3d_auto_80036c8c(self->items[i])) {
                found = self->items[i];
                break;
            }
            i++;
        } while (i < (unsigned int)self->items.count());
    }
    if (!found) {
        found = new Item;
        self->items.push(found);
    }
    return found;
}
