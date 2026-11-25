// GWMP8P rev0 0x80026288. Starts the weapon aim display: subscribes three
// message handlers, reads the active worm index, loads and hides the aim
// line, refreshes its transform, loads the first-person cursor mesh and its
// inner and outer bitmaps, attaches the bitmaps, reads the camera mode into
// a first-person flag, updates visibility and posts a message. Names are
// inferred from the original strings and instructions.
/* Weapon aim line start-up (0x80026288): subscribes to three cached messages with
 * slots +80, +84 and +88, reads "ActiveWormIndex" into +32, resolves four named
 * resources through one reference (0x8015adf4, 0x80343584/0x8034357c casts, with
 * retain/release) into +64, +60, +68 and +72, hides the first (virtual +88),
 * refreshes (0x800261d4), attaches the third and fourth to +60 with the values of
 * 0x804aa7ec and 0x804aa7f0 (virtual +92), sets +92 when the camera mode property
 * equals 1, runs 0x80026064 and posts an 8-byte notification (cache 0x804acb04,
 * vtable 0x8040db38). Field and type names are inferred from the original
 * instructions. Strings and globals are external views of original data; the unit
 * owns no data. */
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);   /* +12 */
    void (*release)(Object *);  /* +16 */
    void *unknown20[17];
    int (*setVisible)(Object *, int);        /* +88 */
    int (*attach)(Object *, Object *, int);  /* +92 */
};
struct Object { ObjectVtable *vtable; };
struct Ref {
    Object *value;
    Ref() {}
    ~Ref() { if (value) value->vtable->release(value); }
private:
    Ref(const Ref &);
};
struct PropertyKey { const char *name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct String;
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
struct String;
extern "C" String *w3d_string_from_text(String *, const char *);
struct String {
    const char *text;
    String(const char *n) { w3d_string_from_text(this, n); }
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
struct Message { unsigned short id; unsigned short unknown02; void *vtable; };
struct WeaponAim {
    char unknown00[32];
    Object *activeWormIndex;   /* +32 */
    char unknown36[24];
    Object *line;              /* +60 */
    Object *cursor;            /* +64 */
    Object *lineTexture;       /* +68 */
    Object *lineFade;          /* +72 */
    char unknown76[4];
    char slot80[4];            /* +80 */
    char slot84[4];            /* +84 */
    char slot88[4];            /* +88 */
    int cameraIsFirst;         /* +92 */
};
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_subscribe_80162024(WeaponAim *, const unsigned short &, void *);
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" int w3d_int_property_800fc230(PropertyKey *, int *);
extern "C" int w3d_handle_load_8015adf4(const String *, Object **, unsigned char);
extern "C" Object *w3d_identity_80343584(Object *);
extern "C" Object *w3d_identity_8034357c(Object *);
extern "C" void w3d_refresh_800261d4(WeaponAim *);
extern "C" void w3d_visibility_80026064(WeaponAim *);
extern "C" Message *w3d_arena_alloc_801613f0(void *, int);
extern "C" int w3d_message_post_8016239c(Message *);
extern void *w3d_message_arena_804b1754;
extern int w3d_attach_804aa7ec, w3d_attach_804aa7f0;
extern MessageCache w3d_message_804acb14, w3d_message_804acafc, w3d_message_804acaf4, w3d_message_804acb04;
extern unsigned char w3d_vtable_8040db38[];
extern "C" char w3d_string_8036c9b8[];
extern "C" char w3d_string_8036c9d8[];
extern "C" char w3d_string_8036c9e8[];
extern "C" char w3d_string_8036c9f8[];
extern "C" char w3d_string_8036ca10[];
extern "C" char w3d_string_8036ca30[];

inline void GetNamed(const String &text, Ref &h)
{
    w3d_handle_load_8015adf4(&text, &h.value, 255);
}

inline void Assign(Object *&slot, Object *value)
{
    if (slot) slot->vtable->release(slot);
    slot = value;
}

template <Object *(*Cast)(Object *)>
inline void LoadNamed(const char *name, Ref &h, Object *&slot)
{
    GetNamed(String(name), h);
    Assign(slot, 0);
    Object *object = Cast(h.value);
    if (object) object->vtable->retain(object);
    Assign(slot, object);
}

extern "C" void w3d_d32a_weapon_aim_start_80026288(WeaponAim *self)
{
    Ref handle;
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acb14, 1), self->slot80);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acafc, 1), self->slot84);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acaf4, 1), self->slot88);
    PropertyKey wormKey;
    wormKey.name = w3d_string_8036c9d8;
    w3d_resource_property_800fc1b0(&wormKey, &self->activeWormIndex);
    handle.value = 0;
    LoadNamed<w3d_identity_80343584>(w3d_string_8036c9e8, handle, self->cursor);
    self->cursor->vtable->setVisible(self->cursor, 0);
    w3d_refresh_800261d4(self);
    LoadNamed<w3d_identity_80343584>(w3d_string_8036c9f8, handle, self->line);
    LoadNamed<w3d_identity_8034357c>(w3d_string_8036ca10, handle, self->lineTexture);
    LoadNamed<w3d_identity_8034357c>(w3d_string_8036ca30, handle, self->lineFade);
    self->line->vtable->attach(self->line, self->lineTexture, w3d_attach_804aa7ec);
    self->line->vtable->attach(self->line, self->lineFade, w3d_attach_804aa7f0);
    PropertyKey modeKey;
    int mode;
    modeKey.name = w3d_string_8036c9b8;
    w3d_int_property_800fc230(&modeKey, &mode);
    self->cameraIsFirst = mode == 1;
    w3d_visibility_80026064(self);
    Message *message = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
    message->id = w3d_cached_message_id_8015f5a0(&w3d_message_804acb04, 1);
    message->vtable = w3d_vtable_8040db38;
    w3d_message_post_8016239c(message);
}
