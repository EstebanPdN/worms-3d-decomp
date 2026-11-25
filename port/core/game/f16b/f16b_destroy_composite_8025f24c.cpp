#include "w3d_ptr.h"
#line 1 "f16b_destroy_composite_8025f24c.cpp"
// Inferred names and layouts from constructor8025f1b8/factory8025f0e4.
// 256-byte factory; primary base28, secondary base184, derived scalars and held members.
// No construction or allocation is performed by this recovered destructor.
extern "C" void fn_802afc40(Ptr32<void>,int);
extern Ptr32<void> vt_8041bb30[]; extern Ptr32<void> vt_8041bb80[];
struct F16bIface{Ptr32<Ptr32<void>> table;};
struct F16bHeld{Ptr32<F16bIface> p;~F16bHeld(){if(p)((Ptr32<void (Ptr32<F16bIface>)>)p->table[4])(p);}};
struct F16bPanel{char prefix[180];Ptr32<Ptr32<void>> table;~F16bPanel(){fn_802afc40(this,0);}};
struct F16bPrimary_8015ff2c{Ptr32<Ptr32<void>> table;char unknown[24];~F16bPrimary_8015ff2c();};
struct F16bOwner:F16bPrimary_8015ff2c,F16bPanel{unsigned derivedScalars[4] __attribute__((aligned(__alignof__(F16bPrimary_8015ff2c)), aligned(__alignof__(F16bPanel))));F16bHeld first;F16bHeld slots[3];F16bHeld beforeLast,last;unsigned trailing;~F16bOwner();};
F16bOwner::~F16bOwner(){F16bPanel::table=vt_8041bb30;F16bPrimary_8015ff2c::table=vt_8041bb80;}


