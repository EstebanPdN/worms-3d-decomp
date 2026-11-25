struct lua_State;
struct K6bIface { void **vtable; };
struct K6bIfaceRef {
    K6bIface *p;
    K6bIfaceRef(K6bIface *q) : p(q) { if (p != 0) ((void (*)(K6bIface *))p->vtable[3])(p); }
    ~K6bIfaceRef() { if (p != 0) ((void (*)(K6bIface *))p->vtable[4])(p); }
};
extern "C" void **w3d_r24a_check_container_userdata_8019e68c(lua_State *L, int index);
extern "C" K6bIface *w3d_s10_service_forward_8020b680(void *service_id);
extern "C" void *fn_8020b208(void);
extern "C" char lbl_80414310[];
extern "C" int w3d_k6b_lua_container_attach_8019f93c(lua_State *L)
{
    void **container = w3d_r24a_check_container_userdata_8019e68c(L, 1);
    K6bIfaceRef service(w3d_s10_service_forward_8020b680(lbl_80414310));
    ((void (*)(K6bIface *, void *))service.p->vtable[12])(service.p, fn_8020b208());
    ((void (*)(K6bIface *, void *))service.p->vtable[6])(service.p, *container);
    return 0;
}
// desc: w3d_k6b_lua_container_attach_8019f93c: Appears to be a Lua binding: look up the service 0x80414310, call its slot 12 with 0x8020b208() and pass the container userdata to its slot 6.
