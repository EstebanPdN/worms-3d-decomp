// Byte-order conversion around a stream write.
//
// The caller supplies a stream, an array of 32-bit words and a word count.
// Each word of the array is byte-swapped in place, the array is handed to the
// stream writer as count*4 bytes, and the words are swapped back so the
// caller's buffer keeps its original byte order.
//
// Observed ABI:
//   r3 : stream, forwarded to the writer untouched
//   r4 : word array
//   r5 : word count (unsigned)
//
// The writer at 0x802047e0 is the already recovered stream write helper.

// Already recovered stream write helper (0x802047e0): writes `length` bytes
// from `buffer` to the stream.
extern "C" unsigned int w3d_cx16c_stream_mode_write_802047e0(void *self, void *buffer, int length);

static inline unsigned int w3d_swap_bytes(unsigned int value)
{
    return (value << 24)
         | ((value >> 8) & 0x0000ff00u)
         | ((value << 8) & 0x00ff0000u)
         | (value >> 24);
}

extern "C" void e13d_swap_stream_words_8035bd50(void *stream, unsigned int *words, unsigned int count)
{
    unsigned int i;
    for (i = 0; i < count; i++)
        words[i] = w3d_swap_bytes(words[i]);
    w3d_cx16c_stream_mode_write_802047e0(stream, words, (int)(count * 4));
    for (i = 0; i < count; i++)
        words[i] = w3d_swap_bytes(words[i]);
}
