// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))

struct Cx14aRegistry{void **begin,**end;};extern Cx14aRegistry *actors_804aa750;extern int selected_804aa6e8;extern const float scale_8036a350[];extern "C" float score_8000b344(void *,int,float,float);
extern "C" void w3d_cx14a_selected_score_800113b0(void *self){int selected=selected_804aa6e8;if(selected!=-1){void *actor=*(void **)((char *)actors_804aa750->begin+(selected<<2));FIELD(self,float,4)+=score_8000b344(self,selected,scale_8036a350[0],float(FIELD(actor,int,28)));}int index=FIELD(self,int,16);void *actor=*(void **)((char *)actors_804aa750->begin+(index<<2));FIELD(self,float,4)+=score_8000b344(self,index,scale_8036a350[0],float(FIELD(actor,int,28)));}
