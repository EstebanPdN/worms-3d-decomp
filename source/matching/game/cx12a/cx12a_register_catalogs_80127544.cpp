// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
extern void *service_804b17ec;
extern unsigned count_804af12c,count_804af130,count_804af134,count_804af138,count_804b0eb4,count_804b0eb8,count_804b0ebc,count_804b0ec0,count_804b0ec4;
extern unsigned char table_803f5e60[],table_803f7a6c[],table_803fcbc0[],table_803fcc80[],table_804021e8[],table_804024a4[],table_80403980[],table_804039b0[],table_804abc28[];
extern "C" void w3d_cx12a_register_catalogs_80127544(){
 {void *svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x28)(svc,table_803f5e60,count_804af12c);}
 {void *svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x24)(svc,table_803f7a6c,count_804af130);}
 {void *svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x2c)(svc,table_803fcbc0,count_804af134);}
 {void *svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x34)(svc,table_803fcc80,count_804af138);}
 {void *svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x28)(svc,table_804021e8,count_804b0eb4);}
 {void *svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x24)(svc,table_804024a4,count_804b0eb8);}
 {void *svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x30)(svc,table_80403980,count_804b0ebc);}
 {void *svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x2c)(svc,table_804039b0,count_804b0ec0);}
 {void *svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x34)(svc,table_804abc28,count_804b0ec4);}
 unsigned char index=0;do{void *svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,unsigned char *,int),0x48)(svc,&index,0);svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,unsigned char *,int),0x54)(svc,&index,1);++index;}while(index<0x59);
}
