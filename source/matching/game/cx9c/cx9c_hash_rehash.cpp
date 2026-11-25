/* Inferred STLport hash resize. Owner has buckets at +4/+8 and compressed
 * allocator/capacity pair at +12/+16. Node +0 links, +4 points to a key whose
 * observed hash is the unsigned sum of words +0 and +8. Empty allocator
 * constructors leave their object byte unspecified, as in the original ABI.
 */
struct Cx9cKey {unsigned int first,middle,last;};
struct Cx9cHashNode {Cx9cHashNode *next;Cx9cKey *key;unsigned int value;};
extern "C" void *cx9c_allocate_80212fd4(unsigned int);
extern "C" void *cx9c_fallback_803413d8(unsigned int);
extern "C" void cx9c_release_802134fc(void *);
struct Cx9cHash;
extern "C" unsigned int cx9c_bucket_capacity_8035c518(Cx9cHash *,unsigned int);
struct Cx9cEmptyAllocator {Cx9cEmptyAllocator(){}Cx9cEmptyAllocator(const Cx9cEmptyAllocator &) {}};
struct Cx9cEndStorage {
 Cx9cEmptyAllocator allocator;Cx9cHashNode **end;
 Cx9cEndStorage(const Cx9cEmptyAllocator &a):allocator(a),end(0){}
 Cx9cEndStorage(const Cx9cEndStorage &other):allocator(other.allocator),end(other.end){}
};
template<class T> static inline void cx9c_swap(T &a,T &b){T temp=a;a=b;b=temp;}
static inline void *cx9c_storage(unsigned int bytes){void*p=cx9c_allocate_80212fd4(bytes);if(!p)p=cx9c_fallback_803413d8(bytes);return p;}
struct Cx9cBuckets {
 Cx9cHashNode **begin,**end;Cx9cEndStorage storage;
 static Cx9cHashNode **allocate(unsigned int count){return count?(Cx9cHashNode**)cx9c_storage(count*4):0;}
 Cx9cBuckets(unsigned int count,Cx9cHashNode *const &value,const Cx9cEmptyAllocator &a=Cx9cEmptyAllocator()):begin(0),end(0),storage(a){
  Cx9cHashNode **p=allocate(count);begin=p;end=p;storage.end=p+count;
  Cx9cHashNode **current=end;
  for(unsigned int n=count;n>0;--n){*current=value;++current;}
  end=current;
 }
 ~Cx9cBuckets(){if(begin)cx9c_release_802134fc(begin);}
 void swap(Cx9cBuckets &other){cx9c_swap(begin,other.begin);cx9c_swap(end,other.end);cx9c_swap(storage,other.storage);}
};
static inline Cx9cHashNode *&cx9c_slot(Cx9cHashNode **base,const unsigned int index){return base[index];}
struct Cx9cHash {unsigned int opaque;Cx9cBuckets buckets;unsigned int count;};
extern "C" void w3d_cx9c_hash_rehash_8035c588(Cx9cHash *self,unsigned int hint)
{
 unsigned int old_count=self->buckets.end-self->buckets.begin;
 if(hint>old_count){
  unsigned int count=cx9c_bucket_capacity_8035c518(self,hint);
  if(count>old_count){
   Cx9cHashNode *zero=0;Cx9cBuckets temporary(count,zero);
   for(unsigned int i=0;i<old_count;++i){
    Cx9cHashNode *first=cx9c_slot(self->buckets.begin,i);
    while(first){
     unsigned int target=(first->key->first+first->key->last)%count;
     cx9c_slot(self->buckets.begin,i)=first->next;
     first->next=cx9c_slot(temporary.begin,target);cx9c_slot(temporary.begin,target)=first;
     first=cx9c_slot(self->buckets.begin,i);
    }
   }
   self->buckets.swap(temporary);
  }
 }
}
