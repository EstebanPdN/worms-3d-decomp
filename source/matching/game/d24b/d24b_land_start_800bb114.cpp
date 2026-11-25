/* Landscape start (0x800bb114): subscribes the object (0x80162024) to eight
 * cached messages with handler slots +28, +32, +36, +44, +48, +56, +60 and
 * +64, loads three settings through one handle into three global objects
 * (casts 0x80342a74, 0x80342a78, 0x80342a78, retaining the new object and
 * releasing the previous one), then loads the "Test.Landscape" resource into
 * the handle at +12544 (0x8015adf4, flags 255). Field and type
 * names are inferred from the original instructions. Strings and globals are
 * external views of original data; the unit owns no data. */
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);   /* +12 */
    void (*release)(Object *);  /* +16 */
};
struct Object { ObjectVtable *vtable; };
struct Handle {
    Object *value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
struct PropertyKey { const char *name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct String {
 String(const String &);
    char *text;
    String(const char *text);
    ~String();
};
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
inline String::~String() {
    w3d_string_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
struct LandSetup {
    char unknown00[28];
    char slot28[4], slot32[4], slot36[4], unknown40[4], slot44[4], slot48[4], unknown52[4],
        slot56[4], slot60[4], slot64[4];
    char unknown68[12476];
    Object *testLandscape;  /* +12544 */
};
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" Object *w3d_identity_80342a74(Object *);
extern "C" Object *w3d_identity_80342a78(Object *);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_subscribe_80162024(LandSetup *, const unsigned short &, void *);
extern "C" int w3d_handle_load_8015adf4(const String *, Object **, unsigned char);
extern MessageCache w3d_message_804ae580, w3d_message_804ae5a8, w3d_message_804ae588, w3d_message_804ae5c0,
    w3d_message_804ae590, w3d_message_804ae5a0, w3d_message_804ae5c8, w3d_message_804ae5d0;
extern PropertyKey w3d_property_804aad4c;
extern Object *w3d_object_804ae5d8, *w3d_object_804ae5dc, *w3d_object_804ae5e0;
extern "C" char w3d_string_80382b6c[]; /* "Land.Changed" */
extern "C" char w3d_string_80382b7c[]; /* "Land.Indestructable" */
extern "C" char w3d_string_80382b90[]; /* "Test.Landscape" */

inline void Open(Handle &h, PropertyKey *key) { h.value = 0; w3d_resource_property_800fc1b0(key, &h.value); }
template <Object *(*Cast)(Object *)>
inline void Store(Handle &h, Object *&slot)
{
    Object *object = Cast(h.value);
    if (object) object->vtable->retain(object);
    if (slot) slot->vtable->release(slot);
    slot = object;
}

extern "C" void w3d_d24b_land_start_800bb114(LandSetup *self)
{
    Handle handle;
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae580, 1), self->slot28);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae5a8, 1), self->slot32);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae588, 1), self->slot36);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae5c0, 1), self->slot44);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae590, 1), self->slot48);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae5a0, 1), self->slot56);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae5c8, 1), self->slot60);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae5d0, 1), self->slot64);
    Open(handle, &w3d_property_804aad4c);
    Store<w3d_identity_80342a74>(handle, w3d_object_804ae5d8);
    PropertyKey changed;
    changed.name = w3d_string_80382b6c;
    w3d_resource_property_800fc1b0(&changed, &handle.value);
    Store<w3d_identity_80342a78>(handle, w3d_object_804ae5dc);
    PropertyKey indestructable;
    indestructable.name = w3d_string_80382b7c;
    w3d_resource_property_800fc1b0(&indestructable, &handle.value);
    Store<w3d_identity_80342a78>(handle, w3d_object_804ae5e0);
    {
        String test(w3d_string_80382b90);
        w3d_handle_load_8015adf4(&test, &self->testLandscape, 255);
    }
}
