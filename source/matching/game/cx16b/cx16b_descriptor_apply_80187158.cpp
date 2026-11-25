/* Literal offsets and access widths come from the original. Naming of the
   two alternative short-pairs is structural; descriptor meaning unknown. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
extern "C" void fn_8020bd38(void *,const char *);
extern "C" int w3d_cx16b_descriptor_apply_80187158(void *self,const void *input)
{
    fn_8020bd38((char *)self+20,FIELD(input,const char *,0));
    FIELD(self,unsigned char,24)=FIELD(input,unsigned char,4);
    FIELD(self,unsigned char,25)=FIELD(input,unsigned char,5);
    FIELD(self,unsigned,32)=FIELD(input,unsigned,8);
    unsigned short flags=FIELD(input,unsigned short,16);
    FIELD(self,unsigned short,56)=flags;
    if(flags&32){
        FIELD(self,unsigned short,40)=0;
        FIELD(self,unsigned short,42)=0;
        FIELD(self,unsigned short,36)=FIELD(input,unsigned short,12);
        FIELD(self,unsigned short,38)=FIELD(input,unsigned short,14);
    }else{
        FIELD(self,unsigned short,40)=FIELD(input,unsigned short,12);
        unsigned short second=FIELD(input,unsigned short,14);
        FIELD(self,unsigned short,36)=flags&32;
        FIELD(self,unsigned short,42)=second;
        FIELD(self,unsigned short,38)=flags&32;
    }
    FIELD(self,unsigned short,44)=0;
    FIELD(self,unsigned,24)&=0xffff7fffU;
    return 0;
}
