#include "w3d_ptr.h"
#line 1 "f8a_destroy_image_8028cea4.cpp"
// Image: complete 236-byte storage; bases at 0 and 28, held interfaces at 212/216/220.
// Observed interface ownership at offsets 212,216,220.
struct Iface{Ptr32<Ptr32<void>> table;};
struct Held{Ptr32<Iface> pointer;~Held(){if(pointer)((Ptr32<void (Ptr32<Iface>)>)pointer->table[4])(pointer);}};
struct F8aBase_8015ff2c {Ptr32<Ptr32<void>> table;char unknown4[24];~F8aBase_8015ff2c();}; struct F8aMember_802afc40{char unknown[180];Ptr32<Ptr32<void>> baseTable;~F8aMember_802afc40();};struct F8aImage_8028cea4:F8aBase_8015ff2c,F8aMember_802afc40{Held single __attribute__((aligned(__alignof__(F8aBase_8015ff2c)), aligned(__alignof__(F8aMember_802afc40))));Held pair[2];char unknown224[12];~F8aImage_8028cea4();};
extern Ptr32<void> vt_8041c120[]; extern Ptr32<void> vt_8041c170[];
F8aImage_8028cea4::~F8aImage_8028cea4(){baseTable=vt_8041c120;table=vt_8041c170;}


