#include "w3d_ptr.h"
#line 1 "d29b_water_light_800919d4.cpp"
/* Water light tables (0x800919d4): normalizes the sun vector at +260 and, unless the tint bytes at
 * +2484 are all above 254, finds the shared table of the prototype (0x800be8f8), creating and locking a
 * new 256-entry table of 16-bit colours through 0x8020b680 when there is none, and publishes it in the
 * prototype; otherwise publishes the object at +368 and uses the plain colours. Then, for each of the 256
 * unit normals at 0x80431ea0, stores the raised normal's light (dot times 63 plus 64) at +388, the normal's
 * own light at +392 unless the prototype byte +450 is set, and for a new table the 4-4-4-4 colour multiplied
 * by the tint. Advances the counter 0x804aab84 by 512. Field names are inferred from the original
 * instructions; layouts are partial views. Owns the float literals at 0x8037e868. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct ArrayHeader { char unknown00[4]; unsigned short refs; char unknown06[18]; int count; unsigned short gen; char unknown30[2]; char data[1]; };
struct Array { Ptr32<ArrayHeader> header; };
extern "C" Ptr32<void> w3d_array_ref_lock_801ef048(Ptr32<Array>, int, int, int);
struct Object { Ptr32<ObjectVtable> vtable; char unknown04[16]; Array array; };
extern "C" Ptr32<Object> w3d_create_8020b680(Ptr32<void>);
extern char lbl_80414840[];
struct Held {
    Ptr32<Object> object;
    template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Object *)w3d_p.get()) {}
 Held(Object *o) : object(o) { if (o) o->vtable->retain(o); }
    Held(const Held &o);
    ~Held() { if (object) object->vtable->release(object); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Object *)w3d_p.get()); }
 void operator=(Object *n) {
        if (n) n->vtable->retain(n);
        if (object) object->vtable->release(object);
        object = n;
    }
    Ptr32<Object> operator->() const { return object; }
};
inline Ptr32<void> Lock(Ptr32<Array> a, int count, int size, int flag) {
    Ptr32<ArrayHeader> h = a->header;
    if (h->refs == 1 && h->count == count) { h->gen++; return h->data; }
    return w3d_array_ref_lock_801ef048(a, count, size, flag);
}
inline Ptr32<void> LockAll(Ptr32<Array> a, int size, int flag) {
    Ptr32<ArrayHeader> h = a->header;
    int n = h->count;
    if (h->refs == 1) { h->gen++; return h->data; }
    return w3d_array_ref_lock_801ef048(a, n, size, flag);
}
struct Proto {
    char unknown00[450]; unsigned char noShade; char unknown451[13]; Ptr32<Object> shade;
    void SetShade(Ptr32<Object> n) {
        Ptr32<Object> old = shade;
        shade = n;
        if (n) n->vtable->retain(n);
        if (old) old->vtable->release(old);
    }
};
extern "C" Ptr32<Object> w3d_find_peer_800be8f8(Ptr32<Proto>);
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { Ptr32<Vec> p = this; x = a; p->y = b; p->z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Scale(float f) { x *= f; y *= f; z *= f; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline bool operator==(const Vec &a, const Vec &b) { return *(Ptr32<int>)&a.x == *(Ptr32<int>)&b.x && *(Ptr32<int>)&a.y == *(Ptr32<int>)&b.y && *(Ptr32<int>)&a.z == *(Ptr32<int>)&b.z; }
extern "C" const Vec lbl_80431ea0[];
extern "C" const Vec lbl_8045e788[];
extern int lbl_804aab84;
struct Pixel {
    unsigned short v;
    const unsigned char &Low() const { return ((Ptr32<const unsigned char>)&v)[0]; }
};
struct Water {
    char unknown00[260]; Vec sun; char unknown272[96]; Ptr32<Object> held368; Ptr32<unsigned short> colors; char unknown376[12];
    Ptr32<unsigned char> shade388; Ptr32<unsigned char> shade392; Ptr32<unsigned short> tinted; char unknown400[132]; Ptr32<Proto> proto; char unknown536[1948];
    unsigned char red, green, blue; /* bytes en crudo: Dolphin da 172 172 172 donde el orden contrario leía 255 172 172 */
};
inline void Tint(Ptr32<Water> self, int i, bool fresh, unsigned red, unsigned green, unsigned blue) {
    unsigned short v = self->colors[i];
    Pixel c;
    c.v = v;
    if (fresh) {
        Ptr32<const Pixel> p = &c;
        unsigned a = (((v >> 8) & 0xf0) * red & 0xf000);
        unsigned g = ((((v >> 4) & 0xf0) * green >> 4) & 0xf00);
        const unsigned char &l = p->Low();
        unsigned b = (((l & 0xf0) * blue >> 8) & 0xf0);
        self->tinted[i] = (l & 15) | (b | (a | g));
    }
}
extern "C" void w3d_d29b_water_light_800919d4(Ptr32<Water> self) {
    Vec sun;
    sun = self->sun;
    bool fresh = false;
    sun.Scale(1.0f / sun.len());
    unsigned red = self->red, green = self->green, blue = self->blue;
    if (red <= 254 || green <= 254 || blue <= 254) {
        Held h(w3d_find_peer_800be8f8(self->proto));
        if (h.object == 0) {
            h = w3d_create_8020b680(lbl_80414840);
            self->tinted = (Ptr32<unsigned short>)Lock(&h->array, 256, 2, 1);
            fresh = true;
        } else {
            self->tinted = (Ptr32<unsigned short>)LockAll(&h->array, 2, 2);
        }
        self->proto->SetShade(h.object);
    } else {
        self->proto->SetShade(self->held368);
        self->tinted = self->colors;
    }
    unsigned char noShade = self->proto->noShade;
    for (int i = 0; i <= 255; i++) {
        Vec d = lbl_80431ea0[i] + Vec(0.0f, 0.1f, 0.0f);
        d.Scale(1.0f / d.len());
        int v = (int)(d.dot(sun) * 63.0f + 64.0f);
        self->shade388[i] = v;
        if (noShade == 0) {
            d = lbl_80431ea0[i];
            if (!(d == lbl_8045e788[0])) d.Scale(1.0f / d.len());
            v = (int)(d.dot(sun) * 63.0f + 64.0f);
        }
        self->shade392[i] = v;
        Tint(self, i, fresh, red, green, blue);
    }
    lbl_804aab84 += 512;
}


