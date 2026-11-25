/* Named border resource attachment with observed shared-string ownership. */
struct S11BorderObject;
struct S11BorderTable { void (*unknown[3])();void (*retain)(S11BorderObject *);void (*release)(S11BorderObject *); };
struct S11BorderObject {S11BorderTable *vtable;char unknown04[32];char *name;};
struct S11BorderRef {S11BorderObject *value;int reserved;};
struct S11BorderString {
 S11BorderString(const S11BorderString &); S11BorderString() {}char *text;};
extern "C" {
S11BorderObject *fn_8020B680(const void *);
int fn_8020BB54(S11BorderString *,const char *);
int fn_8020BB2C(unsigned short *);
void fn_8020C5C4(S11BorderString *);
int fn_80341588(S11BorderString *);
int fn_80174820(void *,S11BorderObject *);
extern const char lbl_803CAA7C[];
extern const unsigned char lbl_804144E8[];
int s11_attach_border_8025e48c(void *owner) {
    struct {S11BorderRef ref;S11BorderString name;} local;
    local.ref.value=fn_8020B680(lbl_804144E8);
    if (local.ref.value) local.ref.value->vtable->retain(local.ref.value);
    S11BorderObject *object=local.ref.value;
    register S11BorderString *name=&local.name;
    fn_8020BB54(name,lbl_803CAA7C);
    ++((unsigned short *)local.name.text)[-3];
    char *old=object->name;
    unsigned short *header=(unsigned short *)old-3;
    unsigned int count=*header-1;
    *header=count;
    if (!(unsigned short)count) fn_8020BB2C(header);
    object->name=local.name.text;
    fn_8020C5C4(name);
    fn_80341588(name);
    fn_80174820(owner,local.ref.value);
    if (local.ref.value) local.ref.value->vtable->release(local.ref.value);
    return 0;
}
}
