// Appears to register the resource search directories of a loader: the root,
// Themes, Effects, Frontend/Levels and Frontend/Wormapedia, and (unless the
// loader is flagged as running from a packed archive) scripts, Logos, Maps and
// Language/NGC. Each path goes through the loader's virtual add-directory method.
extern "C" void *w3d_string_from_text(void *string, const char *text);
extern "C" void w3d_string_base_finish(void *string);
extern "C" void w3d_string_release(void *string);

struct K10aString
{
    char *text;
    unsigned int storage;
    K10aString() {}
    K10aString(const char *source) { w3d_string_from_text(this, source); }
    ~K10aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};

struct K10aLoader;
struct K10aLoaderTable
{
    void (*slots0[5])();
    int (*add_directory)(K10aLoader *self, const K10aString *path);   // +20
};

struct K10aLoader
{
    K10aLoaderTable *vtable;     // +0
    char pad4[184];
    unsigned int flags;          // +188
};

// Adds one search directory through the loader's virtual method.
#define K10A_ADD_DIRECTORY(text) \
    { K10aLoaderTable *table = self->vtable; K10aString path(text); table->add_directory(self, &path); }

extern "C" void w3d_k10a_search_paths_80129108(K10aLoader *self)
{
    // The root entry builds its string through an explicit call, the others through
    // the inline constructor; both read the vtable before the string is built.
    { K10aLoaderTable *table = self->vtable; K10aString path; w3d_string_from_text(&path, ""); table->add_directory(self, &path); }
    K10A_ADD_DIRECTORY("Themes");
    K10A_ADD_DIRECTORY("Effects");
    K10A_ADD_DIRECTORY("Frontend/Levels");
    K10A_ADD_DIRECTORY("Frontend/Wormapedia");
    if (self->flags & 0x20000000)
    {
        if (!(self->flags & 0x10000000))
            return;
    }
    {
        K10A_ADD_DIRECTORY("scripts");
        K10A_ADD_DIRECTORY("Logos");
        K10A_ADD_DIRECTORY("Maps");
        K10A_ADD_DIRECTORY("Language/NGC");
    }
}
