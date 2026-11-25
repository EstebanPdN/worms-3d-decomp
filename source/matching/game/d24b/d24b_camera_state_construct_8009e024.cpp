/* Worm camera state constructor (0x8009e024): runs the base constructor
 * 0x8015a0d4 with flag 1, installs the secondary vtable 0x8040f3c0 at +72 and
 * loads the "Worm.EyeLevelOffset", "Camera.Head.LookUpdateSpeed" and
 * "Worm.Drown.HeightOffset" settings through 0x800fc1b0 (cast 0x80342a74) into the
 * retained slots +76, +80 and +84, releasing the handles. Field and type names
 * are inferred from the original instructions. Strings and globals are external
 * views of original data; the unit owns no data. */
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
struct CameraState {
    char unknown00[72];
    void *vtable72;    /* +72 */
    Object *eyeLevel;  /* +76 */
    Object *head;      /* +80 */
    Object *drown;     /* +84 */
};
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" Object *w3d_identity_80342a74(Object *);
extern "C" int w3d_base_construct_8015a0d4(CameraState *, void *, int);
extern unsigned char w3d_vtable_8040f3c0[];
extern "C" char w3d_string_80380564[]; /* "Worm.EyeLevelOffset" */
extern "C" char w3d_string_80380578[]; /* "Camera.Head.LookUpdateSpeed" */
extern "C" char w3d_string_80380594[]; /* "Worm.Drown.HeightOffset" */

inline void Store(Handle &h, const char *name, Object *&slot)
{
    PropertyKey key;
    key.name = name;
    h.value = 0;
    w3d_resource_property_800fc1b0(&key, &h.value);
    Object *object = w3d_identity_80342a74(h.value);
    if (object) object->vtable->retain(object);
    if (slot) slot->vtable->release(slot);
    slot = object;
}

extern "C" CameraState *w3d_d24b_camera_state_construct_8009e024(CameraState *self, void *owner)
{
    w3d_base_construct_8015a0d4(self, owner, 1);
    self->vtable72 = w3d_vtable_8040f3c0;
    self->eyeLevel = 0;
    self->head = 0;
    self->drown = 0;
    Handle first;
    Store(first, w3d_string_80380564, self->eyeLevel);
    {
        PropertyKey key;
        key.name = w3d_string_80380578;
        w3d_resource_property_800fc1b0(&key, &first.value);
    }
    Object *object = w3d_identity_80342a74(first.value);
    if (object) object->vtable->retain(object);
    if (self->head) self->head->vtable->release(self->head);
    self->head = object;
    {
        Handle second;
        Store(second, w3d_string_80380594, self->drown);
    }
    return self;
}
