// desc: Appears to run a per-element helper over an array of words, stopping at the first negative status and returning zero otherwise.
extern int fn_8020430c(void *, int *);
int w3d_s21_apply_each_802045bc(void *stream, int *items, unsigned count)
{
    unsigned i = 0;
    if (i < count) {
        do {
            int status = fn_8020430c(stream, items);
            items++;
            if (status < 0)
                return status;
            i++;
        } while (i < count);
    }
    return 0;
}
