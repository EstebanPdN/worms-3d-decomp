/* GCC 2.95 libgcc2 __moddi3 (session b169b320), from SN's runtime object
 * that carries its own __clz_tab copy at 0x804b286c (small data). */

extern const unsigned char w3d_clz_tab_804b286c[] __attribute__((section(".sdata")));
#define W3D_CLZ_TAB w3d_clz_tab_804b286c
#include "h1_libgcc2_udivmod.h"

w3d_di
__moddi3 (w3d_di u, w3d_di v)
{
  w3d_word_type c = 0;
  w3d_di_union uu, vv;
  w3d_di w;

  uu.ll = u;
  vv.ll = v;

  if (uu.s.high < 0)
    c = ~c,
    uu.ll = __negdi2 (uu.ll);
  if (vv.s.high < 0)
    vv.ll = __negdi2 (vv.ll);

  (void) __udivmoddi4 (uu.ll, vv.ll, &w);
  if (c)
    w = __negdi2 (w);

  return w;
}
