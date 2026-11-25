#include "w3d_ptr.h"
#line 1 "f1p_construct_pair_control_802c5d3c.cpp"
// Native two-member default construction preserves the observed count loop. Layout and roles inferred.
struct F1pPairCtorIface{Ptr32<Ptr32<void>> table;};struct F1pPairCtorHeld{Ptr32<F1pPairCtorIface> p;F1pPairCtorHeld():p(0){}};struct F1pPairCtorPair{F1pPairCtorHeld value[2];};struct F1pPairCtorVec{float x,y,z;};struct F1pPairCtorOwner{Ptr32<Ptr32<void>> table;char unknown4[24];Ptr32<F1pPairCtorIface> first;int i32,i36,i40,i44;F1pPairCtorPair pair;Ptr32<F1pPairCtorIface> last;F1pPairCtorVec position;float f72,f76;int i80;};extern Ptr32<void> vt_8041c920[];extern F1pPairCtorVec vector_8045e788;extern const float zero_803d8cfc[];extern "C" Ptr32<void> fn_8015fef0(Ptr32<void>);inline void*operator new(__SIZE_TYPE__,void*p){return p;}
extern "C" Ptr32<F1pPairCtorOwner> w3d_construct_pair_control_802c5d3c(Ptr32<F1pPairCtorOwner> s){fn_8015fef0(s);s->table=vt_8041c920;s->first=0;new(&s->pair)F1pPairCtorPair;s->last=0;s->i32=0;s->position=vector_8045e788;s->f72=zero_803d8cfc[0];s->f76=zero_803d8cfc[0];if(s->first)((Ptr32<void (Ptr32<F1pPairCtorIface>)>)s->first->table[4])(s->first);s->first=0;s->i36=0;s->i80=0;s->i40=0;s->i44=-1;return s;}


