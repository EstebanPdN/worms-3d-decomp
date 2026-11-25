typedef struct { unsigned x,y,z; } Vec3;
typedef struct { char pad[12]; float weight; Vec3 position; } Entry;
typedef struct { Entry **begin,**end; } List;
typedef struct { char pad[12]; void *vt; int value; Vec3 position; int z0,flag,z1,index; } Plan;
extern List *lbl_804aa750;
extern int lbl_804aa594;
extern float lbl_8036a730[];
extern char lbl_8040d8e8[],lbl_8040d8b0[];
extern void *fn_8001523c(unsigned);
extern void fn_80006360(Plan *);
extern void fn_80007514(Plan *);
int codex_ai171b4_select(void) {
 int index=0, result=0;
 if(lbl_804aa750->end-lbl_804aa750->begin>0) {
 int zero=0; int off=0; float threshold=lbl_8036a730[0];
 do {
  if((*(Entry **)((unsigned)lbl_804aa750->begin + off))->weight>threshold) {
   Plan *p=(Plan*)fn_8001523c(48);
   Entry *e=(*(Entry **)((unsigned)lbl_804aa750->begin + off));
   fn_80006360(p);
   p->z0=zero; p->value=-1; p->flag=1; p->vt=lbl_8040d8e8; p->z1=zero;
   p->position=e->position;
   p->value=500; p->flag=zero; p->vt=lbl_8040d8b0; p->index=index;
   fn_80007514(p); result=1;
  }
  off+=4; ++index;
 } while(index<lbl_804aa750->end-lbl_804aa750->begin);
 }
 lbl_804aa594=1;
 return result;
}
