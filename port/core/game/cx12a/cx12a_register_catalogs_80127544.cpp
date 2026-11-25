#include "w3d_ptr.h"
#line 1 "cx12a_register_catalogs_80127544.cpp"
// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
extern Ptr32<void> service_804b17ec;
extern unsigned count_804af12c,count_804af130,count_804af134,count_804af138,count_804b0eb4,count_804b0eb8,count_804b0ebc,count_804b0ec0,count_804b0ec4;
extern unsigned char table_803f5e60[],table_803f7a6c[],table_803fcbc0[],table_803fcc80[],table_804021e8[],table_804024a4[],table_80403980[],table_804039b0[],table_804abc28[];
extern "C" void w3d_hat_register(void);
extern "C" void w3d_mapa_um_register(void);
extern "C" void w3d_francotirador_register(void);
extern "C" void w3d_cx12a_register_catalogs_80127544(){
 {Ptr32<void> svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x28)(svc,table_803f5e60,count_804af12c);}
 {Ptr32<void> svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x24)(svc,table_803f7a6c,count_804af130);}
 {Ptr32<void> svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x2c)(svc,table_803fcbc0,count_804af134);}
 {Ptr32<void> svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x34)(svc,table_803fcc80,count_804af138);}
 {Ptr32<void> svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x28)(svc,table_804021e8,count_804b0eb4);}
 {Ptr32<void> svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x24)(svc,table_804024a4,count_804b0eb8);}
 {Ptr32<void> svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x30)(svc,table_80403980,count_804b0ebc);}
 {Ptr32<void> svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x2c)(svc,table_804039b0,count_804b0ec0);}
 {Ptr32<void> svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,void *,unsigned),0x34)(svc,table_804abc28,count_804b0ec4);}
 unsigned char index=0;do{Ptr32<void> svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,unsigned char *,int),0x48)(svc,&index,0);svc=FIELD(service_804b17ec,void *,0x74);VCALL(svc,void (*)(void *,unsigned char *,int),0x54)(svc,&index,1);++index;}while(index<0x59);
 w3d_hat_register();  // Port: recursos y bundle 0x59 de la ropa de prueba (core/native/hat_militar.cpp).
 w3d_mapa_um_register();  // Port (v26): texturas y bundle 0x5A del mapa de Ultimate Mayhem (core/native/mapa_um.cpp).
 w3d_francotirador_register();  // Port (francotirador de UM): mallas y bundle 0x5F del fusil de UM (core/native/francotirador.cpp).
}


