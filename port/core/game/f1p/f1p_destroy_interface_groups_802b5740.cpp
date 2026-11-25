#include "w3d_ptr.h"
#line 1 "f1p_destroy_interface_groups_802b5740.cpp"
// Partial class fields and native C++ destruction inferred from original instructions.
struct F1p_802b5740_Iface{Ptr32<Ptr32<void>> table;};struct F1p_802b5740_Held{Ptr32<F1p_802b5740_Iface> p;~F1p_802b5740_Held(){if(p)((Ptr32<void (Ptr32<F1p_802b5740_Iface>)>)p->table[4])(p);}};
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F1p_802b5740_Text{Ptr32<char> text;~F1p_802b5740_Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1p_802b5740_Row{char unknown[60];F1p_802b5740_Text first;int unknown64;F1p_802b5740_Text second;};struct F1p_802b5740_Record{int unknown0;F1p_802b5740_Held first;int unknown8;F1p_802b5740_Held second;};
struct F1p_802b5740_Base_8015ff2c{Ptr32<Ptr32<void>> table;char unknown[24];~F1p_802b5740_Base_8015ff2c();};
struct F1p_802b5740_Member_802afc40{char unknown[180];Ptr32<void> secondary;~F1p_802b5740_Member_802afc40();};
struct F1p_802b5740_Owner:F1p_802b5740_Base_8015ff2c,F1p_802b5740_Member_802afc40{F1p_802b5740_Held field212 __attribute__((aligned(__alignof__(F1p_802b5740_Base_8015ff2c)), aligned(__alignof__(F1p_802b5740_Member_802afc40))));F1p_802b5740_Held field216;char unknown220[16];F1p_802b5740_Held field236;F1p_802b5740_Held field240;char unknown244[24];F1p_802b5740_Held field268;F1p_802b5740_Held field272;F1p_802b5740_Held field276;F1p_802b5740_Held field280;char unknown284[32];F1p_802b5740_Held field316[2];F1p_802b5740_Held field324[3];F1p_802b5740_Held field336[3];F1p_802b5740_Held field348[3];F1p_802b5740_Held field360;F1p_802b5740_Held field364[2];F1p_802b5740_Held field372;F1p_802b5740_Held field376[2];F1p_802b5740_Held field384[2];F1p_802b5740_Held field392[2];F1p_802b5740_Held field400;~F1p_802b5740_Owner();};
extern char vt_8041c790[],vt_8041c740[];
F1p_802b5740_Owner::~F1p_802b5740_Owner(){secondary=vt_8041c740;table=(Ptr32<Ptr32<void>>)vt_8041c790;}


