// desc: Appears to write a second eight-byte integer value, byte-identical to its sibling, through the same write helper.
extern int fn_802047e0(void *, void *, int);
void w3d_s21_write_i64_802041a4(void *stream, int unused, long long value)
{
    long long copy = value;
    fn_802047e0(stream, &copy, 8);
}
