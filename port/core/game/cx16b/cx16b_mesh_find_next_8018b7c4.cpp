#include "w3d_ptr.h"
#line 1 "cx16b_mesh_find_next_8018b7c4.cpp"
/* Retains the original starting record as the return value; the index is
   separately advanced until the observed category callback matches. */
struct Cx16bMesh276 { Ptr32<Ptr32<void>> vtable; unsigned word; unsigned flags; char unknown[264]; };
static inline bool cx16b_busy(Ptr32<Cx16bMesh276> p){return p->flags&0xfffe;}
extern "C" {
extern Ptr32<Cx16bMesh276> lbl_804b18b0;
extern unsigned short lbl_804b18ac;

Ptr32<Cx16bMesh276> w3d_cx16b_mesh_find_next_8018b7c4(Ptr32<void> owner,Ptr32<int> index)
{
    if(*index<0)return 0;
    Ptr32<Cx16bMesh276> initial=lbl_804b18b0+*index;
    while(*index<(int)lbl_804b18ac && !cx16b_busy(lbl_804b18b0+*index) &&
       owner!=((Ptr32<Ptr32<void> (Ptr32<Cx16bMesh276>)>)((Ptr32<Cx16bMesh276>)w3d::G(((*index*276)+(unsigned)w3d::H(lbl_804b18b0))))->vtable[16])((Ptr32<Cx16bMesh276>)w3d::G(((*index*276)+(unsigned)w3d::H(lbl_804b18b0)))))++*index;
    if(*index==lbl_804b18ac)*index=-1;
    return initial;
}
}


