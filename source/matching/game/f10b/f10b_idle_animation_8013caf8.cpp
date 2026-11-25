// Partial views cover all observed fields; mesh/service vtables remain inferred.
struct F10IdleVec {float x,y,z;};
struct F10IdleObject {void **vtable;};
struct F10IdleOwner {char p0[52]; F10IdleVec position;char p1[100];F10IdleObject *hat,*held;char p2[300];int animation;char p3[8];int heldAnimation,hatAnimation,neutralAnimation;char p4[36];F10IdleObject *effect;char p5[108];unsigned animationId;char p6[36];unsigned weapon;char p7[4];int idle;};
struct F10IdleContext {char p[108];F10IdleObject *effects;};extern F10IdleContext*context_804b1788;
extern float rate_8039f93c[],blend_8039f940[],zero_8039f944[];
extern const char headers_8039f91c[],grenade_8039f92c[],pigeon_8039f3ac[],neutral_8039f3b8[];
extern "C" int clear_801817e0(F10IdleObject*,int),play_801359ec(F10IdleOwner*,F10IdleObject*,const char*,int*,float,float,float);
extern "C" int aim_80181884(F10IdleObject*,unsigned,float,float);extern "C" int fade_80181814(F10IdleObject*,const char*,float,float);
extern "C" float amount_8013c844(F10IdleOwner*);extern "C" unsigned random_80162c20();
extern const char*name_804ab100;
extern const char*name_804ab250;
extern const char*name_804ab258;
extern const char*name_804ab25c;
extern const char*name_804ab254;
extern const char*name_804ab270;
extern const char*name_804ab32c;
extern const char*name_804ab284;
extern const char*name_804ab29c;
extern const char*name_804ab2a0;
extern const char*name_804ab290;
extern const char*name_804ab260;
extern const char*name_804ab28c;
extern const char*name_804ab264;
extern const char*name_804ab268;
extern const char*name_804ab26c;
extern const char*name_804ab274;
extern const char*name_804ab278;
extern const char*name_804ab27c;
extern const char*name_804ab280;
extern const char*name_804ab288;
extern const char*name_804ab294;
extern const char*name_804ab298;
extern "C" void f10b_idle_animation_8013caf8(F10IdleOwner*s,F10IdleObject*mesh){switch(s->weapon){
case 0:clear_801817e0(mesh,-1);aim_80181884(mesh,s->animationId,rate_8039f93c[0],rate_8039f93c[0]);
play_801359ec(s,mesh,name_804ab250,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 7:play_801359ec(s,mesh,name_804ab258,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 3:play_801359ec(s,mesh,name_804ab25c,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 1:{unsigned random=random_80162c20()&1;if(!s->held&&random==1){clear_801817e0(mesh,-1);unsigned id=s->animationId;float amount=amount_8013c844(s);aim_80181884(mesh,id,amount,zero_8039f944[0]);
play_801359ec(s,mesh,name_804ab100,&s->neutralAnimation,rate_8039f93c[0],zero_8039f944[0],zero_8039f944[0]);
play_801359ec(s,mesh,name_804ab254,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
F10IdleObject *service=context_804b1788->effects;if(service){
 ((void(*)(F10IdleObject*,const char*,F10IdleObject**))service->vtable[23])(service,headers_8039f91c,&s->effect);
 ((void(*)(F10IdleObject*))s->effect->vtable[5])(s->effect);
 ((void(*)(F10IdleObject*,int,F10IdleVec*))s->effect->vtable[14])(s->effect,3,&s->position);
 }
((void(*)(F10IdleObject*,F10IdleObject*))mesh->vtable[24])(mesh,s->hat);((void(*)(F10IdleObject*,F10IdleObject*,const char*))mesh->vtable[23])(mesh,s->hat,name_804ab32c);
}else{play_801359ec(s,mesh,name_804ab270,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
F10IdleObject *service=context_804b1788->effects;if(service){
 ((void(*)(F10IdleObject*,const char*,F10IdleObject**))service->vtable[23])(service,grenade_8039f92c,&s->effect);
 ((void(*)(F10IdleObject*))s->effect->vtable[5])(s->effect);
 ((void(*)(F10IdleObject*,int,F10IdleVec*))s->effect->vtable[14])(s->effect,3,&s->position);
 }
}break;}
case 4:play_801359ec(s,mesh,name_804ab284,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 16:clear_801817e0(mesh,-1);aim_80181884(mesh,s->animationId,rate_8039f93c[0],rate_8039f93c[0]);
aim_80181884(mesh,s->animationId,rate_8039f93c[0],zero_8039f944[0]);
if((random_80162c20()&1)==0){
play_801359ec(s,mesh,name_804ab29c,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
if(s->held){clear_801817e0(s->held,-1);fade_80181814(s->held,pigeon_8039f3ac,rate_8039f93c[0],rate_8039f93c[0]);fade_80181814(s->held,pigeon_8039f3ac,rate_8039f93c[0],zero_8039f944[0]);
play_801359ec(s,s->held,neutral_8039f3b8,&s->heldAnimation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
play_801359ec(s,s->held,name_804ab29c,&s->heldAnimation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
}
}else{
play_801359ec(s,mesh,name_804ab2a0,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
if(s->held){clear_801817e0(s->held,-1);fade_80181814(s->held,pigeon_8039f3ac,rate_8039f93c[0],rate_8039f93c[0]);fade_80181814(s->held,pigeon_8039f3ac,rate_8039f93c[0],zero_8039f944[0]);
play_801359ec(s,s->held,neutral_8039f3b8,&s->heldAnimation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
play_801359ec(s,s->held,name_804ab2a0,&s->heldAnimation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
}
}break;
case 39:case 40:play_801359ec(s,mesh,name_804ab290,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 12:play_801359ec(s,mesh,name_804ab260,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 18:case 29:play_801359ec(s,mesh,name_804ab28c,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 13:play_801359ec(s,mesh,name_804ab264,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
if(s->held){play_801359ec(s,s->held,name_804ab264,&s->heldAnimation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
}break;
case 6:clear_801817e0(mesh,-1);aim_80181884(mesh,s->animationId,rate_8039f93c[0],rate_8039f93c[0]);
aim_80181884(mesh,s->animationId,rate_8039f93c[0],zero_8039f944[0]);
play_801359ec(s,mesh,name_804ab268,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 21:clear_801817e0(mesh,-1);aim_80181884(mesh,s->animationId,rate_8039f93c[0],rate_8039f93c[0]);
aim_80181884(mesh,s->animationId,rate_8039f93c[0],zero_8039f944[0]);
play_801359ec(s,mesh,name_804ab26c,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 5:clear_801817e0(mesh,-1);aim_80181884(mesh,s->animationId,rate_8039f93c[0],rate_8039f93c[0]);
aim_80181884(mesh,s->animationId,rate_8039f93c[0],zero_8039f944[0]);
play_801359ec(s,mesh,name_804ab274,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 20:clear_801817e0(mesh,-1);aim_80181884(mesh,s->animationId,rate_8039f93c[0],rate_8039f93c[0]);
aim_80181884(mesh,s->animationId,rate_8039f93c[0],zero_8039f944[0]);
play_801359ec(s,mesh,name_804ab278,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 2:clear_801817e0(mesh,-1);aim_80181884(mesh,s->animationId,rate_8039f93c[0],rate_8039f93c[0]);
aim_80181884(mesh,s->animationId,rate_8039f93c[0],zero_8039f944[0]);
play_801359ec(s,mesh,name_804ab27c,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 34:clear_801817e0(mesh,-1);aim_80181884(mesh,s->animationId,rate_8039f93c[0],rate_8039f93c[0]);
aim_80181884(mesh,s->animationId,rate_8039f93c[0],zero_8039f944[0]);
play_801359ec(s,mesh,name_804ab280,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 8:clear_801817e0(mesh,-1);aim_80181884(mesh,s->animationId,rate_8039f93c[0],rate_8039f93c[0]);
aim_80181884(mesh,s->animationId,rate_8039f93c[0],zero_8039f944[0]);
play_801359ec(s,mesh,name_804ab288,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 9:clear_801817e0(mesh,-1);aim_80181884(mesh,s->animationId,rate_8039f93c[0],rate_8039f93c[0]);
aim_80181884(mesh,s->animationId,rate_8039f93c[0],zero_8039f944[0]);
play_801359ec(s,mesh,name_804ab294,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
break;
case 47:play_801359ec(s,mesh,name_804ab298,&s->animation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
if(s->hat){play_801359ec(s,s->hat,name_804ab298,&s->hatAnimation,rate_8039f93c[0],blend_8039f940[0],zero_8039f944[0]);
}break;default:break;}s->idle=1;}
