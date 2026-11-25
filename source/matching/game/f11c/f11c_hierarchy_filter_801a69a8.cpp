// Names, roles, types, qualifiers and layouts are inferred from original instructions.
struct F11c_Type412{char unknown[20];F11c_Type412*parent;bool contains(const F11c_Type412*target)const{const F11c_Type412*p=this;while(p!=target){if(p==p->parent)return false;p=p->parent;}return true;}};
extern F11c_Type412 lbl_80362754[],lbl_803627f4[];
struct F11c_Object412{void**table;F11c_Type412*type(){return ((F11c_Type412*(*)(F11c_Object412*))table[5])(this);}};
inline bool reject412(bool accepted){return !accepted;}
struct F11c_Filter412{char unknown[44];int mode;int unknown48;int(*hook)(F11c_Object412*,bool,void*);void*context;F11c_Type412**begin,**end;unsigned unknown68;int value;};
extern "C" bool f11c_hierarchy_801a69a8(F11c_Filter412*self,F11c_Object412*object){bool selected=false;switch(self->mode){case 1:selected=reject412(object->type()->contains(lbl_80362754));if(selected)selected=reject412(object->type()->contains(lbl_803627f4));break;case 0:return self->value==0;case 2:break;}F11c_Type412**begin=self->begin;F11c_Type412**end=self->end;F11c_Type412*type=object->type();for(;begin!=end;++begin)if(type->contains(*begin)){selected=true;break;}if(self->hook)return self->hook(object,!selected,self->context)==0;return selected;}

