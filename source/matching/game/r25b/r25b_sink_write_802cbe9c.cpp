// Inferred names. Original 0x802cbe9c; shared text owns one pointer at +0.
// Constructors/methods and sink services remain external, bound by proof witnesses.
struct R25bText;
extern void r25b_finish_8020c5c4(R25bText *);
extern void r25b_release_80341588(R25bText *);
struct R25bText {
    char *data;
    R25bText(const char *);
    void append(const char *);
    ~R25bText() {
        r25b_finish_8020c5c4(this);
        r25b_release_80341588(this);
    }
};
struct R25bSink;
extern int r25b_enabled_804abce4;
extern R25bSink *r25b_sinks_80473724[];
extern const char r25b_suffix_803d9448[];
extern void r25b_write_802cc01c(R25bSink *, const char *, int);
extern "C" void w3d_r25b_sink_write_802cbe9c(unsigned index, const char *input, int mode)
{
    if (r25b_enabled_804abce4 && index <= 15 && r25b_sinks_80473724[index]) {
        R25bText text(input);
        text.append(r25b_suffix_803d9448);
        r25b_write_802cc01c(r25b_sinks_80473724[index], text.data, mode);
    }
}
