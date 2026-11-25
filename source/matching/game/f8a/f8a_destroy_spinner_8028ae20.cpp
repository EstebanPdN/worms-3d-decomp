// Inferred complete 328-byte spinner storage; bases at 0/28, interfaces 224 through 280.
// Observed interface ownership at offsets 212,216,220.
struct Iface{void**table;};
struct Held{Iface*pointer;~Held(){if(pointer)((void(*)(Iface*))pointer->table[4])(pointer);}};
struct Pair{Held elements[2];};
struct F8aBase_8015ff2c {void**table;char unknown4[24];~F8aBase_8015ff2c();}; struct F8aMember_802afc40{char unknown[180];void**baseTable;~F8aMember_802afc40();};struct F8aSpinner_8028ae20:F8aBase_8015ff2c,F8aMember_802afc40{char unknown212[12];Held first,second;Held small[3];Held a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;char unknown284[44];~F8aSpinner_8028ae20();};
extern void*vt_8041c090[],*vt_8041c0e0[];
F8aSpinner_8028ae20::~F8aSpinner_8028ae20(){baseTable=vt_8041c090;table=vt_8041c0e0;}
