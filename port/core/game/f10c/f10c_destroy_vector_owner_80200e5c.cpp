#include "w3d_ptr.h"
#line 1 "f10c_destroy_vector_owner_80200e5c.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
extern "C" void fn_8020c5c4(Ptr32<void>);extern "C" void fn_80341588(Ptr32<void>);extern "C" void fn_802134fc(Ptr32<void>);extern "C" void fn_80210990(Ptr32<void>,int);extern Ptr32<void> vt_80418df0[];extern Ptr32<void> vt_80418eb8[];
struct F10c_80200e5c_Iface{Ptr32<Ptr32<void>> table;};struct F10c_80200e5c_Held{Ptr32<F10c_80200e5c_Iface> p;~F10c_80200e5c_Held(){if(p)((Ptr32<void (Ptr32<F10c_80200e5c_Iface>)>)p->table[4])(p);}};
struct F10c_80200e5c_Text{Ptr32<char> text;~F10c_80200e5c_Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct F10c_80200e5c_Base{Ptr32<Ptr32<void>> table;char unknown[16];~F10c_80200e5c_Base(){table=(Ptr32<Ptr32<void>>)vt_80418eb8;fn_80210990((Ptr32<char>)this+4,0);}};
template<int N>struct F10c_80200e5c_Entry{char unknown[N];};
template<class T>struct F10c_80200e5c_Vector{Ptr32<T> begin; Ptr32<T> end; Ptr32<T> capacity;int unknown;~F10c_80200e5c_Vector(){Ptr32<T> last=end;for(Ptr32<T> p=begin;p!=last;++p)p->~T();if(begin)fn_802134fc(begin);}};
struct F10c_80200e5c_Strings{Ptr32<F10c_80200e5c_Text> begin; Ptr32<F10c_80200e5c_Text> end; Ptr32<F10c_80200e5c_Text> capacity;int unknown;~F10c_80200e5c_Strings(){Ptr32<F10c_80200e5c_Text> last=end;for(Ptr32<F10c_80200e5c_Text> p=begin;p!=last;++p)p->~F10c_80200e5c_Text();if(begin)fn_802134fc(begin);}};
struct F10c_80200e5c_Owner:F10c_80200e5c_Base{F10c_80200e5c_Held held20 __attribute__((aligned(__alignof__(F10c_80200e5c_Base))));char unknown24[16];F10c_80200e5c_Held held40;F10c_80200e5c_Vector<F10c_80200e5c_Entry<12> > a;char unknown60[64];F10c_80200e5c_Vector<F10c_80200e5c_Entry<64> > b;F10c_80200e5c_Strings strings;~F10c_80200e5c_Owner();static void operator delete(void*);};
F10c_80200e5c_Owner::~F10c_80200e5c_Owner(){table=(Ptr32<Ptr32<void>>)vt_80418df0;}



