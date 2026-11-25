
struct Cx8bQueryResult;
struct Cx8bResultVtable {void *unknown00[2];int (*consume)(Cx8bQueryResult *,void *,Cx8bQueryResult **);void *unknown0c;void (*release)(Cx8bQueryResult *);};
struct Cx8bQueryResult {Cx8bResultVtable *vtable;};
struct Cx8bQueryOwner;
struct Cx8bQueryVtable {void *unknown00[8];int (*query)(Cx8bQueryOwner *,Cx8bQueryResult **,int);};
struct Cx8bQueryOwner {Cx8bQueryVtable *vtable;};
extern "C" int w3d_cx8b_interface_query_consume_802010dc(Cx8bQueryOwner *self,Cx8bQueryResult **out,void *value) {
 int result=self->vtable->query(self,out,0);
 if(result>=0) {Cx8bQueryResult *held=*out;result=held->vtable->consume(held,value,out);held->vtable->release(held);}
 do {return result;}while(0);
}


