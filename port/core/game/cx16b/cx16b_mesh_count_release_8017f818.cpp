#include "w3d_ptr.h"
#line 1 "cx16b_mesh_count_release_8017f818.cpp"
/* Observed owner count at +112, flags at +36, virtual category and ID
   slots, and a global pending-ID queue. Semantic names are inferred. */
struct Cx16bMesh { Ptr32<Ptr32<void>> vtable; };
struct Cx16bMeshOwner { char unknown[36]; unsigned short flags; char gap[74]; int count; };
extern "C" {
int fn_80190458(Ptr32<Cx16bMeshOwner>);
int fn_801801b0(Ptr32<Cx16bMeshOwner>);
extern int lbl_804a89d8[];
extern unsigned short lbl_804ab61c;
extern Ptr32<unsigned short> lbl_804ab618;
int w3d_cx16b_mesh_count_release_8017f818(Ptr32<Cx16bMeshOwner> self,Ptr32<Cx16bMesh> mesh)
{
    --self->count;
    fn_80190458(self);
    Ptr32<int> counts=lbl_804a89d8;
    int category=((Ptr32<int (Ptr32<Cx16bMesh>)>)mesh->vtable[12])(mesh);
    --counts[category];
    unsigned short id=((Ptr32<unsigned short (Ptr32<Cx16bMesh>)>)mesh->vtable[14])(mesh);
    unsigned index=lbl_804ab61c++;
    *(Ptr32<unsigned short>)w3d::G(((index<<1)+(unsigned)w3d::H(lbl_804ab618)))=id;
    return 0;
}
}


