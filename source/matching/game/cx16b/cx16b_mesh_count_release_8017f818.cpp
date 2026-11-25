/* Observed owner count at +112, flags at +36, virtual category and ID
   slots, and a global pending-ID queue. Semantic names are inferred. */
struct Cx16bMesh { void **vtable; };
struct Cx16bMeshOwner { char unknown[36]; unsigned short flags; char gap[74]; int count; };
extern "C" {
int fn_80190458(Cx16bMeshOwner *);
int fn_801801b0(Cx16bMeshOwner *);
extern int lbl_804a89d8[];
extern unsigned short lbl_804ab61c;
extern unsigned short *lbl_804ab618;
int w3d_cx16b_mesh_count_release_8017f818(Cx16bMeshOwner *self,Cx16bMesh *mesh)
{
    --self->count;
    fn_80190458(self);
    int *counts=lbl_804a89d8;
    int category=((int(*)(Cx16bMesh *))mesh->vtable[12])(mesh);
    --counts[category];
    unsigned short id=((unsigned short(*)(Cx16bMesh *))mesh->vtable[14])(mesh);
    unsigned index=lbl_804ab61c++;
    *(unsigned short *)((index<<1)+(unsigned)lbl_804ab618)=id;
    if(self->flags&32)fn_801801b0(self);
    return 0;
}
}
