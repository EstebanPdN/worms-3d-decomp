// GWMP8P rev0 0x801961a8. Evaluates a keyframe curve at a time t, reusing a
// cached key cursor. An early return of the local result, not a jump to the
// shared tail, keeps a label until the no-op float move is deleted, so
// reload's value tracking forgets r3 and the argument copy before the first
// call survives.
struct Key { float t, v, inT, inV, outT, outV; };
struct KeyList { Key *keys; unsigned short count; Key &At(int i) { return keys[i]; } Key &Last() { return keys[count - 1]; } };
struct CurveData { unsigned flags; KeyList list; };
struct Curve { CurveData *d; };
extern int lastSeg_804b18bc, flat_804b18c0, idx_804b18cc;
extern Key *key_804b18c8;
extern "C" float fn_80196a54(Curve *, float, int);
extern "C" int fn_801969c4(Curve *, float, int *);
extern "C" void fn_801966a0(Curve *, float *, float *);
extern "C" void fn_801968e8(Curve *, float *, float *);
extern "C" float fn_80196504(Curve *, float);
extern "C" float fn_8019661c(Curve *, float);
#define KEY_AT(c, i) (&(c)->d->list.At(i))
extern "C" float w3d_d41n_curve_evaluate_cached_801961a8(Curve *c, float t) {
    int idx = idx_804b18cc;
    int found = 0;
    float r = 0.0f;
    key_804b18c8 = 0;
    idx_804b18cc = -1;
    lastSeg_804b18bc = -1;
    CurveData *d = c->d;
    KeyList *list = &d->list;
    if (!list->keys || !d || !list->count) return r;
    if (d->flags & 0x0e000000) { if (!(t < list->keys[0].t)) goto after; r = fn_80196a54(c, t, 1); goto done; }
after:
    if ((c->d->flags & 0x01c00000) && t > c->d->list.Last().t) { r = fn_80196a54(c, t, 0); goto done; }
    if (c->d->flags & 0x20000000) { r = c->d->list.keys[0].v; goto done; }
    if (key_804b18c8 && idx_804b18cc < c->d->list.count - 1) {
        int n = idx_804b18cc + 1;
        float next = KEY_AT(c, n)->t;
        if (t >= key_804b18c8->t && t < next) {
            idx = n;
            found = 1;
        } else if (idx_804b18cc < c->d->list.count - 2 && t >= next) {
            n = idx_804b18cc + 2;
            if (t < KEY_AT(c, n)->t) {
                idx = n;
                found = 1;
            }
        }
    }
    if (!found) {
        int exact = fn_801969c4(c, t, &idx);
        if (exact || idx == 0) {
            Key *k = &c->d->list.At(idx);
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
            Key *n = &c->d->list.keys[idx];
            ts[3] = n->t;
            vs[3] = n->v;
            ts[2] = ts[3] - n->inT * third;
            vs[2] = vs[3] - n->inV * third;
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
