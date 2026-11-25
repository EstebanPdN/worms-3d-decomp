// Appears to pick a "Taunt<n>" name (the object's index modulo 13, plus one), reads the
// property it names and hands the resulting text to the name setter.
extern "C" void * w3d_string_default(void *string);
extern "C" void w3d_string_base_finish(void *string);
extern "C" void w3d_string_release(void *string);
extern "C" void * w3d_string_from_text(void *string, const char *text);
extern "C" int w3d_string_format(void *string, const char *format, ...);
struct K9aString
{
    char *text;
    unsigned int storage;
    K9aString() {}
    K9aString(const char *t) { w3d_string_from_text(this, t); }
    ~K9aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K9aObject;
extern "C" unsigned int w3d_auto_8015ff5c(K9aObject *self);
extern "C" int w3d_auto_800fc2b0(const char **key, const char **value);
struct K9aRaw { char *text; unsigned int storage; K9aRaw() {} ~K9aRaw() {} };
extern "C" void w3d_fn_80043134(K9aObject *self, K9aRaw *name, int flag);
extern char w3d_str_803763c0[];
extern "C" void w3d_k9a_taunt_name_set_80048110(K9aObject *self)
{
    K9aString name;
    K9aRaw temp;
    const char *value = 0;
    w3d_string_default(&name);
    unsigned int n = w3d_auto_8015ff5c(self);
    w3d_string_format(&name, w3d_str_803763c0, n % 13 + 1);
    const char *key = name.text;
    w3d_auto_800fc2b0(&key, &value);
    w3d_string_from_text(&temp, value);
    w3d_fn_80043134(self, &temp, 0);
}
