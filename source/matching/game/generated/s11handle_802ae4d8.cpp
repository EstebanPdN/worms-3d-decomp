/* Inferred named resource-handle construction. */
struct S11HandleObject;
struct S11HandleTable {
    void (*unknown[3])();
    void (*retain)(S11HandleObject *);
    void (*release)(S11HandleObject *);
};
struct S11HandleObject { S11HandleTable *vtable; };
struct S11HandleString { int text; int reserved; };
struct S11HandleRef { S11HandleObject *value; int reserved; };
extern "C" {
int fn_8020BB54(S11HandleString *,const char *);
int fn_8015ADF4(S11HandleString *,S11HandleRef *,int);
S11HandleObject *fn_8034BF4C(S11HandleObject *);
void fn_8020C5C4(S11HandleString *);
int fn_80341588(S11HandleString *);
S11HandleRef *s11_named_handle_802ae4d8(S11HandleRef *self,const char *text,int flags) {
    struct {S11HandleString name;S11HandleRef found;} local;
    self->value=0;
    fn_8020BB54(&local.name,text);
    register S11HandleString *name=&local.name;
    local.found.value=0;
    fn_8015ADF4(name,&local.found,flags);
    S11HandleObject *next=fn_8034BF4C(local.found.value);
    if (next) next->vtable->retain(next);
    if (self->value) self->value->vtable->release(self->value);
    self->value=next;
    if (local.found.value) local.found.value->vtable->release(local.found.value);
    fn_8020C5C4(name);
    fn_80341588(name);
    return self;
}
}
