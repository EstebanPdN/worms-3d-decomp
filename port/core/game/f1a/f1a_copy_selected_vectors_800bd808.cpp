#include "w3d_ptr.h"
#line 1 "f1a_copy_selected_vectors_800bd808.cpp"
// Original 0x800bd808; selection interpretation inferred from observed masks.
struct F1aSelectionRange {Ptr32<Ptr32<int>> begin; Ptr32<Ptr32<int>> end;int pad;};
extern "C" {
extern F1aSelectionRange lbl_8043bb64;
extern float lbl_80382cf8[];
void fn_800bcdec(Ptr32<void>,float);
void w3d_collect_selected_800bcd6c(Ptr32<void>);
int fn_800b5fc0(Ptr32<int>,Ptr32<void>);
void w3d_f1a_copy_selected_vectors_800bd808(Ptr32<char> self) {
 unsigned bit=1;
 Ptr32<char> output=self+256;
 fn_800bcdec(self,lbl_80382cf8[0]);
 w3d_collect_selected_800bcd6c(self);
 Ptr32<Ptr32<int>> cursor=lbl_8043bb64.begin; Ptr32<Ptr32<int>> end=lbl_8043bb64.end;
 if(cursor!=end){
  Ptr32<unsigned int> mask=(Ptr32<unsigned int>)(self+128);
  do{
   if(*mask&bit){fn_800b5fc0(*cursor,output);output+=12;}
   bit<<=1;
   if(!bit){bit=1;++mask;}
   ++cursor;
  }while(cursor!=end);
 }
}
}


