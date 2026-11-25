// desc: Appears to update a table-driven CRC value over a byte buffer using a global lookup table and return the result.
extern unsigned lbl_804a98f8[];
unsigned w3d_s21_crc_update_8021d7ec(unsigned crc, const unsigned char *data, unsigned length)
{
    while (length--) {
        crc = (crc >> 8) ^ lbl_804a98f8[(crc & 0xff) ^ *data];
        data++;
    }
    return crc;
}
