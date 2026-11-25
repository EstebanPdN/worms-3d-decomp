// Partial GC32 text-control views from the original instructions.
// Complete engine class identities are not established.
struct Sol35e4bVector {
    float x, y, z;
    Sol35e4bVector(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct Sol35e4bColour {
    unsigned char red, green, blue, alpha;
    Sol35e4bColour(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
        : red(r), green(g), blue(b), alpha(a) {}
    void set(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
        red = r;
        green = g;
        blue = b;
        alpha = a;
    }
};
struct Sol35e4bGlyph;
struct Sol35e4bGlyphTable {
    void (*unknown00[21])();
    void (*set_scale)(Sol35e4bGlyph*, const Sol35e4bVector*, int);
    void (*unknown58)();
    void (*add_child)(Sol35e4bGlyph*, Sol35e4bGlyph*, int);
};
struct Sol35e4bGlyph { Sol35e4bGlyphTable* table; };
struct Sol35e4bString {
    char* text;
    unsigned short length() const {
        return *reinterpret_cast<const unsigned short*>(text - 4);
    }
};
struct Sol35e4bGlyphOwner {
    unsigned char unknown00[28];
    Sol35e4bGlyph* parent;
    unsigned char unknown20[4];
    int enabled;
    unsigned char unknown28[44];
    int alternate;
    unsigned char unknown58[4];
    Sol35e4bGlyph* glyph;
    short character;
    unsigned char unknown62[2];
    Sol35e4bString name;
    unsigned char unknown68[4];
    int ready;
    unsigned char unknown70[16];
    float scale;
};
union Sol35e4bGlyphText {
    unsigned int packed;
    unsigned short units[2];
};
extern int sol35e4b_layer_804abb60;
extern const float sol35e4b_scale_a_803d8e10[];
extern const float sol35e4b_scale_b_803d8e14[];
extern const float sol35e4b_depth_803d8e18[];
extern "C" void sol35e4b_load_handle_8015adf4(const Sol35e4bString*, Sol35e4bGlyph**, unsigned char);
extern "C" Sol35e4bGlyph* sol35e4b_cast_glyph_80343580(Sol35e4bGlyph*);
extern "C" void sol35e4b_set_text_8018c60c(Sol35e4bGlyph*, const unsigned short*);
extern "C" void sol35e4b_fill_colour_8018d35c(Sol35e4bGlyph*, const Sol35e4bColour*);

inline void sol35e4b_ensure_glyph(Sol35e4bGlyphOwner* self,
    const Sol35e4bString& name, Sol35e4bGlyph*& held, int base)
{
    if (!held) {
        unsigned char offset;
        if (!self->alternate)
            offset = 31;
        else
            offset = 32;
        sol35e4b_load_handle_8015adf4(&name, &held, static_cast<unsigned char>(base + offset));
        self->parent->table->add_child(self->parent, held, 0);
    }
}

extern "C" void sol35e4b_update_glyph_802c7a98(Sol35e4bGlyphOwner* self)
{
    Sol35e4bString& name = self->name;
    if (name.length() && self->character && self->ready) {
        sol35e4b_ensure_glyph(self, name, self->glyph, sol35e4b_layer_804abb60);
        Sol35e4bGlyph* glyph = sol35e4b_cast_glyph_80343580(self->glyph);
        float scale = self->scale * sol35e4b_scale_a_803d8e10[0] * sol35e4b_scale_b_803d8e14[0];
        Sol35e4bVector size(scale, scale, sol35e4b_depth_803d8e18[0]);
        glyph->table->set_scale(glyph, &size, 0);
        Sol35e4bGlyphText text;
        text.packed = static_cast<unsigned short>(self->character) << 16;
        sol35e4b_set_text_8018c60c(glyph, text.units);
        Sol35e4bColour colour(255, 255, 255, 255);
        if (!self->enabled)
            colour.set(128, 128, 128, 255);
        sol35e4b_fill_colour_8018d35c(glyph, &colour);
    }
}
