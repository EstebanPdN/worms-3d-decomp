// d24d: integer list used by the team tables (start, finish, storage end). Same
// layout and growth rule at several sites: the new capacity count is
// max(used + 1, used + used / 2), with `used` in bytes, then multiplied by 4;
// the old contents are copied up to min(new bytes, used) and released. erase
// moves the tail down with memcpy, as in the original.
#ifndef D24D_INT_LIST_H
#define D24D_INT_LIST_H
extern "C" Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, unsigned);
extern "C" Ptr32<void> d24d_storage_allocate_80212fd4(unsigned);
extern "C" void d24d_storage_release_802134fc(Ptr32<void>);
template<class T> inline const T &d24d_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline const T &d24d_min(const T &a, const T &b) { return b < a ? b : a; }
struct d24d_IntList {
    Ptr32<int> start; Ptr32<int> finish; Ptr32<int> end;
    bool empty() { return start == finish; }
    Ptr32<int> begin() { return start; }
    void erase(Ptr32<int> p) {
        if (p + 1 != finish) memcpy(p, p + 1, (Ptr32<char>)finish - (Ptr32<char>)(p + 1));
        --finish;
    }
    void grow() {
        unsigned used = (Ptr32<char>)finish - (Ptr32<char>)start;
        unsigned bytes = d24d_max<int>(used + 1, used + used / 2) * 4;
        Ptr32<int> p = (Ptr32<int>)d24d_storage_allocate_80212fd4(bytes);
        if (start) {
            memcpy(p, start, d24d_min(bytes, used));
            d24d_storage_release_802134fc(start);
        }
        start = p;
        finish = (Ptr32<int>)((Ptr32<char>)p + used);
        end = (Ptr32<int>)((Ptr32<char>)p + bytes);
    }
    void push_back(const int &value) {
        if (finish == end) grow();
        *finish = value;
        ++finish;
    }
};
#endif
