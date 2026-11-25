// Image: complete 236-byte storage; bases at 0 and 28, held interfaces at 212/216/220.
// Observed interface ownership at offsets 212,216,220.
struct Iface{void**table;};
struct Held{Iface*pointer;~Held(){if(pointer)((void(*)(Iface*))pointer->table[4])(pointer);}};
struct F8aBase_8015ff2c {void**table;char unknown4[24];~F8aBase_8015ff2c();}; struct F8aMember_802afc40{char unknown[180];void**baseTable;~F8aMember_802afc40();};struct F8aImage_8028cea4:F8aBase_8015ff2c,F8aMember_802afc40{Held single;Held pair[2];char unknown224[12];~F8aImage_8028cea4();};
extern void*vt_8041c120[],*vt_8041c170[];
F8aImage_8028cea4::~F8aImage_8028cea4(){baseTable=vt_8041c120;table=vt_8041c170;}
