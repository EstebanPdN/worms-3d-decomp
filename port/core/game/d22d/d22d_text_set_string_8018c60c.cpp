#include "w3d_ptr.h"
#line 1 "d22d_text_set_string_8018c60c.cpp"
/* GWMP8P rev0 0x8018c60c: text object string to glyph indices.
   Object layout (partial view): +116 glyph owner passed through 0x8034435c,
   +168 font, +180 glyph vector. Font +40 table: direct glyphs for codes up to
   255 at +32; font +36 table: glyphs indexed by the 0x8018b260 lookup at +32.
   Names and semantic types are inferred. */
#include "d22d_glyph_vector.h"
extern "C" {
Ptr32<void> w3d_view_8034435c(Ptr32<void>);
unsigned short w3d_k1d_lookup_entry_8018b260(Ptr32<void>,unsigned short);
int w3d_text_layout_8018ca30(Ptr32<void>);
}
struct GlyphTable { unsigned char pad[32]; unsigned short codes[1]; };
struct GlyphFont { unsigned char pad[36]; Ptr32<GlyphTable> mapped; Ptr32<GlyphTable> direct; };
struct TextString {
    unsigned char pad0[116];
    Ptr32<void> owner;
    unsigned char pad1[48];
    Ptr32<GlyphFont> font;
    unsigned char pad2[8];
    GlyphVector glyphs;
};
extern "C" void w3d_d22d_text_set_string_8018c60c(Ptr32<TextString> self,Ptr32<const unsigned short> text)
{
    unsigned length=0;
    while (text[length]) length++;
    self->glyphs.clear();
    self->glyphs.resize(length,0);
    Ptr32<unsigned short> mapped=self->font->mapped->codes;
    Ptr32<unsigned short> direct=self->font->direct->codes;
    Ptr32<void> table=w3d_view_8034435c(self->owner);
    for (unsigned i=0;i<length;i++) {
        unsigned short code=text[i];
        if (code<=255) self->glyphs[i]=direct[code];
        else self->glyphs[i]=mapped[w3d_k1d_lookup_entry_8018b260(table,code)];
    }
    w3d_text_layout_8018ca30(self);
}


