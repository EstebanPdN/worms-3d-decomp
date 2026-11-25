#include "w3d_ptr.h"
#line 1 "k6b_a_8019f93c.cpp"
struct lua_State;
struct K6bIface { Ptr32<Ptr32<void>> vtable; };
struct K6bIfaceRef {
    Ptr32<K6bIface> p;
    template <class W3dU> K6bIfaceRef(Ptr32<W3dU> w3d_p) : K6bIfaceRef((K6bIface *)w3d_p.get()) {}
 K6bIfaceRef(K6bIface *q) : p(q) { if (p != 0) ((Ptr32<void (Ptr32<K6bIface>)>)p->vtable[3])(p); }
    ~K6bIfaceRef() { if (p != 0) ((Ptr32<void (Ptr32<K6bIface>)>)p->vtable[4])(p); }
};
extern "C" Ptr32<Ptr32<void>> w3d_r24a_check_container_userdata_8019e68c(Ptr32<lua_State> L, int index);
extern "C" Ptr32<K6bIface> w3d_s10_service_forward_8020b680(Ptr32<void> service_id);
extern "C" Ptr32<void> fn_8020b208(void);
extern "C" char lbl_80414310[];
extern "C" int w3d_k6b_lua_container_attach_8019f93c(Ptr32<lua_State> L)
{
    Ptr32<Ptr32<void>> container = w3d_r24a_check_container_userdata_8019e68c(L, 1);
    K6bIfaceRef service(w3d_s10_service_forward_8020b680(lbl_80414310));
    ((Ptr32<void (Ptr32<K6bIface>, Ptr32<void>)>)service.p->vtable[12])(service.p, fn_8020b208());
    ((Ptr32<void (Ptr32<K6bIface>, Ptr32<void>)>)service.p->vtable[6])(service.p, *container);
    return 0;
}
// desc: w3d_k6b_lua_container_attach_8019f93c: Appears to be a Lua binding: look up the service 0x80414310, call its slot 12 with 0x8020b208() and pass the container userdata to its slot 6.


