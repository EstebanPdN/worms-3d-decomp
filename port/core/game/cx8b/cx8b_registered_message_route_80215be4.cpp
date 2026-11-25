#include "w3d_ptr.h"
#line 1 "cx8b_registered_message_route_80215be4.cpp"

extern "C" int count_804b06c4;
extern "C" int ids_804640c0[];
extern "C" void fn_8021573c(Ptr32<void>,Ptr32<void>,int,Ptr32<void>,Ptr32<void>,int);
extern "C" void w3d_cx8b_registered_message_route_80215be4(Ptr32<void> self,int id,Ptr32<void> first,Ptr32<void> second,Ptr32<void> third) {
 if(count_804b06c4>=0) {
  Ptr32<int> it=ids_804640c0+count_804b06c4;
  do { int value=*it--; if(value==id) {fn_8021573c(self,(Ptr32<void>)w3d::G(id),(int)w3d::H(third),first,second,4);return;} }while((int)w3d::H(it)>=(int)w3d::H(ids_804640c0));
 }
}




