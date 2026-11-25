#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8c_panel_message_80270710.c"
struct K8cMessage { unsigned short type; };
struct K8cPanel { char pad00[28]; char body[1]; };
extern int fn_8015fb34(Ptr32<struct K8cPanel> self, Ptr32<struct K8cMessage> msg);
extern void fn_802707f0(Ptr32<struct K8cPanel> self);
extern void fn_80270bdc(Ptr32<struct K8cPanel> self);
extern int fn_802b264c(Ptr32<void> body);
extern void fn_802aff9c(Ptr32<void> body, Ptr32<struct K8cMessage> msg);
int w3d_k8c_panel_message_80270710(Ptr32<struct K8cPanel> self, Ptr32<struct K8cMessage> msg)
{
    switch (msg->type) {
    case 64:
        if (fn_8015fb34(self, msg) >= 0) {
            fn_802707f0(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        fn_80270bdc(self);
        return fn_8015fb34(self, msg);
    default:
        if (fn_802b264c(self->body))
            fn_802aff9c(self->body, msg);
        return fn_8015fb34(self, msg);
    }
}

}
