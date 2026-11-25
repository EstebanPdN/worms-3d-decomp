// Original 0x800bd808; selection interpretation inferred from observed masks.
struct F1aSelectionRange {int **begin,**end;int pad;};
extern "C" {
extern F1aSelectionRange lbl_8043bb64;
extern float lbl_80382cf8[];
void fn_800bcdec(void *,float);
void w3d_collect_selected_800bcd6c(void *);
int fn_800b5fc0(int *,void *);
void w3d_f1a_copy_selected_vectors_800bd808(char *self) {
 unsigned bit=1;
 char *output=self+256;
 fn_800bcdec(self,lbl_80382cf8[0]);
 w3d_collect_selected_800bcd6c(self);
 int **cursor=lbl_8043bb64.begin,**end=lbl_8043bb64.end;
 if(cursor!=end){
  unsigned *mask=(unsigned *)(self+128);
  do{
   if(*mask&bit){fn_800b5fc0(*cursor,output);output+=12;}
   bit<<=1;
   if(!bit){bit=1;++mask;}
   ++cursor;
  }while(cursor!=end);
 }
}
}
