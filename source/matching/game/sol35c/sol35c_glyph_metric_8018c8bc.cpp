// Mapped-resource nodes contain offset-indexed links, packed glyph codes.
inline char *sol35c_link(char *node,int byte_offset) { return *(char **)(node+byte_offset); }
extern float lbl_803a7e2c[];
extern "C" float sol35c_glyph_metric_8018c8bc(char *self) {
 char *group=sol35c_link(*(char **)(self+168),28);
 char *pages=group+32;
 float divisor=*(float *)(sol35c_link(*(char **)(group+32),28)+36);
 float sum=lbl_803a7e2c[0];
 unsigned char *p=*(unsigned char **)(self+180);
 unsigned char *end=*(unsigned char **)(self+184);
 for(;p!=end;p+=2) {
  unsigned short code=*(unsigned short *)p;
  char *page=*(char **)(pages+((code>>8)<<2));
  char *glyphs=sol35c_link(page,28)+32;
  sum+=*(float *)(glyphs+(p[1]<<3));
 }
 return sum**(float *)(self+36)/divisor;
}
