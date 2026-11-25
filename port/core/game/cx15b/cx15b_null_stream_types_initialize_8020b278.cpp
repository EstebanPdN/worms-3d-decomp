#include "w3d_ptr.h"
#line 1 "cx15b_null_stream_types_initialize_8020b278.cpp"
// Inferred names. PPC32 pointers/words are four bytes; stream and iterator offsets are observed.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;typedef unsigned long long u64;
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))

extern "C" {Ptr32<void> construct_8020fbd0(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void>,int,int);Ptr32<void> factory_8020af30();extern char type_803659b8[],type_803659e8[],name_803ea248[],name_803ea264[];}
extern "C" void w3d_cx15b_null_stream_types_initialize_8020b278(int init,int priority){if(priority==65535 && init){construct_8020fbd0(type_803659b8,name_803ea248,type_803659b8,(Ptr32<void>)factory_8020af30,0,0);construct_8020fbd0(type_803659e8,name_803ea264,type_803659b8,0,0,0);}}



