// Inferred names. PPC32 pointers/words are four bytes; stream and iterator offsets are observed.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;typedef unsigned long long u64;
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))

extern "C" {void *construct_8020fbd0(void *,void *,void *,void *,int,int);void * factory_8020af30();extern char type_803659b8[],type_803659e8[],name_803ea248[],name_803ea264[];}
extern "C" void w3d_cx15b_null_stream_types_initialize_8020b278(int init,int priority){if(priority==65535 && init){construct_8020fbd0(type_803659b8,name_803ea248,type_803659b8,(void *)factory_8020af30,0,0);construct_8020fbd0(type_803659e8,name_803ea264,type_803659b8,0,0,0);}}

