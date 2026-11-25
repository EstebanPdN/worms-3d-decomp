// Partial GC32 multiple-inheritance owner and array-header views.
extern "C" void fn_802fa988(void *,unsigned int);
extern "C" void fn_80307d88(int,void *,int);
struct FirstBase { unsigned int first; };
struct SecondBase { unsigned int second; };
struct Owner : FirstBase,SecondBase { unsigned char unknown8[276]; unsigned int serial; unsigned int dirty; };
struct Header { unsigned char unknown0[24]; unsigned int count; unsigned short locks; unsigned char unknown30[2];
 void flush(unsigned int size) { if(locks) { fn_802fa988(this+1,size); locks=0; } }
};
struct Argument { unsigned char unknown0[24]; Header *header; };
extern "C" int sol35c2_bind_array_8016944c(SecondBase *base,Argument *arg) {
 Owner *owner=static_cast<Owner *>(base);
 Header *header=arg->header;
 unsigned int count=header->count;
 void *data=header+1;
 if(count) {
  header->flush(count*16);
  fn_80307d88(9,data,16);
  owner->dirty |= 1;
  ++owner->serial;
 }
 return 0;
}
