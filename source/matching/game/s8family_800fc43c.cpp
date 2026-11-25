struct s8_Interface { void (**vtable)(); };
struct s8_Handle {
    s8_Interface *p;
    int unused;
    s8_Handle() : p(0) {}
    ~s8_Handle() { if(p) ((void (*)(s8_Interface *))p->vtable[4])(p); }
};
struct s8_Service { char pad0[100]; s8_Interface *properties; };
extern s8_Service *lbl_804b1788;
extern "C" void *fn_80342a78(s8_Interface *);
extern "C" int fn_80178d28(void *,int *);
extern "C" int s8_property_write_800fc43c(void *name,int value) {
    s8_Handle property;
    s8_Interface *service=lbl_804b1788->properties;
    int status=((int (*)(s8_Interface *,void *,s8_Handle *))service->vtable[31])(service,name,&property);
    if(status>=0) fn_80178d28(fn_80342a78(property.p),&value);
    return status;
}
