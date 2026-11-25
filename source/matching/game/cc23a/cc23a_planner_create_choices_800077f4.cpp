// Observed planner layouts; names describe inferred roles, not recovered symbols.
struct Cc23aWords800077f4 {unsigned int words[3];};
struct Cc23aEntry800077f4 {unsigned char unknown00[12];float cost0c;Cc23aWords800077f4 origin10;bool usable(float threshold){return cost0c>threshold;}};
struct Cc23aRange800077f4 {Cc23aEntry800077f4 **begin,**end;int size(){return end-begin;}};
struct Cc23aSlot800077f4 {unsigned int unknown00;void *held04;Cc23aSlot800077f4(){held04=0;}};
extern "C" {
extern int lbl_804aa5a0;extern Cc23aRange800077f4 *lbl_804aa750;
extern const float lbl_80369548[],lbl_8036954c[];extern Cc23aWords800077f4 lbl_8041d3a0[];
extern unsigned char lbl_8040da88[],lbl_8040d7f0[],lbl_8040d7b8[],lbl_8040d780[];
void *fn_8001523c(unsigned int);void fn_80006360(void *);void fn_80007514(void *);
}
struct Cc23aBase800077f4 {unsigned int unknown00;float score04;int active08;void *dispatch0c;
 static void *operator new(unsigned int n){return fn_8001523c(n);}
 Cc23aBase800077f4(){fn_80006360(this);}
};
struct Cc23aFirst800077f4:Cc23aBase800077f4 {Cc23aFirst800077f4(){dispatch0c=lbl_8040da88;}};
struct Cc23aSecond800077f4:Cc23aBase800077f4 {Cc23aSecond800077f4(){dispatch0c=lbl_8040d7f0;}};
struct Cc23aChoiceBase800077f4:Cc23aBase800077f4 {Cc23aChoiceBase800077f4(){dispatch0c=lbl_8040d7b8;}};
struct Cc23aPlan800077f4:Cc23aChoiceBase800077f4 {
 int index10;unsigned int duration14;Cc23aWords800077f4 origin18;unsigned char unknown24[24];float cost3c;
 unsigned char flag40,flag41;unsigned short unknown42;unsigned int value44;Cc23aSlot800077f4 held48,held50;Cc23aWords800077f4 saved58;float cost64;
 Cc23aPlan800077f4(int index):Cc23aChoiceBase800077f4(){
 index10=index;duration14=60;
 if(index!=-1) origin18=(*(Cc23aEntry800077f4 **)((char *)lbl_804aa750->begin+(index<<2)))->origin10;
 cost3c=1.0f;flag40=0;value44=0;saved58=lbl_8041d3a0[0];flag41=0;cost64=1.0f;
 }
};
struct Cc23aFallback800077f4:Cc23aPlan800077f4 {Cc23aFallback800077f4():Cc23aPlan800077f4(-1){dispatch0c=lbl_8040d780;}};
extern "C" int cc23a_planner_create_choices_800077f4(){
 fn_80007514(new Cc23aFirst800077f4);
 if(!lbl_804aa5a0){
 int i=0;fn_80007514(new Cc23aSecond800077f4);
 int count=lbl_804aa750->size();
 for(;i<count;++i)if((*(Cc23aEntry800077f4 **)((char *)lbl_804aa750->begin+(i<<2)))->usable(0.0f)) fn_80007514(new Cc23aPlan800077f4(i));
 fn_80007514(new Cc23aFallback800077f4);
 }
 return 1;
}
