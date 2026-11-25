// desc: Appears to swap the bytes of a 16-bit value taken from an int argument into a stack temporary and pass it to a two-byte write helper.
extern int fn_802047e0(void *, void *, int);
void w3d_s21_write_u16_swapped_8020406c(void *stream, unsigned value)
{
    unsigned short x = value;
    unsigned short swapped = ((x & 0xff) << 8) | (x >> 8);
    fn_802047e0(stream, &swapped, 2);
}
