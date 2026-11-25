// Native planner record; inferred names, observed offsets and scalar widths.
struct Cc22aPlan80006eb8 { unsigned int unknown00; float score04; int active08; void **dispatch0c; };
struct Cc22aList80006eb8 { Cc22aPlan80006eb8 **begin,**end; };
struct Cc22aWords80006eb8 { unsigned int words[3]; };
extern "C" {
extern Cc22aList80006eb8 *lbl_804aa558;
extern int lbl_804aa598,lbl_804aa578;
extern float lbl_80369514[];
extern Cc22aWords80006eb8 lbl_8041d3a0[],lbl_8041d3ac[];
Cc22aPlan80006eb8 *fn_800075b0(Cc22aList80006eb8 *);
void fn_80007080(Cc22aPlan80006eb8 *);void fn_80015f38(Cc22aPlan80006eb8 *);
void fn_80006694();void fn_800068a8(int);void fn_800071ec();
}
inline void cc22a_plan_release80006eb8(Cc22aPlan80006eb8 *p) {if(p) ((void (*)(Cc22aPlan80006eb8 *,int))p->dispatch0c[3])(p,3);}
extern "C" void cc22a_planner_execute_selection_80006eb8() {
Cc22aPlan80006eb8 *p=fn_800075b0(lbl_804aa558);int result=0;
if(p->score04>=lbl_80369514[0]) result=((int (*)(Cc22aPlan80006eb8 *))p->dispatch0c[6])(p);
lbl_8041d3a0[0]=lbl_8041d3ac[0];
if(result) {
 if(lbl_804aa598) fn_80007080(p);
 else {((void (*)(Cc22aPlan80006eb8 *))p->dispatch0c[7])(p);fn_80015f38(p);cc22a_plan_release80006eb8(p);fn_80006694();}
} else {
 cc22a_plan_release80006eb8(p);
 if(lbl_804aa578) fn_800068a8(5);
 else if(lbl_804aa558->begin==lbl_804aa558->end) fn_800071ec();
}
}
