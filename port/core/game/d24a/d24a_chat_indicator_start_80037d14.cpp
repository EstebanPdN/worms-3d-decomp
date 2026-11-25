#include "w3d_ptr.h"
#line 1 "d24a_chat_indicator_start_80037d14.cpp"
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
 * Handle and temporary String are block-scoped one-word objects with user copy
 * constructors that share sp+8, as in 0x80026e74. */
struct Vec3 { float x, y, z; };
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
    Ptr32<void> unknown20[8];
    Ptr32<int (Ptr32<Object>, int, float)> setVolume;    /* +52 */
    Ptr32<void (Ptr32<Object>, int, Ptr32<void>)> setPosition; /* +56 */
    Ptr32<void> unknown60[4];
    Ptr32<void (Ptr32<Object>, Ptr32<Vec3>, int)> moveTo;      /* +76 */
    Ptr32<void> unknown80;
    Ptr32<void (Ptr32<Object>, Ptr32<void>, int)> setScale;    /* +84 */
    Ptr32<void> unknown88;
    Ptr32<void (Ptr32<Object>, Ptr32<const char>, Ptr32<Ptr32<Object>>)> createSound; /* +92 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() {}
private:
    Handle(const Handle &);
};
struct PropertyKey { Ptr32<const char> name; };
struct String;
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
struct GameState { char unknown00[108]; Ptr32<Object> audio; };
struct ChatIndicator {
    char unknown00[28];
    Ptr32<Object> bitmap;            /* +28 */
    char unknown32[4];
    Ptr32<Object> offScreenPos;      /* +36 */
    Ptr32<Object> onScreenPos;       /* +40 */
    Ptr32<Object> scale;             /* +44 */
    Ptr32<Object> bitmapCast;        /* +48 */
    Ptr32<Object> audioPos;          /* +52 */
    Ptr32<Object> audioVol;          /* +56 */
    Ptr32<Object> duration;          /* +60 */
    Vec3 position;             /* +64 */
    Ptr32<Object> scrollSpeed;       /* +76 */
    unsigned char active;      /* +80 */
    char unknown81[7];
    int unknown88;             /* +88 */
    int unknown92;             /* +92 */
    Ptr32<Object> sound;             /* +96 */
};
extern "C" void w3d_chat_indicator_reset_80038240(Ptr32<ChatIndicator>);
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Object> w3d_identity_80342a74(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_identity_80342fa4(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_identity_8034357c(Ptr32<Object>);
extern "C" int w3d_handle_load_8015adf4(Ptr32<const String>, Ptr32<Ptr32<Object>>, unsigned char);
extern "C" Ptr32<void> w3d_object_value_80178ec4(Ptr32<Object>);
extern "C" float w3d_object_float_80178df0(Ptr32<Object>);
extern Ptr32<GameState> w3d_game_state_804b1788;
extern "C" char w3d_string_80373ed4[]; /* "Chat.Indicator.Duration" */
extern "C" char w3d_string_80373eec[]; /* "Chat.Indicator.Bitmap" */
extern "C" char w3d_string_80373f04[]; /* "Chat.Indicator.ScrollSpeed" */
extern "C" char w3d_string_80373f20[]; /* "Chat.Indicator.OffScreenPos" */
extern "C" char w3d_string_80373f3c[]; /* "Chat.Indicator.OnScreenPos" */
extern "C" char w3d_string_80373f58[]; /* "Chat.Indicator.Scale" */
extern "C" char w3d_string_80373f70[]; /* "Chat.Indicator.AudioPos" */
extern "C" char w3d_string_80373f88[]; /* "Chat.Indicator.AudioVol" */
extern "C" char w3d_string_80373fa0[]; /* "Telephone" */

template <Ptr32<Object> (*Cast)(Ptr32<Object>)>
inline void LoadResource(Handle &h, Ptr32<const char> name, Ptr32<Object> &slot)
{
    PropertyKey key;
    key.name = name;
    h.value = 0;
    w3d_resource_property_800fc1b0(&key, &h.value);
    Ptr32<Object> object = Cast(h.value);
    if (object) object->vtable->retain(object);
    if (slot) slot->vtable->release(slot);
    slot = object;
    if (h.value) h.value->vtable->release(h.value);
}

inline void ResetSound(Ptr32<ChatIndicator> s, bool on)
{
    s->active = on;
    if (s->sound) s->sound->vtable->release(s->sound);
    s->sound = 0;
}

extern "C" void w3d_d24a_chat_indicator_start_80037d14(Ptr32<ChatIndicator> self)
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
        Ptr32<Object> object = w3d_identity_8034357c(self->bitmap);
        if (object) object->vtable->retain(object);
        if (self->bitmapCast) self->bitmapCast->vtable->release(self->bitmapCast);
        self->bitmapCast = object;
    }
    Ptr32<Ptr32<Object>> soundSlot;
    {
        Handle handle;
        LoadResource<w3d_identity_80342a74>(handle, w3d_string_80373f04, self->scrollSpeed);
        LoadResource<w3d_identity_80342fa4>(handle, w3d_string_80373f20, self->offScreenPos);
        LoadResource<w3d_identity_80342fa4>(handle, w3d_string_80373f3c, self->onScreenPos);
        LoadResource<w3d_identity_80342fa4>(handle, w3d_string_80373f58, self->scale);
        soundSlot = &self->sound;
        Ptr32<Object> bitmap = self->bitmap;
        Ptr32<ObjectVtable> vtable = bitmap->vtable;
        vtable->setScale(bitmap, w3d_object_value_80178ec4(self->scale), 0);
        self->position = *(Ptr32<Vec3>)w3d_object_value_80178ec4(self->offScreenPos);
        self->unknown92 = 1;
        self->bitmap->vtable->moveTo(self->bitmap, &self->position, 0);
        ResetSound(self, false);
        LoadResource<w3d_identity_80342fa4>(handle, w3d_string_80373f70, self->audioPos);
        LoadResource<w3d_identity_80342a74>(handle, w3d_string_80373f88, self->audioVol);
    }
    Ptr32<Object> audio = w3d_game_state_804b1788->audio;
    audio->vtable->createSound(audio, w3d_string_80373fa0, soundSlot);
    {
        Ptr32<Object> sound = self->sound;
        Ptr32<ObjectVtable> vtable = sound->vtable;
        vtable->setVolume(sound, 1, w3d_object_float_80178df0(self->audioVol));
    }
    {
        Ptr32<Object> sound = self->sound;
        Ptr32<ObjectVtable> vtable = sound->vtable;
        vtable->setPosition(sound, 3, w3d_object_value_80178ec4(self->audioPos));
    }
    self->unknown88 = 0;
}


