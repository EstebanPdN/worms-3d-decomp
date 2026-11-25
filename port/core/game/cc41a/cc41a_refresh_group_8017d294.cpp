#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "cc41a_refresh_group_8017d294.cpp"
// Inferred partial interface views; unknown fields and complete sizes are not established.
// The indexed view preserves the observed base-plus-index, then field-offset access.
// Dirty flags and lookup identifier remain unowned original externals.
struct cc41a_Item;
struct cc41a_ItemVtable {
 Ptr32<void> unknown00[13]; Ptr32<int (Ptr32<cc41a_Item>)> refresh;
 Ptr32<void> unknown38[2]; Ptr32<int (Ptr32<cc41a_Item>)> active;
 Ptr32<void> unknown44; Ptr32<Ptr32<const unsigned char> (Ptr32<cc41a_Item>)> group;
};
struct cc41a_Item { Ptr32<cc41a_ItemVtable> vtable; };
struct cc41a_Owner { unsigned char unknown00[24]; Ptr32<cc41a_Item> items[1920]; };
struct cc41a_Control;
struct cc41a_ControlVtable {Ptr32<void> unknown00[12]; Ptr32<int (Ptr32<cc41a_Control>, int)> set;};
struct cc41a_Control { Ptr32<cc41a_ControlVtable> vtable; };
struct cc41a_Service;
struct cc41a_ServiceVtable {Ptr32<void> unknown00[23]; Ptr32<Ptr32<cc41a_Control> (Ptr32<cc41a_Service>, Ptr32<const void>)> lookup;};
struct cc41a_Service {Ptr32<cc41a_ServiceVtable> vtable;};
extern "C" unsigned int cc41a_dirty_804a8dd8[];
extern "C" const unsigned char cc41a_controlKey_804143e0[];
extern "C" int cc41a_begin_8020b5c8(int);
extern "C" void cc41a_end_8020b5d0();
extern "C" Ptr32<cc41a_Service> cc41a_service_8020b648();
inline Ptr32<cc41a_Control> cc41a_lookup(Ptr32<const void> key){Ptr32<cc41a_Service> service=cc41a_service_8020b648();return service->vtable->lookup(service,key);}
extern "C" int cc41a_refresh_group_8017d294(Ptr32<cc41a_Owner> self,Ptr32<const unsigned char> group){
 if(!cc41a_dirty_804a8dd8[*group])return 0;
 cc41a_dirty_804a8dd8[*group]=0;
 int status=0;
 cc41a_begin_8020b5c8(-1);
 Ptr32<cc41a_Item> *slots=(Ptr32<cc41a_Item> *)w3d_restab_slots(); (void)self;   // port (v29): tabla nativa
 for(unsigned short i=0;i<w3d_restab_cap();++i){
  Ptr32<cc41a_Item> item=slots[i];
  if(item && item->vtable->active(item)){
   if(*item->vtable->group(item)==*group){
    int result=item->vtable->refresh(item);
    if(result<0)status=result;
   }
  }
 }
 Ptr32<cc41a_Control> control=cc41a_lookup(cc41a_controlKey_804143e0);
 control->vtable->set(control,0);
 cc41a_end_8020b5d0();
 return status;
}


