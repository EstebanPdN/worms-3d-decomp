#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_prop_8002190c.c"
extern int s8_property_read_800fc5dc(Ptr32<Ptr32<const char>>, Ptr32<void>);
struct S19Task { char pad0[4]; int done; char pad8[12]; float launch; };

int s19_read_launch_velocity_8002190c(Ptr32<struct S19Task> p) {
    Ptr32<const char> name = "AI.LaunchVelocity";
    s8_property_read_800fc5dc(&name, &p->launch);
    p->done = 1;
    return 0;
}

}
