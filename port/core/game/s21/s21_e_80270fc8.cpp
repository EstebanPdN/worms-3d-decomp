#include "w3d_ptr.h"
#line 1 "s21_e_80270fc8.cpp"
// desc: Appears to poll a source handle and update a node, dispatching on its mode and releasing a temporary shared string, then returning 100.
struct S21Text;
extern void fn_8020c5c4(Ptr32<S21Text>);
extern void fn_80341588(Ptr32<S21Text>);
struct S21Text {
    Ptr32<char> data;
    S21Text(int source);
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S21Node { char pad[32]; int source; int pad1; int mode; };
extern int fn_802ccb40(int);
extern int fn_802ccb00(int);
extern int fn_802cbacc(int);
extern int fn_802cbc68(int);
extern int fn_802cba50(int);
extern int fn_802cbb5c(int);
extern void fn_80271420(Ptr32<S21Node>);
extern void fn_8027113c(Ptr32<S21Node>, int);
extern void fn_80271348(Ptr32<S21Node>, Ptr32<char>);
extern "C" int w3d_s21_node_update_80270fc8(Ptr32<S21Node> node)
{
    if (fn_802ccb40(node->source))
        fn_80271420(node);
    if (fn_802ccb00(node->source)) {
        if (node->mode == 1 && fn_802cbacc(node->source)) {
            int value = fn_802cbc68(node->source);
            if (value)
                fn_8027113c(node, value);
        } else if (node->mode == 0 && fn_802cba50(node->source)) {
            S21Text text(fn_802cbb5c(node->source));
            fn_80271348(node, text.data);
        }
    }
    return 100;
}


