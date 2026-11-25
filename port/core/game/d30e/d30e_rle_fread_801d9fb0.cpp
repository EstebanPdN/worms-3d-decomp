#include "w3d_ptr.h"
#line 1 "d30e_rle_fread_801d9fb0.cpp"
// (Worms 3D GameCube PAL, 0x801d9fb0).
//
// Decodes run-length TGA data from a stream (Mark Kilgard's public
// gliReadTGA rle_fread): copies pending decoded bytes from the state buffer,
// reads a packet count, then a repeated value or raw bytes directly into the
// output or into the lazily allocated state buffer, with verbose tracing;
// returns elements read. fgetc and fread are stream read calls through
// virtual slot 3, with end of file reported as 0x90000001.

extern "C" Ptr32<void> memcpy(...);
extern "C" Ptr32<void> memset(Ptr32<void>, int, int);
extern "C" int printf(Ptr32<const char>, ...);
extern "C" Ptr32<void> w3d_handle_storage_allocate(int);
extern char lbl_803af908[], lbl_803af930[], lbl_803af964[], lbl_803af9b0[], lbl_803af9b4[], lbl_803af998[], lbl_803af9b8[];
extern int lbl_804ab7fc;
extern unsigned lbl_804ab800;
struct Stream { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Stream2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN6Stream2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN6Stream2v2Ev")); int w3d_r_read(Ptr32<void>, int, Ptr32<unsigned int>) __asm__(W3D_SYM("_ZN6Stream4readEPviPj"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int read(Ptr32<void> w3d_a0, int w3d_a1, Ptr32<unsigned int> w3d_a2) { return ((int (*)(w3d_u32, Ptr32<void>, int, Ptr32<unsigned int>))w3d::vfn(this->w3d_vptr_Stream, 5))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_Stream; };
struct RLEstate { Ptr32<unsigned char> statebuf; int statelen; int laststate; };
extern "C" int w3d_d30e_rle_fread_801d9fb0(Ptr32<RLEstate> rleInfo, Ptr32<unsigned char> buf, unsigned datasize, unsigned nelems, Ptr32<Stream> fp) {
  int j, k;
  int buflen, count, bytes, curbytes;
  Ptr32<unsigned char> p;
  curbytes = lbl_804ab7fc;
  buflen = nelems * datasize;
  j = 0;
  while (j < buflen) {
    if (rleInfo->laststate < rleInfo->statelen) {
      bytes = rleInfo->statelen - rleInfo->laststate;
      if (bytes > buflen - j) bytes = buflen - j;
      memcpy(w3d::VA(buf + j), w3d::VA(rleInfo->statebuf + rleInfo->laststate), bytes);
      j += bytes;
      rleInfo->laststate += bytes;
      if (rleInfo->laststate >= rleInfo->statelen) {
        rleInfo->laststate = 0;
        rleInfo->statelen = 0;
      }
      if (j >= buflen) break;
    }
    {
      unsigned char c;
      int hr = fp->read(&c, 1, 0);
      count = c;
      if (hr == (int)0x90000001) {
        if (lbl_804ab800) printf(lbl_803af908);
        return (unsigned)j / datasize;
      }
    }
    bytes = ((count & ~0x80) + 1) * datasize;
    if (j + bytes <= buflen) {
      p = buf + j;
    } else {
      if (!rleInfo->statebuf) rleInfo->statebuf = (Ptr32<unsigned char>)w3d_handle_storage_allocate(0x80 * datasize);
      p = rleInfo->statebuf;
    }
    if (count & 0x80) {
      unsigned got;
      fp->read(p, datasize, &got);
      if (got != datasize) {
        if (lbl_804ab800) printf(lbl_803af930, bytes, datasize);
        return (unsigned)j / datasize;
      }
      if (datasize == 1) {
        memset(p + 1, *p, bytes - 1);
      } else {
        for (k = datasize; k < bytes; k += datasize) memcpy(w3d::VA(p + k), w3d::VA(p), datasize);
      }
    } else {
      unsigned got;
      fp->read(p, bytes, &got);
      if (got != (unsigned)bytes) {
        if (lbl_804ab800) printf(lbl_803af964, bytes, datasize);
        return (unsigned)j / datasize;
      }
    }
    if (lbl_804ab800 > 1) {
      lbl_804ab7fc += bytes;
      if (lbl_804ab800 > 2) printf(lbl_803af998, w3d::VA((count & 0x80) ? lbl_803af9b0 : lbl_803af9b4), bytes, lbl_804ab7fc);
    }
    if (p == rleInfo->statebuf) rleInfo->statelen = bytes;
    else j += bytes;
  }
  if (lbl_804ab800 > 1) printf(lbl_803af9b8, nelems * datasize, lbl_804ab7fc - curbytes, lbl_804ab7fc);
  return nelems;
}


