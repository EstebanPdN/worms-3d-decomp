// Planner states and names inferred; full-width flags and single-precision time observed.
extern "C" {
extern int lbl_804aa568,lbl_804aa56c,lbl_804aa578,lbl_804aa6dc,lbl_804aa6e0;
extern float lbl_804aa570;extern float lbl_803694d8[],lbl_803694dc[],lbl_803694e0[];
extern void *lbl_804aa558;extern unsigned char lbl_8040cb70[];
void fn_800067a8();void fn_8000666c();void fn_800160fc();void fn_800166bc();void fn_800169e0();
void fn_800181e8();void fn_80007a28();int fn_80019988();void *fn_8001523c(unsigned int);
void fn_80006360(void *);void fn_800075c4(void *,void *);void fn_800068a8(int);
void fn_80006b78();void fn_80006cc0();void fn_80006eb8();
}
struct Cc23aPlan800064d4 {
 unsigned int unknown00;float score04;int active08;void *dispatch0c;
 static void *operator new(unsigned int n){return fn_8001523c(n);}
 Cc23aPlan800064d4(){fn_80006360(this);dispatch0c=lbl_8040cb70;}
};
inline bool cc23a_wait800064d4(){return lbl_804aa6dc!=0 && lbl_804aa6e0==0;}
extern "C" void cc23a_planner_tick_800064d4(){
 switch(lbl_804aa568){
 case 0:fn_800067a8();lbl_804aa570+=lbl_803694d8[0];break;
 case 1:fn_8000666c();fn_800160fc();fn_800166bc();fn_800169e0();lbl_804aa570+=lbl_803694d8[0];break;
 case 2:switch(lbl_804aa56c){
 case 0:lbl_804aa570+=lbl_803694dc[0];fn_800181e8();fn_80007a28();lbl_804aa56c=1;break;
 case 1:lbl_804aa570+=lbl_803694dc[0];if(cc23a_wait800064d4() && !fn_80019988())break;
 {void *list=lbl_804aa558;fn_800075c4(list,new Cc23aPlan800064d4);}
 fn_800068a8(3);lbl_804aa56c=0;break;}break;
 case 3:lbl_804aa578=0;fn_800068a8(4);break;
 case 4:fn_80006b78();lbl_804aa570+=lbl_803694e0[0];break;
 case 5:fn_80006cc0();break;
 case 6:fn_80006eb8();lbl_804aa570+=lbl_803694e0[0];break;
 }
}
