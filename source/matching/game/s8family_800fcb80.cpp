struct s8_Interface { void (**vtable)(); };
inline void s8_retain(s8_Interface *p) { ((void (*)(s8_Interface *))p->vtable[3])(p); }
inline void s8_release(s8_Interface *p) { ((void (*)(s8_Interface *))p->vtable[4])(p); }
struct s8_Handle {
    s8_Interface *p; int unused;
    s8_Handle() : p(0) {}
    s8_Handle(s8_Interface *q) : p(q) { if (q) s8_retain(q); }
    ~s8_Handle() { if (p) s8_release(p); }
    void assign(const s8_Handle &q) { s8_Interface *held=q.p; if(held) { s8_retain(held); if(p) s8_release(p); p=held; } }
};
extern "C" s8_Interface *fn_80179598(void *,int);
extern "C" void *fn_80341584(void *);
extern void *lbl_8044a5e4[];
extern "C" s8_Interface *s8_handle_800fcb80(int index,int arg) {
 s8_Handle result;
 { s8_Handle temporary(fn_80179598(fn_80341584(*(void **)((index * 4) + (unsigned int)lbl_8044a5e4)),arg)); result.assign(temporary); }
 return result.p;
}
