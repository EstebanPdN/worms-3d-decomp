struct F11SphereVec{float x,y,z;};
struct F11Sphere{F11SphereVec center;float radius;int unknown;unsigned flags;int owner;int tail;};
extern F11Sphere*begin_804273ec[],*end_804273f0[];
extern F11SphereVec origin_80427408[],velocity_80427414[],delta_80427444[],hit_80427450[];
extern float radius_804b17b8,radius2_804b17b0,speed2_804b17c0,distance2_804b17d0;
extern unsigned mask_804aa954;extern int excluded_804aa960,mode_804b17bc,unknown_804b1790,active_804aa958,stationary_804aa964;
extern unsigned short source_804aa950,cursor_804aa95c,last_804aa95e;
extern const float zero_80374730[];
extern "C" unsigned moving_800400f0();extern unsigned(*next_804b17b4)();
extern "C" unsigned f11b_sphere_overlap_next_8003ffb8();
extern "C" void f11b_sphere_query_begin_8003fc70(int index,unsigned mask,F11SphereVec*v,int mode,int excluded){F11Sphere*s=begin_804273ec[0]+index;origin_80427408[0]=s->center;radius_804b17b8=s->radius;velocity_80427414[0]=*v;radius2_804b17b0=radius_804b17b8*radius_804b17b8;cursor_804aa95c=0;float speed=v->x*v->x+v->y*v->y+v->z*v->z;mask_804aa954=mask;excluded_804aa960=excluded;unknown_804b1790=0;mode_804b17bc=mode;source_804aa950=(short)index;active_804aa958=1;speed2_804b17c0=speed;if(speed2_804b17c0==zero_80374730[0]){stationary_804aa964=1;next_804b17b4=f11b_sphere_overlap_next_8003ffb8;}else{next_804b17b4=moving_800400f0;}}
