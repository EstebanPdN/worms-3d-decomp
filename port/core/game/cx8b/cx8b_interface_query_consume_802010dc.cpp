#include "w3d_ptr.h"
#line 1 "cx8b_interface_query_consume_802010dc.cpp"

struct Cx8bQueryResult;
struct Cx8bResultVtable {Ptr32<void> unknown00[2];Ptr32<int (Ptr32<Cx8bQueryResult>, Ptr32<void>, Ptr32<Ptr32<Cx8bQueryResult>>)> consume;Ptr32<void> unknown0c;Ptr32<void (Ptr32<Cx8bQueryResult>)> release;};
struct Cx8bQueryResult {Ptr32<Cx8bResultVtable> vtable;};
struct Cx8bQueryOwner;
struct Cx8bQueryVtable {Ptr32<void> unknown00[8];Ptr32<int (Ptr32<Cx8bQueryOwner>, Ptr32<Ptr32<Cx8bQueryResult>>, int)> query;};
struct Cx8bQueryOwner {Ptr32<Cx8bQueryVtable> vtable;};
extern "C" int w3d_cx8b_interface_query_consume_802010dc(Ptr32<Cx8bQueryOwner> self,Ptr32<Ptr32<Cx8bQueryResult>> out,Ptr32<void> value) {
 int result=self->vtable->query(self,out,0);
 if(result>=0) {Ptr32<Cx8bQueryResult> held=*out;result=held->vtable->consume(held,value,out);held->vtable->release(held);}
 do {return result;}while(0);
}




