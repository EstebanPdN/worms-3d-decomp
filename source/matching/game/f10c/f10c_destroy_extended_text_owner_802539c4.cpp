// Names, roles, types, qualifiers and layouts are inferred from original instructions.
// Inferred native member cleanup; no constructor is defined for the owner.
extern "C" void fn_8020c5c4(void*);extern "C" void fn_80341588(void*);
extern void*vt_8041ba90[];
struct F10c_802539c4_Iface{void**table;};struct F10c_802539c4_Held{F10c_802539c4_Iface*p;~F10c_802539c4_Held(){if(p)((void(*)(F10c_802539c4_Iface*))p->table[4])(p);}};
struct F10c_802539c4_Text{char*text;~F10c_802539c4_Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct F10c_802539c4_Base_802523b4{void**table;char unknown[ 164-4 ];~F10c_802539c4_Base_802523b4();};
struct F10c_802539c4_Owner:F10c_802539c4_Base_802523b4{char unknown164[32];F10c_802539c4_Text text196;char unknown200[4];F10c_802539c4_Text text204;F10c_802539c4_Text text208;F10c_802539c4_Text text212;F10c_802539c4_Text text216;char unknown220[8];F10c_802539c4_Text text228;F10c_802539c4_Held held232;char unknown236[4];F10c_802539c4_Text text240;char unknown244[40];F10c_802539c4_Text text284;char unknown288[44];F10c_802539c4_Text text332;char unknown336[4];F10c_802539c4_Text text340;F10c_802539c4_Text text344;F10c_802539c4_Text text348;F10c_802539c4_Text text352;F10c_802539c4_Text text356;F10c_802539c4_Text text360;char unknown364[4];F10c_802539c4_Text text368;F10c_802539c4_Text text372;F10c_802539c4_Text text376;F10c_802539c4_Text text380;F10c_802539c4_Text text384;char unknown388[20];F10c_802539c4_Text text408;F10c_802539c4_Text text412;F10c_802539c4_Text text416;char unknown420[4];F10c_802539c4_Text text424;F10c_802539c4_Text text428;F10c_802539c4_Text text432;F10c_802539c4_Text text436;F10c_802539c4_Text text440;F10c_802539c4_Text text444;char unknown448[96];~F10c_802539c4_Owner();static void operator delete(void*);};
F10c_802539c4_Owner::~F10c_802539c4_Owner(){table=(void**)vt_8041ba90;}

