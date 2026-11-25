// Partial native GC32 interfaces and a genuine scoped held reference.
namespace sol35d9_bind_interfaces {
struct Interface;
typedef void (*GenericCall)();
struct Methods {
 GenericCall unknown0,unknown4;
 void (*query)(Interface *,const void *,Interface **);
 void (*retain)(Interface *);
 void (*release)(Interface *);
 GenericCall unknown20,unknown24,unknown28;
 int (*bind)(Interface *,Interface *,void *);
};
struct Interface {Methods *vtable;};
extern "C" unsigned char lbl_8040c970[];
struct Held {
 Interface *pointer;
 Held():pointer(0) {}
 ~Held() {if(pointer)pointer->vtable->release(pointer);}
};
inline void query(Interface *entry,Held &out) {
 if(entry)entry->vtable->query(entry,lbl_8040c970,&out.pointer);
 else out.pointer=entry;
}
typedef char HeldSize[(sizeof(Held)==4)?1:-1];
}
extern "C" int sol35d9_bind_interfaces_801ff704(void *unused,
 sol35d9_bind_interfaces::Interface *target,sol35d9_bind_interfaces::Interface **input,
 void *argument,unsigned count) {
 using namespace sol35d9_bind_interfaces;
 for(unsigned i=0;i<count;++i) {
  Held value;
  query(*input,value);
  int result=target->vtable->bind(target,value.pointer,argument);
  if(result<0)return result;
  ++input;
 }
 return 0;
}
