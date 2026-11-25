// PPC32 endpoint vtable slots and global table layouts observed in the original.
struct Endpoint;struct Vtable {void *unused[8];int (*buffers)(Endpoint*,void**,unsigned int*,void**,unsigned int*);void *gap[3];int (*ready)(Endpoint*);};struct Endpoint{Vtable*vtable;};
extern "C" unsigned int enabled_804abce4;extern "C" unsigned int active_80473724[];extern "C" Endpoint *endpoints_804738a4[];

extern "C" void *find_802eed00(const void*,int,unsigned int);extern "C" void control_802cccbc(unsigned int);
extern "C" void w3d_cx12b_endpoint_scan_control_802ccbfc(unsigned int index){if(*(unsigned int*)((index<<2)+(unsigned char*)active_80473724)){void*a,*b;unsigned int na,nb;Endpoint*p=*(Endpoint**)((index<<2)+(unsigned char*)endpoints_804738a4);if(p->vtable->buffers(p,&a,&na,&b,&nb)>=0){if(na||nb){if(find_802eed00(a,3,na)||find_802eed00(b,3,nb))control_802cccbc(index);}}}}

