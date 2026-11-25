/* Worm energy HUD start-up (0x800656b4): creates four parts of type 0x8040edb0
 * into +28..+40 (0x8020b680, 0x80164514), passing each one's looked-up object
 * (0x80164fc8) and index to 0x80064190 and 0x80064384; reads "ActiveWormIndex"
 * into +44; loads "HUD.Energy.MaxLength", "ActiveWormIndex",
 * "HUD.Energy.InActiveTimer", "EFMV.Active" and "WeaponPanel.Open" into +88..+104
 * through one handle (casts 0x80342a74, 0x803426b4, 0x80342a78) with
 * retain/release; subscribes to ten cached messages with handler slots +48..+84
 * and runs 0x80065ce0 and 0x800664c4. Field and type names are inferred from the
 * original instructions. Strings and globals are external views of original
 * data; the unit owns no data.
 *
 * The inline loader takes its key as a const reference to a temporary built by
 * the caller, which puts the key address ahead of the handle address. */
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
struct PropertyKey { const char *name; PropertyKey(const char *n) { name = n; } };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Timed;
struct Self {
    char unknown0[20];
    unsigned id;  /* +20 */
    char unknown24[4];
    void *parts[4];  /* +28 */
    Object *activeWormIndex;  /* +44 */
    char slot48[4];            /* +48 */
    char slot52[4];            /* +52 */
    char slot56[4];            /* +56 */
    char slot60[4];            /* +60 */
    char slot64[4];            /* +64 */
    char slot68[4];            /* +68 */
    char slot72[4];            /* +72 */
    char slot76[4];            /* +76 */
    char slot80[4];            /* +80 */
    char slot84[4];            /* +84 */
    Object *hUDEnergyMaxLength;  /* +88 */
    Object *activeWorm;  /* +92 */
    Object *hUDEnergyInActiveTimer;  /* +96 */
    Object *eFMVActive;  /* +100 */
    Object *weaponPanelOpen;  /* +104 */
};
extern "C" void *w3d_type_lookup_8020b680(void *);
extern "C" void *w3d_create_part_80164514(void *, void *, unsigned);
extern "C" Timed *w3d_lookup_80164fc8(void *);
extern "C" void w3d_set_mode_80064190(Timed *, int);
extern "C" void w3d_set_label_80064384(Timed *, int);
extern "C" void w3d_update_80065ce0(Self *);
extern "C" void w3d_stamp_800664c4(Self *);
extern void *w3d_service_804b178c;
extern unsigned char w3d_type_8040edb0[];
extern "C" int w3d_resource_property_800fc1b0(const PropertyKey *, Object **);
extern "C" Object *w3d_identity_803426b4(Object *);
extern "C" Object *w3d_identity_80342a74(Object *);
extern "C" Object *w3d_identity_80342a78(Object *);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_subscribe_80162024(Self *, const unsigned short &, void *);
extern MessageCache w3d_message_804ad558, w3d_message_804ad560, w3d_message_804ad568, w3d_message_804ad570, w3d_message_804ad578, w3d_message_804ad580, w3d_message_804ad588, w3d_message_804ad590, w3d_message_804ad598, w3d_message_804ad5a0;
extern "C" char w3d_string_80379e18[]; /* "ActiveWormIndex" */
extern "C" char w3d_string_80379e28[]; /* "HUD.Energy.MaxLength" */
extern "C" char w3d_string_80379e40[]; /* "HUD.Energy.InActiveTimer" */
extern "C" char w3d_string_80379e5c[]; /* "EFMV.Active" */
extern "C" char w3d_string_80379e68[]; /* "WeaponPanel.Open" */

template <Object *(*Cast)(Object *)>
inline void LoadResource(const PropertyKey &key, Handle &h, Object *&slot)
{
    h.value = 0;
    w3d_resource_property_800fc1b0(&key, &h.value);
    Object *object = Cast(h.value);
    if (object) object->vtable->retain(object);
    if (slot) slot->vtable->release(slot);
    slot = object;
    if (h.value) h.value->vtable->release(h.value);
}

extern "C" void w3d_d24a_energy_hud_start_800656b4(Self *self)
{
    Handle handle;
    for (unsigned i = 0; i <= 3; i++) {
        void *type = w3d_type_lookup_8020b680(w3d_type_8040edb0);
        self->parts[i] = w3d_create_part_80164514(w3d_service_804b178c, type, self->id);
        Timed *timed = w3d_lookup_80164fc8(self->parts[i]);
        w3d_set_mode_80064190(timed, i);
        w3d_set_label_80064384(timed, i);
    }
    { PropertyKey key(w3d_string_80379e18); w3d_resource_property_800fc1b0(&key, &self->activeWormIndex); }
    LoadResource<w3d_identity_80342a74>(PropertyKey(w3d_string_80379e28), handle, self->hUDEnergyMaxLength);
    LoadResource<w3d_identity_803426b4>(PropertyKey(w3d_string_80379e18), handle, self->activeWorm);
    LoadResource<w3d_identity_80342a78>(PropertyKey(w3d_string_80379e40), handle, self->hUDEnergyInActiveTimer);
    LoadResource<w3d_identity_80342a78>(PropertyKey(w3d_string_80379e5c), handle, self->eFMVActive);
    LoadResource<w3d_identity_80342a78>(PropertyKey(w3d_string_80379e68), handle, self->weaponPanelOpen);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad558, 1), self->slot56);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad560, 1), self->slot48);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad568, 1), self->slot52);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad570, 1), self->slot60);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad578, 1), self->slot64);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad580, 1), self->slot68);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad588, 1), self->slot72);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad590, 1), self->slot80);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad598, 1), self->slot84);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad5a0, 1), self->slot76);
    w3d_update_80065ce0(self);
    w3d_stamp_800664c4(self);
}
