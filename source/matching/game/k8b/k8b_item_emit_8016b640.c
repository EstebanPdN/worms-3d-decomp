extern int w3d_s20_dispatch_item_fields_8016b488(char *self, char *item);
extern void fn_8016797c(void *owner, int handle, int mode, char *target);
extern void w3d_cx13b_gx_index_stream_emit_8016b3f0(int primitive, unsigned int mask, unsigned int count);
extern void *lbl_804b1884;

int w3d_k8b_item_emit_8016b640(char *self, char *item)
{
    int handle;
    char *base = self ? self - 4 : 0;
    int result = w3d_s20_dispatch_item_fields_8016b488(self, item);
    handle = *(int *)(base + 288);
    fn_8016797c(lbl_804b1884, handle, 2, base ? base + 4 : 0);
    if (result != 0)
        return result;
    w3d_cx13b_gx_index_stream_emit_8016b3f0(144, handle, (unsigned short)(*(int *)(item + 84) * 3));
    return 0;
}
