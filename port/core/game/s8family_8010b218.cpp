#include "w3d_ptr.h"
#line 1 "s8family_8010b218.cpp"
typedef Ptr32<int (int, int, int, int, Ptr32<short>, int)> s8_DispatchFn;
struct s8_DispatchContext {
    char pad0[44];
    s8_DispatchFn dispatch;
    char pad48[2256];
    Ptr32<int> entries;
    char pad2308[56];
    Ptr32<short> pairs;
};
extern unsigned char lbl_8044c6ec[];
extern "C" void s8_toggle_dispatch_8010b218(Ptr32<s8_DispatchContext> context,int a,int b,int c,int index,int flag) {
    context->dispatch(a,b,c,*(Ptr32<int>)w3d::G(((int)w3d::H(context->entries)+(index<<2))),context->pairs+index,flag==lbl_8044c6ec[index]);
    lbl_8044c6ec[index]=1-flag;
}


