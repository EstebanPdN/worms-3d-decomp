#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_item_emit_8016b640.c"
extern int w3d_s20_dispatch_item_fields_8016b488(Ptr32<char> self, Ptr32<char> item);
extern void fn_8016797c(Ptr32<void> owner, int handle, int mode, Ptr32<char> target);
extern void w3d_cx13b_gx_index_stream_emit_8016b3f0(int primitive, unsigned int mask, unsigned int count);
extern Ptr32<void> lbl_804b1884;

int w3d_k8b_item_emit_8016b640(Ptr32<char> self, Ptr32<char> item)
{
    int handle;
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int result = w3d_s20_dispatch_item_fields_8016b488(self, item);
    handle = *(Ptr32<int>)(base + 288);
    fn_8016797c(lbl_804b1884, handle, 2, base ? w3d::R(base + 4) : 0);
    if (result != 0)
        return result;
    w3d_cx13b_gx_index_stream_emit_8016b3f0(144, handle, (unsigned short)(*(Ptr32<int>)(item + 84) * 3));
    return 0;
}

}
