
unsigned w3d_k1d_hash_name_8017e1c4(void *unused, const char *s)
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

  return (h % 1920) & 0xffff;
}
// k1d: w3d_k1d_hash_name_8017e1c4|0x8017e1c4|Appears to compute an ELF-style string hash and reduce it modulo a table size.
