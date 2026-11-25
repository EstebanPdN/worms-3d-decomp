/* Girder preview update (0x80093518): looks up the girder at +28 (0x80164fc8). At the
 * placed limit, hides the preview at +32 (slot +88) and returns -1. Otherwise samples
 * the motion (0x800959d0) into position, axis and up vectors, picks the tint (white, or
 * red when placing is not allowed by +696, +704 or 0x80096564), applies it
 * (0x80343584, 0x80182178), passes the vectors to slots +76, +80, +84, updates the
 * handle at +36 (0x801265ec, 0x801266ac) and returns 0. Field and type names are
 * inferred from the original instructions. Literals 1.0 and 0.0 at 0x8037e9d4. */
struct Vec3 { float x, y, z; };
struct Tint {
    float r, g, b, a;
    Tint() {}
    Tint(float v) { r = v; this->g = v; this->b = v; this->a = v; }
    void Set(float x, float y, float z, float w) { r = x; this->g = y; this->b = z; this->a = w; }
};
struct Preview;
struct PreviewVtable {
    char unknown00[76];
    void (*setPosition)(Preview *, const Vec3 *, int);  /* +76 */
    void (*setAxis)(Preview *, const Vec3 *, int);      /* +80 */
    void (*setUp)(Preview *, const Vec3 *, int);        /* +84 */
    void (*show)(Preview *, int);                       /* +88 */
};
struct Preview { PreviewVtable *vtable; };
struct Girder {
    char unknown00[696];
    int busy;         /* +696 */
    char unknown700[4];
    int blocked;      /* +704 */
    char unknown708[32];
    unsigned limit;   /* +740 */
    unsigned count;   /* +744 */
};
struct Handle;
struct Owner {
    char unknown00[28];
    int girder;       /* +28 */
    Preview *preview; /* +32 */
    Handle *handle;   /* +36 */
};
extern "C" Girder *w3d_lookup_handle_80164fc8(int);
extern "C" void f8b_sample_motion_800959d0(Girder *, int, Vec3 *, Vec3 *, Vec3 *);
extern "C" unsigned s19_handle_cast_query_80096564(Girder *);
extern "C" void *w3d_empty_80343584(Preview *);
extern "C" int w3d_set_tint_80182178(void *, Tint *);
extern "C" void w3d_handle_position_801265ec(Handle *, const Vec3 *);
extern "C" void w3d_handle_colour_801266ac(Handle *, int, float, float, float);

extern "C" int w3d_d25b_girder_preview_80093518(Owner *self, int delta)
{
    Girder *girder = w3d_lookup_handle_80164fc8(self->girder);
    if (girder->count >= girder->limit) {
        self->preview->vtable->show(self->preview, 0);
        return -1;
    }
    Vec3 axis, position, up;
    f8b_sample_motion_800959d0(girder, delta, &position, &axis, &up);
    Tint tint(1.0f);
    if (girder->busy != 0 || girder->blocked != 0 || s19_handle_cast_query_80096564(girder) > 44) {
        tint.Set(1.0f, 0.0f, 0.0f, 1.0f);
    }
    w3d_set_tint_80182178(w3d_empty_80343584(self->preview), &tint);
    self->preview->vtable->setPosition(self->preview, &position, 0);
    self->preview->vtable->setAxis(self->preview, &axis, 0);
    self->preview->vtable->setUp(self->preview, &up, 0);
    if (self->handle) {
        w3d_handle_position_801265ec(self->handle, &position);
        w3d_handle_colour_801266ac(self->handle, 0, tint.r, tint.g, tint.b);
    }
    return 0;
}
