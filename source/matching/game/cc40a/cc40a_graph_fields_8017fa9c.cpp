// Partial graph/property reader views inferred from original field and slot offsets.
// Queried interface ownership lasts through the flags read and interface conversion.
struct cc40a_GraphInterface;
struct cc40a_GraphVtable { void* unknown00[2]; int (*query)(cc40a_GraphInterface*,const void*,cc40a_GraphInterface**); void* unknown0c; int (*release)(cc40a_GraphInterface*); };
struct cc40a_GraphInterface { cc40a_GraphVtable* vtable; };
struct cc40a_GraphReader;
struct cc40a_GraphReaderVtable { void* unknown00[8]; int (*readObject)(cc40a_GraphReader*,cc40a_GraphInterface**,const char*); void* unknown24[21]; int (*readFlags)(cc40a_GraphReader*,unsigned short*,const char*); };
struct cc40a_GraphReader { cc40a_GraphReaderVtable* vtable; };
struct cc40a_GraphObject { unsigned char unknown00[36]; unsigned short flags; unsigned char unknown26[2]; cc40a_GraphInterface* graph; };
extern "C" int cc40a_graphBase_80190538(cc40a_GraphObject*,cc40a_GraphReader*);
extern "C" const char cc40a_graphKey_803a7788[],cc40a_flagsKey_803a7794[];
extern "C" const unsigned char cc40a_graphId_8040e058[];
struct cc40a_GraphHandle {cc40a_GraphInterface* pointer;cc40a_GraphHandle():pointer(0){}~cc40a_GraphHandle(){if(pointer)pointer->vtable->release(pointer);}};
extern "C" int cc40a_graph_fields_8017fa9c(cc40a_GraphObject* self,cc40a_GraphReader* reader){
 int result=cc40a_graphBase_80190538(self,reader);
 if(result<0)return result;
 cc40a_GraphHandle local;
 reader->vtable->readObject(reader,&local.pointer,cc40a_graphKey_803a7788);
 reader->vtable->readFlags(reader,&self->flags,cc40a_flagsKey_803a7794);
 cc40a_GraphInterface* graph=local.pointer;
 if(graph)graph->vtable->query(graph,cc40a_graphId_8040e058,&self->graph);
 else {if(self->graph)self->graph->vtable->release(self->graph);self->graph=graph;}
 return 0;
}
