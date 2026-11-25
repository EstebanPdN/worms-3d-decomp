#include "w3d_ptr.h"
#line 1 "f12b_destroy_hash_array_owner_802111a8.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
extern "C" void fn_8035c81c(Ptr32<void>);extern "C" void fn_802134fc(Ptr32<void>);extern "C" void fn_8020c5c4(Ptr32<void>);extern "C" void fn_80341588(Ptr32<void>);extern Ptr32<void> vt_80419668[]; extern Ptr32<void> vt_80419688[]; extern Ptr32<void> vt_80419700[];extern Ptr32<void> lbl_804b18fc;
extern "C" void fn_80210990(Ptr32<void>,int);struct F12bBase{Ptr32<Ptr32<void>> vt;char unknown[16];~F12bBase(){vt=vt_80419700;fn_80210990((Ptr32<char>)this+4,0);}};struct F12bSecond{Ptr32<Ptr32<void>> vt;~F12bSecond(){}};
struct F12bText304{Ptr32<char> text;~F12bText304(){fn_8020c5c4(this);fn_80341588(this);}};
struct F12bBuffer304{Ptr32<void> storage;unsigned words[2];~F12bBuffer304(){if(storage)fn_802134fc(storage);}};struct F12bHash{unsigned unknown;F12bBuffer304 buffer;unsigned words[3];~F12bHash(){fn_8035c81c(this);}};
struct F12bRecord304{Ptr32<void> storage;unsigned words[2];~F12bRecord304(){if(storage)fn_802134fc(storage);}};
struct F12bOwner304:F12bBase,F12bSecond{F12bText304 text24 __attribute__((aligned(__alignof__(F12bBase)), aligned(__alignof__(F12bSecond)))),text28,text32;F12bHash hash36,hash64;F12bRecord304 records[13];F12bHash hash248;~F12bOwner304();static void operator delete(void*);};
F12bOwner304::~F12bOwner304(){F12bSecond::vt=vt_80419668;F12bBase::vt=vt_80419688;lbl_804b18fc=0;}



