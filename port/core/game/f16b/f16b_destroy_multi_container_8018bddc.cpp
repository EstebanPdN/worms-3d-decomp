#include "w3d_ptr.h"
#line 1 "f16b_destroy_multi_container_8018bddc.cpp"
// Inferred partial owner and member cleanup views, uninstantiated here.
extern "C" void fn_802134fc(Ptr32<void>);extern "C" void fn_8020c5c4(Ptr32<void>);extern "C" void fn_80341588(Ptr32<void>);extern "C" void fn_80210abc(Ptr32<void>,int);extern Ptr32<void> vt_80412f50[];extern int lbl_804ab6ac;
struct F16bBase_801799d4{Ptr32<Ptr32<void>> table;char unknown[164];~F16bBase_801799d4();};
struct F16bI296{Ptr32<Ptr32<void>> table;};struct F16bH296{Ptr32<F16bI296> p;~F16bH296(){if(p)((Ptr32<void (Ptr32<F16bI296>)>)p->table[4])(p);}};
struct F16bRaw296{Ptr32<void> storage;unsigned unknown[2];~F16bRaw296(){if(storage)fn_802134fc(storage);}};
struct F16bVec296{unsigned words[3];~F16bVec296(){fn_80210abc(this,2);}};
struct F16bText296{unsigned text;~F16bText296(){fn_8020c5c4(this);fn_80341588(this);}};
struct F16bOwner296:F16bBase_801799d4{F16bH296 first __attribute__((aligned(__alignof__(F16bBase_801799d4)))),second,third;F16bRaw296 buffer;unsigned unknown192;F16bH296 fourth;F16bVec296 a,b,c;unsigned unknown236[3];F16bText296 text;F16bRaw296 x,y;~F16bOwner296();};
F16bOwner296::~F16bOwner296(){table=vt_80412f50;--lbl_804ab6ac;}


