// Text writer for an array-valued binding: "<type>[0] { }" without an object,
// otherwise "<type>[<count>] { e0, e1, ... }". Elements of a directly writable
// type (0x801fff60) are written straight to the output (element type slot 21);
// other elements are read into a temporary text through slot 17 and that text
// is not written here, as in the original. Same binding layout as
// s21_fb_801eb3f4 (info: +4 halfword object offset, +8 element type). The
// writer helpers return the writer, so the header is one chained expression.
// The type-name query receives the direct type, null for indirect types, as in
// the original. Partial external views; names inferred; strings stay external.
struct Mx23oaWriter;
struct Mx23oaText_803426b8;
extern "C" void fn_8020c5c4(Mx23oaText_803426b8*);
extern "C" void fn_80341588(Mx23oaText_803426b8*);
struct Mx23oaText_803426b8 {
 char*data;
 Mx23oaText_803426b8();
 ~Mx23oaText_803426b8(){fn_8020c5c4(this);fn_80341588(this);}
};
struct Mx23oaElementType;
struct Mx23oaElementTypeMethods {
 void(*reserved[17])(void);
 int(*read_text)(Mx23oaElementType*,Mx23oaText_803426b8*,char*,int,int);
 void(*reserved2[3])(void);
 int(*read_direct)(Mx23oaElementType*,Mx23oaWriter*,char*,int);
};
struct Mx23oaElementType {Mx23oaElementTypeMethods*methods;};
struct Mx23oaArrayStore {char unknown[24];unsigned count;char unknown28[4];char data[1];};
struct Mx23oaArrayInfo {char unknown[4];unsigned short offset;char unknown6[2];Mx23oaElementType*element;};
struct Mx23oaArrayBinding {Mx23oaArrayInfo*info;};
extern const char lbl_803b0d4c[],lbl_803b0d54[],lbl_803b0d58[],lbl_803b0d60[],lbl_803b0d64[];
extern "C" Mx23oaWriter*fn_8020dbf8(Mx23oaWriter*,const char*);
extern "C" Mx23oaWriter*fn_8020d980(Mx23oaWriter*,unsigned);
extern "C" const char*fn_801ffea8(Mx23oaElementType*);
extern "C" int fn_801fff60(Mx23oaElementType*);
extern "C" int fn_80200050(Mx23oaElementType*);
extern "C" void mx23oa_write_array_801ef7d8(Mx23oaArrayBinding*self,Mx23oaWriter*out,char*object){
 if(!object){
  fn_8020dbf8(fn_8020dbf8(out,fn_801ffea8(self->info->element)),lbl_803b0d4c);
  return;
 }
 Mx23oaArrayStore*store=*(Mx23oaArrayStore**)(object+self->info->offset);
 unsigned count=store->count;
 char*element=store->data;
 int stride=fn_80200050(self->info->element);
 Mx23oaElementType*direct=0;
 if(fn_801fff60(self->info->element))direct=self->info->element;
 fn_8020dbf8(fn_8020d980(fn_8020dbf8(fn_8020dbf8(out,fn_801ffea8(direct)),lbl_803b0d54),store->count),lbl_803b0d58);
 Mx23oaText_803426b8 text;
 for(unsigned i=0;i<count;++i){
  if(direct)direct->methods->read_direct(direct,out,element,0);
  else{Mx23oaElementType*type=self->info->element;type->methods->read_text(type,&text,element,0,0);}
  element+=stride;
  if(i<count-1)fn_8020dbf8(out,lbl_803b0d60);
 }
 fn_8020dbf8(out,lbl_803b0d64);
}
