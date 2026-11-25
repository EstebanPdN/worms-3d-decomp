// Inferred names and layouts from constructor8025f1b8/factory8025f0e4.
// 256-byte factory; primary base28, secondary base184, derived scalars and held members.
// No construction or allocation is performed by this recovered destructor.
extern "C" void fn_802afc40(void*,int);
extern void*vt_8041bb30[],*vt_8041bb80[];
struct F16bIface{void**table;};
struct F16bHeld{F16bIface*p;~F16bHeld(){if(p)((void(*)(F16bIface*))p->table[4])(p);}};
struct F16bPanel{char prefix[180];void**table;~F16bPanel(){fn_802afc40(this,0);}};
struct F16bPrimary_8015ff2c{void**table;char unknown[24];~F16bPrimary_8015ff2c();};
struct F16bOwner:F16bPrimary_8015ff2c,F16bPanel{unsigned derivedScalars[4];F16bHeld first;F16bHeld slots[3];F16bHeld beforeLast,last;unsigned trailing;~F16bOwner();};
F16bOwner::~F16bOwner(){F16bPanel::table=vt_8041bb30;F16bPrimary_8015ff2c::table=vt_8041bb80;}
