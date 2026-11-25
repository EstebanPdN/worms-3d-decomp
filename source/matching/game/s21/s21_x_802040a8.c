// desc: Appears to swap the bytes of a 16-bit argument into a stack temporary and pass it to a two-byte write helper.
extern int fn_802047e0(void *, void *, int);
void w3d_s21_write_u16_swapped_802040a8(void *stream, unsigned short value)
{
    unsigned short swapped = ((value & 0xff) << 8) | ((value >> 8) & 0xff);
    fn_802047e0(stream, &swapped, 2);
}
