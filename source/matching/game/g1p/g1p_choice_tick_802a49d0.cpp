// Inferred external views only. Complete local vector is three floats.
struct Vec3 {float x,y,z;Vec3(float a,float b,float c){x=a;y=b;z=c;}};
struct Control {void**table;};
struct Choice {
 char unknown0[112];Control*horizontal;char unknown116[108];Control*vertical;
 char unknown228[176];float x,targetX,y,targetY;char unknown420[180];
 unsigned selectedX,pendingX,pendingY,selectedY;int hover;unsigned itemCount;
};
extern "C" void fn_802b0668(void*);
extern "C" void fn_802a62bc(Choice*);
extern "C" void fn_802a75ec(Choice*);
extern "C" void fn_802a77a4(Choice*);
extern "C" void fn_802a6ce8(Choice*);
extern "C" void fn_802a6878(Choice*);
extern "C" void fn_802a64a8(Choice*);
inline void selectVertical(Choice*p,unsigned next,float reset){
 p->selectedY=next;p->targetY=reset;
 fn_802a77a4(p);
 switch(p->selectedY){case 0:case 2:p->itemCount=8;break;case 1:case 3:p->itemCount=4;break;}
 fn_802a64a8(p);fn_802a6ce8(p);
}
extern "C" int g1p_choice_tick_802a49d0(Choice*p){
 fn_802b0668((char*)p+28);
 float x=p->x,target=p->targetX;
 if(x!=target){
  float step=(x-target)* 0.25f;
  float delta=target-x;
  if(delta<0.01f&&delta>-0.01f){
   p->x=target;
   if(target==0.0f){
    p->targetX=1.0f;p->selectedX=p->pendingX;
    fn_802a62bc(p);fn_802a75ec(p);fn_802a77a4(p);fn_802a6ce8(p);fn_802a6878(p);
   }
  }
  else p->x=p->x-step;
  Vec3 value(p->x,1.0f,1.0f);
  ((void(*)(Control*,const Vec3*,int))p->horizontal->table[21])(p->horizontal,&value,0);
 }else if(x==0.0f){
  p->selectedX=p->pendingX;p->targetX=1.0f;
  fn_802a62bc(p);fn_802a75ec(p);fn_802a77a4(p);fn_802a6ce8(p);
 }
 float y=p->y,targetY=p->targetY;
 if(y!=targetY){
  float step=(y-targetY)* 0.25f;
  float delta=targetY-y;
  if(delta<0.01f&&delta>-0.01f){p->y=targetY;if(targetY==0.0f)selectVertical(p,p->pendingY,1.0f);}
  else p->y=p->y-step;
  Vec3 value(1.0f,p->y,1.0f);
  ((void(*)(Control*,const Vec3*,int))p->vertical->table[21])(p->vertical,&value,0);
 }else if(y==0.0f)selectVertical(p,p->pendingY,1.0f);
 if(p->hover==-1)fn_802a6ce8(p);
 return 0;
}
