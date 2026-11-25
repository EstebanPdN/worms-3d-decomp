#include "w3d_ptr.h"
#line 1 "d24f_record_vector_append_all_80346a04.cpp"
// GWMP8P rev0 0x80346a04. Appends every record of the source vector with push_back, then clears it.
// Real STLport 4.5.3 vector over polymorphic records (d24f_timed_record.h, -fvtable-thunks);
// the element class is inferred from its table and field copies. Replaces an unevidenced allocator shape (d28r).
#include "compat/stlport_sn_oom.h"
#include <vector>
#include "game/d24f/d24f_timed_record.h"
typedef D24fTimedFloat D24fElem;
extern "C" void d24f_record_vector_append_all_80346a04(Ptr32<_STL::vector < D24fElem >> self, Ptr32<_STL::vector < D24fElem >> src) {
    for (Ptr32<D24fElem> it = src->begin(); it != src->end(); ++it)
        self->push_back(*it);
    src->clear();
}


