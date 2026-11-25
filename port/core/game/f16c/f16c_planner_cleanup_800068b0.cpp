#include "w3d_ptr.h"
#line 1 "f16c_planner_cleanup_800068b0.cpp"
// External buffer/name views only; native delete boundaries witnessed by callers.
extern "C" void free_802134fc(Ptr32<void>),delete_80015264(Ptr32<void>),clear12_803414b4(Ptr32<void>),clearNames_80341518(Ptr32<void>),clear16_80341450(Ptr32<void>),prepare_80020b20(Ptr32<void>),finish0_80015db8(),finish1_80015e64(),owner_8001cac4(Ptr32<void>),finish_8020c5c4(Ptr32<void>),release_80341588(Ptr32<void>);
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned,...);
struct F16cPlannerBuffer{static void operator delete(void*);Ptr32<char> begin; Ptr32<char> end;~F16cPlannerBuffer(){if(begin)free_802134fc(begin);}void clear(){int bytes=end-begin;copy_802eee50(begin,end,0);end-=bytes;}};
struct F16cPlannerOtherBuffer{static void operator delete(void*);Ptr32<char> begin; Ptr32<char> end;~F16cPlannerOtherBuffer(){if(begin)free_802134fc(begin);}void clear(){int bytes=end-begin;copy_802eee50(begin,end,0);end-=bytes;}};
struct F16cPlannerString{Ptr32<const char> text;~F16cPlannerString(){finish_8020c5c4(this);release_80341588(this);}};
struct F16cPlannerName{static void operator delete(void*);int unknown0;F16cPlannerString name;};
extern Ptr32<F16cPlannerBuffer> buffer_804aa558; extern Ptr32<F16cPlannerBuffer> buffer_804aa55c; extern Ptr32<F16cPlannerBuffer> buffer_804aa560; extern Ptr32<F16cPlannerBuffer> buffer_804aa750; extern Ptr32<F16cPlannerBuffer> buffer_804aa754; extern Ptr32<F16cPlannerBuffer> buffer_804aa564;
extern Ptr32<F16cPlannerOtherBuffer> buffer_804aa75c;extern Ptr32<F16cPlannerName> name_804aa6d4;
extern Ptr32<void> owner_804b1760; extern Ptr32<void> owner_804b1758; extern Ptr32<void> storage_804aa5a8;
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


