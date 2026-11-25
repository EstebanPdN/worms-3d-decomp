#include "w3d_ptr.h"
#line 1 "k10a_text_after_marker_80039f24.cpp"
// Appears to extract the text that follows a marker: depending on the object's
// mode it copies the whole source, or finds the marker (a virtual-provided string
// or one of two stored prefixes) in the source and copies what comes after it
// into the destination string. Always returns 0.
extern "C" Ptr32<char> strstr(Ptr32<const char> haystack, Ptr32<const char> needle);
extern "C" Ptr32<void> w3d_string_default(Ptr32<void> string);
extern "C" void w3d_string_base_finish(Ptr32<void> string);
extern "C" void w3d_string_release(Ptr32<void> string);
extern "C" void w3d_string_assign(Ptr32<void> dest, Ptr32<const char> text);

struct K10aString
{
    Ptr32<char> text;
    unsigned int storage;
    K10aString() {}
    ~K10aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};

struct K10aMarkerSource;
struct K10aMarkerTable
{
    Ptr32<void (void)> slots0[10];
    Ptr32<int (Ptr32<K10aMarkerSource>, Ptr32<const char>, Ptr32<K10aString>)> marker;   // +40 (status, unused here)
};

struct K10aMarkerSource
{
    Ptr32<K10aMarkerTable> vtable;     // +0
    char pad4[44];
    Ptr32<char> prefixA;               // +48 (string text; length in the header before it)
    Ptr32<char> prefixB;               // +52
};

extern "C" int w3d_auto_80039b6c(Ptr32<K10aMarkerSource> self, Ptr32<void>);

static inline unsigned short k10a_length(Ptr32<const char> text)
{
    return *(Ptr32<const unsigned short>)(text - 4);
}

extern "C" int w3d_k10a_text_after_marker_80039f24(Ptr32<K10aMarkerSource> self, Ptr32<const char> source, Ptr32<void> dest)
{
    switch (w3d_auto_80039b6c(self, (Ptr32<void>)source))
    {
    case 0:
        w3d_string_assign(dest, source);
        break;
    case 3:
        w3d_string_assign(dest, strstr(source, self->prefixB) + k10a_length(self->prefixB));
        break;
    case 2:
        w3d_string_assign(dest, strstr(source, self->prefixA) + k10a_length(self->prefixA));
        break;
    case 1:
    {
        K10aString marker;
        w3d_string_default(&marker);
        self->vtable->marker(self, source, &marker);
        w3d_string_assign(dest, strstr(source, marker.text) + k10a_length(marker.text));
        break;
    }
    }
    return 0;
}


