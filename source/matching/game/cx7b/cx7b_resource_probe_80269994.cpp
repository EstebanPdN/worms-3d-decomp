struct Cx7bProbeHeld;
struct Cx7bProbeVtable { void *unknown[4]; void (*release)(Cx7bProbeHeld *); };
struct Cx7bProbeHeld { Cx7bProbeVtable *vtable; };
// Empty constructor plus destructor describe the observed scoped release.
struct Cx7bProbeRef { Cx7bProbeHeld *held; Cx7bProbeRef():held(0) {} ~Cx7bProbeRef(){if(held) held->vtable->release(held);} };
struct Cx7bProbeOwner { char unknown00[496]; int ready; };
extern "C" void fn_8026b3f0(Cx7bProbeOwner *);
extern "C" int w3d_cx7b_resource_probe_80269994(void *,Cx7bProbeOwner *owner) {
 if(owner->ready==0) { Cx7bProbeRef result; fn_8026b3f0(owner); }
 return 0;
}
