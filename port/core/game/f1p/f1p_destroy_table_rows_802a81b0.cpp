#include "w3d_ptr.h"
#line 1 "f1p_destroy_table_rows_802a81b0.cpp"
// Partial class fields and native C++ destruction inferred from original instructions.
struct F1p_802a81b0_Iface{Ptr32<Ptr32<void>> table;};struct F1p_802a81b0_Held{Ptr32<F1p_802a81b0_Iface> p;~F1p_802a81b0_Held(){if(p)((Ptr32<void (Ptr32<F1p_802a81b0_Iface>)>)p->table[4])(p);}};
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F1p_802a81b0_Text{Ptr32<char> text;~F1p_802a81b0_Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1p_802a81b0_Row{char unknown[60];F1p_802a81b0_Text first;int unknown64;F1p_802a81b0_Text second;};struct F1p_802a81b0_Record{int unknown0;F1p_802a81b0_Held first;int unknown8;F1p_802a81b0_Held second;};
struct F1p_802a81b0_Base_8015ff2c{Ptr32<Ptr32<void>> table;char unknown[24];~F1p_802a81b0_Base_8015ff2c();};
struct F1p_802a81b0_Member_802afc40{char unknown[180];Ptr32<void> secondary;~F1p_802a81b0_Member_802afc40();};
struct F1p_802a81b0_Owner:F1p_802a81b0_Base_8015ff2c,F1p_802a81b0_Member_802afc40{F1p_802a81b0_Held field212 __attribute__((aligned(__alignof__(F1p_802a81b0_Base_8015ff2c)), aligned(__alignof__(F1p_802a81b0_Member_802afc40))));F1p_802a81b0_Held field216;F1p_802a81b0_Held field220;char unknown224[20];F1p_802a81b0_Held field244;F1p_802a81b0_Held field248[3];char unknown260[8];F1p_802a81b0_Row field268[11];char unknown1060[16];F1p_802a81b0_Record field1076[15];char unknown1316[40];F1p_802a81b0_Held field1356;F1p_802a81b0_Held field1360;F1p_802a81b0_Held field1364[3];~F1p_802a81b0_Owner();};
extern char vt_8041c550[],vt_8041c500[];
F1p_802a81b0_Owner::~F1p_802a81b0_Owner(){secondary=vt_8041c500;table=(Ptr32<Ptr32<void>>)vt_8041c550;}


