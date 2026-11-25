/* Ballistic actor defaults and held-interface destruction. */
extern "C" {
struct S5BallisticIface;
struct S5BallisticVtable { void (*reserved[4])(); void (*release)(S5BallisticIface *); };
struct S5BallisticIface { S5BallisticVtable *vtable; };
struct S5Ballistic { void *vtable; unsigned char reserved04[304]; int state; S5BallisticIface *held[12]; unsigned owner,slot,time; int pending; unsigned char reserved376[8]; float first,second; };
extern unsigned char w3d_ballistic_vtable_8040fd88[];
int w3d_ballistic_base_init_800ea180(void *);
void w3d_ballistic_base_destroy_800ea324(void *,int);
S5Ballistic *w3d_ballistic_init_800d78ec(S5Ballistic *actor)
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
static inline void s5_ballistic_release(S5BallisticIface *value) { if(value) value->vtable->release(value); }
void w3d_ballistic_destroy_800d797c(S5Ballistic *actor,int flags)
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
