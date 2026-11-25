struct s8_Interface { void **vtable; };
struct s8_ServiceOwner { char pad0[4]; s8_Interface *service; };
extern char lbl_8041b598[];
extern int lbl_804aaccc;
extern "C" s8_Interface *fn_8020b680(void *);
extern "C" void s8_acquire_service_800b1394(s8_ServiceOwner *self) {
    s8_Interface *service=fn_8020b680(lbl_8041b598);
    if(service) ((int (*)(s8_Interface *))service->vtable[3])(service);
    s8_Interface *old=self->service;
    if(old) ((int (*)(s8_Interface *))old->vtable[4])(old);
    self->service=service;
    ++lbl_804aaccc;
}
