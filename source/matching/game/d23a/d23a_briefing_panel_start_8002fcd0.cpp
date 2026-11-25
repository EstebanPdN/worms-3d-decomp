/* Briefing panel start (0x8002fcd0): subscribes the panel (0x80162024) to
 * the messages of caches 0x804acd4c and 0x804acd54 with handler slots +28
 * and +32, then loads eight resources into +36..+64 through one handle
 * (0x800fc1b0, cast per resource, retaining the new object and releasing
 * the previous one and the handle): "CommentaryPanel.Comment" (cast
 * 0x80343744), "FE.BriefingPanel.Width", ".Height", ".XPos", ".YPos",
 * ".TextSize" (cast 0x80342a74), "FE.BriefingPanel" (cast 0x80341584) and
 * "FE.BriefingPanel.DisplayTime" (cast 0x80342a78), and clears +68 and +72.
 * Field and type names are inferred from the original instructions. Strings
 * and globals are external views of original data; the unit owns no data.
 *
 * The subscription takes the message id by const reference; the int result
 * of the cache lookup converts to a temporary at each call (sp+16, sp+18),
 * before the property keys of the inline loader (sp+20..48). */
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
struct BriefingPanel {
    char unknown00[28];
    char slot28[4];            /* +28 */
    char slot32[4];            /* +32 */
    Object *comment;           /* +36 */
    Object *width;             /* +40 */
    Object *height;            /* +44 */
    Object *xPos;              /* +48 */
    Object *yPos;              /* +52 */
    Object *textSize;          /* +56 */
    Object *panel;             /* +60 */
    Object *displayTime;       /* +64 */
    int unknown68;             /* +68 */
    int unknown72;             /* +72 */
};
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" Object *w3d_identity_80343744(Object *);
extern "C" Object *w3d_identity_80342a74(Object *);
extern "C" Object *w3d_identity_80341584(Object *);
extern "C" Object *w3d_identity_80342a78(Object *);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_subscribe_80162024(BriefingPanel *, const unsigned short &, void *);
extern MessageCache w3d_message_804acd4c, w3d_message_804acd54;
extern "C" char w3d_string_80372fc0[]; /* "FE.BriefingPanel" */
extern "C" char w3d_string_80372fd4[]; /* "CommentaryPanel.Comment" */
extern "C" char w3d_string_80372fec[]; /* "FE.BriefingPanel.Width" */
extern "C" char w3d_string_80373004[]; /* "FE.BriefingPanel.Height" */
extern "C" char w3d_string_8037301c[]; /* "FE.BriefingPanel.XPos" */
extern "C" char w3d_string_80373034[]; /* "FE.BriefingPanel.YPos" */
extern "C" char w3d_string_8037304c[]; /* "FE.BriefingPanel.TextSize" */
extern "C" char w3d_string_80373068[]; /* "FE.BriefingPanel.DisplayTime" */

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

extern "C" void w3d_d23a_briefing_panel_start_8002fcd0(BriefingPanel *self)
{
    Handle handle;
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acd4c, 1), self->slot28);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acd54, 1), self->slot32);
    LoadResource<w3d_identity_80343744>(handle, w3d_string_80372fd4, self->comment);
    LoadResource<w3d_identity_80342a74>(handle, w3d_string_80372fec, self->width);
    LoadResource<w3d_identity_80342a74>(handle, w3d_string_80373004, self->height);
    LoadResource<w3d_identity_80342a74>(handle, w3d_string_8037301c, self->xPos);
    LoadResource<w3d_identity_80342a74>(handle, w3d_string_80373034, self->yPos);
    LoadResource<w3d_identity_80342a74>(handle, w3d_string_8037304c, self->textSize);
    LoadResource<w3d_identity_80341584>(handle, w3d_string_80372fc0, self->panel);
    LoadResource<w3d_identity_80342a78>(handle, w3d_string_80373068, self->displayTime);
    self->unknown68 = 0;
    self->unknown72 = 0;
}
