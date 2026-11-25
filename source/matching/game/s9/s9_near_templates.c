/* Small wrappers, ownership operations and callbacks with observed argument flow. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
typedef void (*S9RefFn)(void *);
typedef int (*S9Callback)(int);
extern int *fn_8018d5b8(void *,unsigned int *);
extern void fn_8034435c(int);
extern int fn_8017b348(void *);
extern int lbl_804ab698;
extern void fn_8017fe2c(void *);
extern int fn_80343580(int);
extern void fn_8018c5b0(int,int);
extern void fn_8018d35c(int,void *);
extern void fn_8018d434(int,void *);
extern void fn_8011bc28(void *);
extern void fn_8013f08c(void *);
extern void fn_8013f6b4(void *);
extern void fn_801f67e0(int);
extern void fn_8015aa04(int);
extern int lbl_804aa8c8;
extern void fn_8016c7d0(void *,int,int);
extern int fn_8016b488(void *,void *);

int s9_fill_values_8018d434(void *self,const int *value)
{
    unsigned int count;
    unsigned int i;
    int *out;
    fn_8034435c(FIELD(self,int,116));
    if(!FIELD(self,int,240))goto failed;
    out=fn_8018d5b8(self,&count);
    for(i=0;i<count;i++) { *out=*value;out++; }
    return 0;
failed:
    return 0x80004005;
}
int s9_release_inner_80189190(void *self)
{
    int result=fn_8017b348(self);
    void *inner=FIELD(self,void *,116);
    typedef void (*S9RemoveOwner)(void *,void *);
    FIELD(FIELD(inner,void *,0),S9RemoveOwner,60)(inner,self);
    inner=FIELD(self,void *,168);
    lbl_804ab698--;
    if(inner)FIELD(FIELD(inner,void *,0),S9RefFn,16)(inner);
    FIELD(self,void *,168)=0;
    return result;
}
int s9_invoke_callback_8017f5c8(void *self)
{
    S9Callback callback;
    if(!(FIELD(self,int,24)&0x8000))return 0x80004005;
    if(FIELD(self,unsigned short,36)&32)fn_8017fe2c(self);
    callback=FIELD(self,S9Callback,44);
    return callback ? callback(FIELD(self,int,40)) : 0;
}
void s9_refresh_hud_value_8011ad90(void *self,int value)
{
    int handle;
    if(FIELD(self,int,28)) {
        handle=fn_80343580(FIELD(self,int,28));
        fn_8018c5b0(handle,value);
        fn_8018d35c(handle,(char *)self+68);
        fn_8018d434(handle,(char *)self+72);
        fn_8011bc28(self);
    }
}
void s9_release_actor_inner_8013e458(void *self)
{
    void *inner;
    fn_8013f08c(self);
    fn_8013f6b4(self);
    inner=FIELD(self,void *,164);
    if(inner)FIELD(FIELD(inner,void *,0),S9RefFn,16)(inner);
    FIELD(self,void *,164)=0;
}
void s9_route_setting_8014be44(void *self,int value)
{
    if(FIELD(self,int,300))fn_801f67e0(value);
    else fn_8015aa04(lbl_804aa8c8+328);
}
int s9_adjust_disable_8016d3ec(int self,int value)
{
    fn_8016c7d0(self ? (void *)(self-4):0,value,0);
    return 0;
}
int s9_adjust_enable_8016d428(int self,int value)
{
    fn_8016c7d0(self ? (void *)(self-4):0,value,1);
    return 0;
}
int s9_status_present_801758c8(void *self)
{
    return FIELD(self,int,20) ? 0x80004001 : 0x80004005;
}
int s9_status_signed_8017c24c(void *self)
{
    return FIELD(self,int,20)<0 ? 0x80004001 : 0x80004005;
}
int s9_wait_count_8016b6d8(void *self,void *data)
{
    int result=fn_8016b488(self,data);
    if(!result) {
        unsigned int i;
        unsigned int count=FIELD(data,unsigned int,84);
        for(i=0;i<count;i++);
        result=0;
    }
    return result;
}
