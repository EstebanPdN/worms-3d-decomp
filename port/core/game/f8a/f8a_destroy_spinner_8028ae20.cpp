#include "w3d_ptr.h"
#line 1 "f8a_destroy_spinner_8028ae20.cpp"
// Inferred complete 328-byte spinner storage; bases at 0/28, interfaces 224 through 280.
// Observed interface ownership at offsets 212,216,220.
struct Iface{Ptr32<Ptr32<void>> table;};
struct Held{Ptr32<Iface> pointer;~Held(){if(pointer)((Ptr32<void (Ptr32<Iface>)>)pointer->table[4])(pointer);}};
struct Pair{Held elements[2];};
struct F8aBase_8015ff2c {Ptr32<Ptr32<void>> table;char unknown4[24];~F8aBase_8015ff2c();}; struct F8aMember_802afc40{char unknown[180];Ptr32<Ptr32<void>> baseTable;~F8aMember_802afc40();};struct F8aSpinner_8028ae20:F8aBase_8015ff2c,F8aMember_802afc40{char unknown212[12] __attribute__((aligned(__alignof__(F8aBase_8015ff2c)), aligned(__alignof__(F8aMember_802afc40))));Held first,second;Held small[3];Held a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;char unknown284[44];~F8aSpinner_8028ae20();};
extern Ptr32<void> vt_8041c090[]; extern Ptr32<void> vt_8041c0e0[];
F8aSpinner_8028ae20::~F8aSpinner_8028ae20(){baseTable=vt_8041c090;table=vt_8041c0e0;}


