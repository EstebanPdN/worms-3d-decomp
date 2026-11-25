// (Worms 3D GameCube PAL, 0x801ff704).
//
// Queries each of n interface references for the interface id at 0x8040c970
// and passes the result to the target's virtual slot 6 with arg, releasing
// it after each call; stops and returns the first negative result, otherwise
// returns 0. Names are inferred.

struct Iface {
    virtual int query(const void *iid, void *out);
    virtual void v1();
    virtual void release();
};
struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int connect(Iface *, int);
};
extern char lbl_8040c970[];
struct Ref {
    Iface *p;
    Ref() {}
    Ref(const Ref &);
    void clear() { if (p) p->release(); }
};
extern "C" int w3d_d29e_connect_each_801ff704(void *self, Target *target, Ref *list, int arg, unsigned n)
{
    Ref *src = list;
    Ref r;
    unsigned i = 0;
    if (i < n) {
        Ref *out = &r;
        do {
            r.p = 0;
            Iface *q = src->p;
            if (q) q->query(lbl_8040c970, out);
            else r.p = q;
            int hr = target->connect(r.p, arg);
            if (hr < 0) {
                r.clear();
                return hr;
            }
            src++;
            r.clear();
            i++;
        } while (i < n);
    }
    return 0;
}
