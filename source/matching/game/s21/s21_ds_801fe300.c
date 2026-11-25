// desc: Appears to clear the top two bits of the word the pointer refers to and return the pointer.
unsigned *w3d_s21_clear_top_bits_801fe300(unsigned *word)
{
    *word &= 0x3fffffff;
    return word;
}
