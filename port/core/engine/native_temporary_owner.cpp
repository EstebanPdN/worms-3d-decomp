#include "w3d_ptr.h"
#line 1 "native_temporary_owner.cpp"
/* Reconstructed complete native wrappers. Names/types are inferred.
 * Return types explicitly preserve observed r3, including the allocation
 * result consumed by original caller80197db4. No state ownership claim. */
typedef unsigned int u32;
struct TemporaryOwner { Ptr32<void> data; };
extern "C" {
extern Ptr32<void> w3d_temporary_allocate(u32);
extern Ptr32<void> w3d_temporary_release(Ptr32<void>);
Ptr32<void> w3d_temporary_owner_allocate(Ptr32<TemporaryOwner> owner, u32 size)
{
    return owner->data = w3d_temporary_allocate((size + 31u) & ~31u);
}
Ptr32<void> w3d_temporary_owner_release(Ptr32<TemporaryOwner> owner)
{
    Ptr32<void> result = owner->data;
    if (result) {
        result = w3d_temporary_release(result);
        owner->data = 0;
    }
    return result;
}
}


