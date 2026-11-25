#include "w3d_ptr.h"
#line 1 "f1p_destroy_panels_80264f60.cpp"
// Partial ownership/container views and destructor roles inferred from instructions.
struct Item{Ptr32<Ptr32<void>> v;};struct Held{Ptr32<Item> p;~Held(){if(p)((Ptr32<void (Ptr32<Item>)>)p->v[4])(p);}void clear(){((Ptr32<void (Ptr32<Item>)>)p->v[4])(p);p=0;}};
template<class T,int N>struct Array{T values[N];};
struct Point{Held first,second;char unknown[52];~Point(){if(first.p)first.clear();if(second.p)second.clear();}};
struct F1pPanelBase_8015ff2c{Ptr32<Ptr32<void>> table;char unknown[24];~F1pPanelBase_8015ff2c();};
struct F1pPanelMember_802afc40{char unknown[180];Ptr32<void> secondary;~F1pPanelMember_802afc40();};
struct F1pPanelOwner:F1pPanelBase_8015ff2c,F1pPanelMember_802afc40{Held child __attribute__((aligned(__alignof__(F1pPanelBase_8015ff2c)), aligned(__alignof__(F1pPanelMember_802afc40))));Held rows[42];char unknown384[56];Held triple[3];Held field452;Held pair0[2],pair1[2],pair2[2],pair3[2];Held field488;char unknown492[72];Held field564;char unknown568[8];Point points[2];Held field696,field700;char unknown704[24];Held field728,field732;~F1pPanelOwner();};
extern char vt_8041bc00[],vt_8041bc50[];
F1pPanelOwner::~F1pPanelOwner(){secondary=vt_8041bc00;table=(Ptr32<Ptr32<void>>)vt_8041bc50;}


