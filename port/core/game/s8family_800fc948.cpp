#include "w3d_ptr.h"
#line 1 "s8family_800fc948.cpp"
struct s8_Interface { Ptr32<Ptr32<void (void)>> vtable; };
inline void s8_retain(Ptr32<s8_Interface> p) { ((Ptr32<void (Ptr32<s8_Interface>)>)p->vtable[3])(p); }
inline void s8_release(Ptr32<s8_Interface> p) { ((Ptr32<void (Ptr32<s8_Interface>)>)p->vtable[4])(p); }
struct s8_Handle {
    Ptr32<s8_Interface> p; int unused;
    s8_Handle() : p(0) {}
    template <class W3dU> s8_Handle(Ptr32<W3dU> w3d_p) : s8_Handle((s8_Interface *)w3d_p.get()) {}
 s8_Handle(s8_Interface *q) : p(q) { if (q) s8_retain(q); }
    ~s8_Handle() { if (p) s8_release(p); }
    void assign(const s8_Handle &q) { Ptr32<s8_Interface> held=q.p; if(held) { s8_retain(held); if(p) s8_release(p); p=held; } }
};
extern "C" Ptr32<s8_Interface> fn_80179598(Ptr32<void>,int);
extern "C" Ptr32<void> fn_80341584(Ptr32<void>);
extern Ptr32<void> lbl_8044a574[];
extern "C" Ptr32<s8_Interface> s8_handle_800fc948(int index,int arg) {
 s8_Handle result;
 { s8_Handle temporary(fn_80179598(fn_80341584(*(Ptr32<Ptr32<void>>)w3d::G(((index * 4) + (unsigned int)w3d::H(lbl_8044a574)))),arg)); result.assign(temporary); }
 return result.p;
}


