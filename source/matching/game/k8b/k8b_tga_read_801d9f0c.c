struct K8bStream { int (**vtable)(struct K8bStream *, void *, unsigned int, unsigned int *); };
extern int fn_802ebfbc(const char *format, ...);
extern unsigned int lbl_804ab800;
extern unsigned int lbl_804ab7fc;

unsigned int w3d_k8b_tga_read_801d9f0c(void *unused, void *buffer, unsigned int size, unsigned int count, struct K8bStream *stream)
{
    unsigned int done;
    int status;
    if (lbl_804ab800 > 1) {
        lbl_804ab7fc += count * size;
        fn_802ebfbc("TGA: std_fread %d (total %d)\n", count * size, lbl_804ab7fc);
    }
    done = 0;
    status = stream->vtable[5](stream, buffer, size * count, &done);
    if (status < 0)
        return 0;
    return done / size;
}
