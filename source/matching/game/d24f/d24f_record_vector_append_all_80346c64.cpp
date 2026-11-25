// GWMP8P rev0 0x80346c64. Appends every record of the source vector with push_back, then clears it.
// Real STLport 4.5.3 vector over polymorphic records (d24f_timed_record.h, -fvtable-thunks);
// the element class is inferred from its table and field copies. Replaces an unevidenced allocator shape (d28r).
#include "compat/stlport_sn_oom.h"
#include <vector>
#include "game/d24f/d24f_timed_record.h"
typedef D24fTimedFloat2 D24fElem;
extern "C" void d24f_record_vector_append_all_80346c64(std::vector<D24fElem> *self, std::vector<D24fElem> *src) {
    for (D24fElem *it = src->begin(); it != src->end(); ++it)
        self->push_back(*it);
    src->clear();
}
