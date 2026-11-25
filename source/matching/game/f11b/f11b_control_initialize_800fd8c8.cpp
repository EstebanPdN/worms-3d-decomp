// Partial native object view covers observed stores through byte95. No allocation or complete class claim.
struct F11ControlVector{int x,y,z;};
extern const float initial_80398140[];
struct F11ControlEntry{int flag;F11ControlVector value;float low,high;};
struct F11ControlOwner{void**vtable;char p[24];int a,b,c,d;F11ControlEntry entries[2];unsigned flags;};
extern void*vtable_80410520[];extern F11ControlOwner*owner_804aaf64;
extern "C" void base_801628b0(F11ControlOwner*);
extern "C" F11ControlOwner*f11b_control_initialize_800fd8c8(F11ControlOwner*s){base_801628b0(s);s->vtable=vtable_80410520;s->a=0;s->b=0;s->c=0;float initial=initial_80398140[0];owner_804aaf64=s;s->d=0;s->flags&=0x3fffffff;for(unsigned i=0;i<2;++i){s->entries[i].low=initial;s->entries[i].high=initial;s->entries[i].flag=0;s->entries[i].value.z=0;s->entries[i].value.y=0;s->entries[i].value.x=0;}return s;}
