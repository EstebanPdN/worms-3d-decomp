/* Two array-reference headers at nested owner+40/+36. Only header state,
   lock key and sixteen-bit count offsets are observed; class names inferred. */
struct Cx16bArrayHeader { char pad[4]; unsigned short state; char gap[18]; int key; unsigned short locks; };
struct Cx16bPair { char pad[36]; Cx16bArrayHeader *second,*first; };
struct Cx16bMeshStorage { char pad[52]; Cx16bPair *pair; };
struct Cx16bArrayOwner { char pad[168]; Cx16bMeshStorage *storage; };
extern "C" int fn_801ef048(Cx16bArrayHeader **,int,int,int);
static inline void cx16b_lock(Cx16bArrayHeader **slot,int key)
{
    Cx16bArrayHeader *header=*slot;
    if(header->state==1 && key==header->key)++header->locks;
    else fn_801ef048(slot,key,8,0);
}
extern "C" int w3d_cx16b_dual_array_lock_80189450(Cx16bArrayOwner *self,int key)
{
    Cx16bPair *pair=self->storage->pair;
    cx16b_lock(&pair->first,key);
    cx16b_lock(&pair->second,key);
    return 0;
}
