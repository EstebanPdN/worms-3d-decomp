// Observed PPC32 controller layout: two 128 by 6 tables at +64 and +3136.
// Names express inferred responsibilities; the word at +48 is not initialized here.
extern "C" void * string_803426b8(void*);
// Observed PPC32 controller layout: two 128 by 6 tables at +64 and +3136.
// Names express inferred responsibilities; the word at +48 is not initialized here.
extern "C" int base_8015fef0(void*);
extern int table_8040f7d8[];
struct Cc17aString {unsigned value;Cc17aString(){string_803426b8(this);}};
struct Cc17aWord {int value;Cc17aWord(){value=0;}};
struct Cc17aHeader {unsigned begin,end,capacity;Cc17aHeader(){capacity=0;end=0;begin=0;}};
struct Cc17aBase{char body[28];Cc17aBase(){base_8015fef0(this);*(void**)this=table_8040f7d8;}};
struct Cc17aActor;extern Cc17aActor *global_804aad30;
struct Cc17aActor:Cc17aBase {
 int a,b,c,d,e,unknown;Cc17aHeader header;Cc17aString names[128][6];int values[128][6];int final;
 Cc17aActor():a(0),b(0),c(0),e(0){int *row=&values[0][0];int i=127;do{int *p=row;row+=6;int j=6;--i;do{*p++=0;}while(--j);}while(i!=-1);final=0;d=0;global_804aad30=this;}
};
inline void*operator new(unsigned,void*p){return p;}
extern "C" Cc17aActor *w3d_cc17a_table_actor_construct_800b94b0(void*self){return new(self) Cc17aActor;}
