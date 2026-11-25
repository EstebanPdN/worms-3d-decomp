#include "w3d_ptr.h"
#line 1 "cc40a_graph_fields_8017fa9c.cpp"
// Partial graph/property reader views inferred from original field and slot offsets.
// Queried interface ownership lasts through the flags read and interface conversion.
struct cc40a_GraphInterface;
struct cc40a_GraphVtable { Ptr32<void> unknown00[2]; Ptr32<int (Ptr32<cc40a_GraphInterface>, Ptr32<const void>, Ptr32<Ptr32<cc40a_GraphInterface>>)> query; Ptr32<void> unknown0c; Ptr32<int (Ptr32<cc40a_GraphInterface>)> release; };
struct cc40a_GraphInterface { Ptr32<cc40a_GraphVtable> vtable; };
struct cc40a_GraphReader;
struct cc40a_GraphReaderVtable { Ptr32<void> unknown00[8]; Ptr32<int (Ptr32<cc40a_GraphReader>, Ptr32<Ptr32<cc40a_GraphInterface>>, Ptr32<const char>)> readObject; Ptr32<void> unknown24[21]; Ptr32<int (Ptr32<cc40a_GraphReader>, Ptr32<unsigned short>, Ptr32<const char>)> readFlags; };
struct cc40a_GraphReader { Ptr32<cc40a_GraphReaderVtable> vtable; };
struct cc40a_GraphObject { unsigned char unknown00[36]; unsigned short flags; unsigned char unknown26[2]; Ptr32<cc40a_GraphInterface> graph; };
extern "C" int cc40a_graphBase_80190538(Ptr32<cc40a_GraphObject>,Ptr32<cc40a_GraphReader>);
extern "C" const char cc40a_graphKey_803a7788[],cc40a_flagsKey_803a7794[];
extern "C" const unsigned char cc40a_graphId_8040e058[];
struct cc40a_GraphHandle {Ptr32<cc40a_GraphInterface> pointer;cc40a_GraphHandle():pointer(0){}~cc40a_GraphHandle(){if(pointer)pointer->vtable->release(pointer);}};
extern "C" int cc40a_graph_fields_8017fa9c(Ptr32<cc40a_GraphObject> self,Ptr32<cc40a_GraphReader> reader){
 int result=cc40a_graphBase_80190538(self,reader);
 if(result<0)return result;
 cc40a_GraphHandle local;
 reader->vtable->readObject(reader,&local.pointer,cc40a_graphKey_803a7788);
 reader->vtable->readFlags(reader,&self->flags,cc40a_flagsKey_803a7794);
 Ptr32<cc40a_GraphInterface> graph=local.pointer;
 if(graph)graph->vtable->query(graph,cc40a_graphId_8040e058,&self->graph);
 else {if(self->graph)self->graph->vtable->release(self->graph);self->graph=graph;}
 return 0;
}


