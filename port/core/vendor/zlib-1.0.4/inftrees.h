/* inftrees.h -- header to use inftrees.c
 * Copyright (C) 1995-1996 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */

/* WARNING: this file should *not* be used by applications. It is
   part of the implementation of the compression library and is
   subject to change. Applications should only use zlib.h.
 */

/* Huffman code lookup table entry--this entry is four bytes for machines
   that have 16-bit pointers (e.g. PC's in the small or medium model). */

typedef struct inflate_huft_s FAR inflate_huft;

struct inflate_huft_s {
  union {
    struct { unsigned char Bits; unsigned char Exop; } what;
    Ptr32<Bytef> pad;         /* pad structure to a power of 2 (4 bytes for */
  } word;               /*  16-bit, 8 bytes for 32-bit machines) */
  union {
    uInt Base;          /* literal, length base, or distance base */
    Ptr32<inflate_huft> Next; /* pointer to next level of table */
  } more;
};

#ifdef DEBUG
  extern uInt inflate_hufts;
#endif

extern int inflate_trees_bits (
    Ptr32<uIntf>,                    /* 19 code lengths */
    Ptr32<uIntf>,                    /* bits tree desired/actual depth */
    Ptr32<Ptr32<inflate_huft>>,       /* bits tree result */
    z_streamp );               /* for zalloc, zfree functions */

extern int inflate_trees_dynamic (
    uInt,                       /* number of literal/length codes */
    uInt,                       /* number of distance codes */
    Ptr32<uIntf>,                    /* that many (total) code lengths */
    Ptr32<uIntf>,                    /* literal desired/actual bit depth */
    Ptr32<uIntf>,                    /* distance desired/actual bit depth */
    Ptr32<Ptr32<inflate_huft>>,       /* literal/length tree result */
    Ptr32<Ptr32<inflate_huft>>,       /* distance tree result */
    z_streamp );               /* for zalloc, zfree functions */

extern int inflate_trees_fixed (
    Ptr32<uIntf>,                    /* literal desired/actual bit depth */
    Ptr32<uIntf>,                    /* distance desired/actual bit depth */
    Ptr32<Ptr32<inflate_huft>>,       /* literal/length tree result */
    Ptr32<Ptr32<inflate_huft>>);     /* distance tree result */

extern int inflate_trees_free (
    Ptr32<inflate_huft>,             /* tables to free */
    z_streamp );               /* for zfree function */

