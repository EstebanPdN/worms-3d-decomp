// desc: Appears to byte-swap the bits of a float into a stack temporary and pass the four bytes to a write helper.
extern "C" void r27c_write_802047e0(void *, void *, int);
static inline unsigned swap32(unsigned x){ return (x << 24) | ((x << 8) & 0xff0000) | ((x >> 8) & 0xff00) | (x >> 24); }
extern "C" void r27c_write_float_802041d4(void *stream, float value){union { float f; unsigned u; } v; unsigned t; v.f = value; t = swap32(v.u); r27c_write_802047e0(stream,&t,4);}