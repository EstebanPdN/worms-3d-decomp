// cc39c: 0x8009369c (228 bytes), rebuild the "Girder" light member of an owner.
// Observed in the original DOL: a temporary engine string built from the
// original literal "Girder" (0x8037e9dc) names the owner's handle at +32 with
// flags 255 and is destroyed (0x8020c5c4 then 0x80341588); the handle's object
// is read through the identity cast 0x80343584; a previous member at +36 is
// deleted (0x801265a4 with flags 3); a new 4-byte member is allocated from the
// handle heap (r13 object 0x804af5bc) and constructed (0x8012656c) from the
// object's virtual kind (+60). A non-null member then receives the handle by
// value: the caller only retains the copy (+12), and the callee 0x80126610
// releases its parameter, as g++ 2.95 destroys by-value parameters in the callee.
// All names and views are inferred; unknown words are not recovered layout.
struct cc39c_Heap { void *core; };
struct cc39c_Object;
struct cc39c_ObjectVtable {
    void *unknown00[3];
    void (*retain)(cc39c_Object *);      // +12
    void (*release)(cc39c_Object *);     // +16
    void *unknown14[10];
    int (*kind)(cc39c_Object *);         // +60
};
struct cc39c_Object { cc39c_ObjectVtable *vtable; };
extern "C" {
void cc39c_string_from_text_8020bb54(void *, const char *);
void cc39c_string_base_finish_8020c5c4(void *);
void cc39c_string_release_80341588(void *);
void cc39c_handle_set_name_8015adf4(const void *, void *, unsigned int);
cc39c_Object *cc39c_handle_object_80343584(cc39c_Object *);
void *cc39c_heap_allocate_802098d8(cc39c_Heap *, unsigned int);
extern const char cc39c_girder_8037e9dc[];
extern cc39c_Heap cc39c_handle_heap_804af5bc;
}
struct cc39c_String {
    const char *text;
    int unknown04;
    cc39c_String(const char *s) { cc39c_string_from_text_8020bb54(this, s); }
    ~cc39c_String() { cc39c_string_base_finish_8020c5c4(this); cc39c_string_release_80341588(this); }
};
// Retaining reference to a handle object; copies retain, destruction releases.
struct cc39c_Ref {
    cc39c_Object *object;
    cc39c_Ref(const cc39c_Ref &o) : object(o.object) { if (object) object->vtable->retain(object); }
    ~cc39c_Ref() { if (object) object->vtable->release(object); }
};
struct cc39c_LightMember;
extern "C" {
cc39c_LightMember *cc39c_member_construct_8012656c(cc39c_LightMember *, int);
void cc39c_member_destroy_801265a4(cc39c_LightMember *, int);
void cc39c_member_attach_80126610(cc39c_LightMember *, cc39c_Ref);
}
// Allocation request witnesses 4 bytes for this member view.
struct cc39c_LightMember { unsigned int handle; };
struct cc39c_GirderOwner {
    unsigned char unknown00[32];
    cc39c_Ref handle;                    // +32
    cc39c_LightMember *member;           // +36
};
// The naming step is an inline helper taking the owner (same shape as the
// admitted cc17d name reset): the constructor receives the slot address
// directly and later uses share one saved address register.
static inline void cc39c_name_handle(cc39c_GirderOwner *owner, const char *text) {
    cc39c_String name(text);
    cc39c_handle_set_name_8015adf4(&name, &owner->handle, 255);
}
extern "C" void cc39c_girder_member_8009369c(cc39c_GirderOwner *self) {
    cc39c_name_handle(self, cc39c_girder_8037e9dc);
    cc39c_Object *object = cc39c_handle_object_80343584(self->handle.object);
    if (self->member) cc39c_member_destroy_801265a4(self->member, 3);
    cc39c_LightMember *member = (cc39c_LightMember *)cc39c_heap_allocate_802098d8(&cc39c_handle_heap_804af5bc, 4);
    self->member = cc39c_member_construct_8012656c(member, object->vtable->kind(object));
    if (self->member) cc39c_member_attach_80126610(self->member, self->handle);
}
