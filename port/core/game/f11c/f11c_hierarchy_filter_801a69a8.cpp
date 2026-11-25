#include "w3d_ptr.h"
#line 1 "f11c_hierarchy_filter_801a69a8.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
struct F11c_Type412{char unknown[20];Ptr32<F11c_Type412> parent;bool contains(Ptr32<const F11c_Type412> target)const{Ptr32<const F11c_Type412> p=this;while(p!=target){if(p==p->parent)return false;p=p->parent;}return true;}};
extern F11c_Type412 lbl_80362754[],lbl_803627f4[];
struct F11c_Object412{Ptr32<Ptr32<void>> table;Ptr32<F11c_Type412> type(){return ((Ptr32<Ptr32<F11c_Type412> (Ptr32<F11c_Object412>)>)table[5])(this);}};
inline bool reject412(bool accepted){return !accepted;}
struct F11c_Filter412{char unknown[44];int mode;int unknown48;Ptr32<int (Ptr32<F11c_Object412>, bool, Ptr32<void>)> hook;Ptr32<void> context;Ptr32<Ptr32<F11c_Type412>> begin; Ptr32<Ptr32<F11c_Type412>> end;unsigned unknown68;int value;};
extern "C" bool f11c_hierarchy_801a69a8(Ptr32<F11c_Filter412> self,Ptr32<F11c_Object412> object){bool selected=false;switch(self->mode){case 1:selected=reject412(object->type()->contains(lbl_80362754));if(selected)selected=reject412(object->type()->contains(lbl_803627f4));break;case 0:return self->value==0;case 2:break;}Ptr32<Ptr32<F11c_Type412>> begin=self->begin;Ptr32<Ptr32<F11c_Type412>> end=self->end;Ptr32<F11c_Type412> type=object->type();for(;begin!=end;++begin)if(type->contains(*begin)){selected=true;break;}if(self->hook)return self->hook(object,!selected,self->context)==0;return selected;}



