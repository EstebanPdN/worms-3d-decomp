/* Worm information HUD start-up (0x80023944): sets +136 to -1, resolves four
 * named handles (0x8015adf4) into +28..+40, loads "WormPot" into +104 through a
 * handle (0x800fc1b0, cast 0x80341584, with retain/release), resolves the fifth
 * handle into +44, subscribes to seven cached messages with slots +108..+132,
 * loads "ActiveWormIndex" and the "HUD.ActWormInfo.*" resources into +48..+100
 * and "EFMV.Active", "WeaponPanel.Open" and "Chat.Open" into +84..+92, then runs
 * 0x80024448, 0x80024844, 0x800246e4 and 0x800244d4. Field and type names are
 * inferred from the original instructions. Strings and globals are external
 * views of original data; the unit owns no data.
 *
 * The "WormPot" handle is a local of an inline helper, which gets its own stack
 * block at sp+16 with a gap above it; the later handle reuses sp+8, the slot it
 * shares with the String temporaries. All are one word. */
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
struct String;
struct String {
    char *text;
    String(const char *);
    String(const String &);
    ~String();
};
struct PropertyKey { const char *name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Self {
    char unknown0[28];
    Object *handle28;  /* +28 */
    Object *handle32;  /* +32 */
    Object *handle36;  /* +36 */
    Object *handle40;  /* +40 */
    Object *handle44;  /* +44 */
    Object *activeWormIndex;  /* +48 */
    Object *hUDActWormInfoPos;  /* +52 */
    Object *hUDActWormInfoTextOffset;  /* +56 */
    Object *hUDActWormInfoColourOffset;  /* +60 */
    Object *hUDActWormInfoTextScale;  /* +64 */
    Object *hUDActWormInfoColScale;  /* +68 */
    Object *hUDActWormInfoBackScale;  /* +72 */
    Object *hUDActWormInfoWeapScale;  /* +76 */
    Object *hUDActWormInfoWeapOffset;  /* +80 */
    Object *eFMVActive;  /* +84 */
    Object *weaponPanelOpen;  /* +88 */
    Object *chatOpen;  /* +92 */
    Object *hUDActWormInfoButtOffset;  /* +96 */
    Object *hUDActWormInfoButtScaleTxt;  /* +100 */
    Object *wormPot;  /* +104 */
    char slot108[4];            /* +108 */
    char slot112[4];            /* +112 */
    char slot116[4];            /* +116 */
    char slot120[4];            /* +120 */
    char slot124[4];            /* +124 */
    char slot128[4];            /* +128 */
    char slot132[4];            /* +132 */    int state136;  /* +136 */
};
extern "C" void w3d_hud_layout_80024448(Self *);
extern "C" void w3d_hud_refresh_80024844(Self *, int, int);
extern "C" void w3d_hud_apply_800246e4(Self *);
extern "C" void w3d_hud_offset_800244d4(Self *);
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" Object *w3d_identity_80341584(Object *);
extern "C" Object *w3d_identity_803426b4(Object *);
extern "C" Object *w3d_identity_80342a78(Object *);
extern "C" Object *w3d_identity_80342fa4(Object *);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_subscribe_80162024(Self *, const unsigned short &, void *);
extern MessageCache w3d_message_804aca54, w3d_message_804aca5c, w3d_message_804aca64, w3d_message_804aca6c, w3d_message_804aca74, w3d_message_804aca7c, w3d_message_804aca84;
extern "C" int w3d_handle_load_8015adf4(const String *, Object **, unsigned char);
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
extern "C" char w3d_string_8036c59c[]; /* "HUD.WormInfoBack" */
extern "C" char w3d_string_8036c5b0[]; /* "HUD.WormInfoColour" */
extern "C" char w3d_string_8036c5c4[]; /* "FE.Font" */
extern "C" char w3d_string_8036c5cc[]; /* "FE.WeaponIcons" */
extern "C" char w3d_string_8036c5dc[]; /* "WormPot" */
extern "C" char w3d_string_8036c5e4[]; /* "ActiveWormIndex" */
extern "C" char w3d_string_8036c5f4[]; /* "HUD.ActWormInfo.Pos" */
extern "C" char w3d_string_8036c608[]; /* "HUD.ActWormInfo.TextOffset" */
extern "C" char w3d_string_8036c624[]; /* "HUD.ActWormInfo.ColourOffset" */
extern "C" char w3d_string_8036c644[]; /* "HUD.ActWormInfo.TextScale" */
extern "C" char w3d_string_8036c660[]; /* "HUD.ActWormInfo.ColScale" */
extern "C" char w3d_string_8036c67c[]; /* "HUD.ActWormInfo.BackScale" */
extern "C" char w3d_string_8036c698[]; /* "HUD.ActWormInfo.WeapScale" */
extern "C" char w3d_string_8036c6b4[]; /* "HUD.ActWormInfo.WeapOffset" */
extern "C" char w3d_string_8036c6d0[]; /* "HUD.ActWormInfo.ButtOffset" */
extern "C" char w3d_string_8036c6ec[]; /* "HUD.ActWormInfo.ButtScaleTxt" */
extern "C" char w3d_string_8036c70c[]; /* "EFMV.Active" */
extern "C" char w3d_string_8036c718[]; /* "WeaponPanel.Open" */
extern "C" char w3d_string_8036c72c[]; /* "Chat.Open" */

template <Object *(*Cast)(Object *), class H>
inline void LoadResource(H &h, const char *name, Object *&slot)
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

inline String::~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }

inline void LoadPot(const char *name, Object *&slot)
{
    Handle handle;
    LoadResource<w3d_identity_80341584>(handle, name, slot);
}

extern "C" void w3d_d24a_worm_hud_start_80023944(Self *self)
{
    self->state136 = -1;
    {
        String name(w3d_string_8036c59c);
        w3d_handle_load_8015adf4(&name, &self->handle28, 29);
    }
    {
        String name(w3d_string_8036c5b0);
        w3d_handle_load_8015adf4(&name, &self->handle32, 255);
    }
    {
        String name(w3d_string_8036c5c4);
        w3d_handle_load_8015adf4(&name, &self->handle36, 32);
    }
    {
        String name(w3d_string_8036c5cc);
        w3d_handle_load_8015adf4(&name, &self->handle40, 30);
    }
    LoadPot(w3d_string_8036c5dc, self->wormPot);
    {
        String name(w3d_string_8036c5c4);
        w3d_handle_load_8015adf4(&name, &self->handle44, 32);
    }
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aca54, 1), self->slot108);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aca5c, 1), self->slot112);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aca64, 1), self->slot116);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aca6c, 1), self->slot120);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aca74, 1), self->slot124);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aca7c, 1), self->slot128);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aca84, 1), self->slot132);
    {
    Handle handle;
    LoadResource<w3d_identity_803426b4>(handle, w3d_string_8036c5e4, self->activeWormIndex);
    LoadResource<w3d_identity_80342fa4>(handle, w3d_string_8036c5f4, self->hUDActWormInfoPos);
    LoadResource<w3d_identity_80342fa4>(handle, w3d_string_8036c608, self->hUDActWormInfoTextOffset);
    LoadResource<w3d_identity_80342fa4>(handle, w3d_string_8036c624, self->hUDActWormInfoColourOffset);
    LoadResource<w3d_identity_80342fa4>(handle, w3d_string_8036c644, self->hUDActWormInfoTextScale);
    LoadResource<w3d_identity_80342fa4>(handle, w3d_string_8036c660, self->hUDActWormInfoColScale);
    LoadResource<w3d_identity_80342fa4>(handle, w3d_string_8036c67c, self->hUDActWormInfoBackScale);
    LoadResource<w3d_identity_80342fa4>(handle, w3d_string_8036c698, self->hUDActWormInfoWeapScale);
    LoadResource<w3d_identity_80342fa4>(handle, w3d_string_8036c6b4, self->hUDActWormInfoWeapOffset);
    LoadResource<w3d_identity_80342fa4>(handle, w3d_string_8036c6d0, self->hUDActWormInfoButtOffset);
    LoadResource<w3d_identity_80342fa4>(handle, w3d_string_8036c6ec, self->hUDActWormInfoButtScaleTxt);
    LoadResource<w3d_identity_80342a78>(handle, w3d_string_8036c70c, self->eFMVActive);
    LoadResource<w3d_identity_80342a78>(handle, w3d_string_8036c718, self->weaponPanelOpen);
    LoadResource<w3d_identity_80342a78>(handle, w3d_string_8036c72c, self->chatOpen);
    }
    w3d_hud_layout_80024448(self);
    w3d_hud_refresh_80024844(self, 0, 0);
    w3d_hud_apply_800246e4(self);
    w3d_hud_offset_800244d4(self);
}
