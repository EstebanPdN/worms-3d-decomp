/* Shared-interface cleanup and base-destructor forwarding. */
struct S9HeldInterface {
    void **vtable;
    void retain() { ((void (*)(S9HeldInterface *))vtable[3])(this); }
    void release() { ((void (*)(S9HeldInterface *))vtable[4])(this); }
};
struct S9HeldRef {
    S9HeldInterface *pointer;
    void assign(S9HeldInterface *value) { if(value)value->retain(); if(pointer)pointer->release(); pointer=value; }
    void finish() { if(pointer)pointer->release(); }
};
struct S9SharedOwner {
    void *vtable;
    char unknown4[40];
    S9HeldRef first,second;
};
extern "C" void fn_80190384(void *,int);
extern char lbl_80412bc8[];
extern int lbl_804ab660;
extern S9HeldRef lbl_804b01d4;
extern S9HeldRef lbl_804b01d8;
extern S9HeldRef lbl_804b01dc;
extern S9HeldRef lbl_804b01e0;
extern S9HeldRef lbl_804b01e4;
extern S9HeldRef lbl_804b01e8;
extern S9HeldRef lbl_804b01ec;
extern S9HeldRef lbl_804b01f0;
extern S9HeldRef lbl_804b01f4;
extern S9HeldRef lbl_804b01f8;
extern S9HeldRef lbl_804b01fc;
extern S9HeldRef lbl_804b0200;
extern "C" void s9_destroy_resource_set_80183ae8(S9SharedOwner *self,int flags)
{
    self->vtable=lbl_80412bc8;
    self->second.assign(0);
    self->first.assign(0);
    int remaining=lbl_804ab660-1;
    lbl_804ab660=remaining;
    if(remaining==0) {
        lbl_804b01d4.assign((S9HeldInterface *)remaining);
        lbl_804b01d8.assign(0);
        lbl_804b01dc.assign(0);
        lbl_804b01e0.assign(0);
        lbl_804b01e4.assign(0);
        lbl_804b01e8.assign(0);
        lbl_804b01ec.assign(0);
        lbl_804b01f0.assign(0);
        lbl_804b01f4.assign(0);
        lbl_804b01f8.assign(0);
        lbl_804b01fc.assign(0);
        lbl_804b0200.assign(0);
    }
    self->second.finish();
    self->first.finish();
    fn_80190384(self,flags);
}
