// Partial ownership/container views and destructor roles inferred from instructions.
struct Item{void**v;};struct Held{Item*p;~Held(){if(p)((void(*)(Item*))p->v[4])(p);}void clear(){((void(*)(Item*))p->v[4])(p);p=0;}};
template<class T,int N>struct Array{T values[N];};
struct Point{Held first,second;char unknown[52];~Point(){if(first.p)first.clear();if(second.p)second.clear();}};
struct F1pPanelBase_8015ff2c{void**table;char unknown[24];~F1pPanelBase_8015ff2c();};
struct F1pPanelMember_802afc40{char unknown[180];void*secondary;~F1pPanelMember_802afc40();};
struct F1pPanelOwner:F1pPanelBase_8015ff2c,F1pPanelMember_802afc40{Held child;Held rows[42];char unknown384[56];Held triple[3];Held field452;Held pair0[2],pair1[2],pair2[2],pair3[2];Held field488;char unknown492[72];Held field564;char unknown568[8];Point points[2];Held field696,field700;char unknown704[24];Held field728,field732;~F1pPanelOwner();};
extern char vt_8041bc00[],vt_8041bc50[];
F1pPanelOwner::~F1pPanelOwner(){secondary=vt_8041bc00;table=(void**)vt_8041bc50;}
