// d26c: 0x800f6798. Plane test of an instance's boxes against a mesh's part list: returns 0 on the first part whose
// flags reject the box. Names are inferred.
struct Part { char u0[56]; unsigned char flags; };
struct Box {
    char u0[8]; float d;
    char u12[8]; float a;
    char u24[8]; float b;
    char u36[8]; float c;
    char u48[4]; float e; float f; float g;
};
struct Mesh { char u0[32]; Part *parts[1]; };
struct Node { char u0[76]; Mesh *mesh; };
struct Owner { char u0[80]; Node **nodes; };
struct Inst {
    char u0[16];
    Box **start; Box **finish; char u24[4];
    int index;
    unsigned size() const { return finish - start; }
    Box *&operator[](unsigned i) { return start[i]; }
};
extern "C" int d26c_frustum_test_800f6798(Owner *o, Inst *s) {
    Part **parts = o->nodes[s->index]->mesh->parts;
    for (unsigned i = 0; i < s->size(); i++) {
        unsigned char fl = parts[i]->flags;
        if (fl & 1) {
            Box *b = (*s)[i];
            float e = b->b * b->f; e -= __builtin_fabsf(b->a * b->e); e -= __builtin_fabsf(b->c * b->g);
            if (b->d + e < 0.0f || b->d - e > 0.0f) return 0;
        } else if (fl == 0) {
            Box *b = (*s)[i];
            if ((b->b * b->f + __builtin_fabsf(b->a * b->e) + __builtin_fabsf(b->c * b->g)) * 0.3f + b->d < 0.0f) return 0;
        }
    }
    return 1;
}
