/* Shared-resource constructors and observed interface ownership operations. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
typedef void (*S9RefFn)(void *);
typedef int (*S9ValueFn)(void *);
typedef void (*S9SetFn)(void *,int);
typedef void (*S9UpdateFn)(void *,void *);
extern void fn_801857f4(void *);
extern void fn_8017892c(void *);
extern void fn_802109dc(void *);
extern void fn_801f2678(void *);
extern void *fn_8020b680(void *);
extern char lbl_804126d0[];
extern char lbl_804140d0[];
extern char lbl_80412450[];
extern char lbl_80413be8[];
extern char lbl_804149f0[];
extern int lbl_804ab5d8;
extern int lbl_804ab5d0;
extern void *lbl_804b0160;
extern void *lbl_804b015c;
extern void *lbl_804ab5fc;
extern void *fn_80165254(void);
extern void fn_801fc790(void *,void *);
extern char lbl_803a43d4[];
extern char lbl_803a43e4[];
extern char lbl_803a43f0[];
extern int lbl_804b0060;
extern int lbl_804b0068;
extern int lbl_804b006c;
extern int lbl_804b0074;
extern int lbl_804b0078;
extern int lbl_804b0080;

void *s9_construct_shared_node_8017990c(void *self)
{
    void *value;
    fn_801857f4(self);
    FIELD(self,int,120)=0;
    FIELD(self,int,124)=0;
    FIELD(self,void *,0)=lbl_804126d0;
    fn_802109dc((char *)self+128);
    fn_801f2678((char *)self+140);
    fn_801f2678((char *)self+152);
    if(!lbl_804ab5d8) {
        value=fn_8020b680(lbl_804140d0);
        if(value)FIELD(FIELD(value,void *,0),S9RefFn,12)(value);
        if(lbl_804b0160)FIELD(FIELD(lbl_804b0160,void *,0),S9RefFn,16)(lbl_804b0160);
        lbl_804b0160=value;
    }
    lbl_804ab5d8++;
    FIELD(self,int,164)=1;
    return self;
}
void *s9_construct_resource_owner_8017917c(void *self)
{
    int count;
    void *value;
    fn_8017892c(self);
    count=lbl_804ab5d0+1;
    FIELD(self,void *,0)=lbl_80412450;
    lbl_804ab5d0=count;
    if(count==1) {
        value=fn_8020b680(lbl_80413be8);
        if(value)FIELD(FIELD(value,void *,0),S9RefFn,12)(value);
        if(lbl_804b015c)FIELD(FIELD(lbl_804b015c,void *,0),S9RefFn,16)(lbl_804b015c);
        lbl_804b015c=value;
        FIELD(FIELD(value,void *,0),S9SetFn,52)(value,1);
    }
    return self;
}
void s9_ensure_resource_8017b6dc(void *self)
{
    void *value;
    void *old;
    void *target;
    if(FIELD(self,void *,124))return;
    value=fn_8020b680(lbl_804149f0);
    if(value)FIELD(FIELD(value,void *,0),S9RefFn,12)(value);
    old=FIELD(self,void *,124);
    if(old)FIELD(FIELD(old,void *,0),S9RefFn,16)(old);
    FIELD(self,void *,124)=value;
    FIELD(value,char,25)=FIELD(FIELD(lbl_804ab5fc,void *,0),S9ValueFn,156)(lbl_804ab5fc);
    target=FIELD(self,void *,124);
    FIELD(target,char,24)=FIELD(FIELD(lbl_804ab5fc,void *,0),S9ValueFn,156)(lbl_804ab5fc);
}
void s9_update_render_clock_8015caec(void *self,int delta)
{
    int increment;
    int clock;
    void *context;
    void *child;
    void *renderer;
    if(!lbl_804b0068) { fn_801fc790(&lbl_804b0060,lbl_803a43d4);lbl_804b0068=1; }
    if(!lbl_804b0074) { fn_801fc790(&lbl_804b006c,lbl_803a43e4);lbl_804b0074=1; }
    if(!lbl_804b0080) { fn_801fc790(&lbl_804b0078,lbl_803a43f0);lbl_804b0080=1; }
    increment=delta;
    context=fn_80165254();
    if(FIELD(context,int,56))increment=0;
    clock=FIELD(self,int,120);
    child=FIELD(self,void *,108);
    FIELD(self,int,120)=clock+increment;
    if(child)FIELD(FIELD(child,void *,0),S9SetFn,28)(child,delta);
    renderer=FIELD(self,void *,96);
    FIELD(FIELD(renderer,void *,0),S9UpdateFn,32)(renderer,(char *)self+120);
}
