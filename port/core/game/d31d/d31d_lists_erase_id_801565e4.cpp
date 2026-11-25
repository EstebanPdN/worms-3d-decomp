#include "w3d_ptr.h"
#line 1 "d31d_lists_erase_id_801565e4.cpp"
#include "../d24d/d24d_int_list.h"
struct Queue : d24d_IntList { Ptr32<int> last() { return finish; } };
struct Self { char pad[100]; Queue lists[4]; char pad2[236]; int enabled; };
extern "C" void w3d_d31d_lists_erase_id_801565e4(Ptr32<Self> self, int id) {
    if (!self->enabled) return;
    for (unsigned i = 0; i <= 3; i++) {
        Ptr32<int> p = self->lists[i].begin();
        if (p != self->lists[i].last()) {
            do {
                if (*p == id) { self->lists[i].erase(p); return; }
                ++p;
            } while (p != self->lists[i].last());
        }
    }
}


