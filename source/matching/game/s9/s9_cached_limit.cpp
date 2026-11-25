/* Cached property reference and float limit comparison. */
struct S9LimitInterface {
    void **vtable;
    void retain() { ((void (*)(S9LimitInterface *))vtable[3])(this); }
    void release() { ((void (*)(S9LimitInterface *))vtable[4])(this); }
};
struct S9LimitLocalRef {
    S9LimitInterface *pointer;
    int unknown;
    S9LimitLocalRef() : pointer(0) {}
    ~S9LimitLocalRef() { S9LimitInterface *value=pointer; if(value)value->release(); }
};
struct S9LimitName {
    char *text;
    int unknown[3];
    S9LimitName(char *value) : text(value) {}
};
extern S9LimitInterface *lbl_804afdf8;
extern char lbl_803a1230[];
extern "C" void fn_800fc1b0(S9LimitName *,S9LimitLocalRef *);
extern "C" S9LimitInterface *fn_80342a74(S9LimitInterface *);
extern "C" float fn_8014ca54(void *);
extern "C" float fn_80178df0(S9LimitInterface *);
static inline void s9_assign_limit(S9LimitInterface *&target,S9LimitInterface *value)
{
    if(value)value->retain();
    if(target)target->release();
    target=value;
}
struct S9LimitConverted {
    S9LimitInterface *pointer;
    int unknown;
    S9LimitConverted(S9LimitInterface *value) : pointer(fn_80342a74(value)) {}
};
extern "C" int s9_compare_cached_limit_8014c89c(void *self)
{
    if(!lbl_804afdf8) {
        S9LimitLocalRef local;
        S9LimitName name(lbl_803a1230);
        fn_800fc1b0(&name,&local);
        s9_assign_limit(lbl_804afdf8,fn_80342a74(local.pointer));
    }
    float angle=fn_8014ca54(self);
    return angle<=fn_80178df0(lbl_804afdf8);
}
