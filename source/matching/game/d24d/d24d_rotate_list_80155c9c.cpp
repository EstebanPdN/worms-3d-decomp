// d24d: 0x80155c9c (392 bytes). Rotate a worm's list: for a valid id, read the
// list index byte (+60) of the record from 0x800fc7f8 and, when that list (+100,
// 12 bytes each) is not empty, move its first value to the end. The byte is
// compared with -1 as an int, as in the original. Names are inferred.
#include "d24d_int_list.h"
struct d24d_Record {
    unsigned char unknown00[60];
    unsigned char list_index;            // +60
};
struct d24d_Queues {
    unsigned char unknown00[100];
    d24d_IntList lists[4];               // +100
};
extern "C" d24d_Record *d24d_record_800fc7f8(int);

extern "C" void d24d_rotate_list_80155c9c(d24d_Queues *self, int id) {
    if (id == -1) return;
    int index = d24d_record_800fc7f8(id)->list_index;
    if (index == -1) return;
    if (self->lists[index].empty()) return;
    int first = *self->lists[index].begin();
    self->lists[index].erase(self->lists[index].begin());
    self->lists[index].push_back(first);
}
