// Original entry 0x8002d2c8. Field and vector meanings are inferred.
// An unused vector local preserves the frame reservation observed in the original.
struct Vec {float x,y,z;Vec(){}Vec(float a,float b,float c):x(a),y(b),z(c){}void set(float a,float b,float c){x=a;y=b;z=c;}};
struct Obj {char p[28];Vec olddir;char q[16];void *index;char r[16];int clear;float angle,otherangle;Vec pos,flat,dir;void *a,*b;};
struct Body {char p[72];float angle;char q[4];Vec pos;};
extern "C" {float fn_80178df0(void*);int fn_80178c48(void*);Body *fn_800fc6dc(int);float fn_802e86d4(float);float fn_802e88ac(float);extern float lbl_80372964[],lbl_80372968[];
void w3d_f2a_initialize_orientation_8002d2c8(Obj *p){Vec reservation;p->clear=0;float a=fn_80178df0(p->a);float b=fn_80178df0(p->b);float zero=lbl_80372964[0];p->pos.set(zero,a+b,zero);p->angle=zero;p->otherangle=zero;if(fn_80178c48(p->index)>=0){Body *v=fn_800fc6dc(fn_80178c48(p->index));float half=lbl_80372968[0];p->pos.x=v->pos.x;p->pos.z=v->pos.z;p->otherangle=p->angle=half-v->angle;}p->flat=p->pos;p->flat.y=zero;float c=fn_802e86d4(p->angle);float s=fn_802e88ac(p->angle);p->dir.set(c,zero,s);p->olddir=p->dir;}}
