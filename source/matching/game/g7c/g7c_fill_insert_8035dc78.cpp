// Inferred pointer-vector insertion. The vector is an external view only.
extern "C" {
void *g7c_allocate_80212fd4(unsigned int);
void *g7c_fallback_803413d8(unsigned int);
void g7c_free_802134fc(void *);
void *g7c_move_802eeef4(void *,const void *,unsigned int);
}
typedef void *Value;
static inline void *storage(unsigned int bytes) {void *p=g7c_allocate_80212fd4(bytes);if(!p)p=g7c_fallback_803413d8(bytes);return p;}
static inline Value *allocate(unsigned int n) {return n?(Value *)storage(n*sizeof(Value)):0;}
struct PodTag {};
template<class T> static inline T *copy_words(const T *first,const T *last,T *out) {
 if(last!=first) {unsigned int bytes=(const char *)last-(const char *)first;return (T *)((char *)g7c_move_802eeef4(out,first,bytes)+bytes);}return out;
}
template<class T> static inline T *copy_aux(T *first,T *last,T *out,PodTag) {return copy_words(first,last,out);}
template<class T> static inline T *copy(T *first,T *last,T *out) {return copy_aux(first,last,out,PodTag());}
template<class T,class Size> static inline T *fill_words(T *first,Size count,const T &value) {for(;count;--count,++first)*first=value;return first;}
template<class T,class Size> static inline T *fill_aux(T *first,Size count,const T &value,PodTag) {return fill_words(first,count,value);}
template<class T,class Size> static inline T *fill_n(T *first,Size count,const T &value) {return fill_aux(first,count,value,PodTag());}
template<class T> static inline void fill(T *first,T *last,const T &value) {
 for(;first!=last;++first)*first=value;
}
template<class T> static inline void copy_backward(T *first,T *last,T *out) {
 int bytes=(char *)last-(char *)first;
 if(bytes>0)g7c_move_802eeef4((char *)out-bytes,first,bytes);
}
template<class T> static inline const T &maximum(const T &a,const T &b) {return a<b?b:a;}
struct VectorView {Value *begin,*end;unsigned int allocator;Value *capacity;};
static inline void grow_insert(VectorView *self,Value *position,unsigned int additional,const Value &value) {
   const unsigned int old_size=self->end-self->begin;
   const unsigned int length=old_size+maximum(old_size,additional);
   Value *new_begin=allocate(length);
   Value *new_end=new_begin;
   new_end=copy(self->begin,position,new_end);
   new_end=fill_n(new_end,additional,value);
   new_end=copy(position,self->end,new_end);
   if(self->begin)g7c_free_802134fc(self->begin);
   self->begin=new_begin;
   self->end=new_end;
   self->capacity=new_begin+length;
}
extern "C" void w3d_g7c_fill_insert_8035dc78(VectorView *self,Value *position,unsigned int count,const Value &value) {
 if(count) {
  if((unsigned int)(self->capacity-self->end)>=count) {
   Value value_copy=value;
   unsigned int after=self->end-position;
   Value *old_end=self->end;
   if(after>count) {
    copy(old_end-count,old_end,old_end);
    self->end+=count;
    copy_backward(position,old_end-count,old_end);
    fill(position,position+count,value_copy);
   } else {
    fill_n(old_end,count-after,value_copy);
    self->end+=count-after;
    copy(position,old_end,self->end);
    self->end+=after;
    fill(position,old_end,value_copy);
   }
  } else {
   grow_insert(self,position,count,value);
  }
 }
}
