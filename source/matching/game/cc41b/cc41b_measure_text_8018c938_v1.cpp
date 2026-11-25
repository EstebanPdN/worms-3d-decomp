// Original 0x8018c938. Inferred partial text/font/glyph views; unknown fields are explicit.
// Packed glyph code: high byte chooses page, low byte chooses 8-byte glyph slot.
struct cc41b_Glyph { float advance; float height; };
struct cc41b_GlyphData { unsigned char unknown[32]; cc41b_Glyph glyphs[1]; };
struct cc41b_FontPage { unsigned char unknown[28]; cc41b_GlyphData *data; };
struct cc41b_Font { unsigned char unknown[32]; cc41b_FontPage *pages[1]; };
struct cc41b_TextResources { unsigned char unknown[28]; cc41b_Font *font; };
struct cc41b_Text { unsigned char unknown[36]; float scale; unsigned char gap[128]; cc41b_TextResources *resources; unsigned gap2[2]; unsigned short *begin,*end; };
inline cc41b_Font *cc41b_font(cc41b_TextResources *p) { return *(cc41b_Font **)(28+(unsigned char *)p); }
inline cc41b_GlyphData *cc41b_data(cc41b_FontPage *p) { return *(cc41b_GlyphData **)(28+(unsigned char *)p); }
inline float cc41b_advance(cc41b_GlyphData *p,unsigned char code) { return ((cc41b_Glyph *)(32+(unsigned char *)p))[code].advance; }
extern float cc41b_zero_803a7e30[];
extern "C" unsigned cc41b_length_8018ca1c(cc41b_Text *);
extern "C" float cc41b_measure_text_8018c938(cc41b_Text *self,unsigned start,int count) {
 if(start>cc41b_length_8018ca1c(self)) return cc41b_zero_803a7e30[0];
 cc41b_Font *font=cc41b_font(self->resources);
 unsigned short *cursor=self->begin+start;
 float sum=cc41b_zero_803a7e30[0];
 float scale=self->scale;
 float height=cc41b_data(font->pages[0])->glyphs[0].height;
 for(;cursor!=self->end && count!=0;--count) {
  unsigned page=*cursor>>8;
  unsigned char code=((unsigned char *)cursor)[1];
  ++cursor;
  sum+=cc41b_advance(cc41b_data(font->pages[page]),code);
 }
 return sum*scale/height;
}
