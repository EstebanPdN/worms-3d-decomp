// Partial class fields and native C++ destruction inferred from original instructions.
struct F1p_802c2184_Iface{void**table;};struct F1p_802c2184_Held{F1p_802c2184_Iface*p;~F1p_802c2184_Held(){if(p)((void(*)(F1p_802c2184_Iface*))p->table[4])(p);}};
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct F1p_802c2184_Text{char*text;~F1p_802c2184_Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1p_802c2184_Row{char unknown[60];F1p_802c2184_Text first;int unknown64;F1p_802c2184_Text second;};struct F1p_802c2184_Record{int unknown0;F1p_802c2184_Held first;int unknown8;F1p_802c2184_Held second;};
struct F1p_802c2184_Base_8015ff2c{void**table;char unknown[24];~F1p_802c2184_Base_8015ff2c();};
struct F1p_802c2184_Owner:F1p_802c2184_Base_8015ff2c{F1p_802c2184_Held field28;F1p_802c2184_Held field32;F1p_802c2184_Held field36;F1p_802c2184_Held field40;F1p_802c2184_Held field44;F1p_802c2184_Held field48;F1p_802c2184_Held field52;F1p_802c2184_Held field56;char unknown60[176];F1p_802c2184_Held field236;char unknown240[4];F1p_802c2184_Held field244;F1p_802c2184_Text field248;F1p_802c2184_Text field252;F1p_802c2184_Text field256;F1p_802c2184_Text field260;char unknown264[72];F1p_802c2184_Held field336;F1p_802c2184_Held field340;F1p_802c2184_Held field344;F1p_802c2184_Held field348;F1p_802c2184_Held field352;F1p_802c2184_Held field356;F1p_802c2184_Held field360;~F1p_802c2184_Owner();};
extern char vt_8041c8e0[];
F1p_802c2184_Owner::~F1p_802c2184_Owner(){table=(void**)vt_8041c8e0;}
