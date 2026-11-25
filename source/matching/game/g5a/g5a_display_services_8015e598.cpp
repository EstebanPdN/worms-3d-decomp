// External views only; three local output words have original callee write witnesses.
struct G5aDisplayInterface {void **vtable;};
extern "C" G5aDisplayInterface *query_8020b680(const void*);
extern const char display_80411e50[],window_80411ee8[],renderer_80411c00[],scene_80411cf0[],input_80411b40[],title_803a450c[];
struct G5aDisplayHeld {
 G5aDisplayInterface *p;
 void acquire(const void *descriptor){G5aDisplayInterface *next=query_8020b680(descriptor);if(next)((void(*)(G5aDisplayInterface*))next->vtable[3])(next);if(p)((void(*)(G5aDisplayInterface*))p->vtable[4])(p);p=next;}
};
struct G5aDisplayOwner {
 char unknown0[88];G5aDisplayHeld display,window,renderer,scene,input;char unknown108[8];
 int width,height,minRate,maxRate,minDepth,maxDepth,selectMode,windowFlags;
};
extern "C" int g5a_display_services_8015e598(G5aDisplayOwner *self){
 self->display.acquire(display_80411e50);

 if(self->selectMode){
  unsigned count;int width,height;unsigned selected=0,index=0;
  G5aDisplayInterface **modes=((G5aDisplayInterface**(*)(G5aDisplayInterface*,unsigned*))self->display.p->vtable[7])(self->display.p,&count);
  for(;index<count;++index){
   G5aDisplayInterface *mode=modes[index];
   ((int(*)(G5aDisplayInterface*,int*,int*))mode->vtable[5])(mode,&width,&height);
   mode=modes[index];int depth=((int(*)(G5aDisplayInterface*))mode->vtable[6])(mode);
   mode=modes[index];int rate=((int(*)(G5aDisplayInterface*))mode->vtable[7])(mode);
   if(width==self->width && height==self->height && depth>=self->minDepth && depth<=self->maxDepth && rate>=self->minRate && rate<=self->maxRate)selected=index;
  }
  ((void(*)(G5aDisplayInterface*,G5aDisplayInterface*,int))self->display.p->vtable[9])(self->display.p,modes[selected],2);
 }
 self->window.acquire(window_80411ee8);
 ((int(*)(G5aDisplayInterface*,G5aDisplayInterface*,const char*,int,int,int,int,int,int,int))self->window.p->vtable[10])(self->window.p,self->display.p,title_803a450c,100,100,self->width,self->height,0,self->selectMode,self->windowFlags);
 self->renderer.acquire(renderer_80411c00);
 ((int(*)(G5aDisplayInterface*,G5aDisplayInterface*))self->renderer.p->vtable[5])(self->renderer.p,self->window.p);
 ((int(*)(G5aDisplayInterface*))self->renderer.p->vtable[6])(self->renderer.p);
 ((int(*)(G5aDisplayInterface*,int,int,int,int))self->renderer.p->vtable[19])(self->renderer.p,0,0,self->width,self->height);
 self->scene.acquire(scene_80411cf0);
 ((int(*)(G5aDisplayInterface*,G5aDisplayInterface*))self->scene.p->vtable[12])(self->scene.p,self->renderer.p);
 self->input.acquire(input_80411b40);
 ((int(*)(G5aDisplayInterface*,G5aDisplayInterface*))self->input.p->vtable[18])(self->input.p,self->scene.p);
 return 0;
}
