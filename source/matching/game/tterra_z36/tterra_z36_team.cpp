// Sixteen team slots; ownership transfer/release inferred from observed calls.
struct Cc23aPlan80007080 { unsigned int unknown00;float score04;int active08;void **dispatch0c; };
extern "C" {
extern int lbl_804aa6c0,lbl_804aa6c4,lbl_804aa598;
extern int lbl_804a84d8[];extern Cc23aPlan80007080 *lbl_804a8518[];extern float lbl_80369518[];
void fn_800066e0();void fn_800068a8(int);int fn_800153dc(int);int fn_80015400(int);
void fn_80009404();void fn_800092bc(int);void fn_80007b44(int);
}
inline void cc23a_reset80007080(Cc23aPlan80007080 *&p,Cc23aPlan80007080 *value) {if(p)((void (*)(Cc23aPlan80007080 *,int))p->dispatch0c[3])(p,3);p=value;}
inline void cc23a_clear_all80007080(Cc23aPlan80007080 *zero){ int offset=0;
 for(int count=16;count!=0;--count) {Cc23aPlan80007080 *&p=*(Cc23aPlan80007080 **)(offset+(char *)lbl_804a8518);cc23a_reset80007080(p,zero);offset+=4;}}
extern "C" void tterra_z36_team_80007080(Cc23aPlan80007080 *plan) {
int slot=lbl_804aa6c0;int *pending=lbl_804a84d8;lbl_804a8518[slot]=plan;pending[slot]=0;
fn_800066e0();int i=0;int off=0;fn_800068a8(2);
do {
 int &pending=*(int *)(off+(char *)lbl_804a84d8);
 if(pending) {int valid=fn_800153dc(i);if(valid) {valid=fn_80015400(i);if(valid) break;} pending=valid;}
 ++i;off+=4;
} while(i<16);
if(i==16) {
 int best=-1;float score=lbl_80369518[0];Cc23aPlan80007080 **cursor=lbl_804a8518;
 i=0;int count=16;
 do {Cc23aPlan80007080 *p=*cursor++;if(p && p->score04>score){best=i;score=p->score04;}++i;} while(--count);
 if(best==-1) best=lbl_804aa6c4;
 cc23a_clear_all80007080(0);
 fn_80009404();fn_800092bc(best);fn_80007b44(best);lbl_804aa598=0;
} else fn_80007b44(i);
}
