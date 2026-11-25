void tsonnet_c26_row_copy_801b09a8(char *src, int a1, int w, int a3, char *dst, int a5, int a6, int rows) {
 if (a3 != rows + rows) return;
 if (a1 != a5 + a5) return;
 if (rows == 0) return;
 a6 = a6 - a5;
 do {
  char *end = src + w;
  rows--;
  while (src != end) { *dst = *src; src += 2; dst++; }
  src += w;
  dst += a6;
 } while (rows != 0);
}
