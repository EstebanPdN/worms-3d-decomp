// Original entry 0x8008c858, 252 bytes. PPC32 offsets are observed; names inferred.
// Hold a retained factory result, refresh its position, set the copied offset and scalar fields, register, then release.
// Vector getters return fully initialized three-float copies. Their const-reference call arguments live through each complete expression.
// The inline offset setter uses the class default copy assignment; it reproduces the original word copy.
// Interface vtable +0, retain +0xc, release +0x10 are original observations.
struct Sol35aInterface;
struct Sol35aVtable {void (*unknown[3])();void (*retain)(Sol35aInterface *);void (*release)(Sol35aInterface *);};
struct Sol35aInterface {Sol35aVtable *vtable;};
struct Sol35aHeld {Sol35aInterface *ref;Sol35aHeld(Sol35aInterface *r):ref(r){if(ref)ref->vtable->retain(ref);}~Sol35aHeld(){if(ref)ref->vtable->release(ref);}};
struct Sol35aVec3 {float x,y,z;Sol35aVec3(){} void set(const Sol35aVec3 &o){float vx=o.x,vy=o.y,vz=o.z;x=vx;y=vy;z=vz;} Sol35aVec3(const Sol35aVec3 &o){float vx=o.x,vy=o.y,vz=o.z;x=vx;y=vy;z=vz;}};
struct Sol35aPacket {unsigned char unknown00[8];Sol35aVec3 position,offset;Sol35aVec3 getPosition()const{return position;}Sol35aVec3 getOffset()const{return offset;}unsigned char enabled;unsigned char unknown21[3];unsigned int mode;};
struct Sol35aRequest {unsigned char unknown00[20];unsigned int value;};
struct Sol35aVectorService {Sol35aVtable *vtable;unsigned char unknown04[112];unsigned char enabled;unsigned char unknown75[3];Sol35aVec3 offset;unsigned int mode;void setOffset(const Sol35aVec3 &v){offset=v;}};
extern char sol35a_service_8040f2c0[];
extern "C" Sol35aInterface *sol35a_service_lookup_8020b680(void *);
extern "C" int sol35a_vector_refresh_8003e1f8(Sol35aInterface *,const Sol35aVec3 &);
extern "C" int sol35a_dispatch_80164514(void *,Sol35aInterface *,unsigned int);
extern void *sol35a_context_804b178c;
extern "C" void sol35a_vector_service_dispatch_8008c858(Sol35aRequest *self,const Sol35aPacket *packet){
 Sol35aHeld held(sol35a_service_lookup_8020b680(sol35a_service_8040f2c0));
 sol35a_vector_refresh_8003e1f8(held.ref,packet->getPosition());
 
 ((Sol35aVectorService*)held.ref)->setOffset(packet->getOffset());((Sol35aVectorService*)held.ref)->enabled=packet->enabled;((Sol35aVectorService*)held.ref)->mode=packet->mode;
 sol35a_dispatch_80164514(sol35a_context_804b178c,held.ref,self->value);
}

// Reference ABI checks emit no runtime code.
typedef char sol35a_vec3_size[(sizeof(Sol35aVec3)==12)?1:-1];
typedef char sol35a_held_size[(sizeof(Sol35aHeld)==4)?1:-1];
