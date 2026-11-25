// (Worms 3D GameCube PAL, 0x801d9fb0).
//
// Decodes run-length TGA data from a stream (Mark Kilgard's public
// gliReadTGA rle_fread): copies pending decoded bytes from the state buffer,
// reads a packet count, then a repeated value or raw bytes directly into the
// output or into the lazily allocated state buffer, with verbose tracing;
// returns elements read. fgetc and fread are stream read calls through
// virtual slot 3, with end of file reported as 0x90000001.

extern "C" void *memcpy(...);
extern "C" void *memset(void *, int, int);
extern "C" int printf(const char *, ...);
extern "C" void *w3d_handle_storage_allocate(int);
extern char lbl_803af908[], lbl_803af930[], lbl_803af964[], lbl_803af9b0[], lbl_803af9b4[], lbl_803af998[], lbl_803af9b8[];
extern int lbl_804ab7fc;
extern unsigned lbl_804ab800;
struct Stream { virtual void v0(),v1(),v2(); virtual int read(void *, int, unsigned *); };
struct RLEstate { unsigned char *statebuf; int statelen; int laststate; };
extern "C" int w3d_d30e_rle_fread_801d9fb0(RLEstate *rleInfo, unsigned char *buf, unsigned datasize, unsigned nelems, Stream *fp) {
  int j, k;
  int buflen, count, bytes, curbytes;
  unsigned char *p;
  curbytes = lbl_804ab7fc;
  buflen = nelems * datasize;
  j = 0;
  while (j < buflen) {
    if (rleInfo->laststate < rleInfo->statelen) {
      bytes = rleInfo->statelen - rleInfo->laststate;
      if (bytes > buflen - j) bytes = buflen - j;
      memcpy(buf + j, rleInfo->statebuf + rleInfo->laststate, bytes);
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
      if (!rleInfo->statebuf) rleInfo->statebuf = (unsigned char *)w3d_handle_storage_allocate(0x80 * datasize);
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
        for (k = datasize; k < bytes; k += datasize) memcpy(p + k, p, datasize);
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
      if (lbl_804ab800 > 2) printf(lbl_803af998, (count & 0x80) ? lbl_803af9b0 : lbl_803af9b4, bytes, lbl_804ab7fc);
    }
    if (p == rleInfo->statebuf) rleInfo->statelen = bytes;
    else j += bytes;
  }
  if (lbl_804ab800 > 1) printf(lbl_803af9b8, nelems * datasize, lbl_804ab7fc - curbytes, lbl_804ab7fc);
  return nelems;
}
