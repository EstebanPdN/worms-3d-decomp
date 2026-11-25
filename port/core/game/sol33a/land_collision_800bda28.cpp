#include "w3d_ptr.h"
#line 1 "land_collision_800bda28.cpp"
// Inferred GC32 reference layouts. Unknown prefix words model observed field offsets; no native-platform layout is claimed.
struct Sol33aVec {float x,y,z;Sol33aVec(){} Sol33aVec(const Sol33aVec &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}};
struct Sol33aMotion;
struct Sol33aLandGroup;
// Inferred 32-word mask span: selection helpers use +128 and start vector storage at +256.
// The factory at 800ba7b0 allocates 12576 bytes; this is a partial reference view.
// The original valid domain must keep the group count within the 1024 mask bits.
struct Sol33aLandMask {unsigned unknown[32];unsigned masks[32];};
struct Sol33aLandRange {Ptr32<Ptr32<Sol33aLandGroup>> begin; Ptr32<Ptr32<Sol33aLandGroup>> end; Ptr32<Ptr32<Sol33aLandGroup>> capacity;};
extern Sol33aLandRange sol33a_groups_8043bb64;
struct Sol33aPropertyKey {Ptr32<const char> text;template <class W3dU> Sol33aPropertyKey(Ptr32<W3dU> w3d_p) : Sol33aPropertyKey((const char *)w3d_p.get()) {}
 Sol33aPropertyKey(const char *t):text(t){}};
struct Sol33aLandValue;
extern Ptr32<Sol33aLandValue> sol33a_destroyed_804ae5dc;
extern "C" int sol33a_property_800fc230(Ptr32<Sol33aPropertyKey>,Ptr32<int>);
extern "C" Ptr32<Sol33aLandValue> sol33a_cast_80342a78(Ptr32<Sol33aLandValue>);
extern "C" int sol33a_write_80178d28(Ptr32<Sol33aLandValue>,Ptr32<const int>);
extern "C" int sol33a_read_80178d1c(Ptr32<Sol33aLandValue>);
extern "C" Sol33aVec sol33a_position_80066894(Ptr32<Sol33aMotion>);
extern "C" float sol33a_radius_800668ec(Ptr32<Sol33aMotion>);
extern "C" void sol33a_mask_800bd53c(Ptr32<Sol33aLandMask>,const Sol33aVec&,float);
extern "C" int sol33a_collide_800b17c4(Ptr32<Sol33aLandGroup>,Ptr32<Sol33aMotion>);
struct Sol33aLandMessage;
struct Sol33aLandAllocator;
extern Ptr32<Sol33aLandAllocator> sol33a_landAllocator_804b1754;
extern "C" Ptr32<void> sol33a_landAllocate_801613f0(Ptr32<Sol33aLandAllocator>,unsigned);
extern "C" Ptr32<Sol33aLandMessage> sol33a_landMessage_800b92a4(Ptr32<void>,const Sol33aVec&,float);
extern "C" int sol33a_landPost_8016239c(Ptr32<Sol33aLandMessage>);
extern "C" void sol33a_land_collision_800bda28(Ptr32<Sol33aLandMask> self,Ptr32<Sol33aMotion> motion){
 int indestructible;Sol33aPropertyKey key("Land.Indestructable");sol33a_property_800fc230(&key,&indestructible);
 if(!indestructible){
  int changed=0;sol33a_write_80178d28(sol33a_cast_80342a78(sol33a_destroyed_804ae5dc),&changed);
  Sol33aVec position=sol33a_position_80066894(motion);
  sol33a_mask_800bd53c(self,position,sol33a_radius_800668ec(motion));
  unsigned bit=1;
  Ptr32<Ptr32<Sol33aLandGroup>> i=sol33a_groups_8043bb64.begin; Ptr32<Ptr32<Sol33aLandGroup>> end=sol33a_groups_8043bb64.end;
  if(i!=end){
   Ptr32<unsigned int> word=self->masks;
   do{
    if(*word&bit)sol33a_collide_800b17c4(*i,motion);
    bit<<=1;if(!bit){bit=1;++word;}
    ++i;
   }while(i!=end);
  }
  if(sol33a_read_80178d1c(sol33a_cast_80342a78(sol33a_destroyed_804ae5dc))==1){
   Sol33aVec copy(position);
   Ptr32<void> storage=sol33a_landAllocate_801613f0(sol33a_landAllocator_804b1754,24);
   sol33a_landPost_8016239c(sol33a_landMessage_800b92a4(storage,copy,sol33a_radius_800668ec(motion)));
  }
 }
}

// ABI observations are confined to the reference compiler.
typedef char Sol33aLandPointer32[sizeof(Ptr32<void>)==4?1:-1];
typedef char Sol33aLandWord32[sizeof(unsigned)==4?1:-1];
typedef char Sol33aLandVec12[sizeof(Sol33aVec)==12?1:-1];
typedef char Sol33aLandMaskOffset[__builtin_offsetof(Sol33aLandMask,masks)==128?1:-1];


