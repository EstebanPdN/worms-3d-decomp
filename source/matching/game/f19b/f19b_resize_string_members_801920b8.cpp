// String constructor803426b8 writes only its four-byte base; entry copy8034cc3c
// witnesses separate attributes at4,5,6 and stride8. External owner is incomplete.
extern "C" void fn_8020c5c4(void*);
extern "C" void fn_80341588(void*);
struct F19bString_803426b8 {char*text;F19bString_803426b8();~F19bString_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct F19bEntry {F19bString_803426b8 text;unsigned char a,b;unsigned short c;};
struct F19bVector {F19bEntry*begin,*end,*unknown,*capacity;
 unsigned size(){return end-begin;}
 void erase(F19bEntry*first,F19bEntry*last){for(F19bEntry*p=first;p!=last;++p)p->~F19bEntry();end=first;}
};
extern "C" void fn_8034cc3c(F19bVector*,F19bEntry*,unsigned,const F19bEntry*);
struct F19bOwner {char prefix[20];F19bVector entries;char unknown[40];unsigned count;};
extern "C" void f19b_resize_801920b8(F19bOwner*self,unsigned count){
 {F19bEntry value;F19bVector*v=&self->entries;unsigned old=v->size();
 if(count<old)v->erase(v->begin+count,v->end);else fn_8034cc3c(v,v->end,count-old,&value);}
 self->count=count;
}
