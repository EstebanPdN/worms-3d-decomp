#include "w3d_ptr.h"
#line 1 "d24b_remove_id_8008db88.cpp"
/* Remove a target id from the id list at +344 (0x8008db88): compares each entry with
 * the id of the message (0x801190d0), closes the gap with 0x802eee50 and shrinks the
 * list on the first match. Field and type names are inferred. */
extern "C" int w3d_get_801190d0(Ptr32<void>);
extern "C" Ptr32<void> w3d_copy_802eee50(...);
struct IdList {
    Ptr32<int> begin; Ptr32<int> end; Ptr32<int> capacity;
    Ptr32<int> End() const { return end; }
    void Erase(Ptr32<int> p) {
        Ptr32<int> next = p + 1;
        if (next != end) {
            Ptr32<int> last = end - 1;
            w3d_copy_802eee50(w3d::VA(p), w3d::VA(next), (Ptr32<char>)last - (Ptr32<char>)p);
        }
        end--;
    }
};
struct Owner { char unknown00[344]; IdList ids; };
extern "C" void w3d_d24b_remove_id_8008db88(Ptr32<Owner> self, Ptr32<void> message)
{
    for (Ptr32<int> p = self->ids.begin; p != self->ids.End(); p++) {
        if (*p == w3d_get_801190d0(message)) {
            self->ids.Erase(p);
            return;
        }
    }
}


