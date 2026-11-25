// External partial views. Twelve-byte owned buffer entries are witnessed by
// original stride12, first pointer release, and array count cookie at -8.
extern "C" void free_802134fc(void*),arrayfree_801fe240(void*),prepare_80162480(void*),base_801628ec(void*,int);
extern "C" int find_80161ffc(unsigned short,void**);
extern void *vtable_804117c8[];
struct F16cTaskOwner{void **vtable;};
struct F16cTaskRange{void **begin,**end;};extern F16cTaskRange range_80455244[];
extern unsigned count_804ab498;extern int active_804ab4a0;extern void *names_804ab4a4;
struct F16cTaskRecord{char unknown0[8];unsigned short id;short unknown10;int live;int unknown16;};extern F16cTaskRecord *records_804ab4a8;
struct F16cTaskBuffer{void *begin;unsigned unknown4,unknown8;~F16cTaskBuffer(){if(begin)free_802134fc(begin);}};
extern F16cTaskBuffer *array_804ab4ac,*array_804ab4b0,*array_804ab4b4,*array_804ab4b8;
static inline void destroyArray(F16cTaskBuffer *&array){if(array){F16cTaskBuffer *end=array+((unsigned*)array)[-2];while(array!=end){--end;end->~F16cTaskBuffer();}arrayfree_801fe240((char*)array-8);}}
extern "C" void f16c_tasks_cleanup_80161ae0(F16cTaskOwner*self,int flags){
 self->vtable=vtable_804117c8;prepare_80162480(self);
 void *found;
 if((unsigned)(range_80455244[0].end-range_80455244[0].begin)!=count_804ab498){for(unsigned i=0;i<count_804ab498;++i){if(records_804ab4a8[i].live)find_80161ffc(records_804ab4a8[i].id,&found);}}
 if(names_804ab4a4)arrayfree_801fe240(names_804ab4a4);
 if(records_804ab4a8)arrayfree_801fe240(records_804ab4a8);
 destroyArray(array_804ab4ac);destroyArray(array_804ab4b0);destroyArray(array_804ab4b4);destroyArray(array_804ab4b8);
 active_804ab4a0=0;base_801628ec(self,flags);
}
