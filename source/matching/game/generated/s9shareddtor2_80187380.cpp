/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

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
    char unknown4[44];
    S9HeldRef first,second;
};
extern "C" void fn_80190384(void *,int);
extern char lbl_80412da8[];
extern int lbl_804ab688;
extern S9HeldRef lbl_804b0204;
extern S9HeldRef lbl_804b0208;
extern S9HeldRef lbl_804b020c;
extern S9HeldRef lbl_804b0210;
extern S9HeldRef lbl_804b0214;
extern S9HeldRef lbl_804b0218;
extern S9HeldRef lbl_804b021c;
extern S9HeldRef lbl_804b0220;
extern S9HeldRef lbl_804b0224;
extern S9HeldRef lbl_804b0228;
extern S9HeldRef lbl_804b022c;
extern S9HeldRef lbl_804b0230;

extern "C" void s9_destroy_resource_set_80187380(S9SharedOwner *self,int flags)
{
    self->vtable=lbl_80412da8;
    self->second.assign(0);
    self->first.assign(0);
    int remaining=lbl_804ab688-1;
    lbl_804ab688=remaining;
    if(remaining==0) {
        lbl_804b0204.assign((S9HeldInterface *)remaining);
        lbl_804b0208.assign(0);
        lbl_804b020c.assign(0);
        lbl_804b0210.assign(0);
        lbl_804b0214.assign(0);
        lbl_804b0218.assign(0);
        lbl_804b021c.assign(0);
        lbl_804b0220.assign(0);
        lbl_804b0224.assign(0);
        lbl_804b0228.assign(0);
        lbl_804b022c.assign(0);
        lbl_804b0230.assign(0);
    }
    self->second.finish();
    self->first.finish();
    fn_80190384(self,flags);
}
