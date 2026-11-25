#include "w3d_ptr.h"
#line 1 "f1p_destroy_text_arrays_802a43ec.cpp"
// Partial class fields and native C++ destruction inferred from original instructions.
struct F1p_802a43ec_Iface{Ptr32<Ptr32<void>> table;};struct F1p_802a43ec_Held{Ptr32<F1p_802a43ec_Iface> p;~F1p_802a43ec_Held(){if(p)((Ptr32<void (Ptr32<F1p_802a43ec_Iface>)>)p->table[4])(p);}};
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F1p_802a43ec_Text{Ptr32<char> text;~F1p_802a43ec_Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1p_802a43ec_Row{char unknown[60];F1p_802a43ec_Text first;int unknown64;F1p_802a43ec_Text second;};struct F1p_802a43ec_Record{int unknown0;F1p_802a43ec_Held first;int unknown8;F1p_802a43ec_Held second;};
struct F1p_802a43ec_Base_8015ff2c{Ptr32<Ptr32<void>> table;char unknown[24];~F1p_802a43ec_Base_8015ff2c();};
struct F1p_802a43ec_Member_802afc40{char unknown[180];Ptr32<void> secondary;~F1p_802a43ec_Member_802afc40();};
struct F1p_802a43ec_Owner:F1p_802a43ec_Base_8015ff2c,F1p_802a43ec_Member_802afc40{F1p_802a43ec_Held field212[3] __attribute__((aligned(__alignof__(F1p_802a43ec_Base_8015ff2c)), aligned(__alignof__(F1p_802a43ec_Member_802afc40))));F1p_802a43ec_Held field224;F1p_802a43ec_Held field228;F1p_802a43ec_Held field232;F1p_802a43ec_Held field236;char unknown240[4];F1p_802a43ec_Held field244[2];F1p_802a43ec_Held field252[2];F1p_802a43ec_Held field260[2];F1p_802a43ec_Held field268[2];F1p_802a43ec_Held field276[8];char unknown308[68];F1p_802a43ec_Held field376;F1p_802a43ec_Held field380;F1p_802a43ec_Held field384;F1p_802a43ec_Held field388;F1p_802a43ec_Held field392;F1p_802a43ec_Held field396;F1p_802a43ec_Held field400;char unknown404[16];F1p_802a43ec_Text field420[10];F1p_802a43ec_Text field460[10];F1p_802a43ec_Text field500[10];F1p_802a43ec_Text field540[10];~F1p_802a43ec_Owner();};
extern char vt_8041c4c0[],vt_8041c470[];
F1p_802a43ec_Owner::~F1p_802a43ec_Owner(){secondary=vt_8041c470;table=(Ptr32<Ptr32<void>>)vt_8041c4c0;}


