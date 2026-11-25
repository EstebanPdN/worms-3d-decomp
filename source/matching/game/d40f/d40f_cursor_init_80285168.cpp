// GWMP8P rev0 0x80285168. Cursor setup: loads the pointer sprite and size,
// places it at the configured position and registers its messages.
struct D25fString {
    char *text;
    D25fString(const char *);
    D25fString(const D25fString &);
    ~D25fString();
};
extern "C" void w3d_string_base_finish(D25fString *);
extern "C" void w3d_string_release(D25fString *);
inline D25fString::~D25fString() {
    w3d_string_base_finish(this);
    w3d_string_release(this);
}
struct D25fVec3 { float x, y, z; };
struct D25fNode;
struct D25fNodeTable { char pad[84]; int (*set_scale)(D25fNode *, const D25fVec3 *, int); };
struct D25fNode { D25fNodeTable *vt; };
extern "C" int w3d_handle_set_name_8015adf4(const D25fString &, D25fNode **, unsigned char);
struct D25fKey { const char *name; D25fKey(const char *n) : name(n) {} };
struct D25fCursor {
    char pad0[28];
    D25fNode *node;
    D25fVec3 position;
    D25fVec3 hotspot;
    float size;
    void *press_ref;
    void *release_ref;
};
struct D25fConfig { char pad[124]; float x, y; };
struct D25fGlobals { D25fConfig *config; };
extern D25fGlobals w3d_globals_804aac54;
extern char lbl_803cf368[], lbl_803cf374[];
struct D25fMessageName { unsigned words[2]; };
extern D25fMessageName w3d_name_804b0b8c, w3d_name_804b0b94;
extern "C" void w3d_auto_800fc270(const D25fKey &, float *);
extern "C" bool cc43b_clamp_position_802852c4(D25fCursor *);
extern "C" float w3d_sqrt_802e82c0(float);
extern "C" unsigned int w3d_cached_message_id(void *, int);
extern "C" int d24d_acquire_message_80162024(D25fCursor *, const unsigned short &, void **);
extern "C" void w3d_d40f_cursor_init_80285168(D25fCursor *self) {
    { D25fString name(lbl_803cf368); const D25fString &r = name; w3d_handle_set_name_8015adf4(r, &self->node, 255); }
    D25fVec3 scale;
    D25fVec3 *s = &scale;
    w3d_auto_800fc270(D25fKey(lbl_803cf374), &self->size);
    D25fVec3 &p = self->position;
    self->position.x = w3d_globals_804aac54.config->x;
    self->position.y = w3d_globals_804aac54.config->y;
    cc43b_clamp_position_802852c4(self);
    D25fVec3 *h = &self->hotspot;
    scale.x = self->size;
    scale.y = self->size;
    s->z = 0.0f;
    do { *h = p; } while (0);
    self->hotspot.x += w3d_sqrt_802e82c0(self->size);
    self->hotspot.y += w3d_sqrt_802e82c0(self->size);
    self->node->vt->set_scale(self->node, s, 0);
    d24d_acquire_message_80162024(self, w3d_cached_message_id(&w3d_name_804b0b8c, 1), &self->press_ref);
    d24d_acquire_message_80162024(self, w3d_cached_message_id(&w3d_name_804b0b94, 1), &self->release_ref);
}
