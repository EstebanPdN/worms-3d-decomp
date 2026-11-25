// Layouts inferred from accesses in the target function.
struct Vec {
    float x, y, z;
    Vec(const Vec &v) { float a = v.x, b = v.y, c = v.z; x = a; z = c; y = b; }
    Vec &operator=(const Vec &v) { unsigned *d = (unsigned *)this; const unsigned *s = (const unsigned *)&v; unsigned a=s[0], b=s[1], c=s[2]; d[0]=a; d[2]=c; d[1]=b; return *this; }
};
struct Source { char pad[20]; int elapsed; Vec value; };
struct Context { char pad[52]; int delta; };
struct Message { char pad[8]; int kind; char pad2[4]; Vec value; };
extern "C" {
extern void *queue_804b1754;
Context *context_80165254(void);
void *allocate_801613f0(void *, int);
Message *construct_80131a84(void *);
void post_8016239c(Message *);
int terra_only_a3_motion_8002165c(Source *s) {
    s->elapsed += context_80165254()->delta;
    Message *m = construct_80131a84(allocate_801613f0(queue_804b1754, 236));
    m->kind = 4;
    m->value = Vec(s->value);
    post_8016239c(m);
    return 0;
}
}
