typedef int (*s8_DispatchFn)(int,int,int,int,short *,int);
struct s8_DispatchContext {
    char pad0[44];
    s8_DispatchFn dispatch;
    char pad48[2328];
    int *entries;
    char pad2308[56];
    short *pairs;
};
extern unsigned char lbl_8044c86c[];
extern "C" void s8_toggle_dispatch_8010ae30(s8_DispatchContext *context,int a,int b,int c,int index,int flag) {
    context->dispatch(a,b,c,*(int *)((int)context->entries+(index<<2)),context->pairs+index,flag==lbl_8044c86c[index]);
    lbl_8044c86c[index]=1-flag;
}
