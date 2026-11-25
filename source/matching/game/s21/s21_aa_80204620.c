// desc: Appears to call a virtual write slot on a stream for each sixteen-byte entry, stopping at the first negative status and returning zero otherwise.
struct S21Stream;
struct S21StreamMethods { void (*reserved[34])(void); int (*write_block)(struct S21Stream *, void *, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
int w3d_s21_write_blocks_80204620(struct S21Stream *stream, char *blocks, unsigned count, int context)
{
    unsigned i = 0;
    if (i < count) {
        do {
            int status = stream->methods->write_block(stream, blocks, context, 0);
            blocks += 16;
            if (status < 0)
                return status;
            i++;
        } while (i < count);
    }
    return 0;
}
