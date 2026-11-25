/* Worm-selection start (0x8003c0f0): selects the worm through 0x8003bf70,
 * loads the "Camera.CurrentMode" and "ActiveWormIndex" resources into +100
 * and +40 through one handle (casting with 0x80342a78 and 0x803426b4,
 * retaining the new object, releasing the previous one and the handle),
 * subscribes the object (0x80162024) to eight messages with handler slots
 * +52, +44, +48, +56, +60, +64, +68 and +80, posts an 8-byte notification
 * (cached id 0x804ad170, vtable 0x8040db38), runs 0x8003cdcc and clears
 * +88 and +96. Field and type names are inferred from the original
 * instructions. Strings and globals are external views of original data;
 * the unit owns no data.
 *
 * The subscription takes the message id by const reference; the int result
 * of the cache lookup converts to a temporary at each call, which gets the
 * next free stack slot after the property keys, as in the original. */
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
private:
    Handle(const Handle &);
};
struct PropertyKey { const char *name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message {
    unsigned short id;
    unsigned short unknown02;
    void *vtable;
};
struct WormSelect {
    char unknown00[40];
    Object *activeWormIndex;   /* +40 */
    char slot44[4];            /* +44 */
    char slot48[4];            /* +48 */
    char slot52[4];            /* +52 */
    char slot56[4];            /* +56 */
    char slot60[4];            /* +60 */
    char slot64[4];            /* +64 */
    char slot68[4];            /* +68 */
    char unknown72[8];
    char slot80[4];            /* +80 */
    char unknown84[4];
    int unknown88;             /* +88 */
    char unknown92[4];
    int unknown96;             /* +96 */
    Object *cameraMode;        /* +100 */
};
extern "C" void w3d_worm_select_8003bf70(WormSelect *, int);
extern "C" void w3d_worm_select_update_8003cdcc(WormSelect *);
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" Object *w3d_identity_80342a78(Object *);
extern "C" Object *w3d_identity_803426b4(Object *);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_subscribe_80162024(WormSelect *, const unsigned short &, void *);
extern "C" Message *w3d_arena_alloc_801613f0(void *, int);
extern "C" int w3d_message_post_8016239c(Message *);
extern void *w3d_message_arena_804b1754;
extern MessageCache w3d_message_804ad138, w3d_message_804ad140, w3d_message_804ad148,
    w3d_message_804ad150, w3d_message_804ad158, w3d_message_804ad160,
    w3d_message_804ad168, w3d_message_804ad170, w3d_message_804ad180;
extern unsigned char w3d_vtable_8040db38[];
extern "C" char w3d_string_80374408[]; /* "Camera.CurrentMode" */
extern "C" char w3d_string_8037441c[]; /* "ActiveWormIndex" */

template <Object *(*Cast)(Object *)>
inline void LoadResource(Handle &h, const char *name, Object *&slot)
{
    PropertyKey key;
    key.name = name;
    h.value = 0;
    w3d_resource_property_800fc1b0(&key, &h.value);
    Object *object = Cast(h.value);
    if (object) object->vtable->retain(object);
    if (slot) slot->vtable->release(slot);
    slot = object;
    if (h.value) h.value->vtable->release(h.value);
}

extern "C" void w3d_d23a_worm_select_start_8003c0f0(WormSelect *self)
{
    Handle handle;
    w3d_worm_select_8003bf70(self, 1);
    LoadResource<w3d_identity_80342a78>(handle, w3d_string_80374408, self->cameraMode);
    LoadResource<w3d_identity_803426b4>(handle, w3d_string_8037441c, self->activeWormIndex);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad158, 1), self->slot52);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad138, 1), self->slot44);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad140, 1), self->slot48);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad148, 1), self->slot56);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad150, 1), self->slot60);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad160, 1), self->slot64);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad168, 1), self->slot68);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad180, 1), self->slot80);
    Message *changed = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
    changed->id = w3d_cached_message_id_8015f5a0(&w3d_message_804ad170, 1);
    changed->vtable = w3d_vtable_8040db38;
    w3d_message_post_8016239c(changed);
    w3d_worm_select_update_8003cdcc(self);
    self->unknown88 = 0;
    self->unknown96 = 0;
}
