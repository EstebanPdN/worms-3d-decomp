// desc: Appears to run a setup helper on a temporary string, issue the same request 25 times with a shared global argument and then write the result to the sink, when the subsystem is enabled.
struct S21Text;
extern void fn_8020c5c4(S21Text *);
extern void fn_80341588(S21Text *);
struct S21Text {
    char *data;
    S21Text();
    void request(int a, int b);
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
extern int lbl_804abce4;
extern int lbl_804abcd4;
extern void fn_802cd128(S21Text *);
extern void fn_802cc01c(void *, char *, int);
extern "C" void w3d_s21_dump_request_802cd198(void *sink)
{
    if (lbl_804abce4) {
        unsigned i;
        S21Text text;
        fn_802cd128(&text);
        i = 0;
        do {
            text.request(lbl_804abcd4, 9);
            i++;
        } while (i <= 24);
        fn_802cc01c(sink, text.data, 9);
    }
}
