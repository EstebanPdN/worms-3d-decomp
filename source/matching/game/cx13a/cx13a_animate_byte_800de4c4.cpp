// Observed PPC32 fields and pointer arithmetic; semantic names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
extern "C" void w3d_cx13a_animate_byte_800de4c4(void *self,unsigned now,unsigned char *out,void *parameters,unsigned limit){
 float elapsed=(float)(now-FIELD(self,unsigned,100));if(limit){if(FIELD(parameters,unsigned short,0x18c)==0)*out=FIELD(parameters,unsigned char,0x1e4);
 else{unsigned frame=FIELD(self,unsigned char,0x69)+(unsigned)(elapsed/(float)FIELD(self,int,0x60));*out=FIELD(parameters,unsigned char,0x1e4)+frame%(unsigned)(int)FIELD(parameters,signed char,0x1ec);}if(*out<=limit)return;}*out=(unsigned char)limit;
}
