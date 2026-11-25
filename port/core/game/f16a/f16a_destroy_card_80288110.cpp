#include "w3d_ptr.h"
#line 1 "f16a_destroy_card_80288110.cpp"
// Inferred partial external card owner; never constructed by this unit.
// Base prefix28 and padding through871 describe only external storage.
// Native held-member arrays at872 and904 reproduce original reverse cleanup.
// No complete allocation/layout, original names, or portable integration claimed.
struct F16aCardIface{Ptr32<Ptr32<void>> table;};
struct F16aCardHeld{Ptr32<F16aCardIface> p;~F16aCardHeld(){if(p)((Ptr32<void (Ptr32<F16aCardIface>)>)p->table[4])(p);}void clear(){if(p)((Ptr32<void (Ptr32<F16aCardIface>)>)p->table[4])(p);p=0;}};
struct F16aCardBase_801628ec{Ptr32<Ptr32<void>> table;char unknown[24];~F16aCardBase_801628ec();};
struct F16aCardOwner:F16aCardBase_801628ec{char unknown28[844] __attribute__((aligned(__alignof__(F16aCardBase_801628ec))));F16aCardHeld icons[8],labels[5],held924;unsigned unknown928;F16aCardHeld held932,held936,held940,held944,held948,held952;char unknown956[28];F16aCardHeld animation,model;~F16aCardOwner();};
extern char table_8041c050[];extern "C" void fn_8028aab0(Ptr32<F16aCardOwner>);
F16aCardOwner::~F16aCardOwner(){table=(Ptr32<Ptr32<void>>)table_8041c050;fn_8028aab0(this);for(int i=0;i<8;++i)icons[i].clear();for(int i=0;i<5;++i)labels[i].clear();held924.clear();}


