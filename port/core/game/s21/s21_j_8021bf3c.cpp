#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_j_8021bf3c.c"
struct S21Entry;
struct S21EntryMethods { Ptr32<void (Ptr32<struct S21Entry>)> reserved[4]; Ptr32<void (Ptr32<struct S21Entry>)> release; };
struct S21Entry { Ptr32<struct S21EntryMethods> methods; char pad[20]; unsigned start; char pad1[20]; int state; };
struct S21Timing { char pad[52]; unsigned limit; };
struct S21Slot { char pad[52]; Ptr32<struct S21Entry> entry; Ptr32<struct S21Timing> timing; };
struct S21Clock { char pad[52]; unsigned now; };
struct S21Inner { char pad[24]; Ptr32<struct S21Slot> slot; };
struct S21Object { char pad[36]; Ptr32<struct S21Inner> inner; };
extern Ptr32<struct S21Clock> fn_80165254(void);
extern void fn_8021dd04(Ptr32<struct S21Entry>);
void w3d_s21_expire_entry_8021bf3c(Ptr32<struct S21Object> self)
{
    Ptr32<struct S21Slot> slot = self->inner->slot;
    Ptr32<struct S21Entry> entry = slot->entry;
    if (entry) {
        if (entry->state == 1) goto go;
        if (entry->state == 2) goto go;
        return;
go:
            if (fn_80165254()->now - entry->start > slot->timing->limit) {
                Ptr32<struct S21Entry> old;
                fn_8021dd04(entry);
                old = slot->entry;
                slot->entry = 0;
                if (old)
                    old->methods->release(old);
            }
    }
}

}
