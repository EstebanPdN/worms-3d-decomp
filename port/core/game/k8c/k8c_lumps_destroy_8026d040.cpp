#include "w3d_ptr.h"
#line 1 "k8c_lumps_destroy_8026d040.cpp"
struct K8cHeld { Ptr32<Ptr32<void>> vtable; };
struct K8cLumps;
extern "C" {
extern char w3d_vtable_8041bd20[];
extern Ptr32<K8cLumps> w3d_sdata_804abb7c;
void fn_8020c5c4(Ptr32<void> str);
void fn_80341588(Ptr32<void> str);
void fn_8015ff2c(Ptr32<void> self, int flags);
}
inline void k8c_release(Ptr32<K8cHeld> h) { if (h) ((Ptr32<void (Ptr32<K8cHeld>)>)h->vtable[4])(h); }
struct K8cLumps {
    Ptr32<void> vtable;
    char pad04[24];
    Ptr32<K8cHeld> held;
    char pad20[24];
    char name[4];
    char pad3c[12];
    Ptr32<K8cHeld> first;
    Ptr32<K8cHeld> second;
    int enabled;
};
extern "C" void w3d_k8c_lumps_destroy_8026d040(Ptr32<K8cLumps> self, int flags)
{
    self->vtable = w3d_vtable_8041bd20;
    w3d_sdata_804abb7c = 0;
    k8c_release(self->second);
    k8c_release(self->first);
    fn_8020c5c4(self->name);
    fn_80341588(self->name);
    k8c_release(self->held);
    fn_8015ff2c(self, flags);
}


