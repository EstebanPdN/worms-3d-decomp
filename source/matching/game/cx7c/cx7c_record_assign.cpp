/* Inferred 12-byte value assignment at 0x8035c32c: interface +0,
 * ref-counted string pointers +4/+8. String refcount is a u16 at data-6;
 * interface retain/release slots are byte offsets +12/+16 in its vtable.
 */
struct Cx7cHeld;
struct Cx7cHeldVtable {void *unknown[3]; void (*retain)(Cx7cHeld *);void (*release)(Cx7cHeld *);};
struct Cx7cHeld {Cx7cHeldVtable *vptr;};
extern "C" void cx7c_string_header_free_8020bb2c(unsigned short *);
struct Cx7cSharedString {
    char *data;
    Cx7cSharedString &operator=(const Cx7cSharedString &other) {
        ++*(unsigned short *)(other.data-6);
        unsigned short *header=(unsigned short *)(data-6);
        if (--*header==0) cx7c_string_header_free_8020bb2c(header);
        data=other.data;
        return *this;
    }
};
struct Cx7cRecord {Cx7cHeld *held; Cx7cSharedString first,second;};
extern "C" Cx7cRecord *w3d_cx7c_record_assign_8035c32c(Cx7cRecord *self,const Cx7cRecord *other)
{
    if (other->held) other->held->vptr->retain(other->held);
    if (self->held) self->held->vptr->release(self->held);
    self->held=other->held;
    self->first=other->first;
    self->second=other->second;
    return self;
}
