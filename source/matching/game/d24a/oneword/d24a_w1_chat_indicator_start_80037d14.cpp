/* Chat indicator start-up (0x80037d14): runs 0x80038240, loads the
 * "Chat.Indicator.*" resources (Duration +60, ScrollSpeed +76, OffScreenPos +36,
 * OnScreenPos +40, Scale +44, AudioPos +52, AudioVol +56) through a handle with
 * retain/release, resolves the "Chat.Indicator.Bitmap" handle (0x8015adf4) into
 * +28 and retains its cast in +48, sets the sprite scale (virtual +84) and
 * position (word copy into +64, virtual +76), clears +80, +96 and +88, sets +92,
 * creates the "Telephone" sound through the audio service (game state word
 * +108, virtual +92, into +96) and sets its volume (virtual +52) and position
 * (virtual +56). Field and type names are inferred from the original
 * instructions. Strings and globals are external views of original data; the
 * unit owns no data.
 *
 * Handle and temporary String are block-scoped one-word objects that share
 * sp+8: block-mode locals round to 8 bytes and reuse the freed slot. */
struct Vec3 { float x, y, z; };
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);   /* +12 */
    void (*release)(Object *);  /* +16 */
    void *unknown20[8];
    int (*setVolume)(Object *, int, float);    /* +52 */
    void (*setPosition)(Object *, int, void *); /* +56 */
    void *unknown60[4];
    void (*moveTo)(Object *, Vec3 *, int);      /* +76 */
    void *unknown80;
    void (*setScale)(Object *, void *, int);    /* +84 */
    void *unknown88;
    void (*createSound)(Object *, const char *, Object **); /* +92 */
};
struct Object { ObjectVtable *vtable; };
struct Handle {
    Object *value;
    Handle() {}
private:
    Handle(const Handle &);
};
struct PropertyKey { const char *name; };
struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
struct String {
    char *text;
    String(const char *);
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
struct GameState { char unknown00[108]; Object *audio; };
struct ChatIndicator {
    char unknown00[28];
    Object *bitmap;            /* +28 */
    char unknown32[4];
    Object *offScreenPos;      /* +36 */
    Object *onScreenPos;       /* +40 */
    Object *scale;             /* +44 */
    Object *bitmapCast;        /* +48 */
    Object *audioPos;          /* +52 */
    Object *audioVol;          /* +56 */
    Object *duration;          /* +60 */
    Vec3 position;             /* +64 */
    Object *scrollSpeed;       /* +76 */
    unsigned char active;      /* +80 */
    char unknown81[7];
    int unknown88;             /* +88 */
    int unknown92;             /* +92 */
    Object *sound;             /* +96 */
};
extern "C" void w3d_chat_indicator_reset_80038240(ChatIndicator *);
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" Object *w3d_identity_80342a74(Object *);
extern "C" Object *w3d_identity_80342fa4(Object *);
extern "C" Object *w3d_identity_8034357c(Object *);
extern "C" int w3d_handle_load_8015adf4(const String *, Object **, unsigned char);
extern "C" void *w3d_object_value_80178ec4(Object *);
extern "C" float w3d_object_float_80178df0(Object *);
extern GameState *w3d_game_state_804b1788;
extern "C" char w3d_string_80373ed4[]; /* "Chat.Indicator.Duration" */
extern "C" char w3d_string_80373eec[]; /* "Chat.Indicator.Bitmap" */
extern "C" char w3d_string_80373f04[]; /* "Chat.Indicator.ScrollSpeed" */
extern "C" char w3d_string_80373f20[]; /* "Chat.Indicator.OffScreenPos" */
extern "C" char w3d_string_80373f3c[]; /* "Chat.Indicator.OnScreenPos" */
extern "C" char w3d_string_80373f58[]; /* "Chat.Indicator.Scale" */
extern "C" char w3d_string_80373f70[]; /* "Chat.Indicator.AudioPos" */
extern "C" char w3d_string_80373f88[]; /* "Chat.Indicator.AudioVol" */
extern "C" char w3d_string_80373fa0[]; /* "Telephone" */

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

inline void ResetSound(ChatIndicator *s, bool on)
{
    s->active = on;
    if (s->sound) s->sound->vtable->release(s->sound);
    s->sound = 0;
}

extern "C" void w3d_d24a_chat_indicator_start_80037d14(ChatIndicator *self)
{
    w3d_chat_indicator_reset_80038240(self);
    {
        Handle handle;
        LoadResource<w3d_identity_80342a74>(handle, w3d_string_80373ed4, self->duration);
    }
    {
        String name(w3d_string_80373eec);
        w3d_handle_load_8015adf4(&name, &self->bitmap, 255);
    }
    {
        Object *object = w3d_identity_8034357c(self->bitmap);
        if (object) object->vtable->retain(object);
        if (self->bitmapCast) self->bitmapCast->vtable->release(self->bitmapCast);
        self->bitmapCast = object;
    }
    Object **soundSlot;
    {
        Handle handle;
        LoadResource<w3d_identity_80342a74>(handle, w3d_string_80373f04, self->scrollSpeed);
        LoadResource<w3d_identity_80342fa4>(handle, w3d_string_80373f20, self->offScreenPos);
        LoadResource<w3d_identity_80342fa4>(handle, w3d_string_80373f3c, self->onScreenPos);
        LoadResource<w3d_identity_80342fa4>(handle, w3d_string_80373f58, self->scale);
        soundSlot = &self->sound;
        Object *bitmap = self->bitmap;
        ObjectVtable *vtable = bitmap->vtable;
        vtable->setScale(bitmap, w3d_object_value_80178ec4(self->scale), 0);
        self->position = *(Vec3 *)w3d_object_value_80178ec4(self->offScreenPos);
        self->unknown92 = 1;
        self->bitmap->vtable->moveTo(self->bitmap, &self->position, 0);
        ResetSound(self, false);
        LoadResource<w3d_identity_80342fa4>(handle, w3d_string_80373f70, self->audioPos);
        LoadResource<w3d_identity_80342a74>(handle, w3d_string_80373f88, self->audioVol);
    }
    Object *audio = w3d_game_state_804b1788->audio;
    audio->vtable->createSound(audio, w3d_string_80373fa0, soundSlot);
    {
        Object *sound = self->sound;
        ObjectVtable *vtable = sound->vtable;
        vtable->setVolume(sound, 1, w3d_object_float_80178df0(self->audioVol));
    }
    {
        Object *sound = self->sound;
        ObjectVtable *vtable = sound->vtable;
        vtable->setPosition(sound, 3, w3d_object_value_80178ec4(self->audioPos));
    }
    self->unknown88 = 0;
}
