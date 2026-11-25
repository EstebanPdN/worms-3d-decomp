#include "w3d_ptr.h"
#line 1 "d41n_curve_evaluate_nearest_80196cf0.cpp"
// GWMP8P rev0 0x80196cf0. Second keyframe curve evaluator, twin of the one
// at 0x801961a8, with a cached cursor that can move by one key in either
// direction. The early returns of the local result keep the argument copy
// before the first call, and one key pointer is shared across the cursor and
// segment paths.
struct Key { float t, v, inT, inV, outT, outV; };
struct KeyList { Ptr32<Key> keys; unsigned short count; Key &At(int i) { return keys[i]; } Key &Last() { return keys[count - 1]; } };
struct CurveData { unsigned flags; KeyList list; };
struct Curve { Ptr32<CurveData> d; };
extern int lastSeg_804b18bc, flat_804b18c0, idx_804b18cc;
extern Ptr32<Key> key_804b18c8;
extern "C" float fn_80196a54(Ptr32<Curve>, float, int);
extern "C" int fn_801969c4(Ptr32<Curve>, float, Ptr32<int>);
extern "C" void fn_801966a0(Ptr32<Curve>, Ptr32<float>, Ptr32<float>);
extern "C" void fn_801968e8(Ptr32<Curve>, Ptr32<float>, Ptr32<float>);
extern "C" float fn_80196504(Ptr32<Curve>, float);
extern "C" float fn_8019661c(Ptr32<Curve>, float);
extern "C" float w3d_d41n_curve_evaluate_nearest_80196cf0(Ptr32<Curve> c, float t) {
    int idx;
    int found = 0;
    float r = 0.0f;
    Ptr32<Key> k;
    Ptr32<CurveData> d = c->d;
    if (!d) return r;
    if (!d->list.count) return r;
    if (d->flags & 0x0e000000) { if (!(t < d->list.keys[0].t)) goto after; r = fn_80196a54(c, t, 1); goto done; }
after:
    if ((c->d->flags & 0x01c00000) && t > c->d->list.Last().t) { r = fn_80196a54(c, t, 0); goto done; }
    if (c->d->flags & 0x20000000) { r = c->d->list.keys[0].v; goto done; }
    if (key_804b18c8) {
        float kt = key_804b18c8->t;
        if (idx_804b18cc < c->d->list.count - 1 && t > kt) {
            int n = idx_804b18cc + 1;
            k = &c->d->list.At(n);
            float next = k->t;
            if (t == next) {
                r = k->v;
                idx_804b18cc = n;
                key_804b18c8 = k;
                goto done;
            }
            if (t < next) { idx = n; found = 1; }
        } else if (idx_804b18cc > 0 && t < kt) {
            k = &c->d->list.At(idx_804b18cc + 1);
            if (t > k->t) { idx = idx_804b18cc; found = 1; }
            if (t == k->t) {
                r = k->v;
                key_804b18c8 = k;
                idx_804b18cc = idx_804b18cc - 1;
                goto done;
            }
        }
    }
    if (!found) {
        int exact = fn_801969c4(c, t, &idx);
        if (exact || idx == 0) {
            Ptr32<Key> k = &c->d->list.At(idx);
            idx_804b18cc = idx;
            key_804b18c8 = k;
            r = k->v;
            goto done;
        }
        if (idx == c->d->list.count) {
            idx_804b18cc = exact;
            key_804b18c8 = c->d->list.keys;
            r = key_804b18c8[idx - 1].v;
            goto done;
        }
    }
    {
    int seg = idx - 1;
    if (lastSeg_804b18bc != seg) {
        lastSeg_804b18bc = seg;
        idx_804b18cc = seg;
        key_804b18c8 = &c->d->list.keys[seg];
        if (key_804b18c8->outT == 0.0f && key_804b18c8->outV == 0.0f) {
            flat_804b18c0 = 1;
        } else {
            float ts[4], vs[4];
            const float third = 0.33333334f;
            ts[0] = key_804b18c8->t;
            vs[0] = key_804b18c8->v;
            flat_804b18c0 = 0;
            ts[1] = key_804b18c8->outT * third + ts[0];
            vs[1] = key_804b18c8->outV * third + vs[0];
            k = &c->d->list.keys[idx];
            ts[3] = k->t;
            vs[3] = k->v;
            ts[2] = ts[3] - k->inT * third;
            vs[2] = vs[3] - k->inV * third;
            if (c->d->flags & 0x40000000) fn_801966a0(c, ts, vs);
            else fn_801968e8(c, ts, vs);
        }
    }
    }
    if (flat_804b18c0) { r = key_804b18c8->v; goto done; }
    if (c->d->flags & 0x40000000) r = fn_80196504(c, t);
    else r = fn_8019661c(c, t);
done:
    return r;
}


