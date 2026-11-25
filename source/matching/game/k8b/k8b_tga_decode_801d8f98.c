extern void *lbl_804b0554;
extern unsigned int lbl_804b0558;
extern void *w3d_heap_allocate_entry_b(unsigned int size);
extern void w3d_task_array_release(void *block);
extern int fn_801d8e20(int a, int b, int c, int d, unsigned int width, unsigned int height, unsigned char *out);
extern int fn_801d8cd4(int a, int b, int c, int d, unsigned int width, unsigned int height, unsigned char *out);

int w3d_k8b_tga_decode_801d8f98(unsigned char *luma, int unused0, int unused1, int width, int height, unsigned char *chroma)
{
    unsigned int capacity = 8192;
    if ((unsigned int)(width * height) > 8192)
        capacity = width * height;
    if (lbl_804b0554)
        w3d_task_array_release(lbl_804b0554);
    lbl_804b0558 = capacity;
    lbl_804b0554 = w3d_heap_allocate_entry_b(capacity * 4);
    fn_801d8e20(0, (width + 63) >> 6, 0, 0, width, height, luma);
    fn_801d8cd4(0, ((unsigned int)width / 2 + 63) >> 6, 0, 0, (unsigned int)width >> 1, (unsigned int)height >> 1, chroma);
    if (lbl_804b0554)
        w3d_task_array_release(lbl_804b0554);
    {
        unsigned int *reset = (unsigned int *)&lbl_804b0554;
        reset[1] = 0;
        reset[0] = 0;
    }
    return 0;
}
