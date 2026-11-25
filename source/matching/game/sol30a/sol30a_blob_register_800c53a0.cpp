// UNVERIFIED draft. Original-instruction mismatch remains; not ready for admission.
extern "C" unsigned pool_804af100;
extern "C" void *allocate_802098d8(void *,unsigned);
extern "C" void *copy_802eee50(void *,const void *,unsigned);
struct Sol30aBlob_800f74cc {
 unsigned observed[4];
 static void *operator new(unsigned size) {return allocate_802098d8(&pool_804af100,size);}
 Sol30aBlob_800f74cc();
 void set_data_800f7510(void *);
 void set_name_800f7500(const char *);
 void set_owner_800f7520(void *);
};
struct Sol30aBlock {unsigned size;};
struct Sol30aInput;
extern "C" Sol30aBlock *data_803446e0(Sol30aInput *);
extern "C" void data_field_800f7510(Sol30aBlob_800f74cc *,void *);
extern "C" void name_field_800f7500(Sol30aBlob_800f74cc *,const char *);
extern "C" void owner_field_800f7520(Sol30aBlob_800f74cc *,void *);
extern "C" void register_800c54d0(unsigned,const char *);
struct Sol30aSlots { unsigned *begin,*end,*limit; };
struct Sol30aStats {unsigned unknown,count,other,maximum;};
extern "C" Sol30aSlots free_8043e438[],active_8043e448[];
extern "C" Sol30aStats stats_803f5718[];
extern "C" unsigned generations_804a87d8[];
extern "C" Sol30aBlob_800f74cc *objects_804a85d8[];
inline const unsigned &sol30a_max(const unsigned &a,const unsigned &b){return a<b?b:a;}
extern "C" unsigned sol30a_blob_register_800c53a0(Sol30aInput *input,const char *name){
 Sol30aBlob_800f74cc *object=new Sol30aBlob_800f74cc;
 void *buffer=allocate_802098d8(&pool_804af100,data_803446e0(input)->size);
 Sol30aBlock *block=data_803446e0(input);
 copy_802eee50(buffer,block,block->size);
 object->set_data_800f7510((char *)buffer+4);
 object->set_name_800f7500(name);
 object->set_owner_800f7520(buffer);
 unsigned *back=free_8043e438[0].end;
 unsigned index=*--back;
 free_8043e438[0].end=back;
 register_800c54d0(index,name);
 unsigned active=active_8043e448[0].end-active_8043e448[0].begin;
 unsigned generation=generations_804a87d8[index]+1;
 objects_804a85d8[index]=object;
 generations_804a87d8[index]=generation;
 ++stats_803f5718[0].count;
 stats_803f5718[0].maximum=sol30a_max(stats_803f5718[0].maximum,active);
 return index+(generation<<7);
}
