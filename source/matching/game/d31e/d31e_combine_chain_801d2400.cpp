// (Worms 3D GameCube PAL, 0x801d2400).
//
// Multiplies the local matrices of a bone chain: visits each bone through
// the visitor at +68, copies the first bone's matrix into a pair of working
// matrices, then multiplies each next bone into the other working matrix
// with 0x801f740c. Stores the final product, or the identity at 0x8045e748
// when the chain is empty, in the chain's matrix at +36. Names are inferred.

struct Mat {
    float m[12];
    Mat() { }
    ~Mat() { }
};
struct Bone { char pad[20]; Mat local; };
struct Chain { char pad[24]; int count; char pad28[4]; Bone **items; Mat world; };
struct ChainRef { Chain *p; };
struct Visitor { virtual void v0(),v1(),v2(),v3(); virtual int visit(Bone *); };
struct Self { char pad[68]; Visitor *visitor; };
extern Mat g_identity[];
extern "C" void w3d_auto_801f740c(Mat *, const Mat *, const Mat *);
extern "C" void w3d_d31e_combine_chain_801d2400(Self *self, ChainRef *chain)
{
    bool first = true;
    Mat m[2];
    int cur = 0;
    Chain *c = chain->p;
    Bone **p = c->items;
    Bone **end = p + c->count;
    for (; p != end; p++) {
        self->visitor->visit(*p);
        if (first) {
            m[0] = (*p)->local;
            first = false;
        } else {
            cur ^= 1;
            w3d_auto_801f740c(&m[cur], &(*p)->local, &m[cur ^ 1]);
        }
    }
    if (first) chain->p->world = g_identity[0];
    else chain->p->world = m[cur];
}
