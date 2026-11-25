// Inferred text-list data and partial selection-owner state.
struct F1pNamedArray{char unknown[24];int count;int unknown28;const char*values[1];};struct F1pNamedData{char unknown[28];F1pNamedArray*names;};
struct F1pNamedOwner{char unknown[188];int state;char unknown192[88];void*source;void*panel;char unknown288[8];int selected;};
extern "C" void*fn_80341584(void*);extern "C" F1pNamedData*fn_801797b4(void*);extern "C" int fn_802ef234(const char*,const char*);extern "C" void fn_802b8be0(F1pNamedOwner*),fn_802bc8b4(void*,int),fn_802b83ac(F1pNamedOwner*,int,int);
extern "C" void w3d_select_named_record_802b9ae0(F1pNamedOwner*self,const char*name){
 if(self->source){F1pNamedArray*list=fn_801797b4(fn_80341584(self->source))->names;int count=list->count;const char**names=list->values;
 if(count){int i;for(i=0;count!=i;++i)if(fn_802ef234(name,names[i])==0)break;if(count!=i)self->selected=i;else self->selected=0;fn_802b8be0(self);if(self->panel&&self->state==1){fn_802bc8b4(self->panel,self->selected);fn_802b83ac(self,self->selected,1);}}
 }
}
