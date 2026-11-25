// Observed random celebration switch, including original case-six fallthrough.
struct F10CelebrationOwner{char p[28];void*mesh;char p2[440];int animation;char p3[20];int state;};
extern "C" int allowed_8013fecc(F10CelebrationOwner*),current_80139158(F10CelebrationOwner*),play_801359ec(F10CelebrationOwner*,void*,const char*,int*,float,float,float);
extern "C" void*mesh_80343584(void*);extern "C" unsigned random_80162c20();extern "C" void speak_8013bd0c(F10CelebrationOwner*,const char*);
extern float rate_8039fe20[],blend_8039fe24[],zero_8039fe28[];
extern const char happy_8039ee9c[],taunt_8039fdf8[],amazing_8039fe00[],brilliant_8039fe08[],excellent_8039fe14[];
extern const char *name_804ab2ec;
extern const char *name_804ab2f0;
extern const char *name_804ab2f8;
extern const char *name_804ab300;
extern const char *name_804ab2a4;
extern const char *name_804ab2a8;
extern const char *name_804ab30c;
extern const char *name_804ab2bc;
extern const char *name_804ab2c0;
extern "C" void f10b_celebrate_checked_8013faf0(F10CelebrationOwner*s){if(!allowed_8013fecc(s))return;if(!current_80139158(s))return;if(s->state)return;bool voice=false;void*mesh=mesh_80343584(s->mesh);switch(random_80162c20()%9){
case 0:play_801359ec(s,mesh,name_804ab2ec,&s->animation,rate_8039fe20[0],blend_8039fe24[0],zero_8039fe28[0]);voice=true;
break;
case 1:play_801359ec(s,mesh,name_804ab2f0,&s->animation,rate_8039fe20[0],blend_8039fe24[0],zero_8039fe28[0]);
speak_8013bd0c(s,happy_8039ee9c);break;
case 2:play_801359ec(s,mesh,name_804ab2f8,&s->animation,rate_8039fe20[0],blend_8039fe24[0],zero_8039fe28[0]);voice=true;
break;
case 3:play_801359ec(s,mesh,name_804ab300,&s->animation,rate_8039fe20[0],blend_8039fe24[0],zero_8039fe28[0]);voice=true;
break;
case 4:play_801359ec(s,mesh,name_804ab2a4,&s->animation,rate_8039fe20[0],blend_8039fe24[0],zero_8039fe28[0]);voice=true;
break;
case 5:play_801359ec(s,mesh,name_804ab2a8,&s->animation,rate_8039fe20[0],blend_8039fe24[0],zero_8039fe28[0]);voice=true;
break;
case 6:voice=true;play_801359ec(s,mesh,name_804ab30c,&s->animation,rate_8039fe20[0],blend_8039fe24[0],zero_8039fe28[0]);
case 7:play_801359ec(s,mesh,name_804ab2bc,&s->animation,rate_8039fe20[0],blend_8039fe24[0],zero_8039fe28[0]);
speak_8013bd0c(s,taunt_8039fdf8);break;default:play_801359ec(s,mesh,name_804ab2c0,&s->animation,rate_8039fe20[0],blend_8039fe24[0],zero_8039fe28[0]);
speak_8013bd0c(s,taunt_8039fdf8);break;}
if(voice){switch(random_80162c20()%3){case 0:speak_8013bd0c(s,amazing_8039fe00);break;case 1:speak_8013bd0c(s,brilliant_8039fe08);break;default:speak_8013bd0c(s,excellent_8039fe14);break;}}}
