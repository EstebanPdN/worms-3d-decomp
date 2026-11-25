/* Retains the original starting record as the return value; the index is
   separately advanced until the observed category callback matches. */
struct Cx16bMesh276 { void **vtable; unsigned word; unsigned flags; char unknown[264]; };
static inline bool cx16b_busy(Cx16bMesh276 *p){return p->flags&0xfffe;}
extern "C" {
extern Cx16bMesh276 *lbl_804b18b0;
extern unsigned short lbl_804b18ac;

Cx16bMesh276 *w3d_cx16b_mesh_find_next_8018b7c4(void *owner,int *index)
{
    if(*index<0)return 0;
    Cx16bMesh276 *initial=lbl_804b18b0+*index;
    while(*index<(int)lbl_804b18ac && !cx16b_busy(lbl_804b18b0+*index) &&
       owner!=((void*(*)(Cx16bMesh276 *))((Cx16bMesh276 *)((*index*276)+(unsigned)lbl_804b18b0))->vtable[16])((Cx16bMesh276 *)((*index*276)+(unsigned)lbl_804b18b0)))++*index;
    if(*index==lbl_804b18ac)*index=-1;
    return initial;
}
}
