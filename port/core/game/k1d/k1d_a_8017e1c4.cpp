#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "k1d_a_8017e1c4.c"

unsigned w3d_k1d_hash_name_8017e1c4(Ptr32<void> unused, Ptr32<const char> s)
{
  unsigned h = 0;
  while (*s)
  {
    unsigned g;
    h = h << 4;
    h = h + (*(s++));
    g = h & 0xf0000000;
    if (g)
    {
      h ^= g >> 24;
      h ^= g;
    }
  }

  return (h % w3d_restab_cap()) & 0xffff;   /* port (v29): era % 1920 */
}
// k1d: w3d_k1d_hash_name_8017e1c4|0x8017e1c4|Appears to compute an ELF-style string hash and reduce it modulo a table size.

}
