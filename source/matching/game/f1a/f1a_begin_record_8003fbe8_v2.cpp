// Original 0x8003fbe8; fields and global addresses observed, role inferred.
struct F1aVec3 { float x, y, z; };
struct F1aRec { F1aVec3 v; float f; int pad[4]; };
extern "C" {
extern F1aRec *lbl_804273ec[];
extern F1aVec3 lbl_80427408;
extern short lbl_804aa950;
extern int lbl_804aa954;
extern int lbl_804aa964;
extern short lbl_804aa95c;
extern int lbl_804aa960;
extern int lbl_804aa958;
extern int lbl_804b1790;
extern float lbl_804b17b0;
extern void (*lbl_804b17b4)(void);
extern float lbl_804b17b8;
int fn_8003ffb8(void);
inline void begin_scene(int idx,int a,int b) {
 F1aRec *rec=&lbl_804273ec[0][idx];
 lbl_80427408=rec->v;
 lbl_804aa950=idx;
 float fv=rec->f;
 lbl_804aa95c=0;
 lbl_804aa954=a;
 lbl_804b17b0=fv*fv;
 lbl_804aa960=b;
 lbl_804b1790=0;
 lbl_804aa958=1;
lbl_804aa964=1;
lbl_804b17b4=(void (*)(void))fn_8003ffb8;
lbl_804b17b8=fv;
}
void w3d_f1a_begin_record_8003fbe8(int idx,int a,int b){begin_scene(idx,a,b);}
}
