// desc: Appears to store a text value and show it masked with asterisks when the owner's mode is one, then refresh the widget.
struct S21Text;
extern void fn_8020c5c4(S21Text *);
extern void fn_80341588(S21Text *);
struct S21Text {
    char *data;
    S21Text();
    void * assign(const char *source, unsigned length);
    void set(int value);
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S21Settings { char pad[184]; int mode; };
struct S21Widget { char pad[40]; S21Settings *settings; char pad1[368]; S21Text text; };
extern void fn_8029ec80(S21Widget *, int);
extern void fn_802a21ec(S21Widget *);
extern const char lbl_803d1f04[];
extern "C" void w3d_s21_widget_set_text_802a1bf4(S21Widget *self, int value)
{
    S21Settings *settings = self->settings;
    self->text.set(value);
    if (settings->mode == 1) {
        S21Text masked;
        masked.assign(lbl_803d1f04, *(unsigned short *)(self->text.data - 4));
        fn_8029ec80(self, (int)masked.data);
    } else {
        fn_8029ec80(self, value);
    }
    fn_802a21ec(self);
}
