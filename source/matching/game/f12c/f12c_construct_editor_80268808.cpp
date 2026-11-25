// Partial instruction-observed editor layout. Native pairs carry real construction lifetimes.
struct F12cEditorIface { void **table; };
struct F12cEditorHeld { F12cEditorIface *p; F12cEditorHeld():p(0){} };
struct F12cEditorPair { F12cEditorHeld a[2]; };
struct F12cEditor {
 void **table; char actor4[24]; char menu28[180]; void **menuTable;
 F12cEditorIface *first; int state216;
 F12cEditorPair p220,p228,p236,p244,p252,p260,p268,p276;
 int state284; F12cEditorPair p288; F12cEditorIface *held296; int state300;
 char unknown304[8]; char properties312[96];
 int state408,state412,state416,unknown420; char *text424,*text428;
 int state432,seed436,state440,state444,state448;
 int state452,state456,state460,state464,state468,state472,state476,state480,state484,state488,state492,state496,state500,state504,state508;
};
extern void *vt_8041bc90[],*vt_8041bce0[];
extern const char name_803cb80c[];
extern "C" void *fn_8015fef0(void*),*fn_802afb20(void*),*fn_8026c714(void*);
extern "C" void fn_803426b8(void*),fn_8026c0d0(void*,int);
extern "C" void*fn_8020bd38(void*,const char*);
inline void *operator new(unsigned,void*p){return p;}
extern "C" F12cEditor *w3d_f12c_construct_editor_80268808(F12cEditor*s){
 fn_8015fef0(s);fn_802afb20(s->menu28);s->menuTable=vt_8041bc90;s->table=vt_8041bce0;
 s->first=0;s->state216=0;
 new(&s->p220)F12cEditorPair;new(&s->p228)F12cEditorPair;new(&s->p236)F12cEditorPair;new(&s->p244)F12cEditorPair;
 new(&s->p252)F12cEditorPair;new(&s->p260)F12cEditorPair;new(&s->p268)F12cEditorPair;new(&s->p276)F12cEditorPair;
 s->state284=0;new(&s->p288)F12cEditorPair;
 int zero=0;s->held296=0;s->state300=zero;fn_8026c714(s->properties312);
 s->state408=zero;fn_803426b8(&s->text424);fn_803426b8(&s->text428);
 s->state452=zero;s->state456=zero;s->state460=zero;s->state464=zero;s->state468=zero;s->state472=zero;
 s->state476=zero;s->state480=zero;s->state484=zero;s->state488=zero;s->state492=zero;s->state504=zero;s->state508=zero;s->state444=zero;s->state448=zero;
 fn_8020bd38(&s->text424,name_803cb80c);
 s->state496=zero;s->state432=zero;s->seed436=12345678;fn_8026c0d0(s,0);
 s->state500=zero;s->state412=zero;s->state416=zero;
 if(s->held296)((void(*)(F12cEditorIface*))s->held296->table[4])(s->held296);
 s->held296=0;s->state440=1;return s;
}
