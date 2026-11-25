#include "w3d_ptr.h"
#line 1 "cx14a_score_others_80012018.cpp"
// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
struct Cx14aRegistry{Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end;};extern Ptr32<Cx14aRegistry> actors_804aa750;extern "C" void clear_8000b2f8(Ptr32<void>,int);extern "C" float score_8000b344(Ptr32<void>,int,float,float);extern const float scale_8036a430[],weight_8036a434[];extern int team_804aa6c0;
extern "C" void w3d_cx14a_score_others_80012018(Ptr32<void> self){clear_8000b2f8(self,0);int count=actors_804aa750->end-actors_804aa750->begin;for(int i=0;i<count;++i){Ptr32<void> actor=*(Ptr32<Ptr32<void>>)((Ptr32<char>)actors_804aa750->begin+(i<<2));int team=FIELD(actor,int,8);if(team!=-1&&team!=team_804aa6c0)FIELD(self,float,4)+=score_8000b344(self,i,scale_8036a430[0],weight_8036a434[0]);}}


