// d24d: range erase and clear for the integer list. The removed byte count is
// taken before the tail copy; clear passes the whole list, so the copy has
// length 0 and is still called, as in the original.
#ifndef D24D_INT_LIST_RANGE_H
#define D24D_INT_LIST_RANGE_H
#include "d24d_int_list.h"
struct d24d_RangeList : d24d_IntList {
    void erase(Ptr32<int> first, Ptr32<int> last) {
        unsigned removed = (Ptr32<char>)last - (Ptr32<char>)first;
        memcpy(first, last, (Ptr32<char>)finish - (Ptr32<char>)last);
        finish = (Ptr32<int>)((Ptr32<char>)finish - removed);
    }
    void clear() { erase(start, finish); }
};
#endif
