struct S9PropertyHeader {
    char unknown0[4];
    unsigned short kind;
    char unknown6[18];
    int count;
    unsigned short references;
    char unknown30[2];
    char data[1];
};
extern "C" void *fn_801ef048(void *,int,int,int);
struct S9Property {
    S9PropertyHeader *header;
    int count() const { return header->count; }
    void *get_data(int n,int flags) {
        S9PropertyHeader *h=header;
        void *result;
        if(h->kind!=1)goto slow;
        if(!flags && n!=h->count)goto slow;
        h->references++;
        result=h->data;
        goto done;
slow:
        result=fn_801ef048(this,n,4,flags);
done:
        return result;
    }
};
struct S9PropertyOwner {
    char unknown0[88];
    S9Property primary;
    char unknown92[4];
    S9Property alternate;
};
struct S9PropertyParent { char unknown0[48]; S9PropertyOwner *owner; };
struct S9PropertyObject { char unknown0[168]; S9PropertyParent *parent; };
extern "C" void *s9_property_fallback_80189574(S9PropertyObject *self)
{
    S9PropertyOwner *owner=self->parent->owner;
    int n=owner->primary.count();
    void *result=owner->primary.get_data(n,2);
    if(n)goto done;
    n=owner->alternate.count();
    if(!n)return 0;
    result=owner->primary.get_data(n,0);
done:
    return result;
}
