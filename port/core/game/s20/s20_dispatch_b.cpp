#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_dispatch_b.c"
/* Handler-table dispatch loops over a record's targets. */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20HandlerW;

int w3d_s20_dispatch_early_table_801a38c8(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(self + 24);
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 20);
    Ptr32<Ptr32<char>> cursor = (Ptr32<Ptr32<char>>)(record + 32);
    Ptr32<Ptr32<char>> end = cursor + *(Ptr32<unsigned int>)(record + 24);
    for (; cursor != end; cursor++) {
        Ptr32<char> entry = *cursor;
        int status = ((S20HandlerW)table[*(Ptr32<unsigned short>)(entry + 6)])(self, entry);
        if (status < 0)
            return status;
    }
    return 0;
}

int w3d_s20_dispatch_counted_801a4b4c(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 20);
    unsigned int count = *(Ptr32<unsigned int>)(record + 24);
    Ptr32<Ptr32<char>> items = (Ptr32<Ptr32<char>>)(record + 32);
    unsigned int i = 0;
    if (i < count) {
        Ptr32<Ptr32<char>> cursor = items;
        do {
            Ptr32<char> entry = *cursor;
            i++;
            cursor++;
            ((S20HandlerW)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(entry + 6)])(self, entry);
        } while (i < count);
    }
    return 0;
}

int w3d_s20_dispatch_counted_801a4bc4(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 20);
    unsigned int count = *(Ptr32<unsigned int>)(record + 24);
    Ptr32<Ptr32<char>> items = (Ptr32<Ptr32<char>>)(record + 32);
    unsigned int i = 0;
    if (i < count) {
        Ptr32<Ptr32<char>> cursor = items;
        do {
            Ptr32<char> entry = *cursor;
            i++;
            cursor++;
            ((S20HandlerW)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(entry + 6)])(self, entry);
        } while (i < count);
    }
    return 0;
}

}
