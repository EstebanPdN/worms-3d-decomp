// desc: Appears to format a message from two one-based numbers into a temporary string and append it to the first argument's text.
struct S21Text;
extern void fn_8020c5c4(S21Text *);
extern void fn_80341588(S21Text *);
struct S21Text {
    char *data;
    S21Text();
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
extern const char lbl_803d94bc[];
extern void fn_8020c510(S21Text *, const char *, ...);
extern void * fn_8020bf2c(void *, char *);
extern "C" void w3d_s21_append_position_802cd26c(void *target, int row, int column)
{
    S21Text text;
    fn_8020c510(&text, lbl_803d94bc, column + 1, row + 1);
    fn_8020bf2c(target, text.data);
}
