// Original entry 0x8008bf28, 212 bytes. PPC32 reference layouts; names inferred.
// A scoped retained object receives two copied three-float vectors and is registered.
// Getters return by value; binding each result to a const reference preserves its lifetime through the setter call.
// The original setter callees copy all three words synchronously; neither retains the reference.
// Vtable +0, retain +0xc, release +0x10 are original observations.
struct Sol35aInterface;
struct Sol35aVtable {void (*unknown[3])();void (*retain)(Sol35aInterface *);void (*release)(Sol35aInterface *);};
struct Sol35aInterface {Sol35aVtable *vtable;};
struct Sol35aHeld {Sol35aInterface *ref;Sol35aHeld(Sol35aInterface *r):ref(r){if(ref)ref->vtable->retain(ref);}~Sol35aHeld(){if(ref)ref->vtable->release(ref);}};
struct Sol35aVec3 {float x,y,z;Sol35aVec3(){} void set(const Sol35aVec3 &o){float vx=o.x,vy=o.y,vz=o.z;x=vx;y=vy;z=vz;} Sol35aVec3(const Sol35aVec3 &o){float vx=o.x,vy=o.y,vz=o.z;x=vx;y=vy;z=vz;}};
struct Sol35aPacket {unsigned char unknown00[8];Sol35aVec3 position,offset;Sol35aVec3 getPosition()const{return position;}Sol35aVec3 getOffset()const{return offset;}unsigned char enabled;unsigned char unknown21[3];unsigned int mode;};
struct Sol35aRequest {unsigned char unknown00[20];unsigned int value;};
struct Sol35aVectorService {Sol35aVtable *vtable;unsigned char unknown04[112];unsigned char enabled;unsigned char unknown75[3];Sol35aVec3 offset;unsigned int mode;};
extern char sol35a_service_8040ee70[];
extern "C" Sol35aInterface *sol35a_service_lookup_8020b680(void *);
extern "C" int sol35a_placement_target_80067268(Sol35aInterface *,const Sol35aVec3 &);
extern "C" int sol35a_placement_offset_80067288(Sol35aInterface *,const Sol35aVec3 &);
extern "C" int sol35a_dispatch_80164514(void *,Sol35aInterface *,unsigned int);
extern void *sol35a_context_804b178c;
extern "C" void sol35a_placement_dispatch_8008bf28(Sol35aRequest *self,const Sol35aPacket *packet){
 Sol35aHeld held(sol35a_service_lookup_8020b680(sol35a_service_8040ee70));
 sol35a_placement_target_80067268(held.ref,packet->getPosition());
 sol35a_placement_offset_80067288(held.ref,packet->getOffset());
 sol35a_dispatch_80164514(sol35a_context_804b178c,held.ref,self->value);
}
