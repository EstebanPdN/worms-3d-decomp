#include "w3d_ptr.h"
#line 1 "d24f_timed_record_sweep_80345330.cpp"
// GWMP8P rev0 0x80345330. Timed record sweep: fires due records, appends to the destination when
// the flag is set, and erases them. Real STLport 4.5.3 vector over polymorphic records
// (d24f_timed_record.h, -fvtable-thunks); element class inferred. Replaces an unevidenced allocator shape (d28r).
#include "compat/stlport_sn_oom.h"
#include <vector>
#include "game/d24f/d24f_timed_record.h"
typedef D24fTimedWord2 D24fElem;
extern "C" int w3d_message_post_current(Ptr32<void>);
struct D24fFlags { char pad[188]; unsigned flags; };
extern Ptr32<D24fFlags> lbl_804b1788;
extern "C" void d24f_timed_record_sweep_80345330(Ptr32<_STL::vector < D24fElem >> self, Ptr32<_STL::vector < D24fElem >> dest, unsigned now) {
    Ptr32<D24fElem> it = self->begin();
    while (it != self->end()) {
        if (it->due <= now) {
            w3d_message_post_current(it->fire());
            if (lbl_804b1788->flags & 0x8000)
                dest->push_back(*it);
            self->erase(it);
        } else
            ++it;
    }
}


