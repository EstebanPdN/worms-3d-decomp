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
extern "C" float cc41b_measure_text_8018c938(cc41b_Text *self,unsigned start,int count) {
 if(start>cc41b_length_8018ca1c(self)) return cc41b_zero_803a7e30[0];
 cc41b_Font *font=self->resources->font;
 unsigned short *cursor=self->begin+start;
 float sum=cc41b_zero_803a7e30[0];
 for(;cursor!=self->end && count!=0;--count) {
  unsigned short code=*cursor++;
  sum+=font->pages[code>>8]->data->glyphs[(unsigned char)code].advance;
 }
 return sum*self->scale/font->pages[0]->data->glyphs[0].height;
}
