// cc17d: string property setters (0x802796d4 editor, 0x8027a8a4 name).
// Observed: strings are pointers to text preceded by a 16-bit reference
// count at -6; assignment retains the new text, releases the old one through
// w3d_string_release_header when its count drops to 0, and stores the new
// pointer.  The editor layout matches cc17d_prop_edit_8027a2c4.
extern "C" {
void * w3d_string_from_text(void *, const char *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_string_release_header(void *);
}
struct Cc17dStr {
    char *text;
    int unknown;
    Cc17dStr(const char *s) { w3d_string_from_text(this, s); }
    ~Cc17dStr() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Cc17dStrRef {
    char *text;
    void operator=(const Cc17dStr &o)
    {
        ++*(unsigned short *)(o.text - 6);
        unsigned short *header = (unsigned short *)(text - 6);
        unsigned int remaining = *header - 1;
        *header = remaining;
        if (!(unsigned short)remaining)
            w3d_string_release_header(header);
        text = o.text;
    }
};
struct Cc17dObject { void **methods; };
struct Cc17dField { unsigned char reserved[4]; unsigned short offset; };
struct Cc17dFieldRef { Cc17dField *field; };
struct Cc17dNamed { unsigned char reserved[28]; Cc17dStrRef name; };
struct Cc17dEditor {
    unsigned char reserved[88];
    Cc17dNamed *target;                // +88
    Cc17dObject *receiver;             // +92
    int key;                           // +96
};
extern "C" Cc17dFieldRef *w3d_s21_vector_get_801e9db8(void *, int);
extern "C" void w3d_s21_state_dispatch_8027ae00(Cc17dEditor *);
extern "C" void w3d_auto_8027a98c(Cc17dEditor *);
extern "C" void fn_80271518(Cc17dEditor *, int);
#define CC17D_TYPE(o) (((void *(*)(Cc17dObject *))(o)->methods[5])(o))
#define CC17D_FIELD(T, o, ref) (*(T *)((char *)(o) + (ref)->field->offset))
// The temporary string lives in inline helpers: written directly in the
// caller, GCC computes its address into a saved register too early.
static inline void cc17d_store_text(Cc17dObject *receiver, Cc17dEditor *self, const char *text)
{
    Cc17dStr value(text);
    Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(self->receiver), self->key);
    CC17D_FIELD(Cc17dStrRef, receiver, ref) = value;
}
extern "C" void w3d_cc17d_string_edit_802796d4(Cc17dEditor *self, const char *text)
{
    cc17d_store_text(self->receiver, self, text);
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}
static inline void cc17d_set_name(Cc17dNamed *target, const char *text)
{
    Cc17dStr value(text);
    target->name = value;
}
extern "C" void w3d_cc17d_set_target_name_8027a8a4(Cc17dEditor *self, const char *text)
{
    cc17d_set_name(self->target, text);
    fn_80271518(self, 0);
}
