// desc: Appears to verify a CRC: it computes the checksum of a buffer, logs both values on a mismatch and returns zero, else returns one.
extern const char lbl_803d7494[];
extern unsigned fn_802ad978(const void *, unsigned);
extern int fn_802fb7ac(const char *, ...);
int w3d_s21_verify_crc_802ad9c0(const void *data, unsigned length, unsigned expected)
{
    unsigned actual = fn_802ad978(data, length);
    if (expected == actual)
        return 1;
    fn_802fb7ac(lbl_803d7494, expected, actual);
    return 0;
}
