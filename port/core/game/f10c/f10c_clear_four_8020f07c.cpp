#include "w3d_ptr.h"
#line 1 "f10c_clear_four_8020f07c.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
extern "C" void fn_8020c5c4(Ptr32<void>);extern "C" void fn_80341588(Ptr32<void>);extern "C" void fn_80210990(Ptr32<void>,int);extern "C" void fn_801fe1f8(Ptr32<void>);extern Ptr32<void> vt_804192d8[];extern Ptr32<void> vt_80418490[];
struct F10c_8020f07c_Iface{Ptr32<Ptr32<void>> table;};struct F10c_8020f07c_Held{Ptr32<F10c_8020f07c_Iface> p;~F10c_8020f07c_Held(){if(p)((Ptr32<void (Ptr32<F10c_8020f07c_Iface>)>)p->table[4])(p);}};
struct F10c_8020f07c_Text{Ptr32<char> text;~F10c_8020f07c_Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct F10c_8020f07c_Base{Ptr32<Ptr32<void>> table;char unknown[16];~F10c_8020f07c_Base(){table=(Ptr32<Ptr32<void>>)vt_80418490;fn_80210990((Ptr32<char>)this+4,0);}};
struct F10c_8020f07c_Item:F10c_8020f07c_Base{F10c_8020f07c_Held first __attribute__((aligned(__alignof__(F10c_8020f07c_Base))));int unknown24;F10c_8020f07c_Held second;F10c_8020f07c_Text text;char unknown36[4];~F10c_8020f07c_Item(){table=(Ptr32<Ptr32<void>>)vt_804192d8;}static void operator delete(void*);};
extern "C" int f10c_clear_four_8020f07c(Ptr32<Ptr32<F10c_8020f07c_Item>> items){delete items[0];delete items[1];delete items[2];delete items[3];items[0]=0;items[1]=0;items[2]=0;items[3]=0;return 0;}


