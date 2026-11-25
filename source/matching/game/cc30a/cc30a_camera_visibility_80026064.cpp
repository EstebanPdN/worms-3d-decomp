// Original visibility and animation sequence; class extents beyond used fields unknown.
struct cc30a_Control_80026064;
struct cc30a_VTable_80026064 {char gap[88];void(*visible)(cc30a_Control_80026064*,bool);};
struct cc30a_Control_80026064 {cc30a_VTable_80026064* vt;};
struct cc30a_Owner_80026064 {char gap[60];cc30a_Control_80026064 *a,*b,*c,*d;char gap4c[16];int mode,active,blocked;};
struct cc30a_Global_80026064 {char gap[188];unsigned flags;};
extern cc30a_Global_80026064* cc30a_global_804b1788;
extern float cc30a_float_8036c9cc[],cc30a_float_8036c9d0[],cc30a_float_8036c9d4[];
extern char *cc30a_name_804aa7f4,*cc30a_name_804aa7f8;
extern "C" {
int cc30a_call_801817e0(void*,int);
int cc30a_call_80181640(void*,const char*,unsigned*,int,float,float,float);
int cc30a_call_8018179c(void*,unsigned,int);
void cc30a_camera_visibility_80026064(cc30a_Owner_80026064*self){
 if(cc30a_global_804b1788->flags&1024)self->b->vt->visible(self->b,!self->mode&&!self->blocked);
 self->a->vt->visible(self->a,self->mode&&!self->blocked);
 self->c->vt->visible(self->c,self->mode&&!self->blocked);
 self->d->vt->visible(self->d,self->mode&&!self->blocked);
 if(self->mode){unsigned track[2];cc30a_call_801817e0(self->a,-1);
 cc30a_call_80181640(self->a,cc30a_name_804aa7f4,track,0,*cc30a_float_8036c9cc,*cc30a_float_8036c9d0,*cc30a_float_8036c9d0);
 cc30a_call_80181640(self->a,cc30a_name_804aa7f8,track,1,*cc30a_float_8036c9cc,*cc30a_float_8036c9d0,*cc30a_float_8036c9d4);
 cc30a_call_8018179c(self->a,track[0],1);
 }
}}
