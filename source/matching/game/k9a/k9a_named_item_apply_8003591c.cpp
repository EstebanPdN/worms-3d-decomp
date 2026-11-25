// Appears to look an item up by name: the special item is used when the name equals its
// own, otherwise the first listed item whose name matches; the found item receives the call.
extern "C" void w3d_string_base_finish(void *string);
extern "C" void w3d_string_release(void *string);
extern "C" void w3d_string_from_text(void *string, const char *text);
extern "C" int strcmp(const char *a, const char *b);
struct K9aString
{
    char *text;
    unsigned int storage;
    K9aString(const char *t) { w3d_string_from_text(this, t); }
    ~K9aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K9aItem
{
    char pad0[60];
    const char *name; // +60
};
struct K9aItemVector
{
    K9aItem **begin;
    K9aItem **end;
};
struct K9aOwner
{
    char pad0[316];
    K9aItemVector items; // +316
    char pad324[80];
    K9aItem special;     // +404
    char pad1[464 - 404 - sizeof(K9aItem)];
    const char *special_name; // +464
};
extern "C" void w3d_auto_8015ab2c(void *item, int arg);
extern "C" void w3d_k9a_named_item_apply_8003591c(K9aOwner *self, const char *name, int arg)
{
    K9aItem **p = self->items.begin;
    K9aItemVector *v = &self->items;
    K9aString text(name);
    if (strcmp(text.text, self->special_name) == 0)
    {
        w3d_auto_8015ab2c(&self->special, arg);
    }
    else
    {
        for (; p != v->end; ++p)
        {
            if (strcmp((*p)->name, text.text) == 0)
            {
                w3d_auto_8015ab2c(*p, arg);
                break;
            }
        }
    }
}
