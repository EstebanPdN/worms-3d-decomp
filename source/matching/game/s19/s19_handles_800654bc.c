extern void *w3d_s20_lookup_handle_object_80164fc8(int);
extern void w3d_auto_8015fd1c(void *);
void s19_clear_handles_800654bc(void *self)
{
    int *p = (int *)((char *)self + 28);
    int i;
    for (i = 0; i < 4; i++, p++) {
        int h = *p;
        if (h) {
            void *object = w3d_s20_lookup_handle_object_80164fc8(h);
            if (object)
                w3d_auto_8015fd1c(object);
            *p = 0;
        }
    }
}
