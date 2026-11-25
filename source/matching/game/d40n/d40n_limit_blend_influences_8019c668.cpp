// GWMP8P rev0 0x8019c668. Builds a limited skin blend: for each vertex keeps
// the n largest of its source weights (sorted, then insertion), normalises
// them and writes indices and weights into a new blend object held by the
// owner. Names are inferred.
extern "C" void *fn_8020b680(void *);
struct Pair { float weight; int index; };
extern "C" void fn_80351d58(Pair *, Pair *);
extern char type_80363604[];
extern char registry_804148b0[];
struct Rc { virtual void s8(); virtual void retain(); virtual void release(); };
struct Store;
extern "C" void *fn_801ef048(Store **, unsigned, unsigned, unsigned);
struct Store { char u0[4]; unsigned short refs; char u6[18]; int count; unsigned short locks; short u30; char data[1]; };
struct Blend : Rc { char u4[16]; Store *weights; unsigned short perVertex; char u26[2]; Store *indices;
};
inline void *lockArray(Store **st, unsigned n, unsigned size) {
    Store *s = *st;
    void *p;
    if (s->refs == 1 && n == s->count) { ++s->locks; p = s->data; }
    else p = fn_801ef048(st, n, size, 1);
    return p;
}
struct InputApi { virtual void s8(); virtual void s12(); virtual void s16(); virtual char *Type(); };
struct Input : InputApi { char u4[16]; Store *data; unsigned short stride; };
struct NodeApi { virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual unsigned Influences(); };
struct Second { virtual void z8(); };
struct Owner : NodeApi, Second { char u8[36]; Blend *blend; };
extern "C" int w3d_d40n_limit_blend_influences_8019c668(Second *a, Input *in) {
    Owner *self = static_cast<Owner *>(a);
    unsigned n = self->Influences();
    if (in->Type() != type_80363604) return 0;
    Blend *b = (Blend *)fn_8020b680(registry_804148b0);
    if (b) b->retain();
    if (self->blend) self->blend->release();
    self->blend = b;
    unsigned bytes = n * sizeof(Pair);
    float *src = (float *)in->data->data;
    unsigned stride = in->stride;
    unsigned entries = in->data->count / stride;
    Pair *top = (Pair *)__builtin_alloca(bytes);
    char *idx;
    float *w;
    idx = (char *)lockArray(&b->indices, n * entries, 1);
    w = (float *)lockArray(&b->weights, n * entries, 4);
    b->perVertex = n;
    for (unsigned e = 0; e < entries; e++) {
        for (unsigned j = 0; j < n; j++) { top[j].weight = src[j]; top[j].index = j; }
        fn_80351d58(top, top + n);
        for (unsigned k = n; k < stride; k++) {
            for (unsigned j = 0; j < n; j++) {
                if (top[j].weight < src[k]) {
                    for (unsigned m = n - 1; m > j; m--) top[m] = top[m - 1];
                    top[j].weight = src[k];
                    top[j].index = k;
                    break;
                }
            }
        }
        float sum = 0.0f;
        unsigned j;
        for (j = 0; j < n; j++) sum += top[j].weight;
        float inv = 1.0f / sum;
        for (j = 0; j < n; j++) { idx[j] = top[j].index; w[j] = top[j].weight * inv; }
        idx += n; w += n; src += stride;
    }
    return 0;
}
