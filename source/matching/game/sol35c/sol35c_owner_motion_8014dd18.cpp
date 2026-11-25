// Observed actor prefix offsets. Names describe the local actions only.
#define SOL35C_FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
struct Sol35cMessage { unsigned short id,unused; void *table; };
extern "C" void *fn_80164fc8(int);
extern "C" int fn_800cfc98(void *);
extern "C" int fn_800cfe68(void *,void *,void *,void *);
extern "C" Sol35cMessage *fn_801613f0(int,unsigned);
extern "C" unsigned short fn_8015f5a0(void *,int);
extern "C" int fn_8016239c(void *);
extern float lbl_803a1688[],lbl_803a168c[];
extern unsigned char lbl_8040db38[];
extern unsigned lbl_804afbf8;
extern int lbl_804b1754;
extern "C" int sol35c_owner_motion_8014dd18(void *self) {
 int handle=SOL35C_FIELD(self,int,788);
 if(handle==-1)return 0;
 void *owner=fn_80164fc8(handle);
 if(!owner){SOL35C_FIELD(self,int,788)=-1;return 0;}
 int mode=fn_800cfc98(owner);
 if(mode)fn_800cfe68(owner,(char *)self+560,(char *)self+676,(char *)self+572);
 else {
  if(SOL35C_FIELD(self,int,716)!=0 || SOL35C_FIELD(self,int,824)<0) {
   if(SOL35C_FIELD(owner,int,120)) {
    Sol35cMessage *message=fn_801613f0(lbl_804b1754,8);
    message->id=fn_8015f5a0(&lbl_804afbf8,1);
    message->table=lbl_8040db38;
    fn_8016239c(message);
    return 0;
   }
  }else SOL35C_FIELD(self,float,572)+=SOL35C_FIELD(owner,float,268)*lbl_803a1688[0]*lbl_803a168c[0];
 }
 return mode;
}
