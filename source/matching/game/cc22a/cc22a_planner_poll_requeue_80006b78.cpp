// Plan state names are inferred; all field widths and dispatch slots are observed.
struct Cc22aPlan80006b78 { unsigned int unknown00[2]; int active08; void **dispatch0c; };
struct Cc22aList80006b78 { Cc22aPlan80006b78 **begin; Cc22aPlan80006b78 **end; };
extern "C" {
extern Cc22aList80006b78 *lbl_804aa558,*lbl_804aa55c;
extern int lbl_804aa594,lbl_804aa578,lbl_804aa57c;
extern float lbl_804aa570; extern float lbl_80369500[];
Cc22aPlan80006b78 *fn_800075b0(Cc22aList80006b78 *);
void fn_800075c4(Cc22aList80006b78 *,Cc22aPlan80006b78 *);
void fn_800071ec();void fn_80006b64();void fn_800068a8(int);void fn_800076c4(Cc22aList80006b78 *,int);
}
extern "C" void cc22a_planner_poll_requeue_80006b78() {
Cc22aPlan80006b78 *p=fn_800075b0(lbl_804aa558);
int result=0;lbl_804aa594=2;
if(p->active08) result=((int (*)(Cc22aPlan80006b78 *))p->dispatch0c[4])(p);
if(result) lbl_804aa578=1;
if(lbl_804aa594==0 || (lbl_804aa594==2 && result==0)) {
 fn_800075c4(lbl_804aa55c,p);
 if(lbl_804aa594==2) p->active08=0;
} else if(p) ((void (*)(Cc22aPlan80006b78 *,int))p->dispatch0c[3])(p,3);
if(lbl_804aa558->begin==lbl_804aa558->end) {
 if(lbl_804aa55c->begin==lbl_804aa55c->end) fn_800071ec();
 else {
 fn_80006b64();
 if(lbl_804aa578!=0 || lbl_804aa57c!=0) fn_800068a8(5); else {
 fn_800076c4(lbl_804aa558,0); lbl_804aa570+=lbl_80369500[0]; fn_800068a8(6);
 }
 }
}
}
