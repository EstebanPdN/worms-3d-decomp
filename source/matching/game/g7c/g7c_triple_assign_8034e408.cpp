extern "C" {void *g7c_alloc_801907a8(unsigned int);void g7c_free_801907d0(void *);}
inline void *operator new(unsigned int,void *p) throw(){return p;}
struct Triple {
 unsigned int x,y,z;
 Triple(const Triple &r){unsigned int a=r.x,b=r.y,c=r.z;x=a;y=b;z=c;}
 Triple &operator=(const Triple &r){unsigned int a=r.x,b=r.y,c=r.z;x=a;y=b;z=c;return *this;}
 ~Triple(){}
};
struct NonPodTag {};
template<class Input,class Output> static inline Output copy(Input first,Input last,Output out){for(int n=last-first;n>0;--n,++first,++out)*out=*first;return out;}
template<class T,class U> static inline void construct(T *out,const U &value){new(out) T(value);}
template<class Input,class Output> static inline Output construct_copy_aux(Input first,Input last,Output out,NonPodTag){Output cur=out;for(;first!=last;++first,++cur)construct(&*cur,*first);return cur;}
template<class Input,class Output,class T> static inline Output construct_copy_typed(Input first,Input last,Output out,T *){return construct_copy_aux(first,last,out,NonPodTag());}
template<class Input,class Output> static inline Output construct_copy(Input first,Input last,Output out){return construct_copy_typed(first,last,out,out);}
template<class T> static inline void destroy(T *first,T *last){for(;first!=last;++first)first->~T();}
template<class Input> static inline Triple *allocate_copy(unsigned int size,Input first,Input last){Triple *tmp=(Triple *)g7c_alloc_801907a8(size*sizeof(Triple));construct_copy(first,last,tmp);return tmp;}
// External vector view. Complete locally allocated elements have a12-byte footprint.
struct TripleVectorView {Triple *begin,*end;unsigned int allocator;Triple *capacity;const Triple *first() const{return begin;}const Triple *last() const{return end;}unsigned int size() const{return end-begin;}unsigned int capacity_count() const{return capacity-begin;} TripleVectorView &operator=(const TripleVectorView &); };
inline TripleVectorView &TripleVectorView::operator=(const TripleVectorView &r){TripleVectorView *self=this;const TripleVectorView *other=&r;
 if(other!=self){
  unsigned int size=other->size();
  if(size>self->capacity_count()){
   Triple *tmp=allocate_copy(size,other->first(),other->last());
   destroy(self->begin,self->end);
   if(self->begin)g7c_free_801907d0(self->begin);
   self->begin=tmp;
   self->capacity=tmp+size;
  }else if(self->size()>=size){
   Triple *last=copy(other->first(),other->last(),self->begin);
   destroy(last,self->end);
  }else{
   copy(other->first(),other->first()+self->size(),self->begin);
   construct_copy(other->first()+self->size(),other->last(),self->end);
  }
  self->end=self->begin+size;
 }
 return *self;
}
extern "C" TripleVectorView *w3d_g7c_triple_assign_8034e408(TripleVectorView *self,const TripleVectorView *other){return &(*self=*other);}
