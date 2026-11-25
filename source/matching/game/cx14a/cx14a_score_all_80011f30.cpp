// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
struct Cx14aRegistry{void **begin,**end;};extern Cx14aRegistry *actors_804aa750;extern "C" void clear_8000b2f8(void *,int);extern "C" float score_8000b344(void *,int,float,float);extern const float scale_8036a408[],weight_8036a40c[];
extern "C" void w3d_cx14a_score_all_80011f30(void *self){clear_8000b2f8(self,0);int count=actors_804aa750->end-actors_804aa750->begin;for(int i=0;i<count;++i){void *actor=*(void **)((char *)actors_804aa750->begin+(i<<2));int team=FIELD(actor,int,8);if(team!=-1)FIELD(self,float,4)+=score_8000b344(self,i,scale_8036a408[0],weight_8036a40c[0]);}}
