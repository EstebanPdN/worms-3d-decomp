#include "w3d_ptr.h"
#line 1 "f10c_destroy_text_owner_802523b4.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
// Inferred native member cleanup; no constructor is defined for the owner.
extern "C" void fn_8020c5c4(Ptr32<void>);extern "C" void fn_80341588(Ptr32<void>);
extern Ptr32<void> vt_8041bab8[];
struct F10c_802523b4_Text{Ptr32<char> text;~F10c_802523b4_Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct F10c_802523b4_Base_801ea138{Ptr32<Ptr32<void>> table;char unknown[ 20-4 ];~F10c_802523b4_Base_801ea138();};
struct F10c_802523b4_Owner:F10c_802523b4_Base_801ea138{char unknown20[24] __attribute__((aligned(__alignof__(F10c_802523b4_Base_801ea138))));F10c_802523b4_Text text44;F10c_802523b4_Text text48;char unknown52[20];F10c_802523b4_Text text72;F10c_802523b4_Text text76;F10c_802523b4_Text text80;F10c_802523b4_Text text84;F10c_802523b4_Text text88;F10c_802523b4_Text text92;F10c_802523b4_Text text96;F10c_802523b4_Text text100;F10c_802523b4_Text text104;F10c_802523b4_Text text108;F10c_802523b4_Text text112;F10c_802523b4_Text text116;F10c_802523b4_Text text120;F10c_802523b4_Text text124;F10c_802523b4_Text text128;F10c_802523b4_Text text132;F10c_802523b4_Text text136;F10c_802523b4_Text text140;F10c_802523b4_Text text144;F10c_802523b4_Text text148;char unknown152[12];~F10c_802523b4_Owner();static void operator delete(void*);};
F10c_802523b4_Owner::~F10c_802523b4_Owner(){table=(Ptr32<Ptr32<void>>)vt_8041bab8;}



