#include "w3d_ptr.h"
#line 1 "cx16b_mesh_find_next_8017f954.cpp"
/* Retains the original starting record as the return value; the index is
   separately advanced until the observed category callback matches. */
struct Cx16bMesh204 { Ptr32<Ptr32<void>> vtable; char unknown[200]; };
extern "C" {
extern Ptr32<Cx16bMesh204> lbl_804ab60c;
extern unsigned short lbl_804ab610;
int fn_80185b0c(Ptr32<Cx16bMesh204>);
Ptr32<Cx16bMesh204> w3d_cx16b_mesh_find_next_8017f954(Ptr32<void> owner,Ptr32<int> index)
{
    if(*index<0)return 0;
    Ptr32<Cx16bMesh204> initial=lbl_804ab60c+*index;
    while(*index<(int)lbl_804ab610){
        if(fn_80185b0c(lbl_804ab60c+*index)){
            Ptr32<Cx16bMesh204> record=(Ptr32<Cx16bMesh204>)w3d::G(((*index*204)+(unsigned)w3d::H(lbl_804ab60c)));
            if(owner==((Ptr32<Ptr32<void> (Ptr32<Cx16bMesh204>)>)record->vtable[16])(record))break;
        }
        ++*index;
    }
    if(*index==lbl_804ab610)*index=-1;
    return initial;
}
}


