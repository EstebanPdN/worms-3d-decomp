#include "w3d_ptr.h"
#line 1 "cx14a_selected_score_800113b0.cpp"
// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))

struct Cx14aRegistry{Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end;};extern Ptr32<Cx14aRegistry> actors_804aa750;extern int selected_804aa6e8;extern const float scale_8036a350[];extern "C" float score_8000b344(Ptr32<void>,int,float,float);
extern "C" void w3d_cx14a_selected_score_800113b0(Ptr32<void> self){int selected=selected_804aa6e8;if(selected!=-1){Ptr32<void> actor=*(Ptr32<Ptr32<void>>)((Ptr32<char>)actors_804aa750->begin+(selected<<2));FIELD(self,float,4)+=score_8000b344(self,selected,scale_8036a350[0],float(FIELD(actor,int,28)));}int index=FIELD(self,int,16);Ptr32<void> actor=*(Ptr32<Ptr32<void>>)((Ptr32<char>)actors_804aa750->begin+(index<<2));FIELD(self,float,4)+=score_8000b344(self,index,scale_8036a350[0],float(FIELD(actor,int,28)));}


