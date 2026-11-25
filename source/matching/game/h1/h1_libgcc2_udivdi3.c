/* GCC 2.95 libgcc2 __udivdi3 (session b169b320), from SN's runtime object
 * that carries its own __clz_tab copy at 0x804b296c (small data). */

extern const unsigned char w3d_clz_tab_804b296c[] __attribute__((section(".sdata")));
#define W3D_CLZ_TAB w3d_clz_tab_804b296c
#include "h1_libgcc2_udivmod.h"

w3d_udi
__udivdi3 (w3d_udi n, w3d_udi d)
{
  return __udivmoddi4 (n, d, (w3d_udi *) 0);
}
