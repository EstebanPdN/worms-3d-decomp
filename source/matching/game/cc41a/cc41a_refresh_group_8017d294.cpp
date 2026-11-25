// Inferred partial interface views; unknown fields and complete sizes are not established.
// The indexed view preserves the observed base-plus-index, then field-offset access.
// Dirty flags and lookup identifier remain unowned original externals.
struct cc41a_Item;
struct cc41a_ItemVtable {
 void* unknown00[13]; int (*refresh)(cc41a_Item*);
 void* unknown38[2]; int (*active)(cc41a_Item*);
 void* unknown44; const unsigned char* (*group)(cc41a_Item*);
};
struct cc41a_Item { cc41a_ItemVtable* vtable; };
struct cc41a_Owner { unsigned char unknown00[24]; cc41a_Item* items[1920]; };
struct cc41a_Control;
struct cc41a_ControlVtable {void* unknown00[12]; int (*set)(cc41a_Control*,int);};
struct cc41a_Control { cc41a_ControlVtable* vtable; };
struct cc41a_Service;
struct cc41a_ServiceVtable {void* unknown00[23]; cc41a_Control* (*lookup)(cc41a_Service*,const void*);};
struct cc41a_Service {cc41a_ServiceVtable* vtable;};
extern "C" unsigned int cc41a_dirty_804a8dd8[];
extern "C" const unsigned char cc41a_controlKey_804143e0[];
extern "C" int cc41a_begin_8020b5c8(int);
extern "C" void cc41a_end_8020b5d0();
extern "C" cc41a_Service* cc41a_service_8020b648();
inline cc41a_Control* cc41a_lookup(const void* key){cc41a_Service* service=cc41a_service_8020b648();return service->vtable->lookup(service,key);}
extern "C" int cc41a_refresh_group_8017d294(cc41a_Owner* self,const unsigned char* group){
 if(!cc41a_dirty_804a8dd8[*group])return 0;
 cc41a_dirty_804a8dd8[*group]=0;
 int status=0;
 cc41a_begin_8020b5c8(-1);
 for(unsigned short i=0;i<1920;++i){
  cc41a_Item* item=((cc41a_Owner*)((char*)self+i*4))->items[0];
  if(item && item->vtable->active(item)){
   if(*item->vtable->group(item)==*group){
    int result=item->vtable->refresh(item);
    if(result<0)status=result;
   }
  }
 }
 cc41a_Control* control=cc41a_lookup(cc41a_controlKey_804143e0);
 control->vtable->set(control,0);
 cc41a_end_8020b5d0();
 return status;
}
