/* GCC 2.95 libgcc2 __umoddi3 (session b169b320), from SN's runtime object
 * that carries its own __clz_tab copy at 0x804b2a6c (small data). */

extern const unsigned char w3d_clz_tab_804b2a6c[] __attribute__((section(".sdata")));
#define W3D_CLZ_TAB w3d_clz_tab_804b2a6c
#include "h1_libgcc2_udivmod.h"

w3d_udi
__umoddi3 (w3d_udi u, w3d_udi v)
{
  w3d_udi w;

  (void) __udivmoddi4 (u, v, &w);

  return w;
}
