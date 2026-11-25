// Font-resource prefix offsets and packed glyph identifiers are observed.
#define SOL35C_FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
struct Sol35cGlyph { unsigned short sort_key,code,index; };
extern "C" void fn_801fe240(void *);
extern "C" void *fn_801fe220(unsigned);
extern "C" int fn_8018b628(const void *,const void *);
extern "C" void qsort(void *,unsigned,unsigned,int (*)(const void *,const void *));
extern "C" int sol35c_sorted_glyphs_8018b638(void *self) {
 void *old=SOL35C_FIELD(self,void *,68);
 if(old)fn_801fe240(old);
 void *resource=SOL35C_FIELD(self,void *,36);
 char *indices=SOL35C_FIELD(resource,char *,36);
 unsigned count=SOL35C_FIELD(indices,unsigned,24)-1;
 SOL35C_FIELD(self,unsigned,72)=count;
 SOL35C_FIELD(self,void *,68)=fn_801fe220(count*6);
 resource=SOL35C_FIELD(self,void *,36);
 char *pages=SOL35C_FIELD(resource,char *,28)+32;
 unsigned i=0;
 if(i<SOL35C_FIELD(self,unsigned,72)) {
  unsigned short *source=(unsigned short *)(indices+34);
  unsigned offset=0;
  do {
   unsigned short code=*source;
   unsigned next=i+1;
   char *record=SOL35C_FIELD(self,char *,68)+offset;
   char *page=SOL35C_FIELD(pages,char *,((code>>8)&255)*4);
   char *keys=SOL35C_FIELD(page,char *,40)+32;
   unsigned short key=SOL35C_FIELD(keys,unsigned short,(code&255)*2);
   SOL35C_FIELD(record,unsigned short,2)=code;
   SOL35C_FIELD(SOL35C_FIELD(self,char *,68),unsigned short,offset)=key;
   SOL35C_FIELD(SOL35C_FIELD(self,char *,68),unsigned short,offset+4)=next;
   ++source;offset+=6;i=next;
  }while(i<SOL35C_FIELD(self,unsigned,72));
 }
 qsort(SOL35C_FIELD(self,void *,68),SOL35C_FIELD(self,unsigned,72),6,fn_8018b628);
 return 0;
}
