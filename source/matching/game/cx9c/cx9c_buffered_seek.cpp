/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/* Inferred adaptation of the newlib buffered seek algorithm. PPC32 FILE
 * fields observed at flags+12, seek+40, blocksize+84, offset+88, reent+92.
 * Original branches have no ungetc-release operations; retain the exact
 * observed state changes. Stat observations: mode+4 and size+16, 64 bytes.
 */
struct Cx9cReent{int _errno;unsigned char other[52];int __sdidinit;};
struct Cx9cBuffer{unsigned char *_base;int _size;};
struct Cx9cFile{
 unsigned char *_p;int _r,_w;short _flags,_file;Cx9cBuffer _bf;int _lbfsize;
 void *_cookie;void *_read,*_write;int(*_seek)(void*,int,int);void *_close;
 Cx9cBuffer _ub;unsigned char *_up;int _ur;unsigned char opaque[20];
 int _blksize,_offset;Cx9cReent *_data;
};
struct Cx9cStat{unsigned int prefix,st_mode;unsigned char other[8];int st_size;unsigned char rest[44];};
extern "C" Cx9cReent *cx9c_reent_804ac570;
extern "C" void cx9c_stdio_init_802eb1d4(Cx9cReent*,...);
extern "C" int cx9c_flush_802eb084(Cx9cFile*);
extern "C" void cx9c_make_buffer_802ebee4(Cx9cFile*);
extern "C" int cx9c_seek_file_802ec4f8(void*,int,int);
extern "C" int cx9c_stat_file_802f3278(Cx9cReent*,int,Cx9cStat*);
extern "C" int cx9c_refill_802ec088(Cx9cFile*);
#define POS_ERR (-1)
#define HASUB(fp) ((fp)->_ub._base!=0)
#define __SAPP 0x100
#define __SWR 8
#define __SOFF 0x1000
#define __SRD 4
#define __SRW 0x10
#define __SNBF 2
#define __SNPT 0x800
#define __SOPT 0x400
#define __SMOD 0x2000
#define __SEOF 0x20
extern "C" int w3d_cx9c_buffered_seek_802eb704(Cx9cFile *fp,int offset,int whence)
{
  Cx9cReent *ptr;
  int (*seekfn)(void *,int,int);
  int target, curoff;
  unsigned int n;
  Cx9cStat st;
  int havepos;

  /* Make sure stdio is set up.  */

  do{if(!fp->_data)fp->_data=cx9c_reent_804ac570;
  if(!fp->_data->__sdidinit)cx9c_stdio_init_802eb1d4(fp->_data);}while(0);
  ptr = fp->_data;

  /* If we've been doing some writing, and we're in append mode
     then we don't really know where the filepos is.  */

  if (fp->_flags & __SAPP && fp->_flags & __SWR)
    {
      /* So flush the buffer and seek to the end.  */
      cx9c_flush_802eb084 (fp);
    }

  /* Have to be able to seek.  */

  if ((seekfn = fp->_seek) == 0)
    {
      ptr->_errno = 29;	/* ??? */
      return (-1);
    }

  /*
   * Change any 1 to 0, and check `whence' argument.
   * After this, whence is either 0 or 2.
   */

  switch (whence)
    {
    case 1:
      /*
       * In order to seek relative to the current stream offset,
       * we have to first find the current stream offset a la
       * ftell (see ftell for details).
       */
      cx9c_flush_802eb084(fp);   /* may adjust seek offset on append stream */
      if (fp->_flags & __SOFF)
	curoff = fp->_offset;
      else
	{
	  curoff = (*seekfn) (fp->_cookie, (int) 0, 1);
	  if (curoff == -1L)
	    return (-1);
	}
      if (fp->_flags & __SRD)
	{
	  curoff -= fp->_r;
	  if (HASUB (fp))
	    curoff -= fp->_ur;
	}
      else if (fp->_flags & __SWR && fp->_p != 0)
	curoff += fp->_p - fp->_bf._base;

      offset += curoff;
      whence = 0;
      havepos = 1;
      break;

    case 0:
    case 2:
      havepos = 0;
      break;

    default:
      ptr->_errno = 22;
      return ((-1));
    }

  /*
   * Can only optimise if:
   *	reading (and not reading-and-writing);
   *	not unbuffered; and
   *	this is a `regular' Unix file (and hence seekfn==cx9c_seek_file_802ec4f8).
   * We must check __NBF first, because it is possible to have __NBF
   * and __SOPT both set.
   */

  if (fp->_bf._base == 0)
    cx9c_make_buffer_802ebee4 (fp);
  if (fp->_flags & (__SWR | __SRW | __SNBF | __SNPT))
    goto dumb;
  if ((fp->_flags & __SOPT) == 0)
    {
      if (seekfn != cx9c_seek_file_802ec4f8
	  || fp->_file < 0
	  || cx9c_stat_file_802f3278 (ptr, fp->_file, &st)
	  || (st.st_mode & 0xf000) != 0x8000)
	{
	  fp->_flags |= __SNPT;
	  goto dumb;
	}
#ifdef	HAVE_BLKSIZE
      fp->_blksize = st.st_blksize;
#else
      fp->_blksize = 1024;
#endif
      fp->_flags |= __SOPT;
    }

  /*
   * We are reading; we can try to optimise.
   * Figure out where we are going and where we are now.
   */

  if (whence == 0)
    target = offset;
  else
    {
      if (cx9c_stat_file_802f3278 (ptr, fp->_file, &st))
	goto dumb;
      target = st.st_size + offset;
    }

  if (!havepos)
    {
      if (fp->_flags & __SOFF)
	curoff = fp->_offset;
      else
	{
	  curoff = (*seekfn) (fp->_cookie, 0L, 1);
	  if (curoff == POS_ERR)
	    goto dumb;
	}
      curoff -= fp->_r;
      if (HASUB (fp))
	curoff -= fp->_ur;
    }

  /*
   * Compute the number of bytes in the input buffer (pretending
   * that any ungetc() input has been discarded).  Adjust current
   * offset backwards by this count so that it represents the
   * file offset for the first byte in the current input buffer.
   */

  if (HASUB (fp))
    {
      curoff += fp->_r;       /* kill off ungetc */
      n = fp->_up - fp->_bf._base;
      curoff -= n;
      n += fp->_ur;
    }
  else
    {
      n = fp->_p - fp->_bf._base;
      curoff -= n;
      n += fp->_r;
    }

  /*
   * If the target offset is within the current buffer,
   * simply adjust the pointers, clear (-1), undo ungetc(),
   * and return.  (If the buffer was modified, we have to
   * skip this; see fgetline.c.)
   */

  if ((fp->_flags & __SMOD) == 0 &&
      target >= curoff && target < curoff + n)
    {
      register int o = target - curoff;

      fp->_p = fp->_bf._base + o;
      fp->_r = n - o;
      
      fp->_flags &= ~__SEOF;
      return 0;
    }

  /*
   * The place we want to get to is not within the current buffer,
   * but we can still be kind to the kernel copyout mechanism.
   * By aligning the file offset to a block boundary, we can let
   * the kernel use the VM hardware to map pages instead of
   * copying bytes laboriously.  Using a block boundary also
   * ensures that we only read one block, rather than two.
   */

  curoff = target & ~(fp->_blksize - 1);
  if ((*seekfn) (fp->_cookie, curoff, 0) == POS_ERR)
    goto dumb;
  fp->_r = 0;
  
  fp->_flags &= ~__SEOF;
  n = target - curoff;
  if (n)
    {
      if (cx9c_refill_802ec088 (fp) || fp->_r < n)
	goto dumb;
      fp->_p += n;
      fp->_r -= n;
    }
  return 0;

  /*
   * We get here if we cannot optimise the seek ... just
   * do it.  Allow the seek function to change fp->_bf._base.
   */

dumb:
  if (cx9c_flush_802eb084 (fp) || (*seekfn) (fp->_cookie, offset, whence) == POS_ERR)
    return (-1);
  /* success: clear (-1) indicator and discard ungetc() data */
  
  fp->_p = fp->_bf._base;
  fp->_r = 0;
  /* fp->_w = 0; *//* unnecessary (I think...) */
  fp->_flags &= ~__SEOF;
  return 0;
}
