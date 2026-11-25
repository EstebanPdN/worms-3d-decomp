// d24d: integer list used by the team tables (start, finish, storage end). Same
// layout and growth rule at several sites: the new capacity count is
// max(used + 1, used + used / 2), with `used` in bytes, then multiplied by 4;
// the old contents are copied up to min(new bytes, used) and released. erase
// moves the tail down with memcpy, as in the original.
#ifndef D24D_INT_LIST_H
#define D24D_INT_LIST_H
extern "C" void *memcpy(void *, const void *, unsigned);
extern "C" void *d24d_storage_allocate_80212fd4(unsigned);
extern "C" void d24d_storage_release_802134fc(void *);
template<class T> inline const T &d24d_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline const T &d24d_min(const T &a, const T &b) { return b < a ? b : a; }
struct d24d_IntList {
    int *start, *finish, *end;
    bool empty() { return start == finish; }
    int *begin() { return start; }
    void erase(int *p) {
        if (p + 1 != finish) memcpy(p, p + 1, (char *)finish - (char *)(p + 1));
        --finish;
    }
    void grow() {
        unsigned used = (char *)finish - (char *)start;
        unsigned bytes = d24d_max<int>(used + 1, used + used / 2) * 4;
        int *p = (int *)d24d_storage_allocate_80212fd4(bytes);
        if (start) {
            memcpy(p, start, d24d_min(bytes, used));
            d24d_storage_release_802134fc(start);
        }
        start = p;
        finish = (int *)((char *)p + used);
        end = (int *)((char *)p + bytes);
    }
    void push_back(const int &value) {
        if (finish == end) grow();
        *finish = value;
        ++finish;
    }
};
#endif
