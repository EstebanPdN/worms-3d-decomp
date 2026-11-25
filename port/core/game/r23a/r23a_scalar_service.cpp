#include "w3d_ptr.h"
#line 1 "r23a_scalar_service.cpp"
// Observed GWMP8P rev0 PPC32 fields; complete class identities remain inferred.
extern "C" {
// Float at +64 precedes an embedded member at +68; total object size unknown.
struct ScalarMemberObject { unsigned char unknown[64]; float scalar; unsigned char member[1]; };
// The helper receives the forwarded scalar in f1; its behavior remains external.
void member_query_8012629c(Ptr32<void>, float);
void w3d_r23a_set_scalar_query_8003e25c(Ptr32<ScalarMemberObject> object, float scalar) { object->scalar = scalar; member_query_8012629c(object->member, scalar); }
struct ServiceObject { Ptr32<void> dispatch; };
extern unsigned char dispatch_8040e248[];
extern int active_service_804aa828;
void service_destroy_801628ec(Ptr32<ServiceObject>, Ptr32<void>);
void w3d_r23a_service_shutdown_80029298(Ptr32<ServiceObject> object, Ptr32<void> arg_r4) { object->dispatch = dispatch_8040e248; active_service_804aa828 = 0; service_destroy_801628ec(object, arg_r4); }
}


