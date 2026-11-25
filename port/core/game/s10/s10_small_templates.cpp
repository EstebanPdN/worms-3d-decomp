#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10_small_templates.c"
typedef struct S10Service S10Service;
typedef Ptr32<int (Ptr32<S10Service>, Ptr32<void>)> S10ServiceMethod;
struct S10Service { Ptr32<S10ServiceMethod> vtable; };
extern Ptr32<S10Service> fn_8020b648(Ptr32<void>);
int w3d_s10_service_forward_8020b680(Ptr32<void> object)
{
    Ptr32<S10Service> service = fn_8020b648(object);
    return service->vtable[21](service, object);
}

typedef struct S10OwnedEntry { char reserved[40]; Ptr32<void> owner; } S10OwnedEntry;
extern Ptr32<void> fn_801fe1d8(int);
extern Ptr32<S10OwnedEntry> fn_80208c0c(Ptr32<void>);
extern int fn_80208f48(Ptr32<S10OwnedEntry>, int, int);
Ptr32<S10OwnedEntry> w3d_s10_create_entry_80208aac(Ptr32<void> owner)
{
    Ptr32<S10OwnedEntry> entry = fn_80208c0c(fn_801fe1d8(44));
    entry->owner = owner;
    fn_80208f48(entry, 0, 0);
    return entry;
}
extern int fn_802047e0(Ptr32<void>, Ptr32<const void>, int);
void w3d_s10_write_double_80204224(Ptr32<void> writer, double value)
{
    double temporary = value;
    fn_802047e0(writer, &temporary, 8);
}

}
