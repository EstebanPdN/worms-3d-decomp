#include "w3d_ptr.h"
#line 1 "f11b_control_initialize_checked_800fd8c8.cpp"
// Partial native object view covers observed stores through byte95. No allocation or complete class claim.
struct F11ControlVector{int x,y,z;};
extern const float initial_80398140[];
struct F11ControlEntry{int flag;F11ControlVector value;float low,high;};
struct F11ControlOwner{Ptr32<Ptr32<void>> vtable;char p[24];int a,b,c,d;F11ControlEntry entries[2];unsigned flags;};
extern Ptr32<void> vtable_80410520[];extern Ptr32<F11ControlOwner> owner_804aaf64;
extern "C" Ptr32<F11ControlOwner> base_801628b0(Ptr32<F11ControlOwner>);
extern "C" Ptr32<F11ControlOwner> f11b_control_initialize_checked_800fd8c8(Ptr32<F11ControlOwner> s){base_801628b0(s);s->vtable=vtable_80410520;s->a=0;s->b=0;s->c=0;float initial=initial_80398140[0];owner_804aaf64=s;s->d=0;s->flags&=0x3fffffff;for(unsigned i=0;i<2;++i){s->entries[i].low=initial;s->entries[i].high=initial;s->entries[i].flag=0;s->entries[i].value.z=0;s->entries[i].value.y=0;s->entries[i].value.x=0;}return s;}


