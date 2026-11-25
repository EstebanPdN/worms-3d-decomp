/* Worm-selection start (0x800a064c): selects the worm through 0x800a04d4,
 * loads the "Camera.CurrentMode" and "ActiveWormIndex" resources into +96 and
 * +40 through one handle (casting with 0x80342a78 and 0x803426b4, retaining
 * the new object, releasing the previous one and the handle), subscribes the
 * object (0x80162024) to nine cached messages with handler slots +52, +44,
 * +48, +56, +60, +64, +68, +72 and +76, runs 0x800a12c0 and clears +84 and
 * +92. Same shape as d23a_worm_select_start_8003c0f0. Field and type names
 * are inferred from the original instructions. Strings and globals are
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
private:
    Handle(const Handle &);
};
struct PropertyKey { const char *name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct WormSelect {
    char unknown00[40];
    Object *activeWormIndex;   /* +40 */
    char slot44[4], slot48[4], slot52[4], slot56[4], slot60[4], slot64[4], slot68[4], slot72[4], slot76[4];
    char unknown80[4];
    int unknown84;             /* +84 */
    char unknown88[4];
    int unknown92;             /* +92 */
    Object *cameraMode;        /* +96 */
};
extern "C" void w3d_worm_select_800a04d4(WormSelect *, int);
extern "C" void w3d_worm_select_update_800a12c0(WormSelect *);
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" Object *w3d_identity_80342a78(Object *);
extern "C" Object *w3d_identity_803426b4(Object *);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_subscribe_80162024(WormSelect *, const unsigned short &, void *);
extern MessageCache w3d_message_804ae14c, w3d_message_804ae12c, w3d_message_804ae134, w3d_message_804ae13c,
    w3d_message_804ae144, w3d_message_804ae154, w3d_message_804ae15c, w3d_message_804ae164, w3d_message_804ae16c;
extern "C" char w3d_string_803808b0[]; /* "Camera.CurrentMode" */
extern "C" char w3d_string_803808c4[]; /* "ActiveWormIndex" */

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

extern "C" void w3d_d24b_worm_select_start_800a064c(WormSelect *self)
{
    Handle handle;
    w3d_worm_select_800a04d4(self, 1);
    LoadResource<w3d_identity_80342a78>(handle, w3d_string_803808b0, self->cameraMode);
    LoadResource<w3d_identity_803426b4>(handle, w3d_string_803808c4, self->activeWormIndex);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae14c, 1), self->slot52);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae12c, 1), self->slot44);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae134, 1), self->slot48);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae13c, 1), self->slot56);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae144, 1), self->slot60);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae154, 1), self->slot64);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae15c, 1), self->slot68);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae164, 1), self->slot72);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae16c, 1), self->slot76);
    w3d_worm_select_update_800a12c0(self);
    self->unknown84 = 0;
    self->unknown92 = 0;
}
