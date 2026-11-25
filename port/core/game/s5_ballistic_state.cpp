#include "w3d_ptr.h"
#line 1 "s5_ballistic_state.cpp"
/* Ballistic actor defaults and held-interface destruction. */
extern "C" {
struct S5BallisticIface;
struct S5BallisticVtable { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<S5BallisticIface>)> release; };
struct S5BallisticIface { Ptr32<S5BallisticVtable> vtable; };
struct S5Ballistic { Ptr32<void> vtable; unsigned char reserved04[304]; int state; Ptr32<S5BallisticIface> held[12]; unsigned owner,slot,time; int pending; unsigned char reserved376[8]; float first,second; };
extern unsigned char w3d_ballistic_vtable_8040fd88[];
int w3d_ballistic_base_init_800ea180(Ptr32<void>);
void w3d_ballistic_base_destroy_800ea324(Ptr32<void>,int);
Ptr32<S5Ballistic> w3d_ballistic_init_800d78ec(Ptr32<S5Ballistic> actor)
{
    w3d_ballistic_base_init_800ea180(actor);
    actor->vtable=w3d_ballistic_vtable_8040fd88;
    actor->pending=65535;
    actor->held[0]=0;actor->held[1]=0;actor->held[2]=0;actor->held[3]=0;
    actor->held[4]=0;actor->held[5]=0;actor->held[6]=0;actor->held[7]=0;
    actor->held[8]=0;actor->held[9]=0;actor->held[10]=0;actor->held[11]=0;
    actor->first=0.0f;
    actor->state=0;
    actor->second=0.0f;
    return actor;
}
static inline void s5_ballistic_release(Ptr32<S5BallisticIface> value) { if(value) value->vtable->release(value); }
void w3d_ballistic_destroy_800d797c(Ptr32<S5Ballistic> actor,int flags)
{
    actor->vtable=w3d_ballistic_vtable_8040fd88;
    s5_ballistic_release(actor->held[11]);s5_ballistic_release(actor->held[10]);
    s5_ballistic_release(actor->held[9]);s5_ballistic_release(actor->held[8]);
    s5_ballistic_release(actor->held[7]);s5_ballistic_release(actor->held[6]);
    s5_ballistic_release(actor->held[5]);s5_ballistic_release(actor->held[4]);
    s5_ballistic_release(actor->held[3]);s5_ballistic_release(actor->held[2]);
    s5_ballistic_release(actor->held[1]);s5_ballistic_release(actor->held[0]);
    w3d_ballistic_base_destroy_800ea324(actor,flags);
}
}


