// d24d: range erase and clear for the integer list. The removed byte count is
// taken before the tail copy; clear passes the whole list, so the copy has
// length 0 and is still called, as in the original.
#ifndef D24D_INT_LIST_RANGE_H
#define D24D_INT_LIST_RANGE_H
#include "d24d_int_list.h"
struct d24d_RangeList : d24d_IntList {
    void erase(int *first, int *last) {
        unsigned removed = (char *)last - (char *)first;
        memcpy(first, last, (char *)finish - (char *)last);
        finish = (int *)((char *)finish - removed);
    }
    void clear() { erase(start, finish); }
};
#endif
