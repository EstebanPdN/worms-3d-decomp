#include "w3d_ptr.h"
#line 1 "release_slot_node_unsigned_80173504.cpp"
// Unsigned mask revision: bit31 uses defined unsigned shifting. Original frozen variant is preserved.
// Release of one slot node: base node reset, clear the slot's used byte in the
// group's copy-on-write byte array, release the held handle, clear the slot's
// bit in the resource's group bitset, unregister from the resource and mark
// the group available when no bit remains set. Partial external views with
// observed offsets only; names and meanings are inferred.
struct Mx23oaByteStore {
 unsigned char unknown[4];
 unsigned short references;      // +4
 unsigned char unknown6[18];
 unsigned count;                 // +24
 unsigned short locks;           // +28
 unsigned char unknown30[2];
 unsigned char data[1];          // +32
};
struct Mx23oaByteArray {Ptr32<Mx23oaByteStore> store;};
extern "C" Ptr32<unsigned char> fn_801ef048(Ptr32<Mx23oaByteArray>,unsigned,unsigned,unsigned);
// Same inline write-open as d_array_lock.cpp (count 0, append flag 2), here
// with one-byte elements.
inline Ptr32<unsigned char> mx23oa_open_bytes(Ptr32<Mx23oaByteArray> array,unsigned count,unsigned flags){
 Ptr32<Mx23oaByteStore> store=array->store;
 unsigned size;
 if(flags&2)size=store->count+count;else size=count;
 if(store->references==1&&size==store->count){store->locks++;return store->data;}
 return fn_801ef048(array,size,1,flags);
}
struct Mx23oaSlotFlags {unsigned char unknown[4],value,w3d_tag_rest[3];void mark_available(){value|=4;}};
struct Mx23oaSlotGroup {
 unsigned unknown;
 Mx23oaSlotFlags flags;          // +4
 unsigned char unknown12[84];
 Mx23oaByteArray used;           // +96
};
struct Mx23oaSlotHandle {Ptr32<Ptr32<void>> table;unsigned char unknown4[44];Ptr32<Mx23oaSlotGroup> group;};
inline unsigned mx23oa_first_bit(unsigned bits){
 unsigned bit=0;
 while((bits&1)==0){bits>>=1;++bit;}
 return bit;
}
// Same bitset shape as e12b_BitSet (admitted e12b_release_slot_8017192c).
struct Mx23oaBitSet {
 Ptr32<unsigned int> begin; Ptr32<unsigned int> end; Ptr32<unsigned int> capacity;
 unsigned bit_count;
 void reset(unsigned i){*(Ptr32<unsigned int>)((Ptr32<char>)begin+((i>>5)<<2))&=~(1u<<(i&31));}
 unsigned first(Ptr32<unsigned int> result){
  for(unsigned i=0;i<(unsigned)(end-begin);++i){
   unsigned bits=*(Ptr32<unsigned int>)((Ptr32<char>)begin+(i<<2));
   if(bits){
    *result=i*32+mx23oa_first_bit(bits);
    if(*result>=bit_count){*result=(unsigned)-1;return false;}
    return true;
   }
  }
  *result=(unsigned)-1;
  return false;
 }
};
struct Mx23oaResource {Ptr32<Ptr32<void>> table;};
struct Mx23oaSlotNode {
 Ptr32<Ptr32<void>> table;
 unsigned char group;            // +4
 unsigned char unknown5[111];
 Ptr32<Mx23oaResource> resource;        // +116
 unsigned unknown120;
 unsigned index;                 // +124
 Ptr32<Mx23oaSlotHandle> handle;        // +128
};
extern "C" int fn_801859f8(Ptr32<Mx23oaSlotNode>);
extern "C" Ptr32<Mx23oaResource> fn_80343808(Ptr32<Mx23oaResource>);
extern "C" Ptr32<Mx23oaBitSet> fn_801720c0(Ptr32<Mx23oaResource>,unsigned);
extern "C" int w3d_release_slot_node_80173504(Ptr32<Mx23oaSlotNode> self){
 int result=fn_801859f8(self);
 Ptr32<Mx23oaSlotGroup> group=self->handle->group;
 mx23oa_open_bytes(&group->used,0,2)[self->index]=0;
 if(self->handle)((Ptr32<void (Ptr32<Mx23oaSlotHandle>)>)self->handle->table[4])(self->handle);
 self->handle=0;
 Ptr32<Mx23oaBitSet> bits=fn_801720c0(fn_80343808(self->resource),self->group);
 bits->reset(self->index);
 ((Ptr32<void (Ptr32<Mx23oaResource>, Ptr32<Mx23oaSlotNode>)>)self->resource->table[15])(self->resource,self);
 unsigned first;
 if(!bits->first(&first))group->flags.mark_available();
 return result;
}


