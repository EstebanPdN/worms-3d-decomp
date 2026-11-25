/* Retains the original starting record as the return value; the index is
   separately advanced until the observed category callback matches. */
struct Cx16bMesh204 { void **vtable; char unknown[200]; };
extern "C" {
extern Cx16bMesh204 *lbl_804ab60c;
extern unsigned short lbl_804ab610;
int fn_80185b0c(Cx16bMesh204 *);
Cx16bMesh204 *w3d_cx16b_mesh_find_next_8017f954(void *owner,int *index)
{
    if(*index<0)return 0;
    Cx16bMesh204 *initial=lbl_804ab60c+*index;
    while(*index<(int)lbl_804ab610){
        if(fn_80185b0c(lbl_804ab60c+*index)){
            Cx16bMesh204 *record=(Cx16bMesh204 *)((*index*204)+(unsigned)lbl_804ab60c);
            if(owner==((void*(*)(Cx16bMesh204 *))record->vtable[16])(record))break;
        }
        ++*index;
    }
    if(*index==lbl_804ab610)*index=-1;
    return initial;
}
}
