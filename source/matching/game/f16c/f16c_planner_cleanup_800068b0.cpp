// External buffer/name views only; native delete boundaries witnessed by callers.
extern "C" void free_802134fc(void*),delete_80015264(void*),clear12_803414b4(void*),clearNames_80341518(void*),clear16_80341450(void*),prepare_80020b20(void*),finish0_80015db8(),finish1_80015e64(),owner_8001cac4(void*),finish_8020c5c4(void*),release_80341588(void*);
extern "C" void *copy_802eee50(void*,const void*,unsigned,...);
struct F16cPlannerBuffer{static void operator delete(void*);char *begin,*end;~F16cPlannerBuffer(){if(begin)free_802134fc(begin);}void clear(){int bytes=end-begin;copy_802eee50(begin,end,0);end-=bytes;}};
struct F16cPlannerOtherBuffer{static void operator delete(void*);char *begin,*end;~F16cPlannerOtherBuffer(){if(begin)free_802134fc(begin);}void clear(){int bytes=end-begin;copy_802eee50(begin,end,0);end-=bytes;}};
struct F16cPlannerString{const char*text;~F16cPlannerString(){finish_8020c5c4(this);release_80341588(this);}};
struct F16cPlannerName{static void operator delete(void*);int unknown0;F16cPlannerString name;};
extern F16cPlannerBuffer *buffer_804aa558,*buffer_804aa55c,*buffer_804aa560,*buffer_804aa750,*buffer_804aa754,*buffer_804aa564;
extern F16cPlannerOtherBuffer *buffer_804aa75c;extern F16cPlannerName *name_804aa6d4;
extern void *owner_804b1760,*owner_804b1758,*storage_804aa5a8;
extern int field_804aa758,field_804aa580,field_804aa584,field_804aa568,field_804aa588,field_804aa58c,field_804aa590,field_804aa598,field_804aa59c,field_804aa5a0;
extern "C" void f16c_planner_cleanup_800068b0(int keepOwner){
 if(buffer_804aa558){clear12_803414b4(buffer_804aa558);delete buffer_804aa558;buffer_804aa558=0;}
 if(buffer_804aa55c){clear12_803414b4(buffer_804aa55c);delete buffer_804aa55c;buffer_804aa55c=0;}
 if(buffer_804aa560){clear12_803414b4(buffer_804aa560);delete buffer_804aa560;buffer_804aa560=0;}
 if(buffer_804aa750){clearNames_80341518(buffer_804aa750);delete buffer_804aa750;buffer_804aa750=0;}
 if(buffer_804aa754){buffer_804aa754->clear();delete buffer_804aa754;buffer_804aa754=0;}
 field_804aa758=0;
 if(buffer_804aa75c){buffer_804aa75c->clear();delete buffer_804aa75c;buffer_804aa75c=0;}
 if(buffer_804aa564){prepare_80020b20(owner_804b1760);clear16_80341450(buffer_804aa564);delete buffer_804aa564;buffer_804aa564=0;}
 finish0_80015db8();if(!keepOwner)owner_8001cac4(owner_804b1758);finish1_80015e64();
 delete name_804aa6d4;name_804aa6d4=0;delete_80015264(storage_804aa5a8);
 field_804aa580=-1;field_804aa584=60;storage_804aa5a8=0;field_804aa588=0;field_804aa58c=0;field_804aa590=0;field_804aa598=0;field_804aa59c=0;field_804aa5a0=0;field_804aa568=0;
}
