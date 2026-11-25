/* Shared libgcc2 64-bit division core for the h1_libgcc2_* units
 * (session b169b320): GCC 2.95 libgcc2.c __udivmoddi4 and __negdi2 with the
 * generic C macros of longlong.h (no PowerPC assembly). Each libgcc2 object in
 * SN's runtime carries its own static __clz_tab in small data, so every
 * including unit defines W3D_CLZ_TAB as its own table first. */
#ifndef H1_LIBGCC2_UDIVMOD_H
#define H1_LIBGCC2_UDIVMOD_H

typedef int w3d_word_type;
typedef int w3d_si;
typedef unsigned int w3d_usi;
typedef unsigned short w3d_uhi;
typedef long long w3d_di;
typedef unsigned long long w3d_udi;

struct w3d_di_struct
{
    w3d_si high, low;
};

typedef union
{
    struct w3d_di_struct s;
    w3d_di ll;
} w3d_di_union;

#define W_TYPE_SIZE 32
#define __BITS4 (W_TYPE_SIZE / 4)
#define __ll_B ((w3d_usi)1 << (W_TYPE_SIZE / 2))
#define __ll_lowpart(t) ((w3d_usi)(t) & (__ll_B - 1))
#define __ll_highpart(t) ((w3d_usi)(t) >> (W_TYPE_SIZE / 2))

#define sub_ddmmss(sh, sl, ah, al, bh, bl) \
  do { \
    w3d_usi __x; \
    __x = (al) - (bl); \
    (sh) = (ah) - (bh) - (__x > (al)); \
    (sl) = __x; \
  } while (0)

#define umul_ppmm(w1, w0, u, v) \
  do { \
    w3d_usi __x0, __x1, __x2, __x3; \
    w3d_uhi __ul, __vl, __uh, __vh; \
    __ul = __ll_lowpart (u); \
    __uh = __ll_highpart (u); \
    __vl = __ll_lowpart (v); \
    __vh = __ll_highpart (v); \
    __x0 = (w3d_usi) __ul * __vl; \
    __x1 = (w3d_usi) __ul * __vh; \
    __x2 = (w3d_usi) __uh * __vl; \
    __x3 = (w3d_usi) __uh * __vh; \
    __x1 += __ll_highpart (__x0); \
    __x1 += __x2; \
    if (__x1 < __x2) \
      __x3 += __ll_B; \
    (w1) = __x3 + __ll_highpart (__x1); \
    (w0) = __ll_lowpart (__x1) * __ll_B + __ll_lowpart (__x0); \
  } while (0)

#define udiv_qrnnd(q, r, n1, n0, d) \
  do { \
    w3d_usi __d1, __d0, __q1, __q0; \
    w3d_usi __r1, __r0, __m; \
    __d1 = __ll_highpart (d); \
    __d0 = __ll_lowpart (d); \
    __r1 = (n1) % __d1; \
    __q1 = (n1) / __d1; \
    __m = (w3d_usi) __q1 * __d0; \
    __r1 = __r1 * __ll_B | __ll_highpart (n0); \
    if (__r1 < __m) \
      { \
        __q1--, __r1 += (d); \
        if (__r1 >= (d)) \
          if (__r1 < __m) \
            __q1--, __r1 += (d); \
      } \
    __r1 -= __m; \
    __r0 = __r1 % __d1; \
    __q0 = __r1 / __d1; \
    __m = (w3d_usi) __q0 * __d0; \
    __r0 = __r0 * __ll_B | __ll_lowpart (n0); \
    if (__r0 < __m) \
      { \
        __q0--, __r0 += (d); \
        if (__r0 >= (d)) \
          if (__r0 < __m) \
            __q0--, __r0 += (d); \
      } \
    __r0 -= __m; \
    (q) = (w3d_usi) __q1 * __ll_B | __q0; \
    (r) = __r0; \
  } while (0)

#define count_leading_zeros(count, x) \
  do { \
    w3d_usi __xr = (x); \
    w3d_usi __a; \
    if (W_TYPE_SIZE <= 32) \
      { \
        __a = __xr < ((w3d_usi)1<<2*__BITS4) \
          ? (__xr < ((w3d_usi)1<<__BITS4) ? 0 : __BITS4) \
          : (__xr < ((w3d_usi)1<<3*__BITS4) ?  2*__BITS4 : 3*__BITS4); \
      } \
    else \
      { \
        for (__a = W_TYPE_SIZE - 8; __a > 0; __a -= 8) \
          if (((__xr >> __a) & 0xff) != 0) \
            break; \
      } \
    (count) = W_TYPE_SIZE - (W3D_CLZ_TAB[__xr >> __a] + __a); \
  } while (0)

static inline w3d_udi
__udivmoddi4 (w3d_udi n, w3d_udi d, w3d_udi *rp)
{
  w3d_di_union ww;
  w3d_di_union nn, dd;
  w3d_di_union rr;
  w3d_usi d0, d1, n0, n1, n2;
  w3d_usi q0, q1;
  w3d_usi b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;

  if (d1 == 0)
    {
      if (d0 > n1)
	{
	  count_leading_zeros (bm, d0);
	  if (bm != 0)
	    {
	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_SIZE - bm));
	      n0 = n0 << bm;
	    }
	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;
	}
      else
	{
	  if (d0 == 0)
	    d0 = 1 / d0;
	  count_leading_zeros (bm, d0);
	  if (bm == 0)
	    {
	      n1 -= d0;
	      q1 = 1;
	    }
	  else
	    {
	      b = W_TYPE_SIZE - bm;
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;
	      udiv_qrnnd (q1, n1, n2, n1, d0);
	    }
	  udiv_qrnnd (q0, n0, n1, n0, d0);
	}

      if (rp != 0)
	{
	  rr.s.low = n0 >> bm;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }
  else
    {
      if (d1 > n1)
	{
	  q0 = 0;
	  q1 = 0;
	  if (rp != 0)
	    {
	      rr.s.low = n0;
	      rr.s.high = n1;
	      *rp = rr.ll;
	    }
	}
      else
	{
	  count_leading_zeros (bm, d1);
	  if (bm == 0)
	    {
	      if (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      else
		q0 = 0;
	      q1 = 0;
	      if (rp != 0)
		{
		  rr.s.low = n0;
		  rr.s.high = n1;
		  *rp = rr.ll;
		}
	    }
	  else
	    {
	      w3d_usi m1, m0;
	      b = W_TYPE_SIZE - bm;
	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;
	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);
	      if (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}
	      q1 = 0;
	      if (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.low = (n1 << b) | (n0 >> bm);
		  rr.s.high = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.low = q0;
  ww.s.high = q1;
  return ww.ll;
}
static inline w3d_di
__negdi2 (w3d_di u)
{
  w3d_di_union w;
  w3d_di_union uu;

  uu.ll = u;

  w.s.low = -uu.s.low;
  w.s.high = -uu.s.high - ((w3d_usi) w.s.low > 0);

  return w.ll;
}
#endif
