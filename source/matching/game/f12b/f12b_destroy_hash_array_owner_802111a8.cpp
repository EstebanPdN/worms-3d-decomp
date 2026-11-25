// Names, roles, types, qualifiers and layouts are inferred from original instructions.
extern "C" void fn_8035c81c(void*);extern "C" void fn_802134fc(void*);extern "C" void fn_8020c5c4(void*);extern "C" void fn_80341588(void*);extern void*vt_80419668[],*vt_80419688[],*vt_80419700[];extern void*lbl_804b18fc;
extern "C" void fn_80210990(void*,int);struct F12bBase{void**vt;char unknown[16];~F12bBase(){vt=vt_80419700;fn_80210990((char*)this+4,0);}};struct F12bSecond{void**vt;~F12bSecond(){}};
struct F12bText304{char*text;~F12bText304(){fn_8020c5c4(this);fn_80341588(this);}};
struct F12bBuffer304{void*storage;unsigned words[2];~F12bBuffer304(){if(storage)fn_802134fc(storage);}};struct F12bHash{unsigned unknown;F12bBuffer304 buffer;unsigned words[3];~F12bHash(){fn_8035c81c(this);}};
struct F12bRecord304{void*storage;unsigned words[2];~F12bRecord304(){if(storage)fn_802134fc(storage);}};
struct F12bOwner304:F12bBase,F12bSecond{F12bText304 text24,text28,text32;F12bHash hash36,hash64;F12bRecord304 records[13];F12bHash hash248;~F12bOwner304();static void operator delete(void*);};
F12bOwner304::~F12bOwner304(){F12bSecond::vt=vt_80419668;F12bBase::vt=vt_80419688;lbl_804b18fc=0;}

