// Appears to extract the text that follows a marker: depending on the object's
// mode it copies the whole source, or finds the marker (a virtual-provided string
// or one of two stored prefixes) in the source and copies what comes after it
// into the destination string. Always returns 0.
extern "C" char *strstr(const char *haystack, const char *needle);
extern "C" void * w3d_string_default(void *string);
extern "C" void w3d_string_base_finish(void *string);
extern "C" void w3d_string_release(void *string);
extern "C" void w3d_string_assign(void *dest, const char *text);

struct K10aString
{
    char *text;
    unsigned int storage;
    K10aString() {}
    ~K10aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};

struct K10aMarkerSource;
struct K10aMarkerTable
{
    void (*slots0[10])();
    int (*marker)(K10aMarkerSource *self, const char *source, K10aString *out);   // +40 (status, unused here)
};

struct K10aMarkerSource
{
    K10aMarkerTable *vtable;     // +0
    char pad4[44];
    char *prefixA;               // +48 (string text; length in the header before it)
    char *prefixB;               // +52
};

extern "C" int w3d_auto_80039b6c(K10aMarkerSource *self, void *);

static inline unsigned short k10a_length(const char *text)
{
    return *(const unsigned short *)(text - 4);
}

extern "C" int w3d_k10a_text_after_marker_80039f24(K10aMarkerSource *self, const char *source, void *dest)
{
    switch (w3d_auto_80039b6c(self, (void *)source))
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
