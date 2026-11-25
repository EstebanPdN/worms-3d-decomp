// PPC32 offsets and four-byte pointer slots are observed. Semantic names inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
extern "C" void *lookup_80164fc8(unsigned);extern "C" void destroy_8015fd1c(void *);
extern "C" void w3d_cx12a_clear_ten_handles_800a3e84(void *self){
 {void *object=lookup_80164fc8(FIELD(self,unsigned,0x20));if(object)destroy_8015fd1c(object);}
 {void *object=lookup_80164fc8(FIELD(self,unsigned,0x24));if(object)destroy_8015fd1c(object);}
 {void *object=lookup_80164fc8(FIELD(self,unsigned,0x28));if(object)destroy_8015fd1c(object);}
 {void *object=lookup_80164fc8(FIELD(self,unsigned,0x2c));if(object)destroy_8015fd1c(object);}
 {void *object=lookup_80164fc8(FIELD(self,unsigned,0x30));if(object)destroy_8015fd1c(object);}
 {void *object=lookup_80164fc8(FIELD(self,unsigned,0x34));if(object)destroy_8015fd1c(object);}
 {void *object=lookup_80164fc8(FIELD(self,unsigned,0x38));if(object)destroy_8015fd1c(object);}
 {void *object=lookup_80164fc8(FIELD(self,unsigned,0x3c));if(object)destroy_8015fd1c(object);}
 {void *object=lookup_80164fc8(FIELD(self,unsigned,0x40));if(object)destroy_8015fd1c(object);}
 {void *object=lookup_80164fc8(FIELD(self,unsigned,0x44));if(object)destroy_8015fd1c(object);}
 FIELD(self,unsigned,0x20)=~0u;
 FIELD(self,unsigned,0x24)=~0u;
 FIELD(self,unsigned,0x28)=~0u;
 FIELD(self,unsigned,0x2c)=~0u;
 FIELD(self,unsigned,0x30)=~0u;
 FIELD(self,unsigned,0x34)=~0u;
 FIELD(self,unsigned,0x38)=~0u;
 FIELD(self,unsigned,0x3c)=~0u;
 FIELD(self,unsigned,0x40)=~0u;
 FIELD(self,unsigned,0x44)=~0u;
}
