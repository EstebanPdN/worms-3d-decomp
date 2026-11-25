#include "w3d_ptr.h"
#line 1 "r25b_sink_write_v3_802cbe9c.cpp"
// Inferred names. Original 0x802cbe9c; shared text owns one pointer at +0.
// Sink table indexing uses the observed four-byte target pointer stride.
// Constructors/methods and sink services remain external, bound by proof witnesses.
struct R25bText;
extern void r25b_finish_8020c5c4(Ptr32<R25bText>);
extern void r25b_release_80341588(Ptr32<R25bText>);
struct R25bText {
    Ptr32<char> data;
    template <class W3dU> R25bText(Ptr32<W3dU> w3d_p) : R25bText((const char *)w3d_p.get()) {}
 R25bText(const char *);
    R25bText &append(Ptr32<const char>);
    ~R25bText() {
        r25b_finish_8020c5c4(this);
        r25b_release_80341588(this);
    }
};
struct R25bSink;
extern int r25b_enabled_804abce4;
extern Ptr32<R25bSink> r25b_sinks_80473724[];
extern const char r25b_suffix_803d9448[];
extern void r25b_write_802cc01c(Ptr32<R25bSink>, Ptr32<const char>, int);
extern "C" void w3d_r25b_sink_write_v3_802cbe9c(
    unsigned index, Ptr32<const char> input, int mode)
{
    if (r25b_enabled_804abce4 && index <= 15 &&
        *reinterpret_cast<R25bSink **>(w3d::R(
            (index * 4) + reinterpret_cast<char *>(w3d::R(r25b_sinks_80473724))))) {
        R25bText text(input);
        text.append(r25b_suffix_803d9448);
        r25b_write_802cc01c(
            *reinterpret_cast<R25bSink **>(w3d::R(
                (index * 4) + reinterpret_cast<char *>(w3d::R(r25b_sinks_80473724)))),
            text.data, mode);
    }
}


