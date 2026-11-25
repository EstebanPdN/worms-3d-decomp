#include "w3d_ptr.h"
#line 1 "f11c_destroy_array_owner_801a8adc.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
extern "C" void fn_802134fc(Ptr32<void>);extern "C" void fn_80210990(Ptr32<void>,int);extern "C" void fn_801e828c(Ptr32<void>,int);extern Ptr32<void> vt_80413cc0[];extern Ptr32<void> vt_80413d30[];extern Ptr32<void> vt_80418210[];extern Ptr32<void> vt_804182d0[];
struct F11c_Iface{Ptr32<Ptr32<void>> table;};
struct F11c_Held{Ptr32<F11c_Iface> p;~F11c_Held(){if(p)((Ptr32<void (Ptr32<F11c_Iface>)>)p->table[4])(p);}};
struct F11c_Alloc{Ptr32<void> p;~F11c_Alloc(){if(p)fn_802134fc(p);}};
extern "C" void fn_801bde2c(Ptr32<void>,int);extern "C" void fn_801be020(Ptr32<void>,int);
struct F11c_ItemA{char observed[84];~F11c_ItemA(){fn_801bde2c(this,2);}};struct F11c_ItemB{char observed[84];~F11c_ItemB(){fn_801be020(this,2);}};
struct F11c_BlockA{F11c_ItemA a[512];~F11c_BlockA(){}static void operator delete(void*);};struct F11c_BlockB{F11c_ItemB a[32];~F11c_BlockB(){}static void operator delete(void*);};
template<class T>struct F11c_Owned{Ptr32<T> p;~F11c_Owned(){w3d::vdelete(p);}};
template<class T>struct F11c_Vector{Ptr32<T> begin; Ptr32<T> end; Ptr32<T> capacity;int unknown;~F11c_Vector(){for(Ptr32<T> p=begin;p!=end;++p)p->~T();if(begin)fn_802134fc(begin);}};
struct F11c_Buffer16{F11c_Alloc p;char unknown[12];};
struct F11c_Buffers{Ptr32<F11c_Buffer16> begin; Ptr32<F11c_Buffer16> end; Ptr32<F11c_Buffer16> capacity;int unknown;~F11c_Buffers(){Ptr32<F11c_Buffer16> last=end;for(Ptr32<F11c_Buffer16> p=begin;p!=last;++p)p->~F11c_Buffer16();if(begin)fn_802134fc(begin);}};
struct F11c_Node{char observed[8];~F11c_Node();};
struct F11c_Base168{Ptr32<Ptr32<void>> table;char unknown[164];~F11c_Base168(){table=(Ptr32<Ptr32<void>>)vt_80413d30;fn_801e828c((Ptr32<char>)this+4,0);}};
struct F11c_Owner588:F11c_Base168{F11c_Held held168 __attribute__((aligned(__alignof__(F11c_Base168)))),held172,held176;F11c_Vector<F11c_Owned<F11c_BlockA> > a;char unknown196[8];F11c_Vector<F11c_Owned<F11c_BlockB> > b;char unknown220[12];F11c_Node node;F11c_Alloc p240;char unknown244[8];F11c_Alloc p252;char unknown256[12];F11c_Alloc p268;char unknown272[16];F11c_Buffers buffers;char unknown304[4];F11c_Vector<unsigned short> shorts;char unknown324[4];~F11c_Owner588();static void operator delete(void*);};
F11c_Owner588::~F11c_Owner588(){table=(Ptr32<Ptr32<void>>)vt_80413cc0;}



