// Inferred endpoint promotion and observed virtual slots. Four output words and the frame are observed; complete original declarations remain unknown.
typedef unsigned int cc31b_u32;
struct Cc31bEndpoint_802cccbc;
struct Cc31bEndpointTable_802cccbc {
    void (*unused0)(); void (*unused1)(); void (*unused2)();
    void (*retain)(Cc31bEndpoint_802cccbc*);
    void (*release)(Cc31bEndpoint_802cccbc*);
    void (*unused5)();
    int (*write)(Cc31bEndpoint_802cccbc*,const char*,cc31b_u32,int);
    void (*unused7)(); void (*query)(Cc31bEndpoint_802cccbc*,cc31b_u32*,cc31b_u32*,cc31b_u32*,cc31b_u32*); int (*seek)(Cc31bEndpoint_802cccbc*,cc31b_u32,int); void (*unused10)();
    void (*flush)(Cc31bEndpoint_802cccbc*);
    void (*unused12)();
    int (*accept)(Cc31bEndpoint_802cccbc*,void*);
};
struct Cc31bEndpoint_802cccbc { Cc31bEndpointTable_802cccbc *table;
 int seek(cc31b_u32 offset,int mode) { return table->seek(this,offset,mode); }
};
struct Cc31bAccepted_802cccbc { Cc31bEndpoint_802cccbc *endpoint; cc31b_u32 opaque[1]; };
struct Cc31bReplyTable_802cccbc { const char *text[10]; };
extern "C" {
extern int lbl_804abce4;
extern Cc31bEndpoint_802cccbc *lbl_804b10b0;
extern char lbl_804b1964[4],lbl_804b1960[4];
extern Cc31bEndpoint_802cccbc *lbl_80473764[16];
extern Cc31bReplyTable_802cccbc lbl_80403f54[];
extern const char *lbl_804abcc4;
cc31b_u32 fn_802ef9c0(const char*);
void fn_802cce78(Cc31bEndpoint_802cccbc*);
}
extern "C" {
extern Cc31bEndpoint_802cccbc *lbl_80473724[];
extern Cc31bEndpoint_802cccbc *lbl_804738a4[];
extern cc31b_u32 lbl_804a9cf8[];
extern int lbl_804abce8;
void fn_802cc01c(Cc31bEndpoint_802cccbc*,const char*,int);
}
static inline void cc31b_clear_802cccbc(Cc31bEndpoint_802cccbc **slot,Cc31bEndpoint_802cccbc *value) {
 Cc31bEndpoint_802cccbc *old=*slot;
 if(old) old->table->release(old);
 *slot=value;
}
extern "C" void w3d_cc31b_promote_endpoint_802cccbc(cc31b_u32 index) {
 if(lbl_804abce4 && index<17 && *(Cc31bEndpoint_802cccbc**)((index<<2)+(char*)lbl_80473724)) {
  struct Cc31bPosition_802cccbc { cc31b_u32 x,y,z,w; } pos;
  Cc31bEndpoint_802cccbc *file=*(Cc31bEndpoint_802cccbc**)((index<<2)+(char*)lbl_804738a4);
  file->table->query(file,&pos.x,&pos.y,&pos.z,&pos.w);
  Cc31bEndpoint_802cccbc *positionFile=*(Cc31bEndpoint_802cccbc**)((index<<2)+(char*)lbl_804738a4);
  positionFile->seek(pos.y+pos.w,0);
  cc31b_u32 slot=0;
  if(lbl_80473764[0]) do { ++slot; if(slot>15) break; } while(lbl_80473764[slot]);
  if(slot==16) {
   Cc31bEndpoint_802cccbc **source=(Cc31bEndpoint_802cccbc**)((index<<2)+(char*)lbl_80473724);
   fn_802cc01c(*source,lbl_804abcc4,1);
   cc31b_u32 zero=0;
   Cc31bEndpoint_802cccbc *old=*source;
   lbl_804a9cf8[index]=zero;
   if(old) old->table->release(old);
   *source=0;
  } else {
   Cc31bEndpoint_802cccbc **source=(Cc31bEndpoint_802cccbc**)((index<<2)+(char*)lbl_80473724);
   Cc31bEndpoint_802cccbc **dest=(Cc31bEndpoint_802cccbc**)((slot<<2)+(char*)lbl_80473764);
   if(*source) (*source)->table->retain(*source);
   if(*dest) (*dest)->table->release(*dest);
   *dest=*source;
   cc31b_clear_802cccbc(source,0);
   Cc31bEndpoint_802cccbc *next=*dest;
   lbl_804a9cf8[index]=0;
   fn_802cce78(next);
  }
  lbl_804abce8=1;
 }
}
