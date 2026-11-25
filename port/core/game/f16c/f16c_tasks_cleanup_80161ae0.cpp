#include "w3d_ptr.h"
#line 1 "f16c_tasks_cleanup_80161ae0.cpp"
// External partial views. Twelve-byte owned buffer entries are witnessed by
// original stride12, first pointer release, and array count cookie at -8.
extern "C" void free_802134fc(Ptr32<void>),arrayfree_801fe240(Ptr32<void>),prepare_80162480(Ptr32<void>),base_801628ec(Ptr32<void>,int);
extern "C" int find_80161ffc(unsigned short,Ptr32<Ptr32<void>>);
extern Ptr32<void> vtable_804117c8[];
struct F16cTaskOwner{Ptr32<Ptr32<void>> vtable;};
struct F16cTaskRange{Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end;};extern F16cTaskRange range_80455244[];
extern unsigned count_804ab498;extern int active_804ab4a0;extern Ptr32<void> names_804ab4a4;
struct F16cTaskRecord{char unknown0[8];unsigned short id;short unknown10;int live;int unknown16;};extern Ptr32<F16cTaskRecord> records_804ab4a8;
struct F16cTaskBuffer{Ptr32<void> begin;unsigned unknown4,unknown8;~F16cTaskBuffer(){if(begin)free_802134fc(begin);}};
extern Ptr32<F16cTaskBuffer> array_804ab4ac; extern Ptr32<F16cTaskBuffer> array_804ab4b0; extern Ptr32<F16cTaskBuffer> array_804ab4b4; extern Ptr32<F16cTaskBuffer> array_804ab4b8;
static inline void destroyArray(Ptr32<F16cTaskBuffer> &array){if(array){Ptr32<F16cTaskBuffer> end=array+((Ptr32<unsigned int>)array)[-2];while(array!=end){--end;end->~F16cTaskBuffer();}arrayfree_801fe240((Ptr32<char>)array-8);}}
extern "C" void f16c_tasks_cleanup_80161ae0(Ptr32<F16cTaskOwner> self,int flags){
 self->vtable=vtable_804117c8;prepare_80162480(self);
 Ptr32<void> found;
 if((unsigned)(range_80455244[0].end-range_80455244[0].begin)!=count_804ab498){for(unsigned i=0;i<count_804ab498;++i){if(records_804ab4a8[i].live)find_80161ffc(records_804ab4a8[i].id,&found);}}
 if(names_804ab4a4)arrayfree_801fe240(names_804ab4a4);
 if(records_804ab4a8)arrayfree_801fe240(records_804ab4a8);
 destroyArray(array_804ab4ac);destroyArray(array_804ab4b0);destroyArray(array_804ab4b4);destroyArray(array_804ab4b8);
 active_804ab4a0=0;base_801628ec(self,flags);
}


