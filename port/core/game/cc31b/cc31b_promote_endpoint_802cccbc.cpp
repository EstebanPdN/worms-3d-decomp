#include "w3d_ptr.h"
#line 1 "cc31b_promote_endpoint_802cccbc.cpp"
// Inferred endpoint promotion and observed virtual slots. Four output words and the frame are observed; complete original declarations remain unknown.
typedef unsigned int cc31b_u32;
struct Cc31bEndpoint_802cccbc;
struct Cc31bEndpointTable_802cccbc {
    Ptr32<void (void)> unused0; Ptr32<void (void)> unused1; Ptr32<void (void)> unused2;
    Ptr32<void (Ptr32<Cc31bEndpoint_802cccbc>)> retain;
    Ptr32<void (Ptr32<Cc31bEndpoint_802cccbc>)> release;
    Ptr32<void (void)> unused5;
    Ptr32<int (Ptr32<Cc31bEndpoint_802cccbc>, Ptr32<const char>, cc31b_u32, int)> write;
    Ptr32<void (void)> unused7; Ptr32<void (Ptr32<Cc31bEndpoint_802cccbc>, Ptr32<cc31b_u32>, Ptr32<cc31b_u32>, Ptr32<cc31b_u32>, Ptr32<cc31b_u32>)> query; Ptr32<int (Ptr32<Cc31bEndpoint_802cccbc>, cc31b_u32, int)> seek; Ptr32<void (void)> unused10;
    Ptr32<void (Ptr32<Cc31bEndpoint_802cccbc>)> flush;
    Ptr32<void (void)> unused12;
    Ptr32<int (Ptr32<Cc31bEndpoint_802cccbc>, Ptr32<void>)> accept;
};
struct Cc31bEndpoint_802cccbc { Ptr32<Cc31bEndpointTable_802cccbc> table;
 int seek(cc31b_u32 offset,int mode) { return table->seek(this,offset,mode); }
};
struct Cc31bAccepted_802cccbc { Ptr32<Cc31bEndpoint_802cccbc> endpoint; cc31b_u32 opaque[1]; };
struct Cc31bReplyTable_802cccbc { Ptr32<const char> text[10]; };
extern "C" {
extern int lbl_804abce4;
extern Ptr32<Cc31bEndpoint_802cccbc> lbl_804b10b0;
extern char lbl_804b1964[4],lbl_804b1960[4];
extern Ptr32<Cc31bEndpoint_802cccbc> lbl_80473764[16];
extern Cc31bReplyTable_802cccbc lbl_80403f54[];
extern Ptr32<const char> lbl_804abcc4;
cc31b_u32 fn_802ef9c0(Ptr32<const char>);
void fn_802cce78(Ptr32<Cc31bEndpoint_802cccbc>);
}
extern "C" {
extern Ptr32<Cc31bEndpoint_802cccbc> lbl_80473724[];
extern Ptr32<Cc31bEndpoint_802cccbc> lbl_804738a4[];
extern cc31b_u32 lbl_804a9cf8[];
extern int lbl_804abce8;
void fn_802cc01c(Ptr32<Cc31bEndpoint_802cccbc>,Ptr32<const char>,int);
}
static inline void cc31b_clear_802cccbc(Ptr32<Ptr32<Cc31bEndpoint_802cccbc>> slot,Ptr32<Cc31bEndpoint_802cccbc> value) {
 Ptr32<Cc31bEndpoint_802cccbc> old=*slot;
 if(old) old->table->release(old);
 *slot=value;
}
extern "C" void w3d_cc31b_promote_endpoint_802cccbc(cc31b_u32 index) {
 if(lbl_804abce4 && index<17 && *(Ptr32<Ptr32<Cc31bEndpoint_802cccbc>>)((index<<2)+(Ptr32<char>)lbl_80473724)) {
  struct Cc31bPosition_802cccbc { cc31b_u32 x,y,z,w; } pos;
  Ptr32<Cc31bEndpoint_802cccbc> file=*(Ptr32<Ptr32<Cc31bEndpoint_802cccbc>>)((index<<2)+(Ptr32<char>)lbl_804738a4);
  file->table->query(file,&pos.x,&pos.y,&pos.z,&pos.w);
  Ptr32<Cc31bEndpoint_802cccbc> positionFile=*(Ptr32<Ptr32<Cc31bEndpoint_802cccbc>>)((index<<2)+(Ptr32<char>)lbl_804738a4);
  positionFile->seek(pos.y+pos.w,0);
  cc31b_u32 slot=0;
  if(lbl_80473764[0]) do { ++slot; if(slot>15) break; } while(lbl_80473764[slot]);
  if(slot==16) {
   Ptr32<Ptr32<Cc31bEndpoint_802cccbc>> source=(Ptr32<Ptr32<Cc31bEndpoint_802cccbc>>)((index<<2)+(Ptr32<char>)lbl_80473724);
   fn_802cc01c(*source,lbl_804abcc4,1);
   cc31b_u32 zero=0;
   Ptr32<Cc31bEndpoint_802cccbc> old=*source;
   lbl_804a9cf8[index]=zero;
   if(old) old->table->release(old);
   *source=0;
  } else {
   Ptr32<Ptr32<Cc31bEndpoint_802cccbc>> source=(Ptr32<Ptr32<Cc31bEndpoint_802cccbc>>)((index<<2)+(Ptr32<char>)lbl_80473724);
   Ptr32<Ptr32<Cc31bEndpoint_802cccbc>> dest=(Ptr32<Ptr32<Cc31bEndpoint_802cccbc>>)((slot<<2)+(Ptr32<char>)lbl_80473764);
   if(*source) (*source)->table->retain(*source);
   if(*dest) (*dest)->table->release(*dest);
   *dest=*source;
   cc31b_clear_802cccbc(source,0);
   Ptr32<Cc31bEndpoint_802cccbc> next=*dest;
   lbl_804a9cf8[index]=0;
   fn_802cce78(next);
  }
  lbl_804abce8=1;
 }
}


