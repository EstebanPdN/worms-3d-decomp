#include "w3d_ptr.h"
#line 1 "f12b_clear_global_controls_801fd238.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
extern "C" void fn_8020c5c4(Ptr32<void>);extern "C" void fn_80341588(Ptr32<void>);extern "C" void fn_80210990(Ptr32<void>,int);extern "C" void fn_801fe1f8(Ptr32<void>);extern Ptr32<void> vt_804192f8[];extern Ptr32<void> vt_804192d8[];extern Ptr32<void> vt_80418490[];
struct F12b_Clear1748_Iface{Ptr32<Ptr32<void>> table;};struct F12b_Clear1748_Held{Ptr32<F12b_Clear1748_Iface> p;void reset(Ptr32<F12b_Clear1748_Iface> next){if(p)((Ptr32<void (Ptr32<F12b_Clear1748_Iface>)>)p->table[4])(p);p=next;}~F12b_Clear1748_Held(){if(p)((Ptr32<void (Ptr32<F12b_Clear1748_Iface>)>)p->table[4])(p);}};
struct F12b_Clear1748_Text{Ptr32<char> text;~F12b_Clear1748_Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct F12b_Clear1748_Base{Ptr32<Ptr32<void>> table;char unknown[16];~F12b_Clear1748_Base(){table=(Ptr32<Ptr32<void>>)vt_80418490;fn_80210990((Ptr32<char>)this+4,0);}};
struct F12b_Clear1748_Item:F12b_Clear1748_Base{F12b_Clear1748_Held first __attribute__((aligned(__alignof__(F12b_Clear1748_Base))));int unknown24;F12b_Clear1748_Held second;F12b_Clear1748_Text text;char unknown36[4];~F12b_Clear1748_Item(){table=(Ptr32<Ptr32<void>>)vt_804192d8;}static void operator delete(void*);};
struct F12b_Clear1748_Small:F12b_Clear1748_Base{F12b_Clear1748_Held held __attribute__((aligned(__alignof__(F12b_Clear1748_Base))));F12b_Clear1748_Text text;char unknown28[4];~F12b_Clear1748_Small(){table=(Ptr32<Ptr32<void>>)vt_804192f8;}static void operator delete(void*);};
extern Ptr32<F12b_Clear1748_Item> lbl_8045e9ac[];
extern Ptr32<F12b_Clear1748_Item> lbl_8045e9b0[];
extern Ptr32<F12b_Clear1748_Item> lbl_8045e9b4[];
extern Ptr32<F12b_Clear1748_Item> lbl_8045e9b8[];
extern Ptr32<F12b_Clear1748_Item> lbl_8045e99c[];
extern Ptr32<F12b_Clear1748_Item> lbl_8045e9a0[];
extern Ptr32<F12b_Clear1748_Item> lbl_8045e9a4[];
extern Ptr32<F12b_Clear1748_Item> lbl_8045e9a8[];
struct F12b_Clear1748_Group{Ptr32<F12b_Clear1748_Iface> items[9];Ptr32<F12b_Clear1748_Iface> pair[2];void clear(){for(unsigned i=0;i<3;++i){Ptr32<F12b_Clear1748_Iface> p=items[i];if(p)((Ptr32<void (Ptr32<F12b_Clear1748_Iface>)>)p->table[4])(p);items[i]=0;}Ptr32<Ptr32<F12b_Clear1748_Iface>> slot=pair;for(unsigned i=0;i<2;++i,++slot){Ptr32<F12b_Clear1748_Iface> p=*slot;if(p)((Ptr32<void (Ptr32<F12b_Clear1748_Iface>)>)p->table[4])(p);*slot=0;}}};extern F12b_Clear1748_Group lbl_8045e944[];
extern Ptr32<F12b_Clear1748_Iface> lbl_8045e968[];
extern F12b_Clear1748_Group lbl_8045e970[];
extern Ptr32<F12b_Clear1748_Iface> lbl_8045e994[];
extern F12b_Clear1748_Held lbl_804b05e0;
extern F12b_Clear1748_Held lbl_804b05e4;
extern F12b_Clear1748_Held lbl_804b05e8;
extern Ptr32<F12b_Clear1748_Small> lbl_804b05f8;
extern Ptr32<F12b_Clear1748_Small> lbl_804b05fc;
extern "C" int f12b_clear_globals_801fd238(){delete lbl_8045e9ac[0];delete lbl_8045e9ac[1];delete lbl_8045e9ac[2];delete lbl_8045e9ac[3];lbl_8045e9ac[0]=0;lbl_8045e9ac[1]=0;lbl_8045e9ac[2]=0;lbl_8045e9ac[3]=0;delete lbl_8045e99c[0];delete lbl_8045e99c[1];delete lbl_8045e99c[2];delete lbl_8045e99c[3];lbl_8045e99c[0]=0;lbl_8045e99c[1]=0;lbl_8045e99c[2]=0;lbl_8045e99c[3]=0;lbl_8045e944[0].clear();lbl_8045e970[0].clear();delete lbl_804b05f8;delete lbl_804b05fc;lbl_804b05e0.reset(0);lbl_804b05e4.reset(0);lbl_804b05e8.reset(0);return 0;}


