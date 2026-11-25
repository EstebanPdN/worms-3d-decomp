#include "w3d_ptr.h"
#line 1 "f3a_comment_8028ebe0.cpp"
// Roles and deque view are inferred.
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct Text_8020bb54 {
 Text_8020bb54(const Text_8020bb54 &);Ptr32<char> data;template <class W3dU> Text_8020bb54(Ptr32<W3dU> w3d_p) : Text_8020bb54((const char *)w3d_p.get()) {}
 Text_8020bb54(const char*p);~Text_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}};
struct Deque {char pad[16];Ptr32<unsigned int> current;Ptr32<void> unused;Ptr32<unsigned int> end;};
struct Owner {char pad[72];char first[20],second[28];Deque queue;};
extern "C" int fn_800fc2b0(Ptr32<Ptr32<char>>,Ptr32<Ptr32<char>>);
extern "C" int fn_800c467c(Ptr32<void>,Ptr32<char>);
extern "C" void fn_8035f16c(Ptr32<Deque>,Ptr32<unsigned int>);
extern char name_803d004c[];
inline void append(Ptr32<Deque> q,unsigned&value){if(q->current!=q->end-1){if(q->current)*q->current=value;++q->current;}else fn_8035f16c(q,&value);}
extern "C" void w3d_f3a_comment_8028ebe0(Ptr32<Owner> s,Text_8020bb54 input,unsigned value){
 Ptr32<char> name=name_803d004c; Ptr32<char> out;
 fn_800fc2b0(&name,&out);
 fn_800c467c(s->first,input.data);
 append(&s->queue,value);
 Text_8020bb54 text(out);fn_800c467c(s->second,text.data);
}


