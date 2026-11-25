#include "w3d_ptr.h"
#line 1 "cx7b_resource_probe_80269994.cpp"
struct Cx7bProbeHeld;
struct Cx7bProbeVtable { Ptr32<void> unknown[4]; Ptr32<void (Ptr32<Cx7bProbeHeld>)> release; };
struct Cx7bProbeHeld { Ptr32<Cx7bProbeVtable> vtable; };
// Empty constructor plus destructor describe the observed scoped release.
struct Cx7bProbeRef { Ptr32<Cx7bProbeHeld> held; Cx7bProbeRef():held(0) {} ~Cx7bProbeRef(){if(held) held->vtable->release(held);} };
struct Cx7bProbeOwner { char unknown00[496]; int ready; };
extern "C" void fn_8026b3f0(Ptr32<Cx7bProbeOwner>);
extern "C" int w3d_cx7b_resource_probe_80269994(Ptr32<void>,Ptr32<Cx7bProbeOwner> owner) {
 if(owner->ready==0) { Cx7bProbeRef result; fn_8026b3f0(owner); }
 return 0;
}


