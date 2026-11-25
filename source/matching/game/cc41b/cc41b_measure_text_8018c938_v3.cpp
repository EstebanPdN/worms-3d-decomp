// Original 0x8018c938. Inferred partial text/font/glyph views; unknown fields are explicit.
// Packed glyph code: high byte chooses page, low byte chooses 8-byte glyph slot.
struct cc41b_Glyph { float advance; float height; };
struct cc41b_GlyphData { unsigned char unknown[32]; cc41b_Glyph glyphs[1]; };
struct cc41b_FontPage { unsigned char unknown[28]; cc41b_GlyphData *data; };
struct cc41b_Font { unsigned char unknown[32]; cc41b_FontPage *pages[1]; };
struct cc41b_TextResources { unsigned char unknown[28]; cc41b_Font *font; };
struct cc41b_Text { unsigned char unknown[36]; float scale; unsigned char gap[128]; cc41b_TextResources *resources; unsigned gap2[2]; unsigned short *begin,*end; };
extern float cc41b_zero_803a7e30[];
extern "C" unsigned cc41b_length_8018ca1c(cc41b_Text *);
template<class T> inline T *cc41b_pointer(void *p,int offset) { return *(T **)((unsigned char *)p+offset); }
inline float cc41b_glyphAdvance(cc41b_Glyph *glyphs,unsigned char code) { return glyphs[code].advance; }
inline float cc41b_sum(cc41b_TextResources *resources,int offset,unsigned short *cursor,unsigned short *end,int count,float scale) {
 cc41b_Font *font=cc41b_pointer<cc41b_Font>(resources,offset);
 float sum=cc41b_zero_803a7e30[0];
 float height=cc41b_pointer<cc41b_GlyphData>(font->pages[0],offset)->glyphs[0].height;
 for(;cursor!=end && count!=0;--count) {
  unsigned page=*cursor>>8;
  unsigned char code=((unsigned char *)cursor)[1];
  ++cursor;
  cc41b_GlyphData *data=cc41b_pointer<cc41b_GlyphData>(font->pages[page],offset);
  sum+=cc41b_glyphAdvance(data->glyphs,code);
 }
 return sum*scale/height;
}
extern "C" float cc41b_measure_text_8018c938(cc41b_Text *self,unsigned start,int count) {
 if(start>cc41b_length_8018ca1c(self)) return cc41b_zero_803a7e30[0];
 return cc41b_sum(self->resources,28,self->begin+start,self->end,count,self->scale);
}
