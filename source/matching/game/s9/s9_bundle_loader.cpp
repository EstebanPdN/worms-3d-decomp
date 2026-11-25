/* Temporary string arguments to the observed virtual resource loader. */
struct S9TemporaryString;
extern "C" void fn_8020bb54(S9TemporaryString *,const char *);
extern "C" void fn_8020c5c4(S9TemporaryString *);
extern "C" void fn_80341588(S9TemporaryString *);
struct S9TemporaryString {
    void *header;
    S9TemporaryString(const char *text) { fn_8020bb54(this,text); }
    ~S9TemporaryString() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S9BundleLoader {
    void **vtable;
    char unknown4[184];
    unsigned int flags;
};
typedef void (*S9LoadName)(S9BundleLoader *,const S9TemporaryString &);
extern char lbl_8039c85c[];
extern char lbl_8039c864[];
extern char lbl_8039c86c[];
extern char lbl_8039c874[];
extern char lbl_8039c878[];
extern char lbl_8039c88c[];
#define LOAD_NAME(text) ((S9LoadName)self->vtable[5])(self,S9TemporaryString(text))
extern "C" void s9_load_resource_groups_80128f6c(S9BundleLoader *self)
{
    if(self->flags & 0x20000000) {
        LOAD_NAME(lbl_8039c85c);
        if((self->flags & 0x20000000) && !(self->flags & 0x10000000))return;
    }
    LOAD_NAME(lbl_8039c864);
    LOAD_NAME(lbl_8039c86c);
    LOAD_NAME(lbl_8039c874);
    LOAD_NAME(lbl_8039c878);
    LOAD_NAME(lbl_8039c88c);
}
