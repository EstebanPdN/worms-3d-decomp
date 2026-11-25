/* Rope trail update (0x800cd178): keeps the segment nodes of the rope effect in
 * step with the rope points, sets each node's position, scale and rotation, and
 * moves the payload to the first point. Names and field views are inferred from
 * the original instructions; the unit owns no data.
 *
 * The compiled-out block before the first test stands for deleted debug or
 * disabled code. Its text is inferred. What the original witnesses is only that
 * Vec temporaries were allocated and freed there: the slots at +152..+200 are
 * never written, and the first operator- result reuses +136. Unused locals
 * cannot give this (their slots are never freed: frame 312 or 344, not 296). */
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    void Set(float v) { Vec *p = this; x = v; p->y = v; p->z = v; }
    Vec(float a, float b, float c) { Vec *p = this; x = a; p->y = b; p->z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline float Inv(float f) { return 1.0f / f; }
inline float Dist(const Vec &a, const Vec &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
}
struct Node;
struct NodeVtable {
    void *unknown00[19];
    int (*set_position)(Node *, const Vec *, int);  /* +76 */
    int (*set_rotation)(Node *, const Vec *, int);  /* +80 */
    int (*set_scale)(Node *, const Vec *, int);     /* +84 */
    void *unknown88;
    int (*spawn)(Node *, Node *, const char *);     /* +92 */
    int (*unspawn)(Node *, Node *);                 /* +96 */
};
struct Node { NodeVtable *vtable; };
struct Rope;
inline void Set0(Node *n, const Vec *v, int f) { n->vtable->set_position(n, v, f); }
inline void Set1(Node *n, const Vec *v, int f) { n->vtable->set_rotation(n, v, f); }
inline void Set2(Node *n, const Vec *v, int f) { n->vtable->set_scale(n, v, f); }
struct List { char unknown00[8]; Node **items; Node *Item(unsigned i) const { return items[i]; } };
struct Trail {
    char unknown00[28]; int handle; char unknown32[4]; Node *payload; Node *owner;
    List list; char unknown56[8]; int attached;
};
struct Key { const char *name; };
struct Worm { char unknown00[72]; float yaw; char unknown76[40]; float pitch; };
extern "C" Rope *lookup_80164fc8(int);
extern "C" int read_800fc1f0(Key *, int *);
extern "C" Worm *worm_800fc6dc(int);
extern "C" int attached_800cfc80(Rope *);
extern "C" int mode2_800cfc98(Rope *);
extern "C" void detach_800cd990(Trail *);
extern "C" void pending_800ccd54(Trail *);
extern "C" void trail_update_800cd834(Trail *, Rope *);
extern "C" unsigned count_800d0f54(Rope *);
extern "C" void resize_800ccdd8(Trail *, unsigned);
extern "C" Vec point_800d0f74(Rope *, unsigned);
extern "C" Vec spawn_800ccc14(Trail *);
extern "C" Vec angles_800ccf50(Trail *, const Vec &);
extern const Vec lbl_8045e788[];
extern char lbl_80387df8[], lbl_80387e28[];
inline void Set2r(Node *n, const Vec &v, int f) { Set2(n, &v, f); }
extern "C" void d31x_rope_trail_update_800cd178(Trail *self) {
    Rope *rope = lookup_80164fc8(self->handle);
    if (rope == 0) return;
    Key key; key.name = lbl_80387e28;
    int index;
    read_800fc1f0(&key, &index);
    Worm *worm = worm_800fc6dc(index);
    Vec angle(-worm->pitch, worm->yaw, 0.0f);
    Vec a, b, mid;
    Vec scale;
    Vec rot;
    int on = attached_800cfc80(rope);
    if (on != self->attached) {
        if (on) self->owner->vtable->unspawn(self->owner, self->payload);
        else self->owner->vtable->spawn(self->owner, self->payload, lbl_80387df8);
    }
    self->attached = on;
    if (0) { Vec t1 = a + b; Vec t2 = a - b; Vec t3 = a - t2; Vec t4 = t1 + t2; Vec t5 = t4 + t3; }
    if (mode2_800cfc98(rope) == 0) {
        if (attached_800cfc80(rope) == 0) {
            detach_800cd990(self);
            pending_800ccd54(self);
            self->payload->vtable->set_position(self->payload, lbl_8045e788, 0);
            self->payload->vtable->set_rotation(self->payload, lbl_8045e788, 0);
            return;
        }
        trail_update_800cd834(self, rope);
        unsigned n = count_800d0f54(rope);
        resize_800ccdd8(self, n);
        scale.Set(1.0f);
        if (n) {
            a = point_800d0f74(rope, 0);
                b = spawn_800ccc14(self);
            Dist(a, b);
                    mid = (b + a) * Inv(2.0f);
            scale.z = Dist(a, b) * 0.25f;
                rot = angles_800ccf50(self, b - a);
            Set0(self->list.Item(0), &mid, 0);
            Set2(self->list.Item(0), &scale, 0);
            Set1(self->list.Item(0), &rot, 0);
        }
        self->payload->vtable->set_position(self->payload, &a, 0);
        self->payload->vtable->set_rotation(self->payload, &angle, 0);
        return;
    }
    trail_update_800cd834(self, rope);
    unsigned n = count_800d0f54(rope);
    resize_800ccdd8(self, n);
    scale.Set(1.0f);
    for (unsigned i = 0; i < n; i++) {
        a = point_800d0f74(rope, i);
        if (i + 1 == n) b = spawn_800ccc14(self);
        else b = point_800d0f74(rope, i + 1);
        mid = (b + a) * 0.5f;
        scale.z = Dist(a, b) * 0.25f;
        rot = angles_800ccf50(self, b - a);
        Set0(self->list.Item(i), &mid, 0);
        { const Vec *ps = &scale; Set2(self->list.Item(i), ps, 0); }
        Set1(self->list.Item(i), &rot, 0);
        if (i == 0) {
            self->payload->vtable->set_position(self->payload, &a, 0);
            self->payload->vtable->set_rotation(self->payload, &rot, 0);
        }
    }
}
