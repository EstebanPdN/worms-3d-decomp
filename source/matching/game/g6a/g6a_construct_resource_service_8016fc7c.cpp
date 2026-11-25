// g6a near miss only: exact instruction layout still fails six frame words.
// External views below are never instantiated as complete local objects.
// The heap State28 is constructed only at the original allocation size28;
// its nested groups reproduce observed +8/+16 member accesses, with unknown8 untouched.
struct G6aResourceFlags { char unknown0[7]; unsigned char flags; void dirty(){flags|=2;} void activate(){flags|=1;} };
struct G6aResourceInterface {
 void **vtable; G6aResourceFlags status; char unknown12[12];
};
struct G6aResourceWordsView : G6aResourceInterface {
 unsigned fields[8];
 void dirty(){status.dirty();}
 void activate(){status.activate();}
 void set0(unsigned value){fields[0]=value;dirty();}
 void set1(unsigned value){fields[1]=value;dirty();}
 void set2(unsigned value){fields[2]=value;dirty();}
 void set3(unsigned value){fields[3]=value;dirty();}
 void set7(unsigned value){fields[7]=value;dirty();}
};
struct G6aResourceFloatView : G6aResourceInterface {
 float value; unsigned first,second;
 void set1(unsigned v){first=v;status.dirty();}
 void set2(unsigned v){second=v;status.dirty();}
 void setFloat(float v){value=v;status.dirty();}
 void activate(){status.activate();}
};
extern "C" G6aResourceInterface *query_8020b680(const void*);
template<class T> struct G6aResourceHeld {
 T *p;
 void acquire(const void *type){T *next=(T*)query_8020b680(type);if(next)((void(*)(G6aResourceInterface*))next->vtable[3])(next);if(p)((void(*)(G6aResourceInterface*))p->vtable[4])(p);p=next;}
};
struct G6aStorage12 { void *begin;unsigned short count,capacity;void *data; };
struct G6aResourceOwnerView { void **vtable;char unknown4[48];G6aStorage12 arrays[2];unsigned word76;void *state; };
extern "C" G6aResourceOwnerView *base_801902e8(G6aResourceOwnerView *);
extern "C" G6aStorage12 *storage_802109dc(G6aStorage12 *);
extern "C" void *allocate_801fe1d8(unsigned);
extern const char vtable_80412008[];
extern unsigned count_804b1898;
extern const float value_803a65a8[];
extern G6aResourceHeld<G6aResourceWordsView> held_804b0124;
extern G6aResourceHeld<G6aResourceWordsView> held_804b0128;
extern G6aResourceHeld<G6aResourceWordsView> held_804b012c;
extern G6aResourceHeld<G6aResourceFloatView> held_804b0130;
extern G6aResourceHeld<G6aResourceWordsView> held_804b0134;
extern G6aResourceHeld<G6aResourceWordsView> held_804b0138;
extern G6aResourceHeld<G6aResourceWordsView> held_804b013c;
extern G6aResourceHeld<G6aResourceWordsView> held_804b0140;
extern G6aResourceHeld<G6aResourceWordsView> held_804b0144;
extern G6aResourceHeld<G6aResourceWordsView> held_804b0148;
extern G6aResourceHeld<G6aResourceWordsView> held_804b014c;
extern G6aResourceHeld<G6aResourceWordsView> held_804b0150;
extern const char type_80414210[];
extern const char type_80415bb0[];
extern const char type_80415c00[];
extern const char type_80415c10[];
extern const char type_80415c30[];
extern const char type_80415c80[];
extern const char type_80415cb0[];
extern const char type_804166b0[];
extern const char type_80416750[];
inline void *operator new(unsigned n){return allocate_801fe1d8(n);}
struct G6aResourceCapacity { unsigned unknown0,capacity; G6aResourceCapacity(){capacity=0;} };
struct G6aResourceRange { unsigned first,second,third; G6aResourceRange(){third=0;second=0;first=0;} };
struct G6aResourceState { unsigned begin,end; G6aResourceCapacity storage; G6aResourceRange pending; G6aResourceState():begin(0),end(0) {} };
extern "C" G6aResourceOwnerView *g6a_construct_resource_service_8016fc7c(G6aResourceOwnerView *self){
 base_801902e8(self);self->vtable=(void**)vtable_80412008;
 storage_802109dc(&self->arrays[0]);storage_802109dc(&self->arrays[1]);self->word76=0;
 if(count_804b1898==0){
 held_804b0124.acquire(type_80415c10);
 held_804b0128.acquire(type_80415c10);
 held_804b012c.acquire(type_80415c80);
 held_804b0130.acquire(type_80415bb0);
 held_804b0134.acquire(type_80415cb0);
 held_804b0138.acquire(type_80415cb0);
 held_804b013c.acquire(type_80415c30);
 held_804b0140.acquire(type_80415c00);
 held_804b0144.acquire(type_80415c00);
 held_804b0148.acquire(type_804166b0);
 held_804b014c.acquire(type_80414210);
 held_804b0150.acquire(type_80416750);
 held_804b0124.p->set2(3);
 held_804b0124.p->set3(1);
 held_804b0124.p->activate();
 held_804b0128.p->set2(7);
 held_804b0128.p->set3(1);
 held_804b0128.p->activate();
 held_804b012c.p->set7(0);
 held_804b012c.p->activate();
 held_804b0130.p->set1(4);
 held_804b0130.p->set2(1);
 held_804b0130.p->activate();
 held_804b0130.p->setFloat(0.0f);
 held_804b0134.p->set1(6);
 held_804b0134.p->set0(7);
 held_804b0134.p->activate();
 held_804b0138.p->set1(6);
 held_804b0138.p->set0(1);
 held_804b0138.p->activate();
 held_804b013c.p->set0(0);
 held_804b013c.p->activate();
 held_804b0140.p->set0(0);
 held_804b0140.p->activate();
 held_804b0144.p->set0(1);
 held_804b0144.p->activate();
 }
 ++count_804b1898;
 self->state=new G6aResourceState;
 return self;
}
