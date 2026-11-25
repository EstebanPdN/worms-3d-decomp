struct K6bFileInfo {
    int size;
    int flags;
    int kind;
};
struct K6bFileReader {
    char head[24];
    void *file;
};
extern int fn_802e4d04(void *file, int offset, int whence);
int w3d_k6b_file_reader_query_size_8021931c(struct K6bFileReader *self, struct K6bFileInfo *info)
{
    int position;
    info->flags = 0;
    info->kind = 2;
    position = fn_802e4d04(self->file, 0, 1);
    info->size = fn_802e4d04(self->file, 0, 2);
    fn_802e4d04(self->file, position, 0);
    return 0;
}
// desc: w3d_k6b_file_reader_query_size_8021931c: Appears to fill a file info record: clear +4, set kind 2, and measure the size by seeking the file at +24 to its end and back.
