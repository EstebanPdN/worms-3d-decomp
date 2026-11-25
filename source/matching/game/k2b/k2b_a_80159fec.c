extern void *w3d_global_804aa8c8;
extern void *w3d_global_804b1924;
extern int w3d_call_80033208(void *obj, void *arg);
void *w3d_k2b_call_twice_80159fec(void *unused, void *arg)
{
    void *obj = w3d_global_804aa8c8;
    if (obj != 0) {
        w3d_call_80033208(obj, arg);
        return w3d_call_80033208(obj, arg);
    }
    return w3d_global_804b1924;
}
// desc: Appears to call a global object's handler twice with an argument and return the second result, else a fallback global.
