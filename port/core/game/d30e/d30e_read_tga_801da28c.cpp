#include "w3d_ptr.h"
#line 1 "d30e_read_tga_801da28c.cpp"
// (Worms 3D GameCube PAL, 0x801da28c).
//
// Reads a TGA image from a stream into a new generic image (Mark Kilgard's
// public gliReadTGA, with stream reads and seeks through virtual slots 3 and
// 5): checks footer and header, decodes the image type, validates channel
// sizes, reads the optional color map with BGR to RGB swap, reads each row
// through the plain or run-length reader, reverses rows when needed, and
// fills the 36-byte result. Errors format into the buffer at 0x8045d818 and
// return null.

extern "C" Ptr32<void> memset(Ptr32<void>, int, int);
extern "C" int memcmp(Ptr32<const void>, Ptr32<const void>, unsigned);
extern "C" int printf(Ptr32<const char>, ...);
extern "C" int sprintf(Ptr32<char>, Ptr32<const char>, ...);
extern "C" Ptr32<void> w3d_handle_storage_allocate(int);
extern "C" void w3d_handle_storage_release(Ptr32<void>);
extern char lbl_8045d818[];
extern char lbl_803af9dc[], lbl_803afa00[], lbl_803afa04[], lbl_803afa18[], lbl_803afa2c[], lbl_803afa48[], lbl_803afa6c[], lbl_803afa90[], lbl_803afab4[], lbl_803afacc[], lbl_803afaf0[], lbl_803afb14[], lbl_803afb40[], lbl_803afb5c[], lbl_803afb74[], lbl_803afb94[], lbl_803afbb0[], lbl_803afbdc[], lbl_803afbfc[], lbl_803afc28[], lbl_803afc44[], lbl_803afc68[], lbl_803afca0[], lbl_803afcd4[], lbl_803afd0c[], lbl_803afd3c[], lbl_803afd60[], lbl_803afd8c[], lbl_803afdbc[];
extern unsigned lbl_804ab800;
struct Stream { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Stream2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN6Stream2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN6Stream2v2Ev")); int w3d_r_read(Ptr32<void>, int, Ptr32<int>) __asm__(W3D_SYM("_ZN6Stream4readEPviPi")); void w3d_r_v4() __asm__(W3D_SYM("_ZN6Stream2v4Ev")); int w3d_r_seek(int, int, Ptr32<int>) __asm__(W3D_SYM("_ZN6Stream4seekEiiPi"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int read(Ptr32<void> w3d_a0, int w3d_a1, Ptr32<int> w3d_a2) { return ((int (*)(w3d_u32, Ptr32<void>, int, Ptr32<int>))w3d::vfn(this->w3d_vptr_Stream, 5))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Stream, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int seek(int w3d_a0, int w3d_a1, Ptr32<int> w3d_a2) { return ((int (*)(w3d_u32, int, int, Ptr32<int>))w3d::vfn(this->w3d_vptr_Stream, 7))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_Stream; };
struct RLEstate { Ptr32<unsigned char> statebuf; int statelen; int laststate; };
extern "C" int fn_801d9fb0(Ptr32<RLEstate>, Ptr32<unsigned char>, unsigned, unsigned, Ptr32<Stream>);
extern "C" int fn_801d9f0c(Ptr32<RLEstate>, Ptr32<unsigned char>, unsigned, unsigned, Ptr32<Stream>);
struct TgaHeader {
  unsigned char idLength, colorMapType, imageType;
  unsigned char colorMapIndexLow, colorMapIndexHigh, colorMapLengthLow, colorMapLengthHigh, colorMapSize;
  unsigned char xOriginLow, xOriginHigh, yOriginLow, yOriginHigh;
  unsigned char widthLow, widthHigh, heightLow, heightHigh;
  unsigned char bpp, descriptor;
};
struct TgaFooter { unsigned extensionAreaOffset, developerDirectoryOffset; unsigned char signature[16]; char dot, null; };
struct GenericImage { int width, height, components, format, cmapEntries, cmapFormat; Ptr32<unsigned char> cmap; Ptr32<unsigned char> pixels; int pixelDepth; };
extern "C" Ptr32<GenericImage> w3d_d30e_read_tga_801da28c(Ptr32<Stream> fp, Ptr32<char> name, int yFlip) {
  TgaHeader tgaHeader;
  TgaFooter tgaFooter;
  int horzrev, vertrev;
  int width, height, bpp;
  int start, end, dir;
  int i, j, k;
  int pelbytes, wbytes;
  int format, components;
  RLEstate rleRec;
  Ptr32<RLEstate> rleInfo;
  int rle;
  int index, colors, length;
  Ptr32<unsigned char> cmap; Ptr32<unsigned char> pixels; Ptr32<unsigned char> data;
  Ptr32<int (Ptr32<RLEstate>, Ptr32<unsigned char>, unsigned int, unsigned int, Ptr32<Stream>)> myfread;
  Ptr32<GenericImage> image;

  if (fp->seek(-28, 2, 0) < 0 || fp->read(&tgaFooter, 28, 0) < 0) {
    sprintf(lbl_8045d818, lbl_803af9dc, w3d::VA(name));
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
  if (memcmp(tgaFooter.signature, lbl_803afa04, 16) == 0) {
    if (lbl_804ab800) printf(lbl_803afa18);
  } else {
    if (lbl_804ab800) printf(lbl_803afa2c);
  }
  if (fp->seek(0, 0, 0) < 0 || fp->read(&tgaHeader, 18, 0) < 0) {
    sprintf(lbl_8045d818, lbl_803afa48, w3d::VA(name));
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
  if (lbl_804ab800) printf(lbl_803afa6c, tgaHeader.idLength, tgaHeader.colorMapType);
  if (lbl_804ab800 && tgaHeader.idLength) {
    Ptr32<unsigned char> idData = (Ptr32<unsigned char>)w3d_handle_storage_allocate(tgaHeader.idLength);
    if (fp->read(idData, tgaHeader.idLength, 0) < 0) {
      sprintf(lbl_8045d818, lbl_803afa90, w3d::VA(name));
      printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    } else {
      printf(lbl_803afab4, tgaHeader.idLength, w3d::VA(idData));
    }
    w3d_handle_storage_release(idData);
  } else if (tgaHeader.idLength) {
    if (fp->seek(tgaHeader.idLength, 1, 0) < 0) {
    sprintf(lbl_8045d818, lbl_803afacc, w3d::VA(name));
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
  }
  width = (tgaHeader.widthHigh << 8) | tgaHeader.widthLow;
  height = (tgaHeader.heightHigh << 8) | tgaHeader.heightLow;
  bpp = tgaHeader.bpp;
  if (lbl_804ab800) printf(lbl_803afaf0, width, height, bpp);
  if (width == 0 || height == 0 || bpp == 0) {
    sprintf(lbl_8045d818, lbl_803afb14, w3d::VA(name));
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
  horzrev = tgaHeader.descriptor & 0x10;
  vertrev = !(tgaHeader.descriptor & 0x20);
  if (lbl_804ab800 && horzrev) printf(lbl_803afb40);
  if (lbl_804ab800 && vertrev) printf(lbl_803afb5c);
  if (yFlip) {
    if (lbl_804ab800) printf(lbl_803afb74);
    vertrev = !vertrev;
  }
  rle = 0;
  switch (tgaHeader.imageType) {
  case 9:
    rle = 1;
    if (lbl_804ab800) printf(lbl_803afb94);
  case 1:
    format = 6400;
    components = 1;
    if (lbl_804ab800) printf(lbl_803afbb0, tgaHeader.colorMapSize, bpp);
    break;
  case 11:
    rle = 1;
    if (lbl_804ab800) printf(lbl_803afb94);
  case 3:
    format = 6409;
    components = 1;
    if (lbl_804ab800) printf(lbl_803afbdc, bpp);
    break;
  case 10:
    rle = 1;
    if (lbl_804ab800) printf(lbl_803afb94);
  case 2:
    if (bpp == 32) {
      format = 0x80e1;
      components = 4;
      if (lbl_804ab800) printf(lbl_803afbfc, bpp);
    } else {
      format = 0x80e0;
      components = 3;
      if (lbl_804ab800) printf(lbl_803afc28, bpp);
    }
    break;
  default:
    {
    sprintf(lbl_8045d818, lbl_803afc44, tgaHeader.imageType);
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
  }
  if ((format == 0x80e1 && bpp != 32) || (format == 0x80e0 && bpp != 24) || ((format == 6409 || format == 6400) && bpp != 8)) {
    sprintf(lbl_8045d818, lbl_803afc68);
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
  if (format == 6400) {
    if (tgaHeader.colorMapType != 1) {
    sprintf(lbl_8045d818, lbl_803afca0, tgaHeader.colorMapType);
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
  } else if (tgaHeader.colorMapType != 0) {
    sprintf(lbl_8045d818, lbl_803afcd4, tgaHeader.colorMapType);
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
  if (tgaHeader.colorMapType == 1) {
    index = (tgaHeader.colorMapIndexHigh << 8) | tgaHeader.colorMapIndexLow;
    length = (tgaHeader.colorMapLengthHigh << 8) | tgaHeader.colorMapLengthLow;
    if (lbl_804ab800) printf(lbl_803afd0c, index, length, tgaHeader.colorMapSize);
    if (length == 0) {
    sprintf(lbl_8045d818, lbl_803afd3c, length);
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
    if (tgaHeader.colorMapSize != 24 && tgaHeader.colorMapSize != 32) {
    sprintf(lbl_8045d818, lbl_803afc68);
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
    pelbytes = tgaHeader.colorMapSize / 8;
    colors = length + index;
    cmap = (Ptr32<unsigned char>)w3d_handle_storage_allocate(colors * pelbytes);
    memset(cmap, 0, index * pelbytes);
    if (fp->read(cmap, pelbytes * length, 0) < 0) {
      int pos;
      fp->seek(0, 1, &pos);
      {
    sprintf(lbl_8045d818, lbl_803afd60, pos);
    if (lbl_804ab800) printf(lbl_803afa00, w3d::VA(lbl_8045d818));
    return 0;
  }
    }
    if (pelbytes >= 3) {
      for (j = index; j < pelbytes * length; j += pelbytes) {
        int tmp = cmap[j];
        cmap[j] = cmap[j + 2];
        cmap[j + 2] = tmp;
      }
    }
  } else {
    colors = 0;
    cmap = 0;
  }
  pelbytes = bpp / 8;
  pixels = (Ptr32<unsigned char>)w3d_handle_storage_allocate(width * height * pelbytes);
  if (rle) {
    rleRec.statebuf = 0;
    rleRec.statelen = 0;
    rleRec.laststate = 0;
    rleInfo = &rleRec;
    myfread = fn_801d9fb0;
  } else {
    rleInfo = 0;
    myfread = fn_801d9f0c;
  }
  wbytes = width * pelbytes;
  if (vertrev) {
    start = 0;
    end = height;
    dir = 1;
  } else {
    start = height - 1;
    end = -1;
    dir = -1;
  }
  for (i = start; i != end; i += dir) {
    data = pixels + i * wbytes;
    if (myfread(rleInfo, data, pelbytes, width, fp) != width) {
      if (lbl_804ab800) {
        int pos;
        fp->seek(0, 1, &pos);
        printf(lbl_803afd8c, pos, width);
      }
      return 0;
    }
    if (horzrev) {
      for (j = 0; j < width / 2; j++) {
        for (k = 0; k < pelbytes; k++) {
          int tmp = data[j * pelbytes + k];
          data[j * pelbytes + k] = data[(width - j - 1) * pelbytes + k];
          data[(width - j - 1) * pelbytes + k] = tmp;
        }
      }
    }
  }
  if (rle) w3d_handle_storage_release(rleInfo->statebuf);
  {
    unsigned char c;
    if (fp->read(&c, 1, 0) >= 0) {
      if (lbl_804ab800) printf(lbl_803afdbc);
    }
  }
  image = (Ptr32<GenericImage>)w3d_handle_storage_allocate(36);
  int depth = tgaHeader.colorMapSize;
  image->width = width;
  image->height = height;
  image->format = format;
  image->pixelDepth = depth;
  image->components = components;
  image->cmapEntries = colors;
  image->cmap = cmap;
  image->cmapFormat = cmap ? 6407 : 0;
  image->pixels = pixels;
  return image;
}


